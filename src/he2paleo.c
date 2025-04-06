#include "he2paleo.h"
#include <stdbool.h>

#define HE2PALEO_TABLE_LITERAL {                       \
		0x10900, 0x10901, 0x10902, 0x10903, 0x10904,   \
		0x10905, 0x10906, 0x10907, 0x10908, 0x10909,   \
		0x1090A, 0x1090A, /* kaf */                    \
		0x1090B,                                       \
		0x1090C, 0x1090C, /* mem */                    \
		0x1090D, 0x1090D, /* nun */                    \
		0x1090E, 0x1090F,                              \
		0x10910, 0x10910, /* pe */                     \
		0x10911, 0x10911, /* sadi */                   \
		0x10912, 0x10913, 0x10914, 0x10915             \
	}

uint32_t he2paleo_scalar_unchecked(uint32_t input) {
	static const uint32_t HE2PALEO_TABLE_16[] = HE2PALEO_TABLE_LITERAL;
	return HE2PALEO_TABLE_16[input - 0x05D0];
}

uint32_t he2paleo_scalar(uint32_t input) {
	if (input < 0x05D0 || input > 0x05EA) { return input; }
	return he2paleo_scalar_unchecked(input);
}