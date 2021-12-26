#pragma once

#include <string>

#include "mygui/Events/Event.hpp"

namespace mygui {
    class Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate(float dt);
        virtual void OnImGuiRender();
        virtual void OnEvent(Event& event);

        inline const std::string& GetName() const;

    protected:
        std::string m_DebugName;
    };
}  // namespace mygui
