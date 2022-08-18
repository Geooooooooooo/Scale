#pragma once

#include "Event.h"

namespace Scale {

	class SCALE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(const double x, const double y) : m_MouseX(x), m_MouseY(y) {}

		double GetX() const { return m_MouseX; }
		double GetY() const { return m_MouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	private:
		double m_MouseX, m_MouseY;
	};

	class SCALE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(const double xOffset, const double yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		double GetXOffset() const { return m_XOffset; }
		double GetYOffset() const { return m_YOffset; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	private:
		double m_XOffset, m_YOffset;
	};

	class SCALE_API MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input | EC_MouseButton)
	protected:
		MouseButtonEvent(const int button) : m_Button(button) {}

		int m_Button;
	};

	class SCALE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SCALE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}