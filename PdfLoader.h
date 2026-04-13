#pragma once

#include <vector>
#include <string>
#include <expected>
#include <cstdint>

class PdfLoader {
public:
    static std::expected<std::vector<std::uint8_t>, std::string>
        load(const std::string& filePath);
};