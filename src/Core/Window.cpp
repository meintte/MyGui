#include "mygui/Core/Window.hpp"

#ifdef PLATFORM_WINDOWS
#    include "mygui/Platform/Windows/WindowsWindow.hpp"
#    define FOUND_VALID_PLATFORM
#endif
namespace mygui {
    Scope<Window> Window::Create(const WindowProperties& properties) {
#ifdef PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(properties);
#endif

#ifndef FOUND_VALID_PLATFORM
        // ERROR / ASSERT
        return nullptr;
#else
#    undef FOUND_VALID_PLATFORM
#endif
    }

}  // namespace mygui
