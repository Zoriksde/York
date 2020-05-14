#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace York {
	
	class YORK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define YK_CORE_TRACE(...)	::York::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YK_CORE_INFO(...)	::York::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YK_CORE_WARN(...)	::York::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YK_CORE_ERROR(...)	::York::Log::GetCoreLogger()->error(__VA_ARGS__)

#define YK_TRACE(...)	::York::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YK_INFO(...)	::York::Log::GetClientLogger()->info(__VA_ARGS__)
#define YK_WARN(...)	::York::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YK_ERROR(...)	::York::Log::GetClientLogger()->error(__VA_ARGS__)



