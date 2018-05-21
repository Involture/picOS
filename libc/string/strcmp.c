#include <string.h>

size_t strcmp(const char* str1, const char* str2) {
	size_t len = 0;
	size_t rslt = 0;
	while (str1[len] && str2[len]) {
		if (! (str1[len] == str2[len])) {
			rslt = 1;
			break;
		}
		len++;
	}
		
	return rslt;
}
