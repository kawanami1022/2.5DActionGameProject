//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "BaseScene.h"

BaseScene::BaseScene()
{
	pad = new Pad();
}

BaseScene::~BaseScene()
{
	delete pad;
}
