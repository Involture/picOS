#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <kernel/tty_ext.h>

#define print tty_ext_write

static char hex_cvrt_array[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

static void hex_cvrt (char* dest, const char* src, size_t size) {
  for (size_t i = 0; i < size; i++) {
    dest[2 * i] = hex_cvrt_array[src[i] >> 4 & (char) 0x0F];
    dest[2 * i + 1] = hex_cvrt_array[src[i] & (char) 0x0F];
  };
}

int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			print(format, amount);
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			print(&c, sizeof(c));
			written++;
		} 
    else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			print(str, len);
			written += len;
		} 
    else if (*format == 'x') {
      format++;
      char c = (char) va_arg(parameters, int);
      if (maxrem < 2) {
        //TODO: Set errno to EOVERFLOW
        return -1;
      }
      char dest[2];
      hex_cvrt(dest, &c, sizeof(c));
      print(dest, sizeof(dest));
      written += 2;
    }
    else if (*format == 'w') {
      format++;
      const char* bytes = va_arg(parameters, const char*);
      size_t size = va_arg(parameters, size_t);
      if (maxrem < size) {
        // TODO: set errno to EOVERFLOW
        return -1;
      }
      char dest[2];
      for (size_t i = 0; i < size;  i++) {
        hex_cvrt(dest, bytes + i, sizeof(char));
        print(dest, sizeof(dest));
      }
      written += 2 * size;
    }
    else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
		  print(format, len);
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}
