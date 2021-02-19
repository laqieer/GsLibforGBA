//
#ifndef GsGBA_GFX_H
#define GsGBA_GFX_H

//mode
#define MODE_0			DISP_MODE_0 | DISP_OBJ_BG_ALL_ON
#define MODE_1			DISP_MODE_1 | DISP_BG0_ON | DISP_BG1_ON | DISP_BG2_ON | DISP_OBJ_ON
#define MODE_2			DISP_MODE_2 | DISP_BG2_ON | DISP_BG3_ON | DISP_OBJ_ON
#define MODE_3			DISP_MODE_3 | DISP_BG2_ON | DISP_OBJ_BG_ALL_ON
#define MODE_4			DISP_MODE_4 | DISP_BG2_ON | DISP_OBJ_BG_ALL_ON
#define MODE_5		    DISP_MODE_5 | DISP_OBJ_BG_ALL_ON
#define Gs_BG_COLOR16  0
#define Gs_BG_COLOR256 1
#define Gs_BG_TEXT_SIZE_256x256		0
#define Gs_BG_TEXT_SIZE_512x256		1
#define Gs_BG_TEXT_SIZE_256x512		2
#define Gs_BG_TEXT_SIZE_512x512		3
#define Gs_BG_AFFINE_SIZE_128x128   0
#define Gs_BG_AFFINE_SIZE_256x256   1
#define Gs_BG_AFFINE_SIZE_512x512   2
#define Gs_BG_AFFINE_SIZE_1024x1024 3

// DISPCNT DEFINE

#define BACKBUFFER		BIT04
#define H_BLANK_OAM		BIT05 
#define FORCE_BLANK		BIT07


extern u16 *VideoBuffer		;



//MODE_0.....MODE_5
#define GsSetMode(mode)	REG_DISPCNT = (mode)
#define GsGetTileSize(tile)  (sizeof(tile)/0x800 + 1)

//��ɫ�̺���
//����BG��ɫ��256ɫ
// pal   : �����ɫ�̵ĵ�ַ
// count : �����ֽ���
void GsLoadBgPal(const u16 *pal,int count);


//����BG��ɫ��16ɫ
//pal : �����ɫ�̵ĵ�ַ
//no  : Ŀ���
void GsLoadBgPal16(const u16 *pal,int no);

//����OBJ��ɫ��256ɫ	
//����	����
void GsLoadObjPal(const u16 *pal,int count);

//����OBJ��ɫ��16ɫ
//����	,λ��
void GsLoadObjPal16(const u16 *pal,int no);

//��ʼ��

void GsClearRamAll( void );
void GsClearWorkRam( void );
void GsClearGraphicRam( void );
void GsClearVram( void );
void GsClearOamRam( void );
void GsClearPaletteRam( void );


//����ΪMODE0~2����

//map����
//����ʼ��BG
void GsInitBG();		

//��MAP����BGNO�� // loc ��0~31
void GsLoadBgMap(const u16 *map,u16 size,u8 locate);

//��TILE����BGNO�� // loc ��0~3
void GsLoadBgTile(const u8 *tile,u16 size,u8 locate);

//����BGģʽ
void GsSetBg(int bgno,int size,int colormode,int charbase,int scbase,int mosaic);

//����BG���ȼ�
void GsBgPriority(int bgno,int prio);

//��/��ĳһBG
void GsSetBgState(int bgno,u8 state);

//����BG
void GsBgOffset(int bgno,  u16 x , u16 y);

//MODE1��MODE2��ʱ BG2��BG3  ר��

//��ʼ��һ���仯����
void GsBgAffineInit(GsBGAffine *aff);

//�����仯����
void GsBgAffine(int bgno,  GsBGAffine *aff);

//�仯Ӱ��BG
void GsBgMakeAffine(int bgno,GsBGAffine *aff);

//��ʼ����תBG�Ļ�����
void GsBgAffineRegInit(int bgno);	

//����BGΪƽ��
void GsSetBgLoop(int bgno,u8 flag);


//-----------------------------------------------------------------------------
//����ȫΪMODE4ר�ú���

//����
void GsSetPix(u8 x,u8 y,u16 color);

//���� ����Ļ��ĵ㲻�ᱻ��ʾ
void GsSetPixLimit(u8 x,u8 y,u16 color);

//�ȴ�
void GsWaitSync(void);

//��ת
void GsFlip();

//ͼ������,	//MODE3,4ר��
void GsSortImage(const u16 *IndexData, unsigned long size);


//�������
void GsClearBackBuffer(void);


//��Ч

//������������Ч
void GsSetMosaic(u8 bh,u8 bv,u8 oh,u8 ov);

//����ALPHA��϶�
void GsSetAlpha(u8 ap_eva,u8 ap_evb);

//��������						dark		light
void GsSetBright(s16 level);	// -15 ~ 15 
//����Ŀ��
void GsSetEffect(u16 tg1,u16 tg2);

//�ر���Ч
void GsCloseEffect();



//  ����

void GsCreateWin(u8 winno,u8 x1,u8 y1,u8 x2,u8 y2,u8 INWINDOW,u8 OUTWINDOW,u8 fx0_on,u8 fx1_on);
void GsReleaseWin();

void GsSetWinState(u8 winno,u8 state);

#endif

  