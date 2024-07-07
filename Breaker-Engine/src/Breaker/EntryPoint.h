#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Breaker::Application* Breaker::CreateApplication();

int main(int argc, char** argv) {
	Breaker::Log::Init();
	Breaker::Log::GetCoreLogger()->warn("Initialized Log!");
	Breaker::Log::GetClientLogger()->info("Hello");

	auto app = Breaker::CreateApplication();
	app->Run();
	delete app;
}

#endif
