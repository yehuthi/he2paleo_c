#include <gtest/gtest.h>
#include <stdint.h>
#include "he2paleo.h"

#define LETTER(NAME, HEBR, PHNX) \
	TEST(letter, NAME) { \
		const uint32_t actual = he2paleo_scalar(HEBR); \
		EXPECT_EQ(PHNX, actual) << std::hex << " expected: " \
			"f(0x" << HEBR << ") = 0x" << PHNX << " but got 0x" << actual; }
#include "alphabet.inc.h"
#undef LETTER

TEST(letter, latin_a) { EXPECT_EQ('a', he2paleo_scalar('a')); }