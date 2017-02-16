#pragma once
#include "Entity.h"
#include "SelectionArea.h"
#include "Input.h"
#include <memory>

namespace GameEngine
{
	class SelectionManager : public Entity
	{
	public:
		SelectionManager();
		SelectionManager(SelectionArea* area);
		~SelectionManager();

		virtual void Update() override;
		
	protected:
		std::shared_ptr<SelectionArea> selection_area;

	private:
		std::array<int, 3> ids;
		void OnMouseDown(MouseClickArgs*, int);
		void OnMouseMove(MouseMoveArgs*, int);
		void OnMouseUp(MouseClickArgs*, int);
	};

}
