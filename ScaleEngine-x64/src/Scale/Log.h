#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Scale {

	//Êכאסס כמדדונא
	class SCALE_API Log {
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SL_CORE_TRACE(...)    ::Scale::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_INFO(...)     ::Scale::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_WARN(...)     ::Scale::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_ERROR(...)    ::Scale::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_CRITICAL(...) ::Scale::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SL_TRACE(...)         ::Scale::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_INFO(...)          ::Scale::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)          ::Scale::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_ERROR(...)         ::Scale::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_CRITICAL(...)      ::Scale::Log::GetClientLogger()->critical(__VA_ARGS__)

