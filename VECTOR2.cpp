#include "VECTOR2.h"


VECTOR2::VECTOR2()
{
	x = 0;
	y = 0;
}

VECTOR2::VECTOR2(int x, int y)
{
	this->x = x;
	this->y = y;
}

VECTOR2::~VECTOR2()
{
}

VECTOR2 & VECTOR2::operator=(const VECTOR2 & vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

VECTOR2 & VECTOR2::operator=(const int & num)
{
	this->x = num;
	this->y = num;
	return *this;
}

int & VECTOR2::operator[](int i)
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

bool VECTOR2::operator==(const VECTOR2 & vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool VECTOR2::operator!=(const VECTOR2 & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}


bool VECTOR2::operator<=(const VECTOR2 & vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

bool VECTOR2::operator<(const VECTOR2 & vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}


VECTOR2 & VECTOR2::operator+=(const VECTOR2 & vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

VECTOR2 & VECTOR2::operator-=(const VECTOR2 & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

VECTOR2 & VECTOR2::operator*=(int k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}

VECTOR2 & VECTOR2::operator/=(int k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}

VECTOR2 VECTOR2::operator+() const
{
	return *this;
}

VECTOR2 VECTOR2::operator-() const
{
	return VECTOR2(-this->x, -this->y);
}

//VECTOR2  VECTOR2::operator+(const int & num)
//{
//	this->x =+ num;
//	this->y =+ num;
//	return *this;
//}

VECTOR2 operator+(const VECTOR2 & a, const VECTOR2 & b)
{
	VECTOR2 vec;
	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	return vec;

	//return VECTOR2(a.x + b.x, a.y + b.y);
}

VECTOR2 operator-(const VECTOR2 & a, const VECTOR2 & b)
{
	VECTOR2 vec;
	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return vec;

	//return VECTOR2(a.x - b.x, a.y - b.y);
}

VECTOR2 operator*(const VECTOR2 & a, int k)
{
	VECTOR2 vec;
	vec.x = a.x * k;
	vec.y = a.y * k;
	return vec;

	//return VECTOR2(a.x * k, a.y * k);
}

VECTOR2 operator*(int k, const VECTOR2 & a)
{
	VECTOR2 vec;
	vec.x = k * a.x;
	vec.y = k * a.y;
	return vec;
	//return VECTOR2(k * a.x, k * a.y);
}

VECTOR2 operator/(const VECTOR2 & a, int k)
{
	VECTOR2 vec;
	vec.x = a.x / k;
	vec.y = a.y / k;
	return vec;

	//return VECTOR2(a.x / k, a.y / k);
}


VECTOR2 operator%(const VECTOR2 & a, int k)
{
	VECTOR2 vec;
	vec.x = a.x % k;
	vec.y = a.y % k;
	return vec;
	//return VECTOR2(a.x % k, a.y % k);
}
