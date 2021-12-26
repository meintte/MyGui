#pragma once

#include <GLFW/glfw3.h>

#include "mygui/Core/Window.hpp"
#include "mygui/Events/ApplicationEvent.hpp"
#include "mygui/Events/KeyEvent.hpp"
#include "mygui/Events/MouseEvent.hpp"
// #include "mygui/Platform/OpenGLContext.hpp"

namespace mygui {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProperties& properties);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline uint32_t GetWidth() const override;
        inline uint32_t GetHeight() const override;

        void SetEventCallback(const EventCallbackFunction& callback) override;
        void SetVSync(bool enabled) override;
        inline bool IsVSync() const override;

        virtual void* GetNativeWindow() const;

    private:
        virtual void Init(const WindowProperties& properties);
        virtual void Shutdown();

        GLFWwindow* m_Window;
        // Scope<GraphicsContext> m_Context;

        struct WindowData {
            std::string Title;
            uint32_t Width, Height;
            bool VSync;

            EventCallbackFunction EventCallback;
        };

        WindowData m_Data;
    };

}  // namespace mygui
