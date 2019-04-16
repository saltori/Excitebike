#pragma once

class FVECTOR2
{
public:
	FVECTOR2();
	FVECTOR2(float x, float y);
	~FVECTOR2();
	float x;
	float y;
	// ‘ã“ü‰‰ŽZŽq
	FVECTOR2& operator = (const FVECTOR2& vec);
	FVECTOR2& operator = (const float& num);

	// “Y‚¦Žš‰‰ŽZŽq
	float& operator [](float i);

	// ”äŠr‰‰ŽZŽq
	bool operator ==(const FVECTOR2& vec)const;
	bool operator !=(const FVECTOR2& vec)const;
	bool operator <=(const FVECTOR2& vec)const;
	bool operator <(const FVECTOR2& vec)const;



	// ’P€‰‰ŽZŽq
	FVECTOR2& operator +=(const FVECTOR2& vec);
	FVECTOR2& operator -=(const FVECTOR2& vec);
	FVECTOR2& operator *=(float k);
	FVECTOR2& operator /=(float k);
	FVECTOR2 operator +()const;
	FVECTOR2 operator -()const;
	
	// FVECTOR2 + float
	//FVECTOR2 operator +(const float& num);
};

// ƒxƒNƒgƒ‹‚Ì‰‰ŽZ
// FVECTOR2“¯Žm‚Ì‰‰ŽZ
FVECTOR2 operator+(const FVECTOR2& a, const FVECTOR2& b);

FVECTOR2 operator-(const FVECTOR2& a, const FVECTOR2& b);

FVECTOR2 operator*(const FVECTOR2& a, int k);
FVECTOR2 operator*(int k, const FVECTOR2& a);

FVECTOR2 operator/(const FVECTOR2& a, int k);
