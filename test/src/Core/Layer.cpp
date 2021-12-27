#include <doctest/doctest.h>

#include <mygui/Core/Layer.hpp>
#include <mygui/Events/ApplicationEvent.hpp>
#include <string>

TEST_CASE("Layer") {
    float dt = 0.1;
    mygui::ApplicationTickEvent e;

    mygui::Layer default_constructor{};
    mygui::Layer named_constructor("Name test");

    default_constructor.OnAttach();
    default_constructor.OnDetach();
    default_constructor.OnUpdate(dt);
    default_constructor.OnImGuiRender();
    default_constructor.OnEvent(e);

    CHECK(default_constructor.GetName() == "Layer");
    CHECK(named_constructor.GetName() == "Name test");
}