#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Breaker::Application* Breaker::CreateApplication();

int main(int argc, char** argv) {
	auto app = Breaker::CreateApplication();
	app->Run();
	delete app;
}

#endif
