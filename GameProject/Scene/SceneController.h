//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
#include <vector>
#include "BaseScene.h"
#define SCREEN_SIZE_X   1336
#define SCREEN_SIZE_Y   768

enum class DRAW_QUE // enumは型が曖昧 classをつけるとclass名＝名前空間だからXという名前が同じでも違うものになる 
{
    IMAGE,				// 画像ID	
    X,
    Y,
    RAD
};

using DrawQueT = std::tuple<int, double, double, double>;		// 4つ目,回転角
#define lpSceneMng SceneController::GetInstance()

// ゲームの実処理を管理する.
class SceneController {
private:
    // 今がどのシーンか示すクラス.
    //std::unique_ptr<BaseScene> nowScene;
    activeScene _activeScene;

    

    // List of pictures
    // Each graphic will be added to this List
    std::vector<DrawQueT> _drawList;

    // Delete pointer method for unique pointer
    struct SceneControllerDeleter
    {
        void operator()(SceneController* sceneCtl) const    // 一つ目　オーバーロードしたい　二つ目　右辺式何をﾃﾞﾘｰﾄしたいかを右側に書く
        {
            delete sceneCtl;
        }
    };

    static std::unique_ptr<SceneController,SceneControllerDeleter> sInstance;



public:
    // コンストラクタ、初期画面をタイトルにセットする.
    SceneController();
    ~SceneController();

    static SceneController& GetInstance(void)
    {
        return *sInstance;
    }


    // Method that adding pictures to que
    bool AddDrawQue(DrawQueT dQue);

    void changeScene(BaseScene* scene);
    int run();

    // Draw all images in _drawList
    void Draw();
};