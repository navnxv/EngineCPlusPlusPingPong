//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exVector2
{
	float x, y;
	exVector2 operator + (exVector2 const& obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		return *this;
	}

	exVector2 operator += (exVector2 const& obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		return *this;
	}

	exVector2 operator - (exVector2 const& obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		return *this;
	}

	exVector2 operator -= (exVector2 const& obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		return *this;
	}

	exVector2 operator * (exVector2 const& obj)
	{
		this->x *= obj.x;
		this->y *= obj.y;
		return *this;
	}

	bool operator == (exVector2 const& obj)
	{
		return (this->x == obj.x && this->y == obj.y);
	}


};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
	int x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
	unsigned char mColor[4];
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//Escoped Enum for Different types of components
enum class ComponentType : int
{
	Transform = 0,
	Rendering,
	Physics,
	BoxShape,
	CircleShape,
	Spaceship,
	Asteroid
	//TODO
	//Bonce, //Add a component
	//Rotating
};



