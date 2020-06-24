#include "Player.h"
#include "../common/ImageMng.h"
#include "../Scene/SceneMng.h"
#include "../Input/XPadState.h"
#include "../_debug/_DebugConOut.h"

Player::Player():inputHandler_{ _pos, _padNum }
{
	Init();
}

Player::Player(Vector2Dbl pos, Vector2Dbl size, int padNum):_padNum(padNum),inputHandler_{_pos, _padNum }
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


	inputHandler_.Update();


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
	/*input_ = std::make_shared<XPadState>();*/

	// Set default state as NORNAL
	state(STATE::NORMAL);
}
