#pragma once

#include "Core.h"
#include "brpch.h"
#include "Events/Event.h"
#include "Events/ApplicationEvents.h"
#include "Log.h"
namespace Breaker {
	void Print() {

	}
	

	class BREAKER_API Application {
	public:
		Application(){ }
		virtual ~Application() { }
		void Run() {
			WindowResizeEvent e(1280, 720);
			BR_TRACE(e);
			while (true);
		}

	};

	//To be defined in client
	Application* CreateApplication();
}

