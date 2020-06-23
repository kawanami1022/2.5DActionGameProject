#pragma once
#include <map>
#include "XPAD_INPUT_ID.h"

using StatePair = std::pair<int, int>;
using KeyMap = std::map<XPAD_INPUT_ID, StatePair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();
	virtual void Update(void) = 0;

	// Get member variable state_
	const KeyMap& state(void) const;

	// Get pad state
	const StatePair& state(XPAD_INPUT_ID) const;

	// Set pad state
	bool state(XPAD_INPUT_ID, int data);

	// ���܂��ɉ�����܂���
	bool isTriggered(XPAD_INPUT_ID) const;

	// ���݉�����Ă���
	bool isPressed(XPAD_INPUT_ID) const;

	// �����Ă��z�����܂��ɗ����ꂽ
	bool isReleased(XPAD_INPUT_ID) const;

	// Set previous state
	void SetOld(void);								

private:
	KeyMap state_;

};

