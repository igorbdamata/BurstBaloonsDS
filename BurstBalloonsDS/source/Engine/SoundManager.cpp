#include <maxmod9.h>
#include <soundbank.h>

#include "Engine/SoundManager.h"

int SoundManager::currentSong = -1;

void SoundManager::LoadAllSoundsFromSoundbank()
{
	for (int i = 0; i < MSL_NSONGS; i++)
		mmLoad(i);
	for (int i = 0; i < MSL_NSAMPS; i++)
		mmLoadEffect(i);
}

void SoundManager::PlaySFX(int sfxToPlay)
{
	mmEffect(sfxToPlay);
}
void SoundManager::StopSFX(int sfxToStop)
{
	mmEffectCancel(sfxToStop);
}
void SoundManager::StopAllSFXs()
{
	mmEffectCancelAll();
}

void SoundManager::PlaySong(int songToPlay)
{
	mmStart(songToPlay, MM_PLAY_LOOP);
	SoundManager::currentSong = songToPlay;
}
void SoundManager::StopCurrentSong()
{
	mmStop();
	SoundManager::currentSong = -1;
}

bool SoundManager::IsPlayingSong(int song)
{
	return SoundManager::currentSong == song;
}
bool SoundManager::IsPlayingAnySong()
{
	return SoundManager::currentSong != -1;
}