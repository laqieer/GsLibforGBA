#ifndef  GBA_SPRITE_H
#define GBA_SPRITE_H


//��־
#define Gs_OBJ_MODE0_START_CHARNO 0
#define Gs_OBJ_MODE3_START_CHARNO 512
//��״
#define Gs_OAM_SQUARE 0
#define Gs_OAM_HRECT  1
#define Gs_OAM_VRECT  2
//��С
#define Gs_OAM_SMALL  0
#define Gs_OAM_MIDDLE 1
#define Gs_OAM_BIG    2
#define Gs_OAM_LARGE  3

//ɫ��ģʽ
#define Gs_OAM_COLOR16  0
#define Gs_OAM_COLOR256 1

//ģʽ
#define Gs_OAM_NORMAL   0
#define Gs_OAM_SEMI		1
#define Gs_OAM_WINDOW   2
//��Чģʽ
#define Gs_OAM_ROTATE_ENABLE 3

//char�������
#define Gs_OAM_MODET_CHAR_C16  1024
#define Gs_OAM_MODET_CHAR_C256 512
#define Gs_OAM_MODEB_CHAR_C16  512
#define Gs_OAM_MODEB_CHAR_C256 256

// OBJ
//��CHAR���ݴ��䵽VRAM��OBJ RAMλ��
#define GsLoadObjChar(src,mode)			DmaArrayCopy(3, src, mode, 32)
//�õ�CHAR���ݵĴ�С
#define GsGetObjSize16(src)				(sizeof(src)/32)
#define GsGetObjSize256(src)			(sizeof(src)/64)

//define function

extern SPRITE	OAM_Buffer[128];						//OAM����

extern void GsLoadObjTile(const u8 *src,u16 size,int loc,int COLORDEP); //����TILE ,�ŵ�OBJRAM��LOCλ��
extern void GsOamCopy();										//����OAM��
extern void GsSortSPRITE(GsSPRITE *p);							//��OBJ���Ƶ���Ļ��
extern void GsKillSPRITE(GsSPRITE *p);							//��OBJɾ��
extern void GsAffineSelectParameter(GsSPRITE *p,u8 no);			//ѡ��һ������任������
extern void GsAffineSPRITE(GsSPRITE *p,GsSPRITEAffine *affsrc);	//���÷���任���� no = 0~31
extern void GsScaleSPRITE(GsSPRITE *p,GsSPRITEAffine *affsrc);		//���÷������� no = 0~31	//syscall 
extern void GsCloseSPRITEAffine(GsSPRITE *p);					//�ر�ĳ��OBJ����ת��������


#endif