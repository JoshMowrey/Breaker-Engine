#pragma once
#include "Breaker/Core.h"
#include "brpch.h"


/*
	TO DO: FIX DISPATCH IN BUFFER CLASS TO DISPATCH WHOLE BUFFER (CURRENTLY ONLY DISPATCHES FIRST EVENT)
*/


namespace Breaker {
	
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	enum EventCategory {
		None = 0, 
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
								virtual int GetCategoryFlags() const override { return category; }

	class BREAKER_API Event {
		friend class EventBuffer;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };
		
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
		
	};

	class BREAKER_API EventBuffer {
		#define BuffLen 100
		template<typename T> 
		using EventFn = std::function<bool(T&)>;
	public:
		EventBuffer() { m_Length = 0; };

		~EventBuffer() {
			for (int i = 0; i < BuffLen; i++) {
				delete m_Buffer[i];
			}
		}
		void AddEvent(Event* event) {
			if (m_Length < BuffLen) {
				m_Buffer[m_Length] = event;
				m_Length++;
			}
		}
		void CleanBuffer() {
			int index = 0;
			for (int i = 0; i < m_Length; i++) {
				if (m_Buffer[i]->m_Handled == true) {
					delete m_Buffer[i];
					m_Buffer[i] = nullptr;
				}
				else {
					m_Buffer[index] = m_Buffer[i];
					m_Buffer[i] = nullptr;
					index++;
				}
			}
			m_Length = index;
		}
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Buffer[0]->GetEventType() == T::GetStaticType()) {
				m_Buffer[0]->m_Handled = func(*(T*)m_Buffer[0]);
				return true;
			}
			return false;
		}
	private:
		Event* m_Buffer[BuffLen];
		int m_Length;
	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
