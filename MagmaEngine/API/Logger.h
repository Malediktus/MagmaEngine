#pragma once

#include <spdlog/spdlog.h>

namespace Magma
{
	class Logger
	{
	public:
		static void Init();
		static void Shutdown();

		static std::shared_ptr<spdlog::logger> GetEngineLogger();
		static std::shared_ptr<spdlog::logger> GetApplicationLogger();

	private:
		static std::shared_ptr<spdlog::logger> m_EngineLogger;
		static std::shared_ptr<spdlog::logger> m_ApplicationLogger;
	};
}

// Core log macros
#define MG_CORE_TRACE(...)    ::Magma::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define MG_CORE_INFO(...)     ::Magma::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define MG_CORE_WARN(...)     ::Magma::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...)    ::Magma::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define MG_CORE_FATAL(...)    ::Magma::Logger::GetEngineLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MG_TRACE(...)	      ::Magma::Logger::GetApplicationLogger()->trace(__VA_ARGS__)
#define MG_INFO(...)	      ::Magma::Logger::GetApplicationLogger()->info(__VA_ARGS__)
#define MG_WARN(...)	      ::Magma::Logger::GetApplicationLogger()->warn(__VA_ARGS__)
#define MG_ERROR(...)	      ::Magma::Logger::GetApplicationLogger()->error(__VA_ARGS__)
#define MG_FATAL(...)	      ::Magma::Logger::GetApplicationLogger()->fatal(__VA_ARGS__)