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

