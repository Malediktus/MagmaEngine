#pragma once

namespace Magma
{
	enum class Platform
	{
		WINDOWS,
		MACOS,
		LINUX,
		IOS,
		ANDROID,
	};

	class Context
	{
	public:
		static void Init();
		static Platform GetPlatform();

	private:
		static Platform m_Platform;
	};
}