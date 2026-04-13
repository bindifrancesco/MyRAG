#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdint>

class HexPrinter {
public:
    static std::string toHex(const std::vector<std::uint8_t>& data, size_t maxBytes);
};