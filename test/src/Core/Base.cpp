#include <doctest/doctest.h>

#include <mygui/Core/Base.hpp>
#include <string>

TEST_CASE("Base") {
    auto a = mygui::CreateScope<std::string>("test");
    CHECK((*a) == "test");
}