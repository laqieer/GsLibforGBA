#ifndef _GtSPRITE_
#define _GtSPRITE_

typedef struct GtSPRAnim_Frame				//4 byte	only one obj
{
	u16 shape:2;	//��״
	u16 size:2;		//��С
	u16 vflip:1;	//�Ƿ�V��ת
	u16 hflip:1;	//�Ƿ�H��ת
	u16 charno:10;	//CHAR��ַ
	s8  dx;		
	s8  dy;
}GtSPRAnim_Frame;

typedef struct GtSPRFrameList			//only one obj
{
	const GtSPRAnim_Frame *frames;
	u8 MaxFrame;						//���֡
}GtSPRFrameList;

typedef struct GtSPRITE					//һ����Ͼ���
{
	//u8 oam_locate;						//OAMλ��
	const GtSPRFrameList *SubObjFrame;		//֡����
	u8 part;							//һ�������Ĳ�����
}GtSPRITE;

typedef struct GtSPRITERect
{
	u8 width;
	u8 height;
}GtSPRITERect;
//////////////////////////////////////////////////////////////////
typedef struct GtSPRBitmap
{
	const u16 *Paddr;	//��ɫ�̵�ַ
	const u8  *Daddr;	//���ݵ�ַ
	u16  width;
	u16  height;
	u8  ObjPalNo;
	u16 StartChar;
}GtSPRBitmap;

extern u8 GtGetObjSizeW(u8 shape,u8 size);
extern u8 GtGetObjSizeH(u8 shape,u8 size);

extern void GtLoadObjChar2D	(const u8 *p,u16 hc,u16 vc,u16 offset);			//����
extern void GtSPRLoadBitmap	(const GtSPRBitmap *bmp);				//load bmp to OBJVRAM
extern void GtSPRCreate		(const GtSPRITE *p,u8 oam_locate,u8 OBJMODE,u8 PlttNo,u8 prioi);		//����һ�����OBJ
extern void GtSPRSetPal		(const GtSPRITE *p,u8 oam_locate,u8 part,u8 PlttNo);
extern void GtSPRGetSize	(const GtSPRITE *p,GtSPRITERect	*dec);					//�õ����OBJ�Ĵ�С
extern void GtSPRSetAffine	(const GtSPRITE *p,u8 oam_locate,u8 number);			//���÷��������

extern void GtSPRAnimate	(const GtSPRITE *p,u8 oam_locate,u8 part,u8 frame);		//����
extern void GtSPRSetXY		(const GtSPRITE *p,u8 oam_locate,int x,int y);							//ֱ����������
extern void GtSPRMove		(const GtSPRITE *p,u8 oam_locate,int dx,int dy);							//�ƶ�
extern void GtSPRFlipH		(const GtSPRITE *p,u8 oam_locate,u8 part);						//��ת
extern void GtSPRFlipV		(const GtSPRITE *p,u8 oam_locate,u8 part);						//��ת
extern void GtSPRRotate		(const GtSPRITE *p,u8 oam_locate,u8 part,GsSPRITEAffine *affine,u8 AffineNo,u8 centerx,u8 centery,s16 Theta);//��ת

//extern int Adjust(const GtSPRITE *s,u8 oam_locate,u8 desx,u8 desy);



#endif
