//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
// �^�C�g���V�[�����ł̏������s���N���X.
class TitleScene : public BaseScene {
public:
    TitleScene();
    ~TitleScene();

    void update()override;      // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.
    void draw()override;      // �^�C�g�����̏����A���͂�҂��ăQ�[����ʂ֑J�ڂ���.
};