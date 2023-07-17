#if !defined(HARDWARE_MANAGER_H) 
#define HARDWARE_MANAGER_H 1
#pragma once

class HardwareManager
{
public:
    static void InitAndSetEverything();
    static void PowerOnConsole();
    static void InitVideo();
    static void InitAudio();
    static void SetVRAM();
    static void SetBackgrounds();
    static void StartMillisecondsTimer();

    static float GetCurrentMilliseconds();

    static void WaitForNextFrame();
    static void ClearScreens();
};

#endif  