#include <MagmaEngine.h>

class SandboxApp : public Magma::Application
{
public:
	void Start() override
	{
	}

	void Update() override
	{
	}
};

Magma::Application* Magma::Initialize()
{
	// Doesnt need to be deleted
	return new SandboxApp;
}