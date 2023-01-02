#include<nds.h>

#include <stdio.h>

#include <Square.h>
#include <woman.h>
#include <BackGround.h>
#include <Ground.h>
#include "Engine.h"
#include "Game.h"
#include "Entity.h"
#include "Vector2.h"

volatile int frame = 0;


#define FRAMES_PER_ANIMATION 3
// The state of the sprite (which way it is walking)
//---------------------------------------------------------------------
enum SpriteState {W_UP = 0, W_RIGHT = 1, W_DOWN = 2, W_LEFT = 3};

//---------------------------------------------------------------------
// Screen dimentions
//---------------------------------------------------------------------
enum {SCREEN_TOP = 0, SCREEN_BOTTOM = 192, SCREEN_LEFT = 0, SCREEN_RIGHT = 256};

typedef struct
{
	int x;
	int y;

	u16* sprite_gfx_mem[12];
	int gfx_frame;

	int state;
	int anim_frame;


}SquareSpr;

typedef struct
{
	int x;
	int y;

	u16* sprite_gfx_mem[12];
	int gfx_frame;

	int state;
	int anim_frame;


}Woman;

void initWoman(Woman *sprite, u8* gfx)
{
	int i;

	for(i = 0; i < 12; i++)
	{
		sprite->sprite_gfx_mem[i] = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
		dmaCopy(gfx, sprite->sprite_gfx_mem[i], 32*32);
		gfx += 32*32;
	}
}

void InitSquare(SquareSpr *sprite, u8* gfx)
{
	int i;

	for(i = 0; i < 12; i++)
	{
		sprite->sprite_gfx_mem[i] = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
		dmaCopy(gfx, sprite->sprite_gfx_mem[i], 32*32);
		gfx += 32*32;
	}
}

void animateWoman(Woman *sprite)
{
	sprite->gfx_frame = sprite->anim_frame + sprite->state * FRAMES_PER_ANIMATION;
}


//---------------------------------------------------------------------------------
void Vblank() {
//---------------------------------------------------------------------------------
	frame++;
}
	
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	SquareSpr square = {0,0};
	Woman woman = {100,0};
	touchPosition touchXY;

consoleDemoInit();
	Engine engine = Engine();
	engine.InitializeVideo();

	Game game = Game();

	InitSquare(&square, (u8*)SquareTiles);
	initWoman(&woman, (u8*)womanTiles);
	
	dmaCopy(SquarePal, SPRITE_PALETTE_SUB, 512);
	dmaCopy(womanPal, SPRITE_PALETTE_SUB, 512);

	Entity ground = Entity(Vector2(0,0), (u8*) GroundTiles,  GroundPal, 32*32, 1);

	Entity entity = Entity(Vector2(0,0), (u8*)womanTiles, womanPal,  32*32, 12);

	while(1) {
	
		scanKeys();

		entity.position+= Vector2(1,0);
		if(entity.position.x > SCREEN_RIGHT)
		{
			entity.position=Vector2(0,0);
		}

		touchRead(&touchXY);

		entity.RenderInLowerScreen((void*)womanPal,0);
		ground.RenderInLowerScreen((void*)GroundPal,1);

		game.Update();
		engine.UpdateScreens();
	}

	return 0;
}
