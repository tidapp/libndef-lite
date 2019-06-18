#ifndef UTF_HPP
#define UTF_HPP

#include <codecvt>
#include <string>
#include <vector>

namespace encoding {
/// \param src std::string source to convert
/// \return std::string encoded in UTF-8
std::string to_utf8(const std::string& src);

/// \param src std::u16string source to convert
/// \return std::string encoded in UTF-8
std::string to_utf8(const std::u16string& src);

/// \param srcstd::u32string source to convert
/// \return std::string encoded in UTF-8
std::string to_utf8(const std::u32string& src);

// \param src std::string source to convert
/// \return std::u16string encoded in UTF-16
std::u16string to_utf16(const std::string& src);

/// \param src std::u16string source to convert
/// \return std::u16string encoded in UTF-16
std::u16string to_utf16(const std::u16string& src);

/// \param src std::u32string source to convert
/// \return std::u16string encoded in UTF-16
std::u16string to_utf16(const std::u32string& src);

/// \param src std::vector<uint8_t> source bytes to convert
/// \return std::u16string encoded in UTF-16
std::u16string to_utf16(const std::vector<uint8_t>& src);

/// \param src std::u16string source to convert
/// \return std::vector<uint8_t> of UTF-16LE bytes
std::vector<uint8_t> to_utf16le(const std::u16string& src);

/// \param src byte vector source to convert
/// \return std::u16string of text
std::u16string from_utf16le_bytes(const std::vector<uint8_t>& src);

/// \param text string to check. Should be a UTF-16 string
/// \return boolean indicating whether this string has the UTF BOM
bool has_BOM(const std::u16string& text);

/// \param bytes vector of bytes to check. Should be containing UTF-16 string
/// \return boolean indicating whether this string has the UTF BOM
bool has_BOM(const std::vector<uint8_t>& bytes);
} // namespace encoding

#endif // UTF_HPP