#include "FVECTOR2.h"


FVECTOR2::FVECTOR2()
{
	x = 0;
	y = 0;
}

FVECTOR2::FVECTOR2(float x, float y)
{
	this->x = x;
	this->y = y;
}

FVECTOR2::~FVECTOR2()
{
}

FVECTOR2 & FVECTOR2::operator=(const FVECTOR2 & vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

FVECTOR2 & FVECTOR2::operator=(const float & num)
{
	this->x = num;
	this->y = num;
	return *this;
}

float & FVECTOR2::operator[](float i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

bool FVECTOR2::operator==(const FVECTOR2 & vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool FVECTOR2::operator!=(const FVECTOR2 & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}


bool FVECTOR2::operator<=(const FVECTOR2 & vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

bool FVECTOR2::operator<(const FVECTOR2 & vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}


FVECTOR2 & FVECTOR2::operator+=(const FVECTOR2 & vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

FVECTOR2 & FVECTOR2::operator-=(const FVECTOR2 & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

FVECTOR2 & FVECTOR2::operator*=(float k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}

FVECTOR2 & FVECTOR2::operator/=(float k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}

FVECTOR2 FVECTOR2::operator+() const
{
	return *this;
}

FVECTOR2 FVECTOR2::operator-() const
{
	return FVECTOR2(-this->x, -this->y);
}

//FVECTOR2  FVECTOR2::operator+(const float & num)
//{
//	this->x =+ num;
//	this->y =+ num;
//	return *this;
//}

FVECTOR2 operator+(const FVECTOR2 & a, const FVECTOR2 & b)
{
	FVECTOR2 vec;
	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	return vec;

	//return FVECTOR2(a.x + b.x, a.y + b.y);
}

FVECTOR2 operator-(const FVECTOR2 & a, const FVECTOR2 & b)
{
	FVECTOR2 vec;
	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return vec;

	//return FVECTOR2(a.x - b.x, a.y - b.y);
}

FVECTOR2 operator*(const FVECTOR2 & a, int k)
{
	FVECTOR2 vec;
	vec.x = a.x * k;
	vec.y = a.y * k;
	return vec;

	//return FVECTOR2(a.x * k, a.y * k);
}

FVECTOR2 operator*(int k, const FVECTOR2 & a)
{
	FVECTOR2 vec;
	vec.x = k * a.x;
	vec.y = k * a.y;
	return vec;
	//return FVECTOR2(k * a.x, k * a.y);
}

FVECTOR2 operator/(const FVECTOR2 & a, int k)
{
	FVECTOR2 vec;
	vec.x = a.x / k;
	vec.y = a.y / k;
	return vec;

	//return FVECTOR2(a.x / k, a.y / k);
}
