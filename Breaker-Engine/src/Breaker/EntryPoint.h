#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Breaker::Application* Breaker::CreateApplication();

//BR_CLIENT_INFO("How To Print Var {0}", a);

int main(int argc, char** argv) {
	Breaker::Log::Init();
	BR_CORE_WARN("Initialized Log!");
	int a = 5;
	BR_INFO("How To Print Var: " << a);

	auto app = Breaker::CreateApplication();
	app->Run();
	delete app;
}

#endif
