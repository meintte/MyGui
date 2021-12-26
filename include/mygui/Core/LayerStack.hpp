#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

#include "mygui/Core/Layer.hpp"

namespace mygui {
    class LayerStack {
    public:
        LayerStack() = default;
        LayerStack(const LayerStack&) = default;
        LayerStack(LayerStack&&) = default;
        LayerStack& operator=(const LayerStack&) = default;
        LayerStack& operator=(LayerStack&&) = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin();
        std::vector<Layer*>::iterator end();
        std::vector<Layer*>::reverse_iterator rbegin();
        std::vector<Layer*>::reverse_iterator rend();

        std::vector<Layer*>::const_iterator begin() const;
        std::vector<Layer*>::const_iterator end() const;
        std::vector<Layer*>::const_reverse_iterator rbegin() const;
        std::vector<Layer*>::const_reverse_iterator rend() const;

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}  // namespace mygui
