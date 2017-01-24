#include "UnitController.h"
#include <iostream>


namespace GameEngine
{
	UnitController::UnitController(Camera** mainCameraPointer) : cameraPointer(mainCameraPointer)
	{
		mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}

	UnitController::~UnitController()
	{
		//The unit controller is not the owner of the units, its just a controller thus not
		//deleting the units on destruction of the controler.
	}

	void UnitController::Update()
	{
		if (removeOnUnitDeath) {
			units.erase(
				std::remove_if(units.begin(), units.end(), 
					[](Unit* unit) { return unit != nullptr && unit->getHealth() <= 0; }),
				units.end());
		}
	}

	void UnitController::addUnit(Unit * unit)
	{
	}

	void UnitController::killUnit(Unit * unit)
	{
	}

	Unit * UnitController::getUnit(int index)
	{
		if (vector_inrange(units, index))
			return units.at(index);
		return nullptr;
	}

	int UnitController::getUnitAmount()
	{
		return units.size();
	}

	void UnitController::OnMouseDown(MouseClickArgs *, int)
	{
		Camera* c = *cameraPointer;
		std::cout << c->x() << std::endl;
	}
	void UnitController::OnMouseMove(MouseMoveArgs *, int)
	{
	}
	void UnitController::OnMouseUp(MouseClickArgs *, int)
	{
	}
}
