#include <vector>
#include <functional>
#include <stdio.h>

namespace GameEngine {
	template<typename... P>
	class EventSource {
	public:
		using callbackType = std::function<void(P...)>;

		bool addListener(const callbackType& handler) {
			listeners.push_back(handler);
			return true;
		}

		bool delListener(const callbackType& handler) {
			return false;
		}

		void call(P&& ... params) {
			for each (callbackType handler in listeners)
			{
				handler(std::forward<P>(params)...);
			}
		}

		//EventSource& operator+=(const callbackType& handler) { //TODO: test if this works
		//	this->addListener(handler);
		//}
		//EventSource& operator-=(const callbackType& handler) {
		//	this->delListener(handler);
		//}
	protected:
		std::vector<callbackType> listeners;
	};
}