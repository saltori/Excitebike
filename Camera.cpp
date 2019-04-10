
#include "SceneTask.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "Camera.h"

Camera::Camera()
{
}


Camera::~Camera()
{
}

VECTOR2 & Camera::GetPos()
{
	return pos;
}

bool Camera::SetPos(VECTOR2 pos)
{
	this->pos = pos;
	return true;
}

bool Camera::SetPos(int x, int y)
{
	pos = { x,y };
	return true;
}

bool Camera::SetTarget(std::weak_ptr<Player> target)
{
	this->target = target;
	VECTOR2 tmpPos = (lpSceneTask.GetScreenSize() / 2 + lpSceneTask.GetScreenSize() % 2);
	DrawRange.top	= tmpPos.y;
	DrawRange.left = tmpPos.x;

	tmpPos = (lpSceneTask.GetScreenSize() * 2 - (lpSceneTask.GetScreenSize() / 2 + lpSceneTask.GetScreenSize() % 2));
	DrawRange.right = tmpPos.x;
	DrawRange.bottom = tmpPos.y;

	if (DrawRange.top > DrawRange.bottom)
	{
		DrawRange.top = lpSceneTask.GetScreenSize().y;
		DrawRange.bottom = DrawRange.top;
	}

	if (DrawRange.left > DrawRange.right)
	{
		DrawRange.left	= 
		DrawRange.right = DrawRange.left;
	}

	defpos = pos;


	return true;
}

void Camera::Update(void)
{
	if (target.expired())
	{
		return;
	}
	VECTOR2 tmpPos = target.lock()->GetPos();

	if (tmpPos.x >= DrawRange.left && tmpPos.x < DrawRange.right)
	{
		pos.x = tmpPos.x;

	}
	//if (tmpPos.y >= DrawRange.top && tmpPos.y < DrawRange.bottom)
	//{
	//	pos.y = tmpPos.y;
	//}
}

void Camera::Draw(void)
{
	DrawRotaGraph(pos.x,pos.y,2,0,IMAGE_ID("image/cameraman.png")[1],true);
}

VECTOR2 Camera::GetdefPos(void)
{
	return defpos;
}
