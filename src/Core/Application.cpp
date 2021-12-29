#include "mygui/Core/Application.hpp"

namespace mygui {

    Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& name) {
        s_Instance = this;
        m_Window = Window::Create(WindowProperties(name));
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        // Render::Init();
        // m_ImGuiLayer = new ImGuiLayer();
        // PushOverlay(m_ImGuiLayer);
    }

    Application::~Application() {}

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
            double time = glfwGetTime();
            m_LastFrameTime = time;
        }
    }

    void Application::Close() { m_Running = false; }

    inline Window& Application::GetWindow() { return *m_Window; }

    inline Application& Application::Get() { return *s_Instance; }

    void Application::PushLayer(Layer* layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer) {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
            //     if (e.Handled) {
            //         break;
            //     }
            (*it)->OnEvent(e);
        }
    }

    bool Application::OnWindowClose([[maybe_unused]] WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e) {
        uint32_t width, height;

        width = e.GetWidth();
        height = e.GetHeight();

        if (width == 0 || height == 0) {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        // Renderer::OnWindowResize(width, height);

        return false;
    }

}  // namespace mygui
