#pragma once

// �摜�N���X�A�摜�̕��⍂�����m�肽���̂ŃN���X��
class Texture {
private:
	// �摜�n���h��
	int handle;
	// �摜�̕�
	int width;
	// �摜�̍���
	int height;
public:
	// �R���X�g���N�^�A�ǂݍ��񂾉摜�n���h����ݒ肷��
	// �܂��n���h������A�摜�̕��ƍ�����ݒ肷��
	Texture(int handle);
};