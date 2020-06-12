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

enum class DRAW_QUE // enum�͌^���B�� class�������class�������O��Ԃ�����X�Ƃ������O�������ł��Ⴄ���̂ɂȂ� 
{
    IMAGE,				// �摜ID	
    X,
    Y,
    RAD
};

using DrawQueT = std::tuple<int, double, double, double>;		// 4��,��]�p
#define lpSceneMng SceneController::GetInstance()

// �Q�[���̎��������Ǘ�����.
class SceneController {
private:
    // �����ǂ̃V�[���������N���X.
    //std::unique_ptr<BaseScene> nowScene;
    activeScene _activeScene;

    

    // List of pictures
    // Each graphic will be added to this List
    std::vector<DrawQueT> _drawList;

    // Delete pointer method for unique pointer
    struct SceneControllerDeleter
    {
        void operator()(SceneController* sceneCtl) const    // ��ځ@�I�[�o�[���[�h�������@��ځ@�E�ӎ�������ذĂ����������E���ɏ���
        {
            delete sceneCtl;
        }
    };

    static std::unique_ptr<SceneController,SceneControllerDeleter> sInstance;



public:
    // �R���X�g���N�^�A������ʂ��^�C�g���ɃZ�b�g����.
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