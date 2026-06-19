cmake_minimum_required(VERSION 3.16)
project(snake VERSION 1.0.0 LANGUAGES CXX)

find_package(raylib REQUIRED)

add_executable(snake src/main.cpp)
target_link_libraries(snake PRIVATE raylib)

install(TARGETS snake
        RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_NAME "snake")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "seixasben@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ Snake")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "c++snake")

set(CPACK_GENERATOR "DEB;RPM")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <you@example.com>")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "Applications/System")

include(CPack)
