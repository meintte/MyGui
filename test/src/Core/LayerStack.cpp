#include <doctest/doctest.h>

#include <mygui/Core/LayerStack.hpp>
#include <string>

TEST_CASE("LayerStack") {
    mygui::LayerStack stack;
    auto layer_a = new mygui::Layer("a");
    auto layer_b = new mygui::Layer("b");
    auto layer_c = new mygui::Layer("c");
    auto layer_d = new mygui::Layer("d");

    stack.PushOverlay(layer_a);
    stack.PushLayer(layer_b);
    stack.PushOverlay(layer_d);
    stack.PushLayer(layer_c);

    std::string order_1[] = {"b", "c", "a", "d"};

    // normal iterator
    int i = 0;
    for (auto it = stack.begin(); it != stack.end(); it++) {
        CHECK(order_1[i++] == (*it)->GetName());
    }
    i = 0;
    for (std::vector<mygui::Layer*>::const_iterator it = stack.begin(); it != stack.end(); it++) {
        CHECK(order_1[i++] == (*it)->GetName());
    }
    i = 0;
    for (const auto it : stack) {
        CHECK(order_1[i++] == it->GetName());
    }

    // reverse iterator
    i = 3;
    for (auto it = stack.rbegin(); it != stack.rend(); it++) {
        CHECK(order_1[i--] == (*it)->GetName());
    }
    i = 3;
    for (std::vector<mygui::Layer*>::const_reverse_iterator it = stack.rbegin(); it != stack.rend();
         it++) {
        CHECK(order_1[i--] == (*it)->GetName());
    }

    // remove a layer
    stack.PopLayer(layer_b);
    i = 1;
    for (auto it : stack) {
        CHECK(order_1[i++] == it->GetName());
    }

    // should change nothingas:
    // c is a normal layer
    // a is an overlay
    stack.PopOverlay(layer_c);
    stack.PopLayer(layer_a);
    i = 1;
    for (auto it : stack) {
        CHECK(order_1[i++] == it->GetName());
    }

    // remove an overlay
    stack.PopOverlay(layer_a);
    i = 1;
    for (auto it : stack) {
        if (i == 2) {
            ++i;
        }
        CHECK(order_1[i++] == it->GetName());
    }
}