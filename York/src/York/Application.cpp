#include "ykpch.h"
#include "Application.h"
#include "York/Log.h"

#include <glad/glad.h>

namespace York {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;
	
	Application::Application()
	{
		YK_CORE_ASSERT(!s_Instance, "Application already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event) {

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

		YK_CORE_TRACE("Event {0}", event);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(event);
			if (event.Handled) break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::PopOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
		overlay->OnDetach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running) {
			glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_ImGuiLayer->Begin();	

			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();

			m_ImGuiLayer->End();
			m_Window->OnUpdate();
		}
	}
}
