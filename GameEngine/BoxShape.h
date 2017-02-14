#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "GenericRectangle.h"

namespace GameEngine {
	//Old and tidy BoxShape :(
	/*class BoxShape : public Shape, public Rectangle{ 
		using Rectangle::Rectangle;
	};*/

	class BoxShape : public Shape, public GenericRectangle<float> {
		using GenericRectangle<float>::GenericRectangle;
	};
}