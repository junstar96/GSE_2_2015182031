#include"stdafx.h"
#include"object.h"

object::object()
{
	image = new Renderer(1000, 1000);
	x = 400;
	y = 300;
	v.x = 1;
	v.y = 1;
	if (!image->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
}


object::~object()
{
	delete image;
}

void object::get_object(int x, int y)
{

}

void object::move_object()
{
	if (x >= 500.0)
	{
		v.x = 2;
	}
	else if (x <= -500.0)
	{
		v.x = 1;
	}

	if (y >= 500.0)
	{
		v.y = 2;
	}
	else if (y <= -500.0)
	{
		v.y = 1;
	}



	switch (v.x)
	{
	case 1:
		x += 5.0;
		break;
	case 2:
		x -= 5.0;
		break;
	default:
		break;
	}

	

	switch (v.y)
	{
	case 1:
		y += 5.0;
		break;
	case 2:
		y -= 5.0;
		break;
	default:
		break;
	}

	

}

void object::draw()
{

	// Renderer Test
	image->DrawSolidRect(x, y, 0.0, 16, 1.0, 0.5, 0.5, 1);
}