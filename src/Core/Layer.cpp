#include "mygui/Core/Layer.hpp"

namespace mygui {

    Layer::Layer(const std::string& debugName) : m_DebugName(debugName) {}

    Layer::~Layer() {}

    void Layer::OnAttach() {}
    void Layer::OnDetach() {}
    void Layer::OnUpdate([[maybe_unused]] float dt) {}
    void Layer::OnImGuiRender() {}
    void Layer::OnEvent([[maybe_unused]] Event& event) {}

    inline const std::string& Layer::GetName() const { return m_DebugName; }
}  // namespace mygui