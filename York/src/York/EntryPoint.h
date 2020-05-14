#pragma once

#ifdef YK_PLATFORM_WINDOWS

extern York::Application* York::CreateApplication();

int main(int argc, char** argv) {
	
	York::Log::Init();

	auto app = York::CreateApplication();
	app->Run();
	delete app;
}

#endif