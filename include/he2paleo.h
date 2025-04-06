/**
 * @file he2paleo.h
 * @brief Unicode Hebrew to Phoenician conversion functions.
 */

#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

/// @brief Converts a Hebrew codepoint to a Phoenician codepoint.
/// @warning The input must be a valid Hebrew codepoint in the range `0x05D0` to `0x05EA`.
/// @param input The Hebrew codepoint to convert.
/// @return The converted Phoenician codepoint.
/// @see he2paleo_scalar()
uint32_t he2paleo_scalar_unchecked(uint32_t input);

/// @brief Converts a Hebrew codepoint to a Phoenician codepoint.
/// @param input The Hebrew codepoint to convert.
/// @return The converted Phoenician codepoint, or the input if it is not a valid Hebrew codepoint.
/// @see he2paleo_scalar_unchecked()
uint32_t he2paleo_scalar(uint32_t input);

#ifdef __cplusplus
}
#endif