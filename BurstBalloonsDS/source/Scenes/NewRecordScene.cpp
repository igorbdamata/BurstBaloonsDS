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

NewRecordScene::NewRecordScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	mainEngine->AddSprite("TextPassRecord0", TextPassRecord0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord1", TextPassRecord1Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord2", TextPassRecord2Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("TextPassRecord3", TextPassRecord3Tiles, SpriteSize_64x64);
	mainEngine->AddPalette(PressAnyKeyText0Pal, "PressAnyKeyText");

	subEngine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, SpriteSize_64x64);

	float textPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float textPositionY = SCREEN_HEIGHT / 2;

	Entity* pressAnyKeyText[4] = { new Entity(new Vector2(textPositionX , textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64, textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64 * 2,textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64) };
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
		subEngine->InitEntity(this->pressAnyKeyText[i]);
		this->pressAnyKeyText[i]->SetPaletteTo(subEngine->GetPalette("PressAnyKeyText"));
	}
	this->pressAnyKeyText[0]->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText0"));
	this->pressAnyKeyText[1]->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText1"));
	this->pressAnyKeyText[2]->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText2"));
	this->pressAnyKeyText[3]->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText3"));


	Entity* passRecordText[4] = { new Entity(new Vector2(textPositionX, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
								  new Entity(new Vector2(textPositionX + 64, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
								  new Entity(new Vector2(textPositionX + 64 * 2, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
								  new Entity(new Vector2(textPositionX + 64 * 3, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64) };
	for (int i = 0; i < 4; i++)
	{
		this->passRecordText[i] = passRecordText[i];
		mainEngine->InitEntity(this->passRecordText[i]);
		this->passRecordText[i]->SetPaletteTo(mainEngine->GetPalette("PressAnyKeyText"));
	}
	this->passRecordText[0]->SetSpriteTo(mainEngine->GetSprite("TextPassRecord0"));
	this->passRecordText[1]->SetSpriteTo(mainEngine->GetSprite("TextPassRecord1"));
	this->passRecordText[2]->SetSpriteTo(mainEngine->GetSprite("TextPassRecord2"));
	this->passRecordText[3]->SetSpriteTo(mainEngine->GetSprite("TextPassRecord3"));

	this->sceneManager = sceneManager;

	SetMainBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
	SetSubBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
}

void NewRecordScene::Load()
{
	Scene::Load();
	SoundManager::PlaySFX(SFX_PASSRECORD);
	SoundManager::StopCurrentSong();
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