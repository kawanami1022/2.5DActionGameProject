#include "InputState.h"

InputState::InputState()
{
	for (auto id : XPAD_INPUT_ID())	// enum class のbegin関数とend関数がないため、その場で作る　そうすれば範囲for文が作れる
	{	
		state_.try_emplace(XPAD_INPUT_ID::DPAD_UP, StatePair{0,1});	// try_emplace その場でﾃﾞｰﾀを作る
	}
}

InputState::~InputState()
{
}

const KeyMap& InputState::state(void) const
{
	return state_;
}

// 書き込みに関することができない　
//_stateの型はmapで作られている　
//idに該当するキーがmapの中にないとき新しくmakeしてしまう。その行為がconstに引っかかる　だからfindを使う
const StatePair& InputState::state(XPAD_INPUT_ID id) const
{
	// &で参照しているからstaticの特性を使う　最初からこのデータは存在するから安全
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
