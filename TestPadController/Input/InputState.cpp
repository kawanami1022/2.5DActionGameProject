#include "InputState.h"

InputState::InputState()
{
	for (auto id : XPAD_INPUT_ID())	// enum class ��begin�֐���end�֐����Ȃ����߁A���̏�ō��@��������Δ͈�for��������
	{	
		state_.try_emplace(XPAD_INPUT_ID::DPAD_UP, StatePair{0,1});	// try_emplace ���̏���ް������
	}
}

InputState::~InputState()
{
}

const KeyMap& InputState::state(void) const
{
	return state_;
}

// �������݂Ɋւ��邱�Ƃ��ł��Ȃ��@
//_state�̌^��map�ō���Ă���@
//id�ɊY������L�[��map�̒��ɂȂ��Ƃ��V����make���Ă��܂��B���̍s�ׂ�const�Ɉ���������@������find���g��
const StatePair& InputState::state(XPAD_INPUT_ID id) const
{
	// &�ŎQ�Ƃ��Ă��邩��static�̓������g���@�ŏ����炱�̃f�[�^�͑��݂��邩����S
	static StatePair defData = { 0,0 }; 
	try
	{
		return state_.at(id);
	}
	catch (...)
	{
		return defData;
	}
}

bool InputState::SetKeyState(XPAD_INPUT_ID id, int data)
{
	if (state_.find(id) != state_.end())
	{
		state_.at(id).first = data;
	}
	return false;
}


bool InputState::isTriggered(XPAD_INPUT_ID id) const
{
	if (state_.find(id) != state_.end())
	{
		return (state_.at(id).first && (!state_.at(id).second));
	}

	return false;
}

bool InputState::isPressed(XPAD_INPUT_ID id) const
{
	if (state_.find(id) != state_.end())
	{
		return (state_.at(id).first);
	}
	return false;
}

bool InputState::isReleased(XPAD_INPUT_ID id) const
{
	if (state_.find(id) != state_.end())
	{
		return (!state_.at(id).first);
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : XPAD_INPUT_ID())
	{
		try
		{
			state_[id].second = state_[id].first;
		}
		catch (...)
		{
			// If id can't be found, create one
			state_.emplace(id, StatePair(0, 1));
		}
	}
}
