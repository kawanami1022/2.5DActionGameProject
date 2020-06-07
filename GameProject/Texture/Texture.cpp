//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "Texture.h"

Texture::Texture(int handle,int pos_x, int pos_y)
{
	pos = new Vector2<int>(pos_x, pos_y);
	this->handle = handle;
	GetGraphSize(handle, &width, &height);
}

Texture::~Texture()
{
	DeleteGraph(handle, true);
	delete pos;
}

void Texture::drawTextureNomal()
{
	DrawGraph(pos->x, pos->y, this->handle, true);
}

//–Ú“I: ‰æ‘œ‚ð’†S‚É•`‰æ‚·‚é
void Texture::drawTextureCenter()
{
	DrawGraph(pos->x - width / 2, pos->y - height / 2, this->handle, true);
}
