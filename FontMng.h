#pragma once
#include<memory>
#include<mutex>
#include <map>
#include <list>
#include "VECTOR2.h"

class FontMng
{
public:
	static FontMng &GetInstance(void)
	{
		return *s_Instance;
	}
	void FontDraw(std::string drawfont);
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
	int i;
	char key[256];
	char keyOld[256];
	static std::unique_ptr<FontMng, FontMngDeleter> s_Instance;
	std::map<char, int> FontMap;
	std::list<char> DrawFontList;
	VECTOR2 pos;

};

