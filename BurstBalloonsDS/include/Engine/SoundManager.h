#pragma once
#if !defined(SOUND_MANAGER_H)
#define SOUND_MANAGER_H true

class SoundManager
{
public:
	static void LoadAllSoundsFromSoundbank();
	static void PlaySFX(int sfxToPlay);
	static void StopSFX(int sfxToStop);
	static void StopAllSFXs();

	static void PlaySong(int songToPlay);
	static void StopCurrentSong();

	static bool IsPlayingSong(int song);
	static bool IsPlayingAnySong();
private:
	static int currentSong;
};

#endif