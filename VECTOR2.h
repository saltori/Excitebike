#pragma once

struct square
{
	int top;
	int bottom;
	int right;
	int left;
};

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;
	// ‘ã“ü‰‰ŽZŽq
	VECTOR2& operator = (const VECTOR2& vec);
	VECTOR2& operator = (const int& num);
	VECTOR2& operator = (const float& num);

	// “Y‚¦Žš‰‰ŽZŽq
	int& operator [](int i);

	// ”äŠr‰‰ŽZŽq
	bool operator ==(const VECTOR2& vec)const;
	bool operator !=(const VECTOR2& vec)const;
	bool operator <=(const VECTOR2& vec)const;
	bool operator <(const VECTOR2& vec)const;



	// ’P€‰‰ŽZŽq
	VECTOR2& operator +=(const VECTOR2& vec);
	VECTOR2& operator -=(const VECTOR2& vec);
	VECTOR2& operator *=(int k);
	VECTOR2& operator /=(int k);
	VECTOR2 operator +()const;
	VECTOR2 operator -()const;
	
	// VECTOR2 + int
	//VECTOR2 operator +(const int& num);
};

// ƒxƒNƒgƒ‹‚Ì‰‰ŽZ
// VECTOR2“¯Žm‚Ì‰‰ŽZ
VECTOR2 operator+(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator-(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator*(const VECTOR2& a, int k);
VECTOR2 operator*(int k, const VECTOR2& a);

VECTOR2 operator/(const VECTOR2& a, int k);

VECTOR2 operator%(const VECTOR2& a, int k);
