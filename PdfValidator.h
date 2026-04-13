#pragma once

#include <vector>
#include <string>
#include <expected>
#include <cstdint>

class PdfValidator {
public:
    static std::expected<void, std::string>
        validate(const std::vector<std::uint8_t>& data);
};