#include "PlayerInputHandler.h"
#include "../Input/XPadState.h"
#include "Player.h"
#include "../_debug/_DebugConOut.h"



PlayerInputHandler::PlayerInputHandler(Vector2Dbl& pos, int& padNum):pos_(pos),padNum_(padNum)
{
	input_ = std::make_shared<XPadState>(padNum_);
}

void PlayerInputHandler::Update()
{
	input_->Update();
	MovePlayer();
}

void PlayerInputHandler::MovePlayer(void)
{
	// Move with DPAD
	auto moveFunc = [](std::weak_ptr<XPadState> input, XPAD_INPUT_ID id, double& pos, int speed)
	{
		if (!input.expired())
		{
			if (input.lock()->isPressed(id))
			{
				pos += speed;
			}
		}
	};

	moveFunc(input_, XPAD_INPUT_ID::DPAD_LEFT, pos_.x, -speed);
	moveFunc(input_, XPAD_INPUT_ID::DPAD_RIGHT, pos_.x, speed);
	moveFunc(input_, XPAD_INPUT_ID::DPAD_UP, pos_.y, -speed);
	moveFunc(input_, XPAD_INPUT_ID::DPAD_DOWN, pos_.y, speed);


	// Move with left joystick
	if (input_->buf_.ThumbLX < (128-128*30)) pos_.x += -speed;
	if (input_->buf_.ThumbLX > (128+128*30)) pos_.x += speed;
	if (input_->buf_.ThumbLY > (128 + 128 * 30)) pos_.y += -speed;
	if (input_->buf_.ThumbLY < (128 - 128 * 30)) pos_.y += speed;

	TRACE("ThumbLX : %d\n", input_->buf_.ThumbLX);
	TRACE("ThumbLY : %d\n", input_->buf_.ThumbLY);
}

PlayerInputHandler::~PlayerInputHandler()
{
}
