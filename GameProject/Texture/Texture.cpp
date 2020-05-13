//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "Texture.h"

Texture::Texture(int handle)
{
	this->handle = handle;
	GetGraphSize(handle, &width, &height);
}