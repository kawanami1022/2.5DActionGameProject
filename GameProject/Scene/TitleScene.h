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

    void input()override;
    activeScene update(activeScene)override;      // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.
    void draw()override;        // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.

    void switchScene();
private:

    // �^�C�g���V�[���摜�n���h��
    int backGroundImage;        // �w�i
    int characterImage;         // �L�����N�^�[
    int jailImage;              // �B
    int lockImage;              // ��


    Vector2<int> characterImageSize;        // �L�����N�^�[�摜�T�C�Y�ۑ��p
    Vector2<int> characterImagePos;         // �L�����N�^�[�摜���W

    Texture* jailImg;           // �B�̉摜���
    Texture* lockImg;           // ���̉摜���

};