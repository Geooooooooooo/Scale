#include "LayerStack.h"

namespace Scale {

	LayerStack::LayerStack() {
		m_LayersIterator = m_Layers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer_ptr l : m_Layers) delete l;
	}

	void LayerStack::pushLayer(Layer_ptr layer) {
		m_LayersIterator = m_Layers.emplace(m_LayersIterator, layer);
	}

	void LayerStack::popLayer(Layer_ptr layer) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayersIterator--;
		}
	}

	void LayerStack::pushOverlay(Layer_ptr overlay) {
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::popOverlay(Layer_ptr overlay) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}
	}

}