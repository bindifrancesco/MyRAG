#include "HexPrinter.h"

std::string HexPrinter::toHex(const std::vector<std::uint8_t>& data, size_t maxBytes)
{
    const size_t show = std::min(data.size(), maxBytes);

    std::ostringstream oss;
    oss << std::hex << std::setfill('0');

    for (size_t i = 0; i < show; ++i) {
        oss << ' ' << std::setw(2)
            << static_cast<int>(data[i]);
    }

    return oss.str();
}