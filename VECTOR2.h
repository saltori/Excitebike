#pragma once

struct square
{
	int top;	// ¶ã
	int bottom;	// ‰E‰º
	int right;	// ‰Eã
	int left;	// ¶‰º
};

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;
	// ‘ã“ü‰‰Zq
	VECTOR2& operator = (const VECTOR2& vec);
	VECTOR2& operator = (const int& num);

	// “Y‚¦š‰‰Zq
	int& operator [](int i);

	// ”äŠr‰‰Zq
	bool operator ==(const VECTOR2& vec)const;
	bool operator !=(const VECTOR2& vec)const;
	bool operator <=(const VECTOR2& vec)const;
	bool operator <(const VECTOR2& vec)const;



	// ’P€‰‰Zq
	VECTOR2& operator +=(const VECTOR2& vec);
	VECTOR2& operator -=(const VECTOR2& vec);
	VECTOR2& operator *=(int k);
	VECTOR2& operator /=(int k);
	VECTOR2 operator +()const;
	VECTOR2 operator -()const;
	
	// VECTOR2 + int
	//VECTOR2 operator +(const int& num);
};

// ƒxƒNƒgƒ‹‚Ì‰‰Z
// VECTOR2“¯m‚Ì‰‰Z
VECTOR2 operator+(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator-(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator*(const VECTOR2& a, int k);
VECTOR2 operator*(int k, const VECTOR2& a);

VECTOR2 operator/(const VECTOR2& a, int k);

VECTOR2 operator%(const VECTOR2& a, int k);
