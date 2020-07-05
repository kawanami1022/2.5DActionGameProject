#pragma once
enum class XPAD_INPUT_ID // ϯ�߂̷�  ����̌^���w��ł���
{
DPAD_UP			,	// �f�W�^�������{�^����		(0)
DPAD_DOWN		,	// �f�W�^�������{�^����		(1)
DPAD_LEFT		,	// �f�W�^�������{�^����		(2)
DPAD_RIGHT		,	// �f�W�^�������{�^���E		(3)
START			,	// START�{�^��				(4)
BACK			,	// BACK�{�^��				(5)
LEFT_THUMB		,	// ���X�e�B�b�N��������		(6)
RIGHT_THUMB		,	// �E�X�e�B�b�N��������		(7)
LEFT_SHOULDER	,	// LB�{�^��					(8)
RIGHT_SHOULDER	,	// RB�{�^��					(9)
A				,	// A�{�^��					(10)
B				,	// B�{�^��					(11)
X				,	// X�{�^��					(12)
Y				,	// Y�{�^��					(13)
MAX
};

XPAD_INPUT_ID begin(XPAD_INPUT_ID);
XPAD_INPUT_ID end(XPAD_INPUT_ID);
XPAD_INPUT_ID operator*(XPAD_INPUT_ID key);
XPAD_INPUT_ID operator++(XPAD_INPUT_ID& key);

