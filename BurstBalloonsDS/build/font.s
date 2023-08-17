
@{{BLOCK(font)

@=======================================================================
@
@	font, 8x768@4, 
@	+ palette 16 entries, not compressed
@	+ 96 tiles not compressed
@	Total size: 32 + 3072 = 3104
@
@	Time-stamp: 2023-08-17, 14:49:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global fontTiles		@ 3072 unsigned chars
	.hidden fontTiles
fontTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00021100,0x00023100,0x00023400,0x00026500,0x00022200,0x00027700,0x00028800,0x00022200
	.word 0x00212100,0x00212100,0x00232300,0x00222200,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x02102100,0x24444440,0x22522520,0x02302300,0x27777770,0x22722720,0x02202200
	.word 0x00021000,0x00111110,0x24924294,0x222A5850,0x00383A00,0x27627267,0x2A777772,0x02227220
	.word 0x00000000,0xA1002110,0x29402330,0x02652220,0x00263000,0x27726700,0x28802670,0x222002A0
	.word 0x00009100,0x00291010,0x002294A0,0xA5025650,0x26830263,0x02780027,0xA7268772,0x22022220
	.word 0x02911000,0x02910000,0x00294000,0x00022000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x02910000,0x00294000,0x00025000,0x00023000,0x000A7000,0x02672000,0x02220000
	.word 0x00000000,0x00091000,0x00242000,0x00250000,0x00230000,0x00270000,0x00267000,0x00022000
	.word 0x00021000,0x0A121210,0x02A43420,0x002A5200,0x00A38300,0x0A727A70,0x02227220,0x00022000
	.word 0x00023000,0x00021000,0x00024000,0x28555555,0x22223222,0x00027000,0x00027000,0x00022000
	.word 0x00000000,0x00000000,0x00000000,0x00A88000,0x00A33000,0x00272000,0x00267000,0x00022000
	.word 0x00000000,0x00000000,0x00000000,0x28555555,0x22222222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00277000,0x00288000,0x00222000
	.word 0x00000000,0x00000000,0x0A400000,0x02650000,0x00263000,0x00026700,0x00002670,0x00000220

	.word 0x00311110,0x23192291,0x24400024,0x25500025,0x23300023,0x28760067,0x2A877772,0x02222220
	.word 0x00213000,0x00211300,0x00244000,0x00255000,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x00311110,0x23192291,0x23400022,0x2A858000,0x022A8380,0x00022678,0x27777777,0x22222222
	.word 0x00311110,0x23192291,0x24400022,0x22555500,0x233A2000,0x28760067,0x2A877772,0x02222220
	.word 0x02110000,0x02111000,0x02449400,0x02552650,0x02330263,0x27777777,0x22772222,0x02220000
	.word 0x02111113,0x02222213,0x00344444,0x28562A85,0x23300222,0x28700067,0x2A877772,0x02222220
	.word 0x00211300,0x00229110,0x00344443,0x285A2655,0x23800283,0x28700678,0x22877782,0x02222220
	.word 0x21111111,0x211A2222,0x29440000,0x02658000,0x00A33000,0x00277000,0x00277000,0x00222000

	.word 0x00311130,0x031A2913,0x23400A43,0x22855580,0x03322A33,0x27700677,0x22777772,0x02222220
	.word 0x00311130,0x031A2913,0x24300234,0x25502658,0x28333380,0x26776200,0x02A87700,0x00222200
	.word 0x00000000,0x00211000,0x00233000,0x00222000,0x00233000,0x00288000,0x00222000,0x00000000
	.word 0x00000000,0x00A33000,0x00A44000,0x00250000,0x00263000,0x00222000,0x00000000,0x00000000
	.word 0x0A100000,0x02910000,0x00294000,0x00026500,0x000A3200,0x00A72000,0x0A720000,0x02200000
	.word 0x00000000,0x00000000,0x23444444,0x22222222,0x28333333,0x22222222,0x00000000,0x00000000
	.word 0x000A1000,0x00A12000,0x0A420000,0xA5200000,0x26300000,0x02670000,0x00267000,0x0002A000
	.word 0x00011100,0x001A2910,0x02400240,0x02650200,0x00263000,0x00020000,0x000A7000,0x00020000

	.word 0x00111100,0x01922910,0x49244294,0x50226525,0x30006323,0x70277267,0x67222672,0x26777720
	.word 0x02911190,0x02139310,0x0A492940,0x295A0A59,0x28333338,0x27722277,0x27800287,0x22200222
	.word 0x00311111,0x23192211,0x24100244,0x2A555555,0x23322233,0x287A0277,0x2A877777,0x02222222
	.word 0x0A111190,0xA192A119,0x20002A44,0x00000255,0x00000A33,0xA7602776,0x26777762,0x02222220
	.word 0x00931111,0x0911A211,0x24420244,0x25500255,0x23300233,0x2677A277,0x02687777,0x00222222
	.word 0x21111111,0x22222211,0x00000244,0x02855555,0x02222233,0x00000277,0x07777777,0x22222222
	.word 0x21111111,0x22222211,0x00000244,0x02855555,0x02222233,0x00000277,0x00000277,0x00000222
	.word 0x0A111190,0xA192A119,0x20002A44,0x25550255,0x23320A33,0x27702776,0x26777762,0x02222220

	.word 0x21100211,0x21100211,0x24100244,0x25555555,0x23322233,0x27700277,0x28800277,0x22200222
	.word 0x00021100,0x00021100,0x00024400,0x00025500,0x00023300,0x00027700,0x00028800,0x00022200
	.word 0x21100000,0x21100000,0x24400000,0x25500000,0x23300000,0x28780000,0x22877772,0x02222220
	.word 0x09100211,0x02310211,0x00234244,0x00028555,0x00A83233,0x0A872277,0xA8720288,0x22200222
	.word 0x00000211,0x00000211,0x00000244,0x00000255,0x00000233,0x00000277,0x28777777,0x22222222
	.word 0x21900291,0x21192911,0x24443444,0x25585855,0x238A3A83,0x27822287,0x28800287,0x22200222
	.word 0x21100011,0x21100111,0x24404344,0x25558A55,0x23382233,0x27720277,0x28800277,0x22000222
	.word 0x0A31113A,0x231A2A13,0x24420244,0x25500255,0x23300233,0x287A2A78,0x2A87778A,0x02222220

	.word 0x09111111,0x21122211,0x24400244,0x26555555,0x02222233,0x00000277,0x00000277,0x00000222
	.word 0x0A31113A,0x231A2A13,0x24420244,0x25500255,0x283A7233,0x2A772A78,0x27A8778A,0x02222220
	.word 0x09111111,0x21122211,0x24400244,0x26555555,0x02382233,0x28720277,0x28700277,0x22200222
	.word 0x00111119,0x21922A11,0x22000244,0x06555556,0x233A2220,0x27700687,0x26777772,0x02222220
	.word 0x31111111,0x22211222,0x00244000,0x00255000,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x23300211,0x21100211,0x24400244,0x25500255,0x23300233,0x28762678,0x2A877782,0x02222220
	.word 0x21300291,0x21100231,0x29400243,0x02552852,0x02632380,0x00277720,0x00267800,0x00022200
	.word 0x21300231,0x21300231,0x24304234,0x25858585,0x2338A333,0x27822A77,0x282002A7,0x22000022

	.word 0x31000031,0x23100312,0x02343420,0x00285200,0x00838300,0x08722870,0x87200287,0x2200002A
	.word 0x10000013,0x91000132,0x29494320,0x02655200,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x23111111,0x22312222,0x02234000,0x00228500,0x00022830,0x00002287,0x27777777,0x22222222
	.word 0x02311100,0x02223100,0x00023400,0x00028500,0x00028300,0x00028700,0x02877700,0x02222200
	.word 0x000000A1,0x00000912,0x00009420,0x00065200,0x00632000,0x06720000,0xA7200000,0x22000000
	.word 0x02311100,0x02312200,0x02340000,0x02850000,0x02830000,0x02870000,0x02877700,0x02222200
	.word 0x00000000,0x000A1000,0x00A49400,0x0A522650,0x02200220,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x28777777,0x22222222

	.word 0x00911000,0x00221000,0x00249000,0x00220000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00344400,0x08522000,0x28333300,0x28722870,0x27777700,0x22222000
	.word 0x00000110,0x00002110,0x00444440,0x05822550,0x23002330,0x27602770,0x26777770,0x02222200
	.word 0x00000000,0x00000000,0x0A444300,0x2562A580,0x22002330,0x2700A780,0x26777820,0x02222200
	.word 0x21100000,0x21100000,0x24444400,0x25522850,0x23300230,0x27700670,0x277777A0,0x22222200
	.word 0x00000000,0x00000000,0x00344300,0x28222580,0x23333330,0x22222780,0x027778A0,0x02222200
	.word 0x2313A000,0x22213000,0x23444440,0x22255220,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x00000000,0x00000000,0x02344400,0x28522650,0x23300630,0x27777720,0x28722200,0x26877700

	.word 0x00002110,0x00002110,0x00444440,0x25822550,0x23002330,0x27002770,0x27002770,0x22002220
	.word 0x00211000,0x002AA000,0x00233000,0x00255000,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x00211000,0x002AA000,0x00233000,0x00255000,0x00233000,0x00277000,0x00287000,0x002A7870
	.word 0x00002110,0x00002110,0x23402440,0x22852550,0x02283330,0x00872770,0x08722770,0x22202220
	.word 0x00231100,0x00211000,0x00244000,0x00255000,0x00233000,0x00277000,0x00277000,0x00222000
	.word 0x00000000,0x00000000,0x0A4A4940,0x25858550,0x23232830,0x27272870,0x27272870,0x22222220
	.word 0x00000000,0x00000000,0x00444340,0x25822550,0x23202830,0x27002870,0x27002870,0x22002220
	.word 0x00000000,0x00000000,0x00444300,0x25626580,0x23002330,0x27006780,0x26777820,0x02222200

	.word 0x00000000,0x00000000,0x09444440,0x25622550,0x23602330,0x26777770,0x02222770,0x00002770
	.word 0x00000000,0x00000000,0x24444490,0x25522650,0x23300630,0x27777760,0x27722200,0x27700000
	.word 0x00000000,0x00000000,0x24493400,0x22655500,0x00228300,0x00028700,0x00028700,0x00022200
	.word 0x00000000,0x00000000,0x02444300,0x02222580,0x06333800,0x27722000,0x26777770,0x02222220
	.word 0x00000000,0x00211000,0x24444440,0x22255220,0x00233000,0x00278000,0x0778A000,0x22220000
	.word 0x00000000,0x00000000,0x24400240,0x25500250,0x23300230,0x28700870,0x26877720,0x22222200
	.word 0x00000000,0x00000000,0x24400240,0x28500A80,0x26332360,0x2287A800,0x02677600,0x00222000
	.word 0x00000000,0x00000000,0x24002340,0x25252850,0x23232380,0x28676760,0x22767620,0x02222200

	.word 0x00000000,0x00000000,0x29400940,0x22856520,0x02283200,0x00678700,0x06722670,0x22202220
	.word 0x00000000,0x00000000,0x24400240,0x25500250,0x28300830,0x28777720,0x26782200,0x22687770
	.word 0x00000000,0x00000000,0x23444440,0x22852220,0x02283000,0x00228700,0x27777770,0x22222220
	.word 0x00219000,0x002A1000,0x00024000,0x00026500,0x00003200,0x000A7000,0x00276000,0x00220000
	.word 0x00023000,0x00021000,0x00024000,0x00025000,0x00023000,0x00027000,0x00027000,0x00022000
	.word 0x00009100,0x00021200,0x00024000,0x00256000,0x00263000,0x00027000,0x00026700,0x00002200
	.word 0x00000000,0x21021100,0x29432940,0x02220220,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global fontPal		@ 32 unsigned chars
	.hidden fontPal
fontPal:
	.hword 0x0000,0x7BFF,0x1420,0x6673,0x779C,0x6E92,0x3CE5,0x5D49
	.hword 0x4CC6,0x4926,0x2C63,0x7FFF,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(font)
