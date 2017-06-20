#include "bia.h"

bia::bia()
{
	vitri = Vec2(0, 0);
	chaibia = Sprite::create("anh/bia.png");
	chaibia->setPosition(vitri);
	chaibia->setScale(0.3);
	bodybia = PhysicsBody::createBox(Size(chaibia->getContentSize().width-60, chaibia->getContentSize().height-30),PhysicsMaterial(0,1,0));
	bodybia->setMass(0.5);
	bodybia->setCollisionBitmask(2);
	bodybia->setContactTestBitmask(true);
	chaibia->setPhysicsBody(bodybia);
}

void bia::setmucdo(int md){
	mucdo = md;
	srand(time(0));
	int x = random(-mucdo * 100, mucdo * 100);
	int y = random(-mucdo * 100, 0);
	vitri2 = Vec2(x,y);
	bodybia->setVelocity(Vec2(x, y));
}

bia::~bia()
{
}
void bia::setvitri(Vec2 vt) {
	vitri = vt;
	chaibia->setPosition(vitri);
}

