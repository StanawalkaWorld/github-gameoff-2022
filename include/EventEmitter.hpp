#pragma once
#include <vector>
#include <functional>

template<typename T>
class EventEmitter {
private:
	using Listener = std::function<void(T)>;
	std::vector<Listener> m_event_listeners;

public:
	void Listen(Listener func);
	void Emit(T val);
};


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

