//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../Vector2D/Vector2.h"
#include "../Texture/Texture.h"

// �^�C�g���V�[�����ł̏������s���N���X.
class TitleScene : public BaseScene {
public:
    TitleScene();
    ~TitleScene();

    void update()override;      // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.
    void draw()override;        // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.
private:

    // �^�C�g���V�[���摜�p
    int backGroundImage;        // �w�i
    int characterImage;         // �L�����N�^�[
    int jailImage;
    int lockImage;


    Vector2<int> characterImageSize;
    Vector2<int> characterImagePos;

    Texture* jailImg;
    Texture* lockImg;

};