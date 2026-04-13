#include "PdfValidator.h"
#include <algorithm>

std::expected<void, std::string>
PdfValidator::validate(const std::vector<std::uint8_t>& data)
{
    const char magic[5] = { '%', 'P', 'D', 'F', '-' };

    if (data.size() < 5 ||
        !std::equal(magic, magic + 5, data.begin())) {
        return std::unexpected("Not a valid PDF");
    }

    return {};
}