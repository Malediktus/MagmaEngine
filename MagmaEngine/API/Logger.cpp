#include "pch.h"
#include "API/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Magma
{
    std::shared_ptr<spdlog::logger> Logger::m_EngineLogger;
    std::shared_ptr<spdlog::logger> Logger::m_ApplicationLogger;

    void Logger::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Magma.log", true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        m_EngineLogger = std::make_shared<spdlog::logger>("MAGMA", begin(logSinks), end(logSinks));
        spdlog::register_logger(m_EngineLogger);

        m_ApplicationLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
        spdlog::register_logger(m_ApplicationLogger);

#ifdef MG_DEBUG
        m_EngineLogger->set_level(spdlog::level::trace);
        m_EngineLogger->flush_on(spdlog::level::trace);
        m_ApplicationLogger->set_level(spdlog::level::trace);
        m_ApplicationLogger->flush_on(spdlog::level::trace);
#else
        m_EngineLogger->set_level(spdlog::level::info);
        m_EngineLogger->flush_on(spdlog::level::info);
        m_ApplicationLogger->set_level(spdlog::level::info);
        m_ApplicationLogger->flush_on(spdlog::level::info);
#endif
    }

    void Logger::Shutdown()
    {
    }

    std::shared_ptr<spdlog::logger> Logger::GetEngineLogger()
    {
        return m_EngineLogger;
    }

    std::shared_ptr<spdlog::logger> Logger::GetApplicationLogger()
    {
        return m_ApplicationLogger;
    }
}