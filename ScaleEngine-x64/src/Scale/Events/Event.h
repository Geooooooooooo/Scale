#pragma once

#include "../Core.h"

#include <string>
#include <functional>
#include <sstream>

namespace Scale {

	// Events in Hazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	//Enum class: ���� ������� 
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//Enum: ��������� �������: ������� ����������, �����, ����������,  � �.�.
	enum EventCategory {
		None = 0,
		EC_Application		= BIT(0),
		EC_Input			= BIT(1),
		EC_Keyboard			= BIT(2),
		EC_Mouse			= BIT(3),
		EC_MouseButton		= BIT(4)
	};

// ��������� ����������� ������� ������ Event
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//����� �������
	class SCALE_API Event {
		//������� ����� �������
		friend class EventDispatcher;
	public:
		//������� ������������ ��������� �������
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string toString() const { return GetName(); }

		bool isInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		//����������, ���� �� ������� ���������� ��� ���
		bool m_Handled = false;
	};

	class EventDispatcher {
		template<typename _Ty> using EventFn = std::function<bool(_Ty&)>;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename _Ty> bool Dispatch(EventFn<_Ty> func) {
			if (m_Event.GetEventType() == _Ty::GetStaticType()) {
				m_Event.m_Handled = func(*(_Ty*)&m_Event);
				return true;
			} return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.toString(); }

}