#include "EventEmitter.hpp"

template <typename T>
void EventEmitter<T>::Listen(Listener func) {
	m_event_listeners.push_back(func);
}

template <typename T>
void EventEmitter<T>::Emit(T val) {
	for (const auto& f : m_event_listeners) {
		f(val);
	}
}