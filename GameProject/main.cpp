//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "Scene/SceneController.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, INT)
{
    /*SceneController sceneController;
    sceneController.run();*/

    // Change to static pointer, so don't need to create entity
    SceneController::GetInstance().run();
}
