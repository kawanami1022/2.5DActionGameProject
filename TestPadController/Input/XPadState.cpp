#include "XPadState.h"

XPadState::XPadState()
{
	DxLib::GetJoypadXInputState(DX_INPUT_PAD1, &buf_);
	keyConDef_.reserve(static_cast<size_t>(end(XPAD_INPUT_ID())));

	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_UP);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_DOWN);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_LEFT);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_RIGHT);
	keyConDef_.emplace_back(XINPUT_BUTTON_START);
	keyConDef_.emplace_back(XINPUT_BUTTON_BACK);
	keyConDef_.emplace_back(XINPUT_BUTTON_LEFT_THUMB);
	keyConDef_.emplace_back(XINPUT_BUTTON_RIGHT_THUMB);
	keyConDef_.emplace_back(XINPUT_BUTTON_LEFT_SHOULDER);
	keyConDef_.emplace_back(XINPUT_BUTTON_RIGHT_SHOULDER);
	keyConDef_.emplace_back(XINPUT_BUTTON_A);
	keyConDef_.emplace_back(XINPUT_BUTTON_B);
	keyConDef_.emplace_back(XINPUT_BUTTON_X);
	keyConDef_.emplace_back(XINPUT_BUTTON_Y);


	keyCon_ = keyConDef_;

	//�֐��߲�����g���Ƃ���&���g���@��������ް�֐��߲�� �N���X����H�遁���O���
	func = &XPadState::RefPadData;				
}

XPadState::~XPadState()
{
}

void XPadState::Update()
{
	SetOld();
	DxLib::GetJoypadXInputState(DX_INPUT_PAD1, &buf_);	// _buf�͂��ׂĂ����݂̉�����Ԃ��Ƃ�
	(this->*func)(); // �������g���߲�����this
}


void XPadState::RefPadData(void)
{
	// _buf�ɓ����Ă��� inputID�̷�(enumclass)�̏���state��set���g���Ă���� 
	// _buf�@inputID���̏���set���g���ā@�͈�for�����g���@_keycon���g����set����@
	// f1�L�[����������func�̓��e��setConFig�ɕς���@
	// f1key���������u��refKeyData�̌Ăяo���ɂ��ǂ��@�g���[�X�Ő؂�ւ������ς�������Ƃ�\������
	for (auto id : XPAD_INPUT_ID())
	{
		state(id, buf_.Buttons[keyCon_[static_cast<int>(id)]]);
	}
}

void XPadState::SetPadConfig(void)
{
}
