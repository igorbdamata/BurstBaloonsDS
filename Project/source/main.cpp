#include <nds.h>
#include <soundbank.h>

#include "Engine/OamEngine.h"
#include "Engine/Entity.h"
#include "Engine/HardwareManager.h"
#include "Engine/SoundManager.h"
#include "Engine/Vector2.h"

#include <soundbank_bin.h>
#include "BalloonSprite.h"
#include "BalloonUI.h"
#include "Background.h"
#include "Background1.h"
#include "Font.h"

#include "Balloon.h"
#include "GameManager.h"

#include <time.h>

int main()
{
    const int DISTANCE_BETWEEN_UI_BALLOONS = 20;
    const int BALLOONS_COUNT = 1;

    HardwareManager::InitAndSetEverything();
    srand(time(NULL));

    OamEngine main = OamEngine(UPPER);
    OamEngine sub = OamEngine(BOTTOM);

    GameManager gameManager = GameManager(3);

    main.AddSprite("balloonUI", BalloonUITiles, SpriteSize_32x32);
    std::vector<void *> balloonFlyFrames;
    std::vector<void *> balloonBurstFrames;
    int balloonSpriteSheetWidth = 2048;
    for (int i = 0; i <= 3; i++)
    {
        const char *frameName = strcat("balloonFly", std::to_string(gameManager.GetScore()).c_str());
        sub.AddSprite(frameName, BalloonSpriteTiles + (balloonSpriteSheetWidth)*i, SpriteSize_64x64);
        balloonFlyFrames.insert(balloonFlyFrames.end(), sub.GetSprite(frameName));
    }
    for (int i = 0; i <= 3; i++)
    {
        const char *frameName = strcat("balloonBurst", std::to_string(gameManager.GetScore()).c_str());
        sub.AddSprite(frameName, BalloonSpriteTiles + (balloonSpriteSheetWidth)*i + 4, SpriteSize_64x64);
        balloonBurstFrames.insert(balloonBurstFrames.end(), sub.GetSprite(frameName));
    }
    touchPosition touch;
    Vector2 touchVector2 = Vector2(0, 0);

    sub.AddPallete(BalloonSpritePal, "balloon");
    Balloon balloon = Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager);
    sub.InitEntity(&balloon);
    balloon.ChangePalleteTo(sub.GetPallete("balloon"));

    Animation flyAnimation = Animation(0.2, 3, balloon.GetSpriteAddress(), true, balloonFlyFrames);
    Animation burstAnimation = Animation(0.2, 3, balloon.GetSpriteAddress(), false, balloonBurstFrames);
    balloon.AddAnimation("fly", &flyAnimation);
    balloon.AddAnimation("burst", &burstAnimation);

    Entity balloonsUI[] = {Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 0, 0), SpriteSize_32x32),
                           Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 1, 0), SpriteSize_32x32),
                           Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 2, 0), SpriteSize_32x32)};
    balloonsUI[0].spriteAddress = main.GetSprite("balloonUI");
    balloonsUI[1].spriteAddress = main.GetSprite("balloonUI");
    balloonsUI[2].spriteAddress = main.GetSprite("balloonUI");
    main.AddPallete(BalloonUIPal, "balloonUI");
    for (int i = 0; i < 3; i++)
    {
        main.InitEntity(&balloonsUI[i]);
        balloonsUI[i].ChangePalleteTo(main.GetPallete("balloonUI"));
    }

    main.SetBackgroundTo(Background1Bitmap, Background1BitmapLen);
    sub.SetBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

    main.SetTextFont((void *)fontTiles, (void *)fontPal, fontPalLen);
int d = 0;
    while (true)
    {
        HardwareManager::ClearScreens();
        scanKeys();
        touchRead(&touch);
        touchVector2.x = touch.px;
        touchVector2.y = touch.py;

        printf("\n   Score: ");
        printf(std::to_string(gameManager.GetScore()).c_str());

        balloon.Update();

        balloon.Render();
        balloon.UpdateAnimation();
        
        if (keysDown() & KEY_TOUCH)
        {
            d++;
            balloon.CheckCollision(&touchVector2);
        }
        for (int i = 0; i < 3; i++)
        {
            if (i < gameManager.GetCurrentLife())
                balloonsUI[i].Render();
        }

        main.UpdateOam();
        sub.UpdateOam();
        HardwareManager::WaitForNextFrame();
    }
    return 0;
}
