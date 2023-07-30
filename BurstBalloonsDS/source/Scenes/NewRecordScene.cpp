#include "Scenes/NewRecordScene.h"
#include "Engine/HardwareManager.h"
#include <nds/arm9/input.h>
#include <nds/arm9/sprite.h>
#include <string>
#include<nds.h>
#include<nds/arm9/sprite.h>


#include"PressAnyKeyText0.h"
#include"PressAnyKeyText1.h"
#include"PressAnyKeyText2.h"
#include"PressAnyKeyText3.h"

#include"TextPassRecord0.h"
#include"TextPassRecord1.h"
#include"TextPassRecord2.h"
#include"TextPassRecord3.h"

#include "BackgroundPassRecord.h"
#include "Engine/SoundManager.h"
#include<soundbank.h>
#include<math.h>

NewRecordScene::NewRecordScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	mainEngine->AddSprite("TextPassRecord0", TextPassRecord0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord1", TextPassRecord1Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord2", TextPassRecord2Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord3", TextPassRecord3Tiles, SpriteSize_64x64);
	mainEngine->AddPallete(TextPassRecord0Pal, "TextPassRecord");

	subEngine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, SpriteSize_64x64);

	float textPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float textPositionY = SCREEN_HEIGHT / 2;

	Entity* pressAnyKeyText[4] = { new Entity(new Vector2(textPositionX , textPositionY), SpriteSize_64x64,64,64),
								   new Entity(new Vector2(textPositionX + 64, textPositionY), SpriteSize_64x64,64,64),
								   new Entity(new Vector2(textPositionX + 64 * 2,textPositionY), SpriteSize_64x64,64,64),
								   new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), SpriteSize_64x64,64,64)};
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
		subEngine->InitEntity(this->pressAnyKeyText[i]);
		this->pressAnyKeyText[i]->ChangePalleteTo(subEngine->GetPallete("TextPassRecord"));
	}
	this->pressAnyKeyText[0]->spriteAddress = subEngine->GetSprite("PressAnyKeyText0");
	this->pressAnyKeyText[1]->spriteAddress = subEngine->GetSprite("PressAnyKeyText1");
	this->pressAnyKeyText[2]->spriteAddress = subEngine->GetSprite("PressAnyKeyText2");
	this->pressAnyKeyText[3]->spriteAddress = subEngine->GetSprite("PressAnyKeyText3");


	Entity* passRecordText[4] = { new Entity(new Vector2(textPositionX, textPositionY), SpriteSize_64x64,64,64),
								  new Entity(new Vector2(textPositionX + 64, textPositionY), SpriteSize_64x64,64,64),
								  new Entity(new Vector2(textPositionX + 64 * 2, textPositionY), SpriteSize_64x64,64,64),
								  new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), SpriteSize_64x64,64,64) };
	for (int i = 0; i < 4; i++)
	{
		this->passRecordText[i] = passRecordText[i];
		mainEngine->InitEntity(this->passRecordText[i]);
		this->passRecordText[i]->ChangePalleteTo(mainEngine->GetPallete("TextPassRecord"));
	}
	this->passRecordText[0]->spriteAddress = mainEngine->GetSprite("TextPassRecord0");
	this->passRecordText[1]->spriteAddress = mainEngine->GetSprite("TextPassRecord1");
	this->passRecordText[2]->spriteAddress = mainEngine->GetSprite("TextPassRecord2");
	this->passRecordText[3]->spriteAddress = mainEngine->GetSprite("TextPassRecord3");

	this->sceneManager = sceneManager;

	SetMainBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
	SetSubBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
}

void NewRecordScene::Load()
{
	Scene::Load();
	SoundManager::PlaySFX(SFX_PASSRECORD);
}

void NewRecordScene::InputLoop()
{
	Scene::InputLoop();

	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}
void NewRecordScene::GameLoop()
{
	for (int i = 0; i < 4; i++)
	{
		this->passRecordText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2 - 64 / 2;
		this->passRecordText[i]->Render();

		this->pressAnyKeyText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2;
		pressAnyKeyText[i]->Render();
	}
}