#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Breaker {
	class BREAKER_API Log {
	public:
		static void Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("BREAKER");
			s_CoreLogger->set_level(spdlog::level::trace);

			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

}

