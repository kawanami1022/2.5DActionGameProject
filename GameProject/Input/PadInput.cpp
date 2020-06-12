 //-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
//#include "InputManager.h"
#include "DxLib.h"
#include "PadInput.h"

std::unique_ptr<Pad, Pad::PadDeleter> Pad::sInstance(new Pad());		// static pointer�@�����

Pad::Pad()
{
	this->input[STATE_ID_NOW] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };		// NOW	0:������ĂȂ�
	this->input[STATE_ID_LAST] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };		// LAST	0:������ĂȂ�
	this->LStickAngle = 0;																	// ���X�e�B�b�N�̊p�x
	vec2 = new Vector2<double>;
}

Pad::~Pad()
{
	delete vec2;
}

void Pad::update()
{
	// ���͏�Ԃ��擾
	GetJoypadXInputState(DX_INPUT_PAD1, &input[STATE_ID_NOW]);					// �p�b�h1��
	this->LStickAngle = this->calcAngleLeft();
}

// NOW 1 LAST 1 ���������Ă���
bool Pad::HoldDown(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 1) { return true; }
	return false;
}

// NOW 0 LAST 0 ���������Ă���
bool Pad::HoldUp(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

// NOW 1 LAST 0 ��������
bool Pad::Push(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

// NOW 0 LAST 1 ��������
bool Pad::Release(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 1){return true;}
	return false;
}

//�ړI	:���͏�Ԃ��擾
//����	:stateID	���
XINPUT_STATE Pad::getXInput(STATE_ID stateID)
{
	return { input[stateID] };
}

//�ړI	:�f�b�h�]�[����݂���
//����	:posX
//		:posY
//		:padNum			
//		:deadZone		�����l
bool Pad::checkStickDeadzone(short posX, short posY, int padNum, double deadZone)
{
	//double deadZoneMax=vec;
	double analogPosDef[2] = { 0,0 };
	double analogPosNow[2] = { posX,posY };
	;
	
	// xy�̍���
	if (deadZone < vec2->calcTwoPtDisComp(analogPosDef, analogPosNow) / SHRT_MAX)
	{
		return true;
	}
	return false;
}

// �ړI	:LStick�̊p�x�����߂�
double Pad::calcAngleLeft()
{
	double angle = vec2->calcAngle(
		(double)this->input[STATE_ID_NOW].ThumbLX,
		(double)this->input[STATE_ID_NOW].ThumbLY);
	return angle;
}

// �ړI	: ���X�e�B�b�N�̊p�x���擾
double Pad::getAngleLeft()
{
	return this->LStickAngle;
}

// �ړI	: ���݂̓��͏���ۑ�����(������Q�[�����[�v���ɌĂԂ��Ƃœ��͏�Ԃɂ���Ĕ��肷�邱�Ƃ��ł���)
void Pad::saveInputState()
{
	this->input[STATE_ID_LAST] = this->input[STATE_ID_NOW];
}



