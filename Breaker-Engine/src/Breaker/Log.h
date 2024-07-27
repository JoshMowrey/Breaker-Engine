 #pragma once
#include "brpch.h"
#include "Core.h"
#include "Events/Event.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

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

// Core Log Macros
#define LOG_TO_STRING(...) (((std::stringstream)(std::stringstream() << __VA_ARGS__)).str())

#define BR_CORE_FATAL(...)	::Breaker::Log::GetCoreLogger()->fatal(LOG_TO_STRING(__VA_ARGS__))
#define BR_CORE_ERROR(...)	::Breaker::Log::GetCoreLogger()->error(LOG_TO_STRING(__VA_ARGS__))
#define BR_CORE_WARN(...)	::Breaker::Log::GetCoreLogger()->warn(LOG_TO_STRING(__VA_ARGS__))
#define BR_CORE_INFO(...)	::Breaker::Log::GetCoreLogger()->info(LOG_TO_STRING(__VA_ARGS__))
#define BR_CORE_TRACE(...)	::Breaker::Log::GetCoreLogger()->trace(LOG_TO_STRING(__VA_ARGS__))

//Client Log Macros

#define BR_FATAL(...)		::Breaker::Log::GetClientLogger()->fatal(LOG_TO_STRING(__VA_ARGS__))
#define BR_ERROR(...)		::Breaker::Log::GetClientLogger()->error(LOG_TO_STRING(__VA_ARGS__))
#define BR_WARN(...)		::Breaker::Log::GetClientLogger()->warn(LOG_TO_STRING(__VA_ARGS__))
#define BR_INFO(...)		::Breaker::Log::GetClientLogger()->info(LOG_TO_STRING(__VA_ARGS__))
#define BR_TRACE(...)		::Breaker::Log::GetClientLogger()->trace(LOG_TO_STRING(__VA_ARGS__))


