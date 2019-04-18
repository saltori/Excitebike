#pragma once

struct square
{
	int top;	// ����
	int bottom;	// �E��
	int right;	// �E��
	int left;	// ����
};

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;
	// ������Z�q
	VECTOR2& operator = (const VECTOR2& vec);
	VECTOR2& operator = (const int& num);

	// �Y�������Z�q
	int& operator [](int i);

	// ��r���Z�q
	bool operator ==(const VECTOR2& vec)const;
	bool operator !=(const VECTOR2& vec)const;
	bool operator <=(const VECTOR2& vec)const;
	bool operator <(const VECTOR2& vec)const;



	// �P�����Z�q
	VECTOR2& operator +=(const VECTOR2& vec);
	VECTOR2& operator -=(const VECTOR2& vec);
	VECTOR2& operator *=(int k);
	VECTOR2& operator /=(int k);
	VECTOR2 operator +()const;
	VECTOR2 operator -()const;
	
	// VECTOR2 + int
	//VECTOR2 operator +(const int& num);
};

// �x�N�g���̉��Z
// VECTOR2���m�̉��Z
VECTOR2 operator+(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator-(const VECTOR2& a, const VECTOR2& b);

VECTOR2 operator*(const VECTOR2& a, int k);
VECTOR2 operator*(int k, const VECTOR2& a);

VECTOR2 operator/(const VECTOR2& a, int k);

VECTOR2 operator%(const VECTOR2& a, int k);
