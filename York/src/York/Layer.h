#pragma once
#include "York/Core.h"
#include "York/Events/Event.h"

namespace York {

	class YORK_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetLayerName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}