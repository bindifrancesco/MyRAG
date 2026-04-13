#include "PdfLoader.h"
#include "PdfValidator.h"
#include "HexPrinter.h"

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    const std::string path = (argc > 1) ? argv[1] : "test.pdf";

    // 📥 LOAD
    auto dataResult = PdfLoader::load(path);
    if (!dataResult) {
        std::cerr << dataResult.error() << '\n';
        return 1;
    }

    const auto& data = dataResult.value();

    // ✅ VALIDATE
    auto validResult = PdfValidator::validate(data);
    if (!validResult) {
        std::cerr << validResult.error() << '\n';
        return 1;
    }

    std::cout << "PDF valid. Size: " << data.size() << " bytes\n";

    // 🔍 DEBUG PRINT
    std::cout << HexPrinter::toHex(data, 32) << '\n';

    return 0;
}