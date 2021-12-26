#include <doctest/doctest.h>

#include <mygui/version.hpp>
#include <string>

TEST_CASE("Mygui version") {
    static_assert(std::string_view(MYGUI_VERSION) == std::string_view("1.0"));
    CHECK(std::string(MYGUI_VERSION) == std::string("1.0"));
}
