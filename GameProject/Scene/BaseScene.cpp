//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "BaseScene.h"
#include "SceneController.h"

BaseScene::BaseScene()
{
	pad = new Pad();
}

BaseScene::~BaseScene()
{
	delete pad;
}
