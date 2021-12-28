#include <doctest/doctest.h>

#include <mygui/Core/Window.hpp>
#include <string>

TEST_CASE("Window") {
    mygui::WindowProperties default_prop{};
    mygui::WindowProperties named_prop{"Test", 10, 100};

    CHECK(default_prop.Title == "Flui2d");
    CHECK(default_prop.Width == 1600);
    CHECK(default_prop.Height == 900);

    CHECK(named_prop.Title == "Test");
    CHECK(named_prop.Width == 10);
    CHECK(named_prop.Height == 100);
}