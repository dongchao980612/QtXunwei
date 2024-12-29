cmake_minimum_required(VERSION 3.16)

project(01_first_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_first_demo main.cpp)

include(GNUInstallDirs)
install(TARGETS 01_first_demo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
