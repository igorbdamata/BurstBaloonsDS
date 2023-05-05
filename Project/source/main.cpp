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

#include "Balloon.h"

int main()
{
    HardwareManager::InitAndSetEverything();

    OamEngine main = OamEngine(UPPER);
    OamEngine sub = OamEngine(BOTTOM);

    touchPosition touch;
    Vector2 touchVector2 = Vector2(0, 0);

    sub.AddPallete(BalloonSpritePal, "balloon");
    Balloon balloon = Balloon(Vector2(100, 100), SpriteSize_64x64, "fly", BalloonSpriteTiles, 2, 22, 27, 20, 5);
    sub.InitEntity(&balloon);
    balloon.ChangePalleteTo(sub.GetPallete("balloon"));

    Animation flyAnimation = Animation(0.2, 0, 3, balloon.GetSpriteAddress(), SpriteSize_64x64, (void *)&BalloonSpriteTiles, 2048, true);
    Animation burstAnimation = Animation(0.2, 4, 7, balloon.GetSpriteAddress(), SpriteSize_64x64, (void *)&BalloonSpriteTiles, 2048, false);
    balloon.AddAnimation("fly", &flyAnimation);
    balloon.AddAnimation("burst", &burstAnimation);

    main.SetBackgroundTo(Background1Bitmap, Background1BitmapLen);
    sub.SetBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

    while (true)
    {
        HardwareManager::ClearScreens();

        touchRead(&touch);
        touchVector2.x = touch.px;
        touchVector2.y = touch.py;

        scanKeys();
        balloon.Move();
        balloon.CheckCollision(touchVector2);

        balloon.Render();
        balloon.UpdateAnimation();

        main.UpdateOam();
        sub.UpdateOam();
        HardwareManager::WaitForNextFrame();
    }
    return 0;
}
