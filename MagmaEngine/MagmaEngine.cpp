#include "pch.h"

#include "API/Logger.h"
#include "API/Application.h"

int main()
{
	Magma::Application* app = Magma::Initialize();
	app->Run();
	return 0;
}
