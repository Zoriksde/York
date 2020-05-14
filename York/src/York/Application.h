#pragma once

#include "Core.h"

#include "Window.h"
#include "York/LayerStack.h"
#include "York/Events/Event.h"
#include "York/Events/ApplicationEvent.h"

namespace York {

	class YORK_API Application {
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		void OnEvent(Event& event);	
		void Run();

		static inline Application& GetInstance() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }

	private:
		bool OnWindowClosed(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}


