#pragma once

#include "Core.h"
#include "Std.h"
namespace Breaker {
	void Print() {

	}
	

	class BREAKER_API Application {
	public:
		Application() { }
		virtual ~Application() { }
		void Run() {
			while (true);
		}

	};

	//To be defined in client
	Application* CreateApplication();
}

