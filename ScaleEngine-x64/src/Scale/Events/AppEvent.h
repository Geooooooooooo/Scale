#pragma once

#include "Event.h"

namespace Scale {

	class SCALE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EC_Application);
	private:
		unsigned int m_Width, m_Height;
	};

	class SCALE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EC_Application);
	};

	class SCALE_API AppTickEvent : public Event {
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EC_Application);
	};

	class SCALE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EC_Application);
	};

	class SCALE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EC_Application);
	};
}