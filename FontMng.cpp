#include "DxLib.h"
#include <string>
#include <algorithm>
#include "FontMng.h"
#include "ImageMng.h"


std::unique_ptr<FontMng, FontMng::FontMngDeleter> FontMng::s_Instance(new FontMng());

void FontMng::FontSet(std::string drawfont)
{
	std::string str;
	DrawFontList.clear();
	str = drawfont;
	std::transform(str.begin(), str.end(), str.begin(), toupper);
	for (int i =0; i <= str.size(); i++)
	{
		DrawFontList.push_back(str[i]);
	}

}

void FontMng::FontDraw(VECTOR2 pos, VECTOR2 offset,bool Flashflag)
{

	if (DrawFontList.size() == 0)
	{
		return;
	}

	if (Flashflag)
	{
		Flash++;
		if (Flash / 20 % 2)
		{
			for (auto tmp : DrawFontList)
			{
				DrawRotaGraph(pos.x, pos.y, 2, 0, FontMap[tmp], true);
				pos += offset;
			}
		}
	}
	else
	{
		for (auto tmp : DrawFontList)
		{
			DrawRotaGraph(pos.x, pos.y, 2, 0, FontMap[tmp], true);
			pos += offset;
		}
	}
}

FontMng::FontMng()
{
}

FontMng::~FontMng()
{
}

void FontMng::FontInit(void)
{
	Flash = 0;
	ImageMng::GetInstance().GetID("image/font.png", { 8,8 }, { 13,3 }, { 0,0 });
	FontMap['1'] = IMAGE_ID("image/font.png")[1];
	FontMap['2'] = IMAGE_ID("image/font.png")[2];
	FontMap['3'] = IMAGE_ID("image/font.png")[3];
	FontMap['4'] = IMAGE_ID("image/font.png")[4];
	FontMap['5'] = IMAGE_ID("image/font.png")[5];
	FontMap['6'] = IMAGE_ID("image/font.png")[6];
	FontMap['7'] = IMAGE_ID("image/font.png")[7];
	FontMap['8'] = IMAGE_ID("image/font.png")[8];
	FontMap['9'] = IMAGE_ID("image/font.png")[9];
	FontMap['A'] = IMAGE_ID("image/font.png")[13];
	FontMap['B'] = IMAGE_ID("image/font.png")[14];
	FontMap['C'] = IMAGE_ID("image/font.png")[15];
	FontMap['D'] = IMAGE_ID("image/font.png")[16];
	FontMap['E'] = IMAGE_ID("image/font.png")[17];
	FontMap['F'] = IMAGE_ID("image/font.png")[18];
	FontMap['G'] = IMAGE_ID("image/font.png")[19];
	FontMap['H'] = IMAGE_ID("image/font.png")[20];
	FontMap['I'] = IMAGE_ID("image/font.png")[21];
	FontMap['J'] = IMAGE_ID("image/font.png")[22];
	FontMap['K'] = IMAGE_ID("image/font.png")[23];
	FontMap['L'] = IMAGE_ID("image/font.png")[24];
	FontMap['M'] = IMAGE_ID("image/font.png")[25];
	FontMap['N'] = IMAGE_ID("image/font.png")[26];
	FontMap['O'] = IMAGE_ID("image/font.png")[27];
	FontMap['P'] = IMAGE_ID("image/font.png")[28];
	FontMap['Q'] = IMAGE_ID("image/font.png")[29];
	FontMap['R'] = IMAGE_ID("image/font.png")[30];
	FontMap['S'] = IMAGE_ID("image/font.png")[31];
	FontMap['T'] = IMAGE_ID("image/font.png")[32];
	FontMap['U'] = IMAGE_ID("image/font.png")[33];
	FontMap['V'] = IMAGE_ID("image/font.png")[34];
	FontMap['W'] = IMAGE_ID("image/font.png")[35];
	FontMap['X'] = IMAGE_ID("image/font.png")[36];
	FontMap['Y'] = IMAGE_ID("image/font.png")[37];
	FontMap['Z'] = IMAGE_ID("image/font.png")[38];
}


