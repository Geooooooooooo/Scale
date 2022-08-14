#pragma once

#include "Event.h"

namespace Scale {

	class SCALE_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EC_Keyboard | EC_Input)
	protected:
		KeyEvent(const int keycode) : m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class SCALE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(const int keycode, int CountRepeate) : KeyEvent(keycode), m_CountRepeate(CountRepeate) {}

		bool isRepeat() const { return m_CountRepeate; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_CountRepeate << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_CountRepeate;
	};

	class SCALE_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(const int keycode) : KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class SCALE_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(const int keycode) : KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}