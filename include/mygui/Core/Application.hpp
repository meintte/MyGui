#pragma once

#include <string>

#include "mygui/Core/Base.hpp"
#include "mygui/Core/Input.hpp"
#include "mygui/Core/LayerStack.hpp"
#include "mygui/Core/Window.hpp"
#include "mygui/Events/ApplicationEvent.hpp"

namespace mygui {

    class Application {
    public:
        Application(const std::string& name = "Flui2d");
        virtual ~Application();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow();

        void Close();

        // inline ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

        inline static Application& Get();

        void Run();

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        Scope<Window> m_Window;
        // ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;

        static Application* s_Instance;
    };
}  // namespace mygui