#include "DxLib.h"
#include "Scene/SceneController.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, INT)
{
    SceneController sceneController;
    sceneController.run();
    return 0;
}
