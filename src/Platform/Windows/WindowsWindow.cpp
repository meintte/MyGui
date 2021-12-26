#include "mygui/Platform/Windows/WindowsWindow.hpp"

namespace mygui {

    static uint8_t s_GLFWWindowCount = 0;

    static void GLFWErrorCallback([[maybe_unused]] int error,
                                  [[maybe_unused]] const char* description) {}

    WindowsWindow::WindowsWindow(const WindowProperties& properties) { Init(properties); }
    WindowsWindow::~WindowsWindow() { Shutdown(); }

    void WindowsWindow::Init(const WindowProperties& properties) {
        if (s_GLFWWindowCount == 0) {
            glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        // opengl rendering & debug:
        // glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height,
                                    m_Data.Title.c_str(), nullptr, nullptr);
        ++s_GLFWWindowCount;

        // m_Context = GraphicsContext::Create(m_Window);
        // m_Context->Init();

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = (uint32_t)width;
            data.Height = (uint32_t)height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, [[maybe_unused]] int scancode,
                                        int action, [[maybe_unused]] int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event((uint16_t)key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event((uint16_t)key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event((uint16_t)key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event((uint16_t)keycode);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(
            m_Window, [](GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action) {
                    case GLFW_PRESS: {
                        MouseButtonPressedEvent event((uint16_t)button);
                        data.EventCallback(event);
                        break;

                        {
                            MouseButtonReleasedEvent event((uint16_t)button);
                            data.EventCallback(event);
                            break;
                        }
                    }
                }
                WindowCloseEvent event;
                data.EventCallback(event);
            });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });
    }

    void WindowsWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;

        if (s_GLFWWindowCount == 0) {
            glfwTerminate();
        }
    }

    uint32_t WindowsWindow::GetWidth() const { return m_Data.Width; }
    uint32_t WindowsWindow::GetHeight() const { return m_Data.Height; }

    void WindowsWindow::SetEventCallback(const EventCallbackFunction& callback) {
        m_Data.EventCallback = callback;
    }
    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const { return m_Data.VSync; }

    void* WindowsWindow::GetNativeWindow() const { return m_Window; }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        // m_Context->SwapBuffers();
    }

}  // namespace mygui
