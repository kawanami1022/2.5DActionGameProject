#include <DxLib.h>
#include "Sound.h"

int Sound::LoadSound(const wchar_t* filePath)
{
	auto Handle = LoadSoundMem(filePath);
	return Handle;
}

int Sound::PlaySoundBG(int Handle)
{
	// Deffalt play type is backGround
	return PlaySoundMem(Handle, DX_PLAYTYPE_BACK, TRUE);
}

bool Sound::CheckPlayingSound()
{
	return (CheckSoundFile() == 1);
}

int Sound::StopPlayingSound(int soundHandle)
{
	return (PlaySoundMem(soundHandle,DX_PLAYTYPE_BACK)==0);
}

int Sound::DeleteSoundHandle(int soundHandle)
{
	return DeleteSoundMem(soundHandle);
}




