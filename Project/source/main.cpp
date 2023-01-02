#include<nds.h>

#include <stdio.h>

#include <Square.h>
#include <woman.h>
#include "Engine.h"
#include "Game.h"

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

	Engine engine = Engine();
	engine.InitializeVideo();

	Game game = Game();

	InitSquare(&square, (u8*)SquareTiles);
	initWoman(&woman, (u8*)womanTiles);
	
	dmaCopy(SquarePal, SPRITE_PALETTE_SUB, 512);
	dmaCopy(womanPal, SPRITE_PALETTE_SUB, 512);

	while(1) {
	
		scanKeys();

		touchRead(&touchXY);

		 oamSet(&oamSub, 0, square.x, square.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, 
			square.sprite_gfx_mem[square.gfx_frame], -1, false, false, false, false, false);

		oamSet(&oamSub, 0, woman.x, woman.y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, 
			woman.sprite_gfx_mem[woman.gfx_frame], -1, false, false, false, false, false);
		game.Update();
		engine.UpdateScreens();
	}

	return 0;
}
