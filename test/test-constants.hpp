#ifndef TEST_CONSTANTS_HPP
#define TEST_CONSTANTS_HPP

#include <string>
#include <vector>

// clang-format off
static const std::vector<uint8_t> invalid_record_bytes{ 0xd3, 0x4d, 0xb3, 0x3f };
static const std::vector<uint8_t> valid_text_record_bytes_sr{
  // Record Header
  // - Message Begin (1b), Message End (1b), Last chunk (0b), Short Record (1b)
  // - ID Length not present (0b), NFC Forum Well Known Type TNF (0b001)
  0xd1,

  // Type length
  // - Payload type field is 1 octet long (single "T" char)
  // - No ID Length
  0x01,

  // Payload length
  // - 19 octet (character) long payload
  // - SR flag set
  0x13,

  // Well Known Type - Text (ASCII "T")
  0x54,

  // Text encoding information
  // - UTF-8 (1b), RFU (always 0b), IANA language code "en-US" length = 5 (0b00101)
  0x85,

  // ISO/IANA language code "en-US" encoded in US-ASCII
  0x65, 0x6e, 0x2d, 0x55, 0x53,

  // UTF-8 encoded text payload ("Hello, World")
  0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
};
static const std::vector<uint8_t> valid_text_record_bytes_sr_id{
  // Record Header
  // - Message Begin (1b), Message End (1b), Last chunk (0b), Short Record (1b)
  // - ID Length present (1b), NFC Forum Well Known Type TNF (0b001)
  0xd9,

  // Type length
  // - Payload type field is 1 octet long (single "T" char)
  0x01,

  // Payload length
  // - 19 octet (character) long payload
  // - SR flag set
  0x13,

  // ID length field
  0x04,

  // Well Known Type - Text (ASCII "T")
  0x54,

  // ID Field - "test"
  0x74, 0x65, 0x73, 0x74,

  // Text encoding information
  // - UTF-8 (1b), RFU (always 0b), IANA language code "en-US" length = 5 (0b00101)
  0x85,

  // ISO/IANA language code "en-US" encoded in US-ASCII
  0x65, 0x6e, 0x2d, 0x55, 0x53,

  // UTF-8 encoded text payload ("Hello, World")
  0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
};
static const std::vector<uint8_t> valid_text_record_bytes_nosr{
  // Record Header
  // - Message Begin (1b), Message End (1b), Last chunk (0b), Short Record (0b)
  // - ID Length not present (0b), NFC Forum Well Known Type TNF (0b001)
  0xc1,

  // Type length
  // - Payload type field is 1 octet long (single "T" char)
  // - No ID Length
  0x01,

  // Payload length
  // - 257 octet (character) long payload
  0x00,
  0x00,
  0x01,
  0x07,

  // Well Known Type - Text (ASCII "T")
  0x54,

  // Text encoding information
  // - UTF-8 (1b), RFU (always 0b), IANA language code "en-US" length = 5 (0b00101)
  0x85,

  // ISO/IANA language code "en-US" encoded in US-ASCII
  0x65, 0x6e, 0x2d, 0x55, 0x53,

  // UTF-8 encoded text payload 257 random ASCII/UTF-8 characters
  0x64, 0x78, 0x6c, 0x66, 0x6e, 0x65, 0x72, 0x65, 0x78, 0x7a, 0x76, 0x79, 0x73, 0x69, 0x67, 0x77, 0x75, 0x67, 0x66,
  0x73, 0x64, 0x74, 0x71, 0x69, 0x6d, 0x6d, 0x6e, 0x7a, 0x6b, 0x74, 0x72, 0x68, 0x65, 0x6c, 0x62, 0x6f, 0x6a, 0x69,
  0x70, 0x6a, 0x71, 0x73, 0x64, 0x61, 0x6b, 0x76, 0x77, 0x7a, 0x74, 0x64, 0x68, 0x6e, 0x6d, 0x76, 0x71, 0x6c, 0x65,
  0x79, 0x69, 0x79, 0x6c, 0x73, 0x66, 0x63, 0x70, 0x73, 0x64, 0x74, 0x6b, 0x64, 0x71, 0x61, 0x63, 0x65, 0x6e, 0x7a,
  0x6a, 0x68, 0x71, 0x65, 0x71, 0x72, 0x75, 0x6e, 0x72, 0x6c, 0x77, 0x6e, 0x76, 0x64, 0x73, 0x61, 0x70, 0x62, 0x6f,
  0x73, 0x69, 0x6a, 0x77, 0x75, 0x6e, 0x62, 0x70, 0x75, 0x78, 0x67, 0x65, 0x69, 0x69, 0x73, 0x61, 0x63, 0x74, 0x65,
  0x73, 0x6b, 0x63, 0x76, 0x78, 0x63, 0x6c, 0x72, 0x63, 0x62, 0x6f, 0x73, 0x6e, 0x63, 0x73, 0x6e, 0x7a, 0x61, 0x69,
  0x71, 0x6b, 0x65, 0x75, 0x6e, 0x68, 0x6b, 0x6c, 0x79, 0x6d, 0x63, 0x79, 0x70, 0x78, 0x6e, 0x75, 0x63, 0x61, 0x63,
  0x75, 0x6d, 0x73, 0x68, 0x70, 0x79, 0x61, 0x70, 0x62, 0x62, 0x65, 0x74, 0x6c, 0x65, 0x68, 0x7a, 0x76, 0x63, 0x62,
  0x68, 0x66, 0x75, 0x70, 0x72, 0x65, 0x6c, 0x70, 0x69, 0x74, 0x6a, 0x63, 0x6c, 0x78, 0x67, 0x76, 0x61, 0x67, 0x73,
  0x6b, 0x61, 0x6f, 0x63, 0x78, 0x70, 0x67, 0x69, 0x72, 0x72, 0x75, 0x72, 0x71, 0x73, 0x68, 0x69, 0x6a, 0x6f, 0x69,
  0x76, 0x6e, 0x69, 0x68, 0x67, 0x61, 0x75, 0x67, 0x72, 0x6c, 0x69, 0x69, 0x77, 0x64, 0x7a, 0x75, 0x73, 0x61, 0x6e,
  0x63, 0x74, 0x71, 0x70, 0x75, 0x68, 0x77, 0x6b, 0x6b, 0x64, 0x6a, 0x79, 0x61, 0x64, 0x6e, 0x69, 0x66, 0x64, 0x6a,
  0x68, 0x6c, 0x64, 0x68, 0x61, 0x67, 0x64, 0x61, 0x6c, 0x6d
};
static const std::vector<uint8_t> valid_https_prefix_uri_payload{
  // Prefix is https://
  0x02,
  // Contents are google.com, encoded in UTF-8
  0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d,
};
static const std::vector<uint8_t> valid_utf8_text_payload{
  // Text encoding information
  // - UTF-8 (1b), RFU (always 0b), IANA language code "en-US" length = 5 (0b00101)
  0x85,

  // ISO/IANA language code "en-US" encoded in US-ASCII
  0x65, 0x6e, 0x2d, 0x55, 0x53,

  // UTF-8 encoded text payload ("Hello, World")
  0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
};

// clang-format on

const std::string rand_string_257 =
    "dxlfnerexzvysigwugfsdtqimmnzktrhelbojipjqsdakvwztdhnmvqleyiylsfcpsdtkdqacenzjhqeqrunrlwnvdsa"
    "pbosijwunbpuxgeiisacteskcvxclrcbosncsnzaiqkeunhklymcypxnucacumshpyapbbetlehzvcbhfuprelpitjcl"
    "xgvagskaocxpgirrurqshijoivnihgaugrliiwdzusanctqpuhwkkdjyadnifdjhldhagdalm";

#endif // TEST_CONSTANTS_HPP