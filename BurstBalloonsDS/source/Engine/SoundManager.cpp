#include "Engine/SoundManager.h"
#include<maxmod9.h>

int currentSFX;
int currentSong;

void SoundManager::PlaySFX(int sfxToPlay)
{
    mmLoadEffect(sfxToPlay);
    mmEffect(sfxToPlay);
}

void SoundManager::PlaySong(int songToPlay)
{
    mmLoad(songToPlay);
    mmStart(songToPlay, MM_PLAY_LOOP);
}
void SoundManager::StopCurrentSong()
{
    mmStop();
}