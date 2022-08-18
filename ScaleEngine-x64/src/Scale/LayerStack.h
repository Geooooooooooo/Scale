#pragma once

#include "../../src/sl_pch.h"

#include "Core.h"
#include "Layer.h"

namespace Scale {
	
	class SCALE_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer_ptr);
		void pushOverlay(Layer_ptr);
		void popLayer(Layer_ptr);
		void popOverlay(Layer_ptr);

		std::vector<Layer_ptr>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer_ptr>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer_ptr>m_Layers;
		std::vector < Layer_ptr>::iterator m_LayersIterator;
	};

}
