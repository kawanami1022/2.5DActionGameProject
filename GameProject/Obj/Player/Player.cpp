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
	pos[FLAME_ID_NOW] = { 500.0,300.0 };				// ���݈ʒu
	pos[FLAME_ID_LAST] = { 500.0,300.0 };
	
	diff = { 0.0,0.0 };
	speed = 5;
	velocity = { 0.0,0.0 };
	LoadDivGraph("Graphic/Character Test/(33x51)(walk).png", 20, 5, 4, 166/5, 205/4, walkImage, false);
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::draw()
{
	DrawFormatString(0, 128, 0xff0000, "player:%f,%f", pos[FLAME_ID_NOW].x, pos[FLAME_ID_NOW].y);
	DrawRotaGraph((int)pos[FLAME_ID_NOW].x, (int)pos[FLAME_ID_NOW].y, 1.5, 0, walkImage[0], true, false);
	DrawCircle((int)pos[FLAME_ID_NOW].x, (int)pos[FLAME_ID_NOW].y, 3, 0xff0000, true, true);
	
}

//�ړI�v���[���[�ړ�
void Player::moveX()
{
	pos[FLAME_ID_NOW].x += getVelocity().x;		// �ړ��FX��
}

void Player::moveY()
{
	pos[FLAME_ID_NOW].y += getVelocity().y;		// �ړ��FX��
}

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
	Vector2 vec2;
	double angle = vec2.calcAngle(LStickPos[0], LStickPos[1]);	// �p�x�����߂�
	velocity.x = vec2.calcCos(angle) * speed;		// �ړ��FX��
	velocity.y = -vec2.calcSin(angle) * speed;		// �ړ��FY��
	return { velocity.x,velocity.y };
}

Vector2 Player::getVelocity()
{
	return { velocity.x,velocity.y };
}


