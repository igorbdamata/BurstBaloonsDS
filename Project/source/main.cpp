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

//consoleDemoInit();
	Engine engine = Engine();
	engine.InitializeVideo();

	Game game = Game();

	//InitSquare(&square, (u8*)SquareTiles);
	//initWoman(&woman, (u8*)womanTiles);
	
	int i =0;
	//Seta a paleta do sprite do ground
	for(int j= 0; j< GroundPalLen/2;j++)
	{
		SPRITE_PALETTE_SUB[i+j+1] = GroundPal[j];
	}

	//Seta a paleta do sprite da mulher
	for(i =5;i<50;i++)
	{
		SPRITE_PALETTE_SUB[i] = womanPal[i];
	}

	//Reserva espaço pro sprite do ground
	u16* ground = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
	
	//Copia o sprite do GroundTiles no ground
	dmaCopy(GroundTiles, ground, SpriteSize_32x32);

	//Reserva espaço pro sprite do ground na memória
	u16* entity = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copia o sprite do womanTiles no entity
	dmaCopy(womanTiles, entity, SpriteSize_32x32);
	for(int j=0;j<32*32;j++)
	{
		entity[j] += 4;
	}
//	Entity ground = Entity(Vector2(0,0), (u8*) GroundTiles,  GroundPal, 32*32, 1);

	//Entity entity = Entity(Vector2(0,1), (u8*)womanTiles, womanPal,  32*32, 12);

	while(1) {
	
		scanKeys();
			oamSet(&oamSub, 
			0, 
			0,0,
			0, 
			0,
			SpriteSize_32x32,
			SpriteColorFormat_256Color, 
			ground,
			-1, 
			false, 
			false,
			false,
			false, 
			false);

			oamSet(&oamSub, 
			1, 
			100,100,
			0, 
			0,
			SpriteSize_32x32,
			SpriteColorFormat_256Color, 
			entity,
			-1, 
			false, 
			false,
			false,
			false, 
			false);
	//	entity.position+= Vector2(1,0);
	//	if(entity.position.x > SCREEN_RIGHT)
	//	{
	//		entity.position=Vector2(0,0);
	//	}

		touchRead(&touchXY);

	//	entity.RenderInLowerScreen((void*)womanPal,0);
	//	ground.RenderInLowerScreen((void*)GroundPal,1);

		game.Update();
		engine.UpdateScreens();
	}

	return 0;
}
