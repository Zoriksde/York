#pragma once
#include "York/Layer.h"
#include "York/Events/ApplicationEvent.h"
#include "York/Events/MouseEvent.h"
#include "York/Events/KeyEvent.h"

namespace York {
	
	class YORK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.f;
	};
}