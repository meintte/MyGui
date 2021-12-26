#include "mygui/Core/LayerStack.hpp"

namespace mygui {
    LayerStack::~LayerStack() {
        for (Layer* layer : m_Layers) {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer) {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        ++m_LayerInsertIndex;
    }

    void LayerStack::PushOverlay(Layer* layer) { m_Layers.emplace_back(layer); }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
        if (it != m_Layers.begin() + m_LayerInsertIndex) {
            layer->OnDetach();
            m_Layers.erase(it);
            --m_LayerInsertIndex;
        }
    }

    void LayerStack::PopOverlay(Layer* layer) {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), layer);
        if (it != m_Layers.end()) {
            layer->OnDetach();
            m_Layers.erase(it);
        }
    }

    std::vector<Layer*>::iterator LayerStack::begin() { return m_Layers.begin(); }
    std::vector<Layer*>::iterator LayerStack::end() { return m_Layers.end(); }
    std::vector<Layer*>::reverse_iterator LayerStack::rbegin() { return m_Layers.rbegin(); }
    std::vector<Layer*>::reverse_iterator LayerStack::rend() { return m_Layers.rend(); }

    std::vector<Layer*>::const_iterator LayerStack::begin() const { return m_Layers.begin(); }
    std::vector<Layer*>::const_iterator LayerStack::end() const { return m_Layers.end(); }
    std::vector<Layer*>::const_reverse_iterator LayerStack::rbegin() const {
        return m_Layers.rbegin();
    }
    std::vector<Layer*>::const_reverse_iterator LayerStack::rend() const { return m_Layers.rend(); }

}  // namespace mygui
