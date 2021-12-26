#pragma once

#include "mygui/Core/KeyCodes.hpp"
#include "mygui/Core/MouseCodes.hpp"

namespace mygui {

    class Input {
    public:
        static bool IsKeyPressed(KeyCode key);

        static bool IsMouseButtonPressed(MouseCode button);
        // static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}  // namespace mygui