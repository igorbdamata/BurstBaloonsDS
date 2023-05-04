#include <nds.h>
#include <soundbank.h>

#include "Engine\OamEngine.h"
#include "Engine\Entity.h"
#include "Engine\HardwareManager.h"
#include "Engine\SoundManager.h"
#include "Engine\Vector2.h"

#include <soundbank_bin.h>
#include "BalloonSprite.h"
#include "Background.h"
#include "Background1.h"

int main()
{
    HardwareManager::InitAndSetEverything();

    OamEngine main = OamEngine(UPPER);
    OamEngine sub = OamEngine(BOTTOM);

    AnimatedEntity balloon = sub.GetNewAnimatedEntity(Vector2(100, 100), BalloonSpriteTiles, BalloonSpriteTilesLen, BalloonSpritePal, SpriteSize_64x64, "fly");
    Animation flyAnimation = Animation(0.2, 0, 3, balloon.GetSpriteAddress(), SpriteSize_64x64, (void *)BalloonSpriteTiles, 2048, true);
    Animation burstAnimation = Animation(0.2, 4, 7, balloon.GetSpriteAddress(), SpriteSize_64x64, (void *)BalloonSpriteTiles, 2048, false);
    balloon.AddAnimation("fly", &flyAnimation);
    balloon.AddAnimation("burst", &burstAnimation);

    main.SetBackgroundTo(Background1Bitmap, Background1BitmapLen);
    sub.SetBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

    while (true)
    {
        HardwareManager::ClearScreens();
        scanKeys();

        balloon.Render();
        balloon.UpdateAnimation();

        main.UpdateOam();
        sub.UpdateOam();
        HardwareManager::WaitForNextFrame();
    }
    return 0;
}
