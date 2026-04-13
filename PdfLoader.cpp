#include "PdfLoader.h"

#include <fstream>

std::expected<std::vector<std::uint8_t>, std::string>
PdfLoader::load(const std::string& filePath)
{
    std::ifstream stream(filePath, std::ios::binary);
    if (!stream) {
        return std::unexpected("Failed to open file: " + filePath);
    }

    stream.seekg(0, std::ios::end);
    std::streamoff size = stream.tellg();
    if (size <= 0) {
        return std::unexpected("Invalid file size");
    }

    stream.seekg(0, std::ios::beg);

    std::vector<std::uint8_t> data(static_cast<size_t>(size));

    stream.read(reinterpret_cast<char*>(data.data()),
        static_cast<std::streamsize>(size));

    if (!stream) {
        return std::unexpected("Failed to read file");
    }

    return data;
}