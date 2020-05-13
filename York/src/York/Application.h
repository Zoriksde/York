#pragma once
#include "Core.h"

namespace York {

	class YK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


