//-----------------------------------------------------------------//
//                     GsLIB  2.6                          
//
//
// ����:      ���SPRITE
// 
// ����:      HuangYZ   
//
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����ͼƬ����
#include "gfx\sprite.c"
#include "gfx\death.raw.c"
#include "gfx\death_pal.c"
//�������OBJ�����ļ�
#include "death.h"


#define GtObjOamBase		0				//�������OBJ������OAM��ʼλ��

//����
void queryKey();							//��ѯ����
void loaddeath();
void Animdeath();
void process();

//�ж�������
const IntrFuncp IntrTable[14] = 
{
	process,	// V Blank interrupt 
    dummy,		// H Blank interrupt
    dummy,      // V Counter interrupt
	dummy,		// Timer 0 interrupt
    dummy,      // Timer 1 interrupt
    dummy,      // Timer 2 interrupt
    dummy,      // Timer 3 interrupt
    dummy,      // Serial communication interrupt
    dummy,      // DMA 0 interrupt
    dummy,      // DMA 1 interrupt
    dummy,      // DMA 2 interrupt
    dummy,      // DMA 3 interrupt
	dummy,      // Key interrupt
    dummy,      // Cassette interrupt
};

u8 frame;

u8 deathx,deathy;
s8 dx,dy;
GsSPRITEAffine deathAffine;

//������
int AgbMain()
{
	
	//���������ж�����
	GsOpenIRQ();
	
	GsSetMode( MODE_0 |DISP_OBJ_CHAR_2D_MAP);					

	GsLoadObjPal(death_Palette,256);
	
	//��ROM���TILE���ݶ����Դ�
	//Դ��ַ,��,��,ƫ����
	GtLoadObjChar2D(death_Bitmap,128,128,0);
	
	//�����ʼ��
	
	//����
	deathx=80;
	deathy=80;

	loaddeath();

	//��ѭ��
	for(;;)								
	{
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//������


	if(Cont & U_KEY)dy=-1;
	if(Cont & D_KEY)dy=1;
	if(Cont & L_KEY)dx=-1;
	if(Cont & R_KEY)dx=1;

	if(Trg & R_BUTTON);
	if(Trg & L_BUTTON);
	if(Trg & A_BUTTON)			
		GtSPRFlipH(&death,GtObjOamBase,8);			//����H��ת
		
	if(Trg & B_BUTTON);


	if(Cont & B_BUTTON)
	{
		if(Cont & U_KEY)deathAffine.RatioY--;
		if(Cont & D_KEY)deathAffine.RatioY++;
		if(Cont & L_KEY)deathAffine.RatioX--;
		if(Cont & R_KEY)deathAffine.RatioX++;
		
	}

	if(Cont & R_BUTTON)
	{
		deathAffine.Theta = (deathAffine.Theta-=2)&0xff;
		GtSPRRotate(&death,GtObjOamBase,0,&deathAffine,0,deathx,deathy,1);

	}
   
	if(Cont & L_BUTTON)
	{
		deathAffine.Theta = (deathAffine.Theta+=2)&0xff;  
		GtSPRRotate(&death,GtObjOamBase,0,&deathAffine,0,deathx,deathy,1);


	}

	
}

void loaddeath()
{
	//��ʼ��    ���OBJ,  ��OAM�е�λ��   ����         ��ɫ�̺�    ���ȼ�
	GtSPRCreate(&death,   GtObjOamBase , Gs_OAM_NORMAL, 0   ,       2);
	
	
	//����0�Ų�������ת����
	GtSPRSetAffine(&death,GtObjOamBase,0);
	
	//��������
	GtSPRSetXY(&death,GtObjOamBase,deathx,deathy);

	//���ò���
	deathAffine.RatioX		=0x100;			//����X�������������ʼ��
	deathAffine.RatioY		=0x100;			//����Y�������������ʼ��
	deathAffine.Theta		=0;				//������ת������ʼ��
}

void process()
{
		dx=0;dy=0;


		queryKey();
		frame++;
		
		//�������OBJ�ĵ�8������
		GtSPRAnimate(&death,GtObjOamBase,8,frame>>3);
		//�������OBJ�ĵ�9������
		GtSPRAnimate(&death,GtObjOamBase,9,frame>>3);

		//�ƶ�
		GtSPRMove(&death,GtObjOamBase,dx,dy);

		GsOamCopy();
		GsWaitSync();
}


