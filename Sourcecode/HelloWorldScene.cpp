#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "bavo.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	audio->playBackgroundMusic("amthanh/nhacnen.mp3", true);
	capnhatnhac();
	//

	chieucaobia = aa.chaibia->getContentSize().height / 2;
	//them anh tri tim
	auto tim = Sprite::create("anh/tim.png");
	tim->setPosition(Point(visibleSize.width - 80, visibleSize.height - 15));
	//
	//
	//them loa
	loamo = Sprite::create("anh/loamo.png");
	loatat = Sprite::create("anh/loatat.png");
	Vec2 vtloa = Vec2(470,305);
	Vec2 vtpause = Vec2(435, 305);
	loamo->setPosition(vtloa);
	loatat->setPosition(vtloa);

	//
	
	auto bg = Sprite::create("anh/background.jpg");
	bg->setAnchorPoint(Vec2(0,0));
	addChild(bg);
	addChild(tim);
	addChild(loamo);
	addChild(loatat);
	//
	if (loadangmo == true) {
		nhachieuung = true;
		nhacnen = true;
		capnhatnhac();
		loamo->setPosition(vtloa);
		loatat->setPosition(-100, 0);
	}
	if (loadangmo == false)
	{
		nhachieuung = false;
		nhacnen = false;
		capnhatnhac();
		loamo->setPosition(Vec2(-100, 0));
		loatat->setPosition(vtloa);// setOpacity(0);
	}
	//
	//
	//
	auto nutpause = MenuItemImage::create("anh/pause.png", "anh/pause1.png", CC_CALLBACK_1(HelloWorld::nhanpause, this));
	nutpause->setPosition(vtpause);
	
	menu1 = Menu::create(nutpause, NULL);
	
	menu1->setPosition(0, 0);
	addChild(menu1);
	//

	
	//
	auto chudiem1 = Label::createWithTTF("score: ", "fonts/Neverwinter.ttf", 24);
	chudiem1->setAnchorPoint(ccp(0, 0.5f));
	chudiem1->setPosition(Point(visibleSize.width - 100, visibleSize.height - 30));

	chudiem = Label::createWithTTF("", "fonts/Neverwinter.ttf", 24);
	chudiem->setAnchorPoint(ccp(0, 0.5f));
	chudiem->setPosition(Point(visibleSize.width - 30, visibleSize.height - 30));
	//chuye kieu du lieu
	__String *diem1 = __String::createWithFormat("%i", diem);
	chudiem->setString(diem1->getCString());
	// chu mang
	chumang = Label::createWithTTF("", "fonts/Neverwinter.ttf", 24);
	chumang->setPosition(Point(visibleSize.width - 68, visibleSize.height - 13));
	//
	__String *mang1 = __String::createWithFormat("%i", mang);
	chumang->setString(mang1->getCString());
	//
	addChild(chumang);
	this->addChild(chudiem);
	this->addChild(chudiem1);
	

	//auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,1.0f);
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,2.0f);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)	);
	edgeBody->setCollisionBitmask(1);
	edgeBody->setContactTestBitmask(true);
	edgeNode->setPhysicsBody(edgeBody);
	addChild(edgeNode);
	/*	edgeBody->setDynamic(false)*/;
	//edgeBody->setCollisionBitmask(1);
	//edgeBody->setContactTestBitmask(true);
	//auto khung = Sprite::create();
	//khung->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	//khung->setPhysicsBody(edgeBody);
	//addChild(khung);

	//
	auto contactListener = EventListenerPhysicsContact::create();

	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onPhysicsContact, this);



	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//ba vo
	addChild(a.bavo_1);
	tudongnem(1);
	//ongchong
	addChild(chong.nguoi);
	addChild(chong.ro);

	auto mouseListener = EventListenerMouse::create();

	mouseListener->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);
	mouseListener->onMouseDown = CC_CALLBACK_1(HelloWorld::onMouseDown, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	///
	//

	//
	auto lancan = Sprite::create("anh/lancan.png");
	lancan->setAnchorPoint(Vec2(0, 0));
	lancan->setPosition(Vec2(0,visibleSize.height-108));
	addChild(lancan);
	//
	//
	
	//(a.phai == true) ? (b.vitri.x = a.vitri.x + 30) : (b.vitri.x=a.vitri.x - 30);
	//b.vitri.y = a.vitri.y - 30;
	//b.setvitri(b.vitri);

    return true;
}



void HelloWorld::onMouseMove(Event* event) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	EventMouse* e = (EventMouse*)event;
	Vec2 vt = Vec2(e->getCursorX(), e->getCursorY());

	if (vt.y >= chong.ro->getContentSize().height + 10 || vt.y <= chong.ro->getContentSize().height) {
		chong.setvitri(Vec2(vt.x,chong.vitriro.y));
	}
	else
		chong.setvitri(vt);
}

void HelloWorld::onMouseDown(Event* event) {
	EventMouse* e = (EventMouse*)event;
	Vec2 vt = Vec2(e->getCursorX(), e->getCursorY());

	if (loamo->boundingBox().containsPoint(vt)|| loatat->boundingBox().containsPoint(vt)) {//neu click vao vung cua loa 
		loadangmo=!loadangmo;
		if (loadangmo==true) {
			nhachieuung = true;
			nhacnen = true;
			capnhatnhac();
			loamo->setPosition(Vec2(470, 305));// setOpacity(0);
			loatat->setPosition(Vec2(-100, 0));
		}
		if(loadangmo==false)
		{
			nhachieuung = false;
			nhacnen = false;
			capnhatnhac();
			loamo->setPosition(Vec2(-100, 0));
			loatat->setPosition(Vec2(470, 305));// setOpacity(0);
		}
		
	}
}

void HelloWorld::tudongnem(float dt) {
	if (dunggame == false) {
		this->schedule(schedule_selector(HelloWorld::tudongnem), tgnem);
		srand(time(0));	
		int mucdo1 = 0;
		if (danem <= 50)
			mucdo1 = (danem / 10)*4;
		tgnem = random(5,30-mucdo1)*0.1;
		int randhuong = rand() % 2;
		(randhuong == 0) ? a.ditrai() : a.diphai();
		a.nem();
		if(nhachieuung==true)
			audio->playEffect("amthanh/nemchai.mp3", false, 1.0f, 1.0f, 1.0f);

		this->scheduleOnce(schedule_selector(HelloWorld::taochaibia), 0.4);
	}
	
	
}

//xu li va cham
bool HelloWorld::onPhysicsContact(const PhysicsContact &contact)
{
	// va cham voi duong duoi
	auto shapeA = contact.getShapeA()->getBody();
	auto shapeB = contact.getShapeB()->getBody();
	if (shapeA->getCollisionBitmask() == 1 && shapeB->getCollisionBitmask() == 2)
	{
		if (shapeB->getPosition().y <= chieucaobia / 2)
		{
			if (shapeB->getNode() != NULL) {
						shapeB->getNode()->removeFromParentAndCleanup(true);
				if(nhachieuung==true)
					audio->playEffect("amthanh/chaibe.mp3", false, 1.0f, 1.0f, 1.0f);
				mang--;
				if (dunggame == true) mang++;
				__String *mang1 = __String::createWithFormat("%i", mang);
				chumang->setString(mang1->getCString());
				if (mang == 0)
				{
					if(dunggame==false)
						gameover();
				}
			}
		}
			
		


	}
	else
	if (shapeA->getCollisionBitmask() == 2 && shapeB->getCollisionBitmask() == 1)
	{
		if (shapeA->getPosition().y <=chieucaobia/2)
			if (shapeA->getNode() != NULL) {
				if(nhachieuung==true)
					audio->playEffect("amthanh/chaibe.mp3", false, 1.0f, 1.0f, 1.0f);
				shapeA->getNode()->removeFromParentAndCleanup(true);
				mang--;
				if (dunggame == true) mang++;
				__String *mang1 = __String::createWithFormat("%i", mang);
				chumang->setString(mang1->getCString());
				if (mang == 0)
				{	
					if (dunggame == false)
						gameover();
				}
			}	
	}
	//
	//va cham bia vo ro
	if (shapeA->getCollisionBitmask() == 2 && shapeB->getCollisionBitmask() == 3)
	{
		if(nhachieuung==true)
			audio->playEffect("amthanh/bialot.mp3", false, 1.0f, 1.0f, 1.0f);
		chong.chamro();
		if(dunggame==false)
			diem++;
		// 
		__String *diem1 = __String::createWithFormat("%i", diem);
		chudiem->setString(diem1->getCString());
		//
		if (shapeA->getNode() != NULL)
			shapeA->getNode()->removeFromParentAndCleanup(true);
	}
	if (shapeA->getCollisionBitmask() == 3 && shapeB->getCollisionBitmask() == 2)
	{
		if(nhachieuung==true)
			audio->playEffect("amthanh/bialot.mp3", false, 1.0f, 1.0f, 1.0f);
		chong.chamro();
		if (dunggame == false)
			diem++;
		//
		__String *diem1 = __String::createWithFormat("%i", diem);
		chudiem->setString(diem1->getCString());
		//
		if (shapeB->getNode() != NULL)
				shapeB->getNode()->removeFromParentAndCleanup(true);
	}
	return true;

}
void HelloWorld::taochaibia(float dt)
{
	b[sobianem]=bia::bia();
	if (danem <= 50) {	
		danem += 1;
	}
	b[sobianem].setmucdo(b[sobianem].mucdo += danem / 10);	

	addChild(b[sobianem].chaibia);
	(a.phai == true) ? (b[sobianem].vitri.x = a.vitri.x + 30) : (b[sobianem].vitri.x = a.vitri.x - 30);
	b[sobianem].vitri.y = a.vitri.y - 30;
	b[sobianem].setvitri(b[sobianem].vitri);
	sobianem++;
	if (sobianem == 10)
		sobianem = 0;
}
void HelloWorld::stopgame() {
	dunggame = true;
	a.dunggame();

		
}
void HelloWorld::gameover() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	stopgame();
	layout = ui::Layout::create();
	layout->setTag(10);
	layout->setBackGroundImage("anh/backgroundgameover.png");
	layout->setBackGroundImageOpacity(100);
//	layout->setAnchorPoint(Vec2(0.5, 0.5));
	layout->setContentSize(visibleSize);
	//layout->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(layout,100);
	auto abc = Sprite::create("anh/nengameover.png");
	abc->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	layout->addChild(abc);
	auto nuthome = MenuItemImage::create("anh/menu.png", "anh/menu1.png", CC_CALLBACK_1(HelloWorld::nhanmenu, this));
	nuthome->setPosition(Vec2(-25, -70));
	auto nutreplay = MenuItemImage::create("anh/replay.png", "anh/replay1.png", CC_CALLBACK_1(HelloWorld::nhanreplay, this));
	nutreplay->setPosition(Vec2(25, -70));
	// tao menu
	auto menu = Menu::create(nuthome, nutreplay, NULL);
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	layout->addChild(menu);

	auto chudiem1 = Label::createWithTTF("", "fonts/Marker Felt.ttf", 20);
	chudiem1->setAnchorPoint(ccp(0, 0.5f));
	chudiem1->setTextColor(Color4B::ORANGE);
	chudiem1->setPosition(Point(visibleSize.width /2+10, visibleSize.height /2-40));
	__String *diem11 = __String::createWithFormat("%i", diem);
	chudiem1->setString(diem11->getCString());
	layout->addChild(chudiem1);
}
void HelloWorld::continuegame() {
	dunggame = false;
	a.tieptucgame();
}
void HelloWorld::capnhatnhac() {
	if (nhacnen == true) {
		audio->resumeBackgroundMusic();
	}
	if (nhacnen == false) {
		audio->pauseBackgroundMusic();
	}
	
}
void HelloWorld::nhanmenu(Ref* pSender) {
	removeChildByTag(10, true);
		
}
void HelloWorld::nhanreplay(Ref* pSender) {
	
	//layout->removeFromParent();
	removeChildByTag(10, true);
	danem = 0;
	a.bavo_1->setPosition(200,267);
	diem = 0;
	mang = 5;
	__String *diem1 = __String::createWithFormat("%i", diem);
	chudiem->setString(diem1->getCString());
	__String *mang1 = __String::createWithFormat("%i", mang);
	chumang->setString(mang1->getCString());
	continuegame();
}
void HelloWorld::nhanpause(Ref* pSender) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (dunggame == false) {
		auto nutplay = MenuItemImage::create("anh/play.png", "anh/play1.png", CC_CALLBACK_1(HelloWorld::nhanplay, this));
		nutplay->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		nutplay->setTag(5);
		menu1->addChild(nutplay);
	}
	stopgame();
	
}
void HelloWorld::nhanplay(Ref* pSender) {
	continuegame();
	menu1->removeChildByTag(5);
}