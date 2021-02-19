//developed by HuangYZ
#ifndef GsLIB_GFX_EXTEND
#define GsLIB_GFX_EXTEND


#define SCREEN_W	240
#define SCREEN_H	160


#define RGB(r,g,b) ((r)+((g)<<5)+((b)<<10))

#define SetPix(x,y,c) 	GsSetPix(x,y,c)

typedef struct GsDOT
{
	u8 x,y;			//XY����
	u16 color;		//��ɫ
}GsDOT;

typedef struct GsLINE				//��
{
	s16 sx,sy;		//Դ
	s16 dx,dy;		//Ŀ
	u16 color;		//��ɫ
}GsLINE;


typedef struct GsTRIANG				//������
{
	u8 x1,y1;
	u8 x2,y2;
	u8 x3,y3;
	u16 color;
}GsTRIANG;


typedef struct GsBOX				//�ı���
{
	u8 sx,sy;		//Դ
	u8 dx,dy;		//Ŀ
	u16 color;		//��ɫ
}GsBOX;

typedef struct GsCIRCLE				//Բ
{
	u8 x,y;
	u16 radius;
	u16 color;
}GsCIRCLE;


typedef struct GsELLIPSE		//��Բ
{
	u8  x,y;
	u8	rx,ry;
	u16 color;
}GsELLIPSE;
//MAP

//��MAP����BGNO�� // loc ��0~31		palno��ѡ��ĵ�ɫ�̱��
void GsLoadBgMapSelectPal(const u16 *map,u16 size,u8 locate,u8 palno);

//v2.5

typedef struct GsBgMapPro
{
	const u16 *map;
	u16 size;				//MAP���ݳ���
	u8 locate;				//���ĸ��鿪ʼ
	u8 palno;				//ѡ���ɫ��
	u16 offset;				//��ʾTILE����ƫ����
}GsBgMapPro;


typedef struct GsCameraMan	//������ṹ
{
	//map��������
	const u16 *pmapdata;	//MAP����
	u16 Hsize;				// (��ͼ��С / 8)
	u16 Vsize;				// (��ͼ��С / 8)
	u8 locate;				//����λ��
	//OFFSET
	int offsetX;			//����������ͼ�ϵ�X
	int offsetY;			//����������ͼ�ϵ�Y
}GsCameraMan;

void GsSetCamera(u8 bgno,GsCameraMan *p);		//����һ�������λ��

//��MAP��������VRAM �߼�Ӧ�ú���
void GsLoadBgMapAdvance(GsBgMapPro *mp);
//��TILE��������VRAM��ĳ����
void GsLoadBgTileOffset(const u8 *tile,u16 size,u8 locate,u16 offset);
//������̬MAP����
void GsCreateDMap(u8 locate,u16 offset,u8 wide,u8 x,u8 y,u8 palno);

//����Ŀ�ĵ�MAP
void GsLoadRectMap(const u16 *map,u16 mapheight,u16 mapwidth,u16 startH,u16 startV,u8 locate);


//MODE4 ����ͼ�κ���///////////////////////////////////////////////////////////////////////////


//ֱ�ӻ���
extern void Line(s16  x1,s16  y1,s16  x2,s16  y2,u16 color);
extern void GsSortLine(GsLINE *line);		//����
extern void GsSortBox(GsBOX *box);			//������
extern void GsSortCircle(GsCIRCLE *cir);	//��Բ
extern void GsSortEllipse(GsELLIPSE *esp);	//����Բ
extern void GsFill(u8 x,u8 y,u8 fillColor,u8 oldColor);



//��ɫ����ǿָ��////////////////////////////////////////////////////////////
//��ɫ����end->start�������һ��

//addr :   BG_PLTT ,  OBJ_PLTT
extern void GsLoadBgPalEx(const u16 *addr,u8 start,int size);		//ֱ������BGPAL��Ӧλ��
extern void GsLoadObjPalEx(const u16 *addr,u8 start,int size);		//ֱ������OBJPAL��Ӧλ��	2.5
extern void GsPalRotate(u16 *addr,u8 start ,u8 end);		//��������
extern void GsPalColorFadeIn(u16 *addr,u8 start ,u8 num);	// FADE IN ����.
extern void GsPalColorFadeOut(u16 *addr,u8 start,u8 num);	// FADE OUT ����.
//SRC��DEC��ɫ��ƥ��.
extern void GsPalColorFade(u16 *addr,u16 *descpal,u8 start,u8 num);



#endif