#pragma once
#include<memory>
#include<mutex>
#include <map>
#include <vector>
#include "VECTOR2.h"

#define lpFontMng (FontMng::GetInstance())

class FontMng
{
public:
	static FontMng &GetInstance(void)
	{
		return *s_Instance;
	}
	void FontSet(std::string drawfont);			// 表示したい文字をｾｯﾄする
	void FontDraw(VECTOR2 pos,VECTOR2 offset,bool Flashflag);	// 文字を表示する座標と文字の間の感覚と点滅させるか
	void FontDraw(std::string drawfont, VECTOR2 pos, VECTOR2 offset, bool Flashflag);							// 上2つまとめたやつ
	void FontInit(void);
private:
	struct FontMngDeleter
	{
		void operator()(FontMng* fontMng)const
		{
			delete fontMng;
		}
	};
	FontMng();
	~FontMng();
	char key[256];
	char keyOld[256];
	static std::unique_ptr<FontMng, FontMngDeleter> s_Instance;
	std::map<char, int> FontMap;
	std::vector<char> DrawFontList;
	VECTOR2 pos;
	int Flash;	// 点滅用のｶｳﾝﾀｰ
	std::string str;

};

