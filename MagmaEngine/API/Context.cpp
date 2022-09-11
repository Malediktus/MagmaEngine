#include "pch.h"
#include "API/Context.h"

namespace Magma
{
	Platform Context::m_Platform;

	void Context::Init()
	{
		m_Platform = Platform::WINDOWS;
	}

	Platform Context::GetPlatform()
	{
		return m_Platform;
	}
}