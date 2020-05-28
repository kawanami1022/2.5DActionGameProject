#include "Player.h"
#include "../common/ImageMng.h"
#include "../Input/KeyState.h"
#include "../Scene/SceneMng.h"

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

void Player::Update(void)
{
	if (DestroyPrpc())
	{
		return;
	}

	// (*_input).Update(); .ÇÕíÜÅ@->ÇÕäO
	_input->Update();			// Use KeyState Update to controll button keys

	// Player Movement Setting
	auto move = [](std::weak_ptr<InputState> keyData, INPUT_ID id, double& pNum, const int speed) {
		// keyData.expired() èIÇÌÇ¡ÇƒÇ¢ÇÈÇ©Ç¢Ç»Ç¢Ç©
		if (!keyData.expired())
		{
			if ((*keyData.lock()).state(id).first)		// Use lock() of weak pointer to access as share pointer
			{
				pNum += speed;
			}
		}
	};

	move(_input, INPUT_ID::LEFT, _pos.x, -5);
	move(_input, INPUT_ID::RIGHT, _pos.x, 5);
	move(_input, INPUT_ID::UP, _pos.y, -5);
	move(_input, INPUT_ID::DOWN, _pos.y, 5);

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

	//_input = ìnÇµÇΩÇ¢Ç‡ÇÃ
	//_input (ìnÇµÇΩÇ¢Ç‡ÇÃ);
	//_input.íáâÓêl(ìnÇµÇΩÇ¢Ç‡ÇÃ)

	// Change pointer from InputState to KeyState use KeyState feature
	_input = std::make_shared<KeyState>();

	// Set default state as NORNAL
	state(STATE::NORMAL);
}
