
//{{BLOCK(Balloon)

//======================================================================
//
//	Balloon, 512x64@8, 
//	+ palette 256 entries, not compressed
//	+ 512 tiles Metatiled by 4x4 not compressed
//	Total size: 512 + 32768 = 33280
//
//	Time-stamp: 2023-01-02, 18:08:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.1
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BALLOON_H
#define GRIT_BALLOON_H

#define BalloonTilesLen 32768
extern const unsigned int BalloonTiles[8192];

#define BalloonPalLen 512
extern const unsigned short BalloonPal[256];

#endif // GRIT_BALLOON_H

//}}BLOCK(Balloon)
