#pragma once
class Sound
{
public:
	// create Sound Handle
	static int LoadSound(const wchar_t* filePath);
	// playing sound in backGround
	// int Handle:SoundHandle
	static int PlaySoundBG(int Handle);

	// check Playing Sound File
	// true:playing
	// false:stop
	static bool CheckPlayingSound();

	// stop Playing Sound
	static int StopPlayingSound(int soundHandle);

	// Delete Handle
	static int DeleteSoundHandle(int soundHandle);


};

