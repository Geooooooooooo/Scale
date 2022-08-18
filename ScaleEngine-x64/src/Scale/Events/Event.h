#pragma once

#include "../Core.h"

namespace Scale {

	// Events in Hazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	//Enum class: типы событий 
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//Enum: категории событий: события приложения, ввода, клавиатуры,  и т.д.
	enum EventCategory {
		None = 0,
		EC_Application		= BIT(0),
		EC_Input			= BIT(1),
		EC_Keyboard			= BIT(2),
		EC_Mouse			= BIT(3),
		EC_MouseButton		= BIT(4)
	};

// Директива обьявляющая функции класса Event
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//Класс событий
	class SCALE_API Event {
		//Базовый класс событий
		friend class EventDispatcher;
	public:

		bool m_Handled = false;

		//Функция возвращающая последнее событие
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string toString() const { return GetName(); }

		bool isInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

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