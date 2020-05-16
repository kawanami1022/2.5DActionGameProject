//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <math.h>
#include "DxLib.h"
#include "../Obj.h"
#include "Player.h"

Player::Player()
{
	vec2 = new Vector2();
	pos[FLAME_ID_NOW] = { 500.0,300.0 };				// 現在位置
	pos[FLAME_ID_LAST] = { 500.0,300.0 };

	diff = { 0.0,0.0 };
	speed = 5;
	velocity = { 0.0,0.0 };
	animCnt = 0;
	angle = 0;
}

Player::~Player()
{
	delete vec2;
}

void Player::update()
{
}

void Player::draw(int angle)
{
	DrawRotaGraph((int)pos[FLAME_ID_NOW].x,
				(int)pos[FLAME_ID_NOW].y,
				1.5, 0, walkImage[animCnt / 10 % 5],
				true, false);
	animCnt++;
}

//目的プレーヤー移動
void Player::moveX()
{
	pos[FLAME_ID_NOW].x += getVelocity().x;		// 移動：X軸
}

void Player::moveY()
{
	pos[FLAME_ID_NOW].y += getVelocity().y;		// 移動：X軸
}

void Player::setAngle(int angle)
{
	this->angle = angle;
}


//目的	:プレーヤーの現在位置保存
void Player::setPos()
{
	pos[FLAME_ID_LAST] = pos[FLAME_ID_NOW];
}



Vector2 Player::getPos()
{
	return pos[FLAME_ID_NOW];
}

Vector2 Player::getDiff()
{
	diff.x = pos[FLAME_ID_NOW].x - pos[FLAME_ID_LAST].x;
	diff.y = pos[FLAME_ID_NOW].y - pos[FLAME_ID_LAST].y;
	return diff;
}

Vector2 Player::calcVelocity(short* LStickPos)
{
	double angle = vec2->calcAngle(LStickPos[0], LStickPos[1]);	// 角度を求める
	velocity.x = vec2->calcCos(angle) * speed;		// 移動：X軸
	velocity.y = -vec2->calcSin(angle) * speed;		// 移動：Y軸
	return { velocity.x,velocity.y };
}

Vector2 Player::getVelocity()
{
	return { velocity.x,velocity.y };
}


