#include "Player.h"
#include "../common/ImageMng.h"
#include "../Scene/SceneMng.h"
#include "../Input/XPadState.h"
#include "../_debug/_DebugConOut.h"

Player::Player()
{
	Init();
}

Player::Player(Vector2Dbl pos, Vector2Dbl size)
{
	_pos = pos;
	_size = size;
	_unitID = UNIT_ID::PLAYER;
	Init();
}

void Player::Update(sharedObj)
{
	if (DestroyPrpc())
	{
		return;
	}

	//// (*_input).Update(); .ÇÕíÜÅ@->ÇÕäO
	input_->Update();			// Use KeyState Update to controll button keys

	//// Player Movement Setting
	auto move = [](std::weak_ptr<InputState> keyData, XPAD_INPUT_ID id, double& pNum, const int speed) {
		// keyData.expired() èIÇÌÇ¡ÇƒÇ¢ÇÈÇ©Ç¢Ç»Ç¢Ç©
		if (!keyData.expired())
		{
			if ((*keyData.lock()).state(id).first)		// Use lock() of weak pointer to access as share pointer
			{
				pNum += speed;
			}
		}
	};

	move(input_, XPAD_INPUT_ID::DPAD_LEFT, _pos.x, -5);
	move(input_, XPAD_INPUT_ID::DPAD_RIGHT, _pos.x, 5);
	move(input_, XPAD_INPUT_ID::DPAD_UP, _pos.y, -5);
	move(input_, XPAD_INPUT_ID::DPAD_DOWN, _pos.y, 5);

	auto makeDead = [this](std::weak_ptr<InputState> padData)
	{
		if (!padData.expired())
		{
			if ((*padData.lock()).isTriggered(XPAD_INPUT_ID::Y))
			{
				this->SetAlive(false);
				TRACE("Y is pressed");
			}
		}
	};

	makeDead(input_);

	// Check Game Screen collision
	if (_pos.x <= (_size.x / 2)) _pos.x = (_size.x / 2);
	if (_pos.y <= _size.y / 2) _pos.y = _size.y / 2;
	if (_pos.x > (lpSceneMng.GameScreenSize.x - _size.x / 2)) _pos.x = (lpSceneMng.GameScreenSize.x - _size.x / 2);
	if (_pos.y > (lpSceneMng.GameScreenSize.y - _size.y / 2)) _pos.y = (lpSceneMng.GameScreenSize.y - _size.y / 2);
}

Player::~Player()
{
}

void Player::Draw(void)
{
	Obj::Draw();
}

void Player::Init(void)
{
	// Set frame animation
	AnimVector data;
	data.emplace_back(IMAGE_ID("∑¨◊")[0], 20);
	data.emplace_back(IMAGE_ID("∑¨◊")[1], 40);
	data.emplace_back(IMAGE_ID("∑¨◊")[2], 60);
	data.emplace_back(IMAGE_ID("∑¨◊")[3], 80);
	SetAnim(STATE::NORMAL, data);

	data.emplace_back(-1, 0);
	SetAnim(STATE::DETH, data);

	//_input = ìnÇµÇΩÇ¢Ç‡ÇÃ
	//_input (ìnÇµÇΩÇ¢Ç‡ÇÃ);
	//_input.íáâÓêl(ìnÇµÇΩÇ¢Ç‡ÇÃ)

	// Change pointer from InputState to KeyState use KeyState feature
	input_ = std::make_shared<XPadState>();

	// Set default state as NORNAL
	state(STATE::NORMAL);
}
