#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/ps2_kbd.h>
#include <kernel/ps2_kbd_kmp.h>

static unsigned char ps2_kbd_kmp_history[PS2_KBD_KMP_HISTORY_SIZE];

char ps2_kbd_kmp_pos = 0;
char ps2_kbd_kmp_pos_last_cmd = -1;
char ps2_kbd_kmp_pos_shift = 1;

void ps2_kbd_kmp_load(unsigned char x) {
	ps2_kbd_kmp_history[(unsigned char) (ps2_kbd_kmp_pos % PS2_KBD_KMP_HISTORY_SIZE)] = x;

	ps2_kbd_kmp_is_cmd(ps2_kbd_kmp_history);

	ps2_kbd_kmp_pos += 1;
	ps2_kbd_kmp_pos %= PS2_KBD_KMP_HISTORY_SIZE;
	// printf("%x ", ps2_kbd_kmp_pos);
	// printf("%x ", ps2_kbd_kmp_pos_shift);
	// printf("%x\n", ps2_kbd_kmp_pos_last_cmd);
};

void pli(unsigned long int a) {
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;
	unsigned char b5;
	unsigned char b6;
	unsigned char b7;
	unsigned char b8;
	b1 = a;
	b2 = a >> 4;
	b3 = a >> 8;
	b4 = a >> 12;
	b5 = a >> 16;
	b6 = a >> 20;
	b7 = a >> 24;
	b8 = a >> 28;
	b1 = b1 % 256;
	b2 = b2 % 256;
	b3 = b3 % 256;
	b4 = b4 % 256;
	b5 = b5 % 256;
	b6 = b6 % 256;
	b7 = b7 % 256;
	b8 = b8 % 256;
	printf("%x", b8);
	printf("%x", b7);
	printf("%x", b6);
	printf("%x", b5);
	printf("%x", b4);
	printf("%x", b3);
	printf("%x", b2);
	printf("%x", b1);
	printf("\n");
}

void ps2_clear() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void ps2_kbd_kmp_is_cmd(unsigned char* history) {
	unsigned char last_cmd[3] = {0};

	ps2_kbd_kmp_pos_shift = (unsigned char) (((unsigned char) (ps2_kbd_kmp_pos - ps2_kbd_kmp_pos_last_cmd)) % PS2_KBD_KMP_HISTORY_SIZE);

	// printf("%x ", ps2_kbd_kmp_pos);
	// printf("%x ", ps2_kbd_kmp_pos_shift);
	// printf("%x\n", ps2_kbd_kmp_pos_last_cmd);
	unsigned char i = 0;
	while (i <= (ps2_kbd_kmp_pos_shift - 1) && i <= 2) {
		last_cmd[2-i] = history[((unsigned char) ((ps2_kbd_kmp_pos - i) % PS2_KBD_KMP_HISTORY_SIZE))];
		// printf("%x ", last_cmd[2-i]);
		i += 1;
	};
	// printf("\n");
	unsigned char a = 0x00;
	unsigned char b = 0x00;
	unsigned char c = 0x00;
	switch (ps2_kbd_kmp_pos_shift) {
		case 1:
			a = 0x00;
			b = 0x00;
			c = last_cmd[2];
			break;
		case 2:
			a = 0x00;
			b = last_cmd[1];
			c = last_cmd[2];
			break;
		case 3:
			a = last_cmd[0];
			b = last_cmd[1];
			c = last_cmd[2];
			break;
		default:
			a = 0x00;
			b = 0x00;
			c = 0x00;
	}

	// printf("%x ", a);
	// printf("%x ", b);
	// printf("%x\n", c);


	char* last_cmd_name = "";
	char* last_cmd_chr = "";
	unsigned char last_cmd_is_pressed = 1;
	unsigned char is_cmd = 1;
    switch(a) {
        case 0x00:
            switch(b) {
                case 0x00:
                    switch(c) {
                        case 0x01:
                            last_cmd_name = "F9";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x02:
                            last_cmd_name = "F7";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x03:
                            last_cmd_name = "F5";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x04:
                            last_cmd_name = "F3";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x05:
                            last_cmd_name = "F1";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x06:
                            last_cmd_name = "F2";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x07:
                            last_cmd_name = "F12";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x09:
                            last_cmd_name = "F10";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x0A:
                            last_cmd_name = "F8";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x0B:
                            last_cmd_name = "F6";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x0C:
                            last_cmd_name = "F4";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x0D:
                            last_cmd_name = "Tab";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "  ";
                            break;
                        case 0x0E:
                            last_cmd_name = "^{2}";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x11:
                            last_cmd_name = "AltL";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x12:
                            last_cmd_name = "ShiftL";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x14:
                            last_cmd_name = "CtrlL";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x15:
                            last_cmd_name = "A";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "a";
                            break;
                        case 0x16:
                            last_cmd_name = "1";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "1";
                            break;
                        case 0x1A:
                            last_cmd_name = "W";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "w";
                            break;
                        case 0x1B:
                            last_cmd_name = "S";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "s";
                            break;
                        case 0x1C:
                            last_cmd_name = "Q";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "q";
                            break;
                        case 0x1D:
                            last_cmd_name = "Z";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "z";
                            break;
                        case 0x1E:
                            last_cmd_name = "2";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "2";
                            break;
                        case 0x1F:
                            last_cmd_name = "Windows";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x21:
                            last_cmd_name = "C";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "c";
                            break;
                        case 0x22:
                            last_cmd_name = "X";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "x";
                            break;
                        case 0x23:
                            last_cmd_name = "D";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "d";
                            break;
                        case 0x24:
                            last_cmd_name = "E";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "e";
                            break;
                        case 0x25:
                            last_cmd_name = "4";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "4";
                            break;
                        case 0x26:
                            last_cmd_name = "3";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "3";
                            break;
                        case 0x29:
                            last_cmd_name = "Espace";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = " ";
                            break;
                        case 0x2A:
                            last_cmd_name = "V";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "v";
                            break;
                        case 0x2B:
                            last_cmd_name = "F";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "f";
                            break;
                        case 0x2C:
                            last_cmd_name = "T";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "t";
                            break;
                        case 0x2D:
                            last_cmd_name = "R";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "r";
                            break;
                        case 0x2E:
                            last_cmd_name = "5";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "5";
                            break;
                        case 0x31:
                            last_cmd_name = "N";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "n";
                            break;
                        case 0x32:
                            last_cmd_name = "B";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "b";
                            break;
                        case 0x33:
                            last_cmd_name = "H";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "h";
                            break;
                        case 0x34:
                            last_cmd_name = "G";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "g";
                            break;
                        case 0x35:
                            last_cmd_name = "Y";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "y";
                            break;
                        case 0x36:
                            last_cmd_name = "6";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "6";
                            break;
                        case 0x3A:
                            last_cmd_name = "?";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "?";
                            break;
                        case 0x3B:
                            last_cmd_name = "J";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "j";
                            break;
                        case 0x3C:
                            last_cmd_name = "U";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "u";
                            break;
                        case 0x3D:
                            last_cmd_name = "7";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "7";
                            break;
                        case 0x3E:
                            last_cmd_name = "8";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "8";
                            break;
                        case 0x41:
                            last_cmd_name = ".";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = ".";
                            break;
                        case 0x42:
                            last_cmd_name = "K";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "k";
                            break;
                        case 0x43:
                            last_cmd_name = "I";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "i";
                            break;
                        case 0x44:
                            last_cmd_name = "O";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "o";
                            break;
                        case 0x45:
                            last_cmd_name = "0";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "0";
                            break;
                        case 0x46:
                            last_cmd_name = "9";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "9";
                            break;
                        case 0x49:
                            last_cmd_name = "/";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "/";
                            break;
                        case 0x4A:
                            last_cmd_name = "Paragraphe";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "!";
                            break;
                        case 0x4B:
                            last_cmd_name = "L";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "l";
                            break;
                        case 0x4C:
                            last_cmd_name = "M";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "m";
                            break;
                        case 0x4D:
                            last_cmd_name = "P";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "p";
                            break;
                        case 0x4E:
                            last_cmd_name = "\no";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "°";
                            break;
                        case 0x52:
                            last_cmd_name = "%";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "%";
                            break;
                        case 0x54:
                            last_cmd_name = "Trema";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "^";
                            break;
                        case 0x55:
                            last_cmd_name = "+";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "+";
                            break;
                        case 0x58:
                            last_cmd_name = "CapsLock";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = " ";
                            break;
                        case 0x59:
                            last_cmd_name = "ShiftR";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x5A:
                            last_cmd_name = "Entree";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x5B:
                            last_cmd_name = "Livre";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "$";
                            break;
                        case 0x5D:
                            last_cmd_name = "Mu";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "*";
                            break;
                        case 0x61:
                            last_cmd_name = "<>";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "<>";
                            break;
                        case 0x66:
                            last_cmd_name = "Backspace";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x69:
                            last_cmd_name = "k1";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "1";
                            break;
                        case 0x6B:
                            last_cmd_name = "k4";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "4";
                            break;
                        case 0x6C:
                            last_cmd_name = "k7";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "7";
                            break;
                        case 0x70:
                            last_cmd_name = "k0";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "0";
                            break;
                        case 0x71:
                            last_cmd_name = "k.";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = ".";
                            break;
                        case 0x72:
                            last_cmd_name = "k2";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "2";
                            break;
                        case 0x73:
                            last_cmd_name = "k5";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "5";
                            break;
                        case 0x74:
                            last_cmd_name = "k6";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "6";
                            break;
                        case 0x75:
                            last_cmd_name = "k8";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "8";
                            break;
                        case 0x76:
                            last_cmd_name = "Esc";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x77:
                            last_cmd_name = "kVerrNum";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x78:
                            last_cmd_name = "F11";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x79:
                            last_cmd_name = "k+";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "+";
                            break;
                        case 0x7A:
                            last_cmd_name = "k3";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "3";
                            break;
                        case 0x7B:
                            last_cmd_name = "k-";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "-";
                            break;
                        case 0x7C:
                            last_cmd_name = "k*";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "*";
                            break;
                        case 0x7D:
                            last_cmd_name = "k9";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "9";
                            break;
                        default:
                            is_cmd = 2;
                    }
                    break;
                case 0xE0:
                    switch(c) {
                        case 0x11:
                            last_cmd_name = "AltGr";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x14:
                            last_cmd_name = "CtrlR";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x4A:
                            last_cmd_name = "k/";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "/";
                            break;
                        case 0x5A:
                            last_cmd_name = "kEntree";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x69:
                            last_cmd_name = "kFin";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x6B:
                            last_cmd_name = "Fleche Gauche";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x6C:
                            last_cmd_name = "kHome";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x70:
                            last_cmd_name = "Insert";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x71:
                            last_cmd_name = "Suppr";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x72:
                            last_cmd_name = "Fleche Bas";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x74:
                            last_cmd_name = "Fleche Droite";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x75:
                            last_cmd_name = "Fleche Haut";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x7A:
                            last_cmd_name = "kPage Basse";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x7C:
                            last_cmd_name = "Impression ecran";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        case 0x7D:
                            last_cmd_name = "kPage Haute";
                            last_cmd_is_pressed = 1;
                            last_cmd_chr = "";
                            break;
                        default:
                            is_cmd = 3;
                    }
                    break;
                case 0xF0:
                    switch(c) {
                        case 0x01:
                            last_cmd_name = "F9 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x02:
                            last_cmd_name = "F7 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x03:
                            last_cmd_name = "F5 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x04:
                            last_cmd_name = "F3 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x05:
                            last_cmd_name = "F1 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x06:
                            last_cmd_name = "F2 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x07:
                            last_cmd_name = "F12 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x09:
                            last_cmd_name = "F10 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x0A:
                            last_cmd_name = "F8 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x0B:
                            last_cmd_name = "F6 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x0C:
                            last_cmd_name = "F4 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x0D:
                            last_cmd_name = "Tab released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x0E:
                            last_cmd_name = "^{2} released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x11:
                            last_cmd_name = "AltL released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x12:
                            last_cmd_name = "ShiftL released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x14:
                            last_cmd_name = "CtrlL released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x15:
                            last_cmd_name = "A released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x16:
                            last_cmd_name = "1 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1A:
                            last_cmd_name = "W released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1B:
                            last_cmd_name = "S released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1C:
                            last_cmd_name = "Q released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1D:
                            last_cmd_name = "Z released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1E:
                            last_cmd_name = "2 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x1F:
                            last_cmd_name = "Windows released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x21:
                            last_cmd_name = "C released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x22:
                            last_cmd_name = "X released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x23:
                            last_cmd_name = "D released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x24:
                            last_cmd_name = "E released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x25:
                            last_cmd_name = "4 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x26:
                            last_cmd_name = "3 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x29:
                            last_cmd_name = "Espace released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x2A:
                            last_cmd_name = "V released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x2B:
                            last_cmd_name = "F released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x2C:
                            last_cmd_name = "T released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x2D:
                            last_cmd_name = "R released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x2E:
                            last_cmd_name = "5 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x31:
                            last_cmd_name = "N released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x32:
                            last_cmd_name = "B released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x33:
                            last_cmd_name = "H released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x34:
                            last_cmd_name = "G released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x35:
                            last_cmd_name = "Y released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x36:
                            last_cmd_name = "6 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x3A:
                            last_cmd_name = "? released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x3B:
                            last_cmd_name = "J released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x3C:
                            last_cmd_name = "U released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x3D:
                            last_cmd_name = "7 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x3E:
                            last_cmd_name = "8 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x41:
                            last_cmd_name = ". released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x42:
                            last_cmd_name = "K released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x43:
                            last_cmd_name = "I released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x44:
                            last_cmd_name = "O released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x45:
                            last_cmd_name = "0 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x46:
                            last_cmd_name = "9 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x49:
                            last_cmd_name = "/ released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4A:
                            last_cmd_name = "Paragraphe released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4B:
                            last_cmd_name = "L released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4C:
                            last_cmd_name = "M released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4D:
                            last_cmd_name = "P released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4E:
                            last_cmd_name = "\no released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x52:
                            last_cmd_name = "% released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x54:
                            last_cmd_name = "Trema released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x55:
                            last_cmd_name = "+ released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x58:
                            last_cmd_name = "CapsLock released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x59:
                            last_cmd_name = "ShiftR released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x5A:
                            last_cmd_name = "Entree released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x5B:
                            last_cmd_name = "Livre released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x5D:
                            last_cmd_name = "Mu released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x61:
                            last_cmd_name = "<> released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x66:
                            last_cmd_name = "Backspace released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x69:
                            last_cmd_name = "k1 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x6B:
                            last_cmd_name = "k4 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x6C:
                            last_cmd_name = "k7 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x70:
                            last_cmd_name = "k0 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x71:
                            last_cmd_name = "k. released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x72:
                            last_cmd_name = "k2 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x73:
                            last_cmd_name = "k5 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x74:
                            last_cmd_name = "k6 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x75:
                            last_cmd_name = "k8 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x76:
                            last_cmd_name = "Esc released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x77:
                            last_cmd_name = "kVerrNum released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x78:
                            last_cmd_name = "F11 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x79:
                            last_cmd_name = "k+ released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7A:
                            last_cmd_name = "k3 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7B:
                            last_cmd_name = "k- released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7C:
                            last_cmd_name = "k* released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7D:
                            last_cmd_name = "k9 released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        default:
                            is_cmd = 4;
                    }
                    break;
                default:
                    is_cmd = 5;
            }
            break;
        case 0xE0:
            switch(b) {
                case 0x00:
                    switch(c) {
                        default:
                            is_cmd = 6;
                    }
                    break;
                case 0xE0:
                    switch(c) {
                        default:
                            is_cmd = 7;
                    }
                    break;
                case 0xF0:
                    switch(c) {
                        case 0x11:
                            last_cmd_name = "AltGr released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x14:
                            last_cmd_name = "CtrlR released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x4A:
                            last_cmd_name = "k/ released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x5A:
                            last_cmd_name = "kEntree released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x69:
                            last_cmd_name = "kFin released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x6B:
                            last_cmd_name = "Fleche Gauche released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x6C:
                            last_cmd_name = "kHome released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x70:
                            last_cmd_name = "Insert released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x71:
                            last_cmd_name = "Suppr released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x72:
                            last_cmd_name = "Fleche Bas released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x74:
                            last_cmd_name = "Fleche Droite released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x75:
                            last_cmd_name = "Fleche Haut released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7A:
                            last_cmd_name = "kPage Basse released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7C:
                            last_cmd_name = "Impression ecran released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                        case 0x7D:
                            last_cmd_name = "kPage Haute released";
                            last_cmd_is_pressed = 0;
                            last_cmd_chr = "";
                            break;
                    }
                    break;
                default:
                    is_cmd = 8;
            }
            break;
        default:
            is_cmd = 9;
    }







    // printf("%x\n", is_cmd);
	if (is_cmd == 1) {
		ps2_kbd_kmp_pos_last_cmd = ps2_kbd_kmp_pos;
		printf("Key: %s\n", last_cmd_name);
		// printf("%s", last_cmd_chr);
		// printf("Is pressed: %x\n", last_cmd_is_pressed);
	}

	// printf("%x\n", s);
	// // char a = rslt[ps2_kbd_kmp_pos];
	// // char b = rslt[(ps2_kbd_kmp_pos - 1) % PS2_KBD_KMP_HISTORY_SIZE];
	// // char c = rslt[(ps2_kbd_kmp_pos - 2) % PS2_KBD_KMP_HISTORY_SIZE];

	// // printf("%x\n", a);s
	// // printf("%x\n", b);
	// // printf("%x\n", c);
	// // printf("%x\n", PS2_KBD_KMP_HISTORY_SIZE);
	// for (int i = 0; i < PS2_KBD_KMP_HISTORY_SIZE; ++i)
	// {
	// 	printf("%x: %x ", i, history[i]);
	// }
	// printf("%x\n", ps2_kbd_kmp_pos);
};