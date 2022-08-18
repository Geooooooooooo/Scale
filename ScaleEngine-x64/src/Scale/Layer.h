#pragma once

#include "../../src/sl_pch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Scale {

	class SCALE_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event&) {}


		inline const std::string getName() const { return m_Name; }

	private:
		std::string m_Name;
	};

	using Layer_ptr = Layer*;
}