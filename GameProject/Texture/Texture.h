//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../Vector2D/Vector2.h"

// �摜�N���X�A�摜�̕��⍂�����m�肽���̂ŃN���X��
class Texture {
private:

	Vector2<int> *pos;
	// �摜�n���h��
	int handle;
	// �摜�̕�
	int width;
	// �摜�̍���
	int height;
public:
	// �R���X�g���N�^�A�ǂݍ��񂾉摜�n���h����ݒ肷��
	// �܂��n���h������A�摜�̕��ƍ�����ݒ肷��
	Texture(int handle, int pos_x, int pos_y);
	~Texture();

	void drawTextureNomal();
	void drawTextureCenter();

};