#pragma once
#include "BaseScene.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	void Init(void);
	uniqueBase Update(uniqueBase ub);
private:
	VECTOR2 CursorPos;	// ¶°¿Ù‚ÌÀ•W
	int Flash;			// •¶š“_–Å
	int ShadowOffset;	// •¶š‚É‰e‚ğ‚Â‚¯‚é
};

