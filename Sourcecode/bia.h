#pragma once
#include "cocos2d.h"
USING_NS_CC;

class bia
{
public:
	Vec2 vitri2;
	int mucdo = 2;//5 muc do
	bia();
	~bia();
	Sprite* chaibia;
	Vec2 vitri;
	PhysicsBody* bodybia;
	void setvitri(Vec2 vt);
	bool dichuyen = false;
	void setmucdo(int md);

};

