cmake_minimum_required(VERSION 3.10)

project(CMakeRAG)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CMakeRAG
    main.cpp
    PdfLoader.cpp
    PdfValidator.cpp
    HexPrinter.cpp
)