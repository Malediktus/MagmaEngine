#pragma once

#include "API/Logger.h"

#ifdef MG_DEBUG
	#define MG_ASSERT(x, ...) { if(!(x)) { Magma::Logger::GetApplicationLogger()->critical("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MG_CORE_ASSERT(x, ...) { if(!(x)) { Magma::Logger::GetEngineLogger()->critical("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MG_ASSERT(x, ...) { if(!(x)) { Magma::Logger::GetApplicationLogger()->critical("Assertion Failed: {0}", __VA_ARGS__); } }
	#define MG_CORE_ASSERT(x, ...) { if(!(x)) { Magma::Logger::GetEngineLogger()->critical("Assertion Failed: {0}", __VA_ARGS__); } }
#endif