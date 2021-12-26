#pragma once

#include <sstream>
#include <string>

#include "mygui/Events/Event.hpp"

namespace mygui {
    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(uint32_t width, uint32_t height) : m_Width(width), m_Height(height) {}

        inline uint32_t GetWidth() const { return m_Width; }
        inline uint32_t GetHeight() const { return m_Height; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        uint32_t m_Width, m_Height;
    };

    class WindowCloseEvent : public Event {
    public:
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ApplicationTickEvent : public Event {
    public:
        EVENT_CLASS_TYPE(ApplicationTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ApplicationUpdateEvent : public Event {
    public:
        EVENT_CLASS_TYPE(ApplicationUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ApplicationRenderEvent : public Event {
    public:
        EVENT_CLASS_TYPE(ApplicationRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}  // namespace mygui