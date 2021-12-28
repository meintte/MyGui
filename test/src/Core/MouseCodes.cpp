#include <doctest/doctest.h>

#include <mygui/Core/MouseCodes.hpp>
#include <string>

TEST_CASE("MouseCodes") {
    CHECK(mygui::Mouse::Button0 == 0);
    CHECK(mygui::Mouse::Button1 == 1);
    CHECK(mygui::Mouse::Button2 == 2);
    CHECK(mygui::Mouse::Button3 == 3);
    CHECK(mygui::Mouse::Button4 == 4);
    CHECK(mygui::Mouse::Button5 == 5);
    CHECK(mygui::Mouse::Button6 == 6);
    CHECK(mygui::Mouse::Button7 == 7);
    CHECK(mygui::Mouse::ButtonLast == mygui::Mouse::Button7);
    CHECK(mygui::Mouse::ButtonLeft == mygui::Mouse::Button0);
    CHECK(mygui::Mouse::ButtonRight == mygui::Mouse::Button1);
    CHECK(mygui::Mouse::ButtonMiddle == mygui::Mouse::Button2);
}