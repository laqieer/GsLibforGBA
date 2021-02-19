//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      SPRITE DEMO 
// 
// ����:      HuangYZ   
//
// ʹ��:      GsSortSPRITE(&myspr);
//	
//			  GsAffineSPRITE(&myspr,&myAff);//������OBJ
//	
//			  GsOamCopy();   //��OAM���濽����OAM RAM
//
// 
//
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����OBJͼ������
#include "gfx\sprite.c"

//����
void queryKey();							//��ѯ����
void init_spr();							//��ʼ��SPRITE

//ȫ�ֱ���
GsSPRITE			myspr;					//���������ʹ�õ�OBJ
GsSPRITEAffine		myAff;					//���������ʹ�õ�OBJ�仯����

//�ж�������
const IntrFuncp IntrTable[14] = 
{
	queryKey,	// V Blank interrupt 
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


//������
int AgbMain()
{

	//���������ж�����
	GsOpenIRQ();

	//����BGģʽΪ0
	GsSetMode( MODE_0 |DISP_OBJ_CHAR_1D_MAP);					
	
	//��ROM��ѵ�ɫ�����ݶ���PALRAM
	GsLoadObjPal(sprite_Palette,256);
	
	//��ROM���TILE���ݶ����Դ�
	GsLoadObjChar( sprite_Char,OBJ_MODE0_VRAM );


	//�����ʼ��
	init_spr();								

	//��ѭ��
	while(1)								
	{

	//��ʾ���OBJ
	GsSortSPRITE(&myspr);
	//������OBJ
	GsAffineSPRITE(&myspr,&myAff);
	
	
	//��OAM���濽����OAM RAM
	GsOamCopy();
	//�ȴ�ͬ��
	GsWaitSync();
		
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//������

	if(Cont & B_BUTTON)
	{
		if(Cont & U_KEY)myAff.RatioY--;
		if(Cont & D_KEY)myAff.RatioY++;
		if(Cont & L_KEY)myAff.RatioX--;
		if(Cont & R_KEY)myAff.RatioX++;
	}
	else
	{
//�ƶ�����
	//	OBJ�ṹ�е�VPOS��ʾ�ڴ�ֱ��������
	//	OBJ�ṹ�е�HPOS��ʾ�ڴ�ֱ��������

		if(Cont & U_KEY)myspr.obj.VPos--;
		if(Cont & D_KEY)myspr.obj.VPos++;
		if(Cont & L_KEY)myspr.obj.HPos--;
		if(Cont & R_KEY)myspr.obj.HPos++;
	}

	if(Cont & R_BUTTON)
		myAff.Theta = (myAff.Theta-1)&0xff;
   
	if(Cont & L_BUTTON)
		myAff.Theta = (++myAff.Theta)&0xff;  
   
   if(Trg & A_BUTTON)
   {
	   if(myspr.obj.AffineMode&0x2==0x2)
		   myspr.obj.AffineMode|=0x2;
	   else
		   myspr.obj.AffineMode&=0x1;
   }


  if(Trg & START_BUTTON)
	  init_spr();

  if(Trg & SELECT_BUTTON);
  	  

}

void init_spr()							//��ʼ��
{
	myspr.ID=0;							//����λ��
	
	myspr.obj.HPos		=50;			//����h����(��)����
	myspr.obj.VPos		=50;			//����v����(��)����
	myspr.obj.Shape		=Gs_OAM_SQUARE; //����OBJ��״ΪSQUARE
	myspr.obj.Size		=Gs_OAM_LARGE;	//���ô�С,�޴�
	myspr.obj.CharNo	=0;				//����TILE��ʼ��
	myspr.obj.Pltt		=0;				//ѡ��0�ŵ�ɫ��
	myspr.obj.Priority	=0;				//���ȼ���Ϊ���
	myspr.obj.ColorMode	=Gs_OAM_COLOR16;//16ɫ
	myspr.obj.AffineMode=Gs_OAM_NORMAL; //����ģʽΪ����ģʽ
	myspr.obj.Mosaic	=TRUE;			//������������Ч


	myspr.obj.AffineMode=Gs_OAM_ROTATE_ENABLE;	//��ת/��������
	myspr.obj.AffineParamNo_L=0;		//��ת/�����任,������0
	
	myAff.RatioX		=0x100;			//����X�������������ʼ��
	myAff.RatioY		=0x100;			//����Y�������������ʼ��
	myAff.Theta			=0;				//������ת������ʼ��
}

