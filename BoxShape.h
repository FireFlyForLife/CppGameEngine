#pragma once
#include "Shape.h"
#include "Rectangle.h"

namespace GameEngine {
	class BoxShape : public Shape, public Rectangle{ 
		using Rectangle::Rectangle;
	};
}