#pragma once

#include <functional>
#include <string>

#include "mygui/Core/Base.hpp"
#include "mygui/Events/Event.hpp"

namespace mygui {
    struct WindowProperties {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProperties(const std::string& title = "Flui2d", uint32_t width = 1600,
                         uint32_t height = 900)
            : Title(title), Width(width), Height(height) {}
    };

    class Window {
    public:
        using EventCallbackFunction = std::function<void(Event&)>;

        virtual void OnUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProperties& properties = WindowProperties());
    };
}  // namespace mygui