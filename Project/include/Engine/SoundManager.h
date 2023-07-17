#if !defined(SOUND_MANAGER_H)
#define SOUND_MANAGER_H 1
#pragma once

class SoundManager
{
public:
    static void PlaySFX(int sfxToPlay);
    static void PlaySong(int songToPlay);
    static void StopCurrentSong();
};

#endif