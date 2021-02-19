//-----------------------------------------------------------------//
//                     GsLIB  2.0                           
//
//
// ����:      SPRITE & MAP DEMO 
// 
// ����:      EyesOnMe
//
// ʹ��:      GsSortSPRITE(&myspr);
//	
// ʹ�ã�     GsAffineSPRITE(&myspr,&myAff);//������OBJ
//	
// ʹ�ã�     GsOamCopy();   //��OAM���濽����OAM RAM
//
// ʹ�ã�     GsLoadtils    ����TILES
//
// ʹ�ã�     GsLoadBgMap   ����MAP
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����OBJͼ������
#include "gfx\ani.c"

//����BGͼ������
#include "gfx\text.raw.c"
#include "gfx\text.map.c"

#include "gfx\map.raw.c"
#include "gfx\map.map.c"


#include "gfx\master.pal.c"


//����
void queryKey();							//��ѯ����
void init_spr();							//��ʼ��SPRITE

//ȫ�ֱ���
GsSPRITE			myspr;					//���������ʹ�õ�OBJ
GsSPRITEAffine		myAff;					//���������ʹ�õ�OBJ�仯����

u16 frames=0;     //����֡��
u8 anicnt=0;      //OBJ��֡����
u8 anidir=0;      //OBJ��ָ����

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
	GsSetMode(MODE_0|DISP_OBJ_CHAR_1D_MAP);					
	
        GsInitBG();  //��ʼ��BG
        
 	GsLoadBgPal16(master_Palette,0);      //����BG��16ɫ��ɫ�� 
    
	GsLoadBgMap(map_Map,sizeof(map_Map),25);    //����MAP��30λ��
    GsLoadBgTile(map_Tiles,sizeof(map_Tiles),0);  //����TILE��1λ��


//		GsLoadBgMap(text_Map,sizeof(text_Map),28);    //����MAP��30λ��
  //      GsLoadBgTile(text_Tiles,sizeof(text_Tiles),1);  //����TILE��1λ��
 
   GsSetBg(1,Gs_BG_TEXT_SIZE_512x512,Gs_BG_COLOR16,0,25,0);  
        GsBgPriority(1,1);

        //��ROM��ѵ�ɫ�����ݶ���PALRAM
	GsLoadObjPal16(ani_Palette,2);
	//��ROM���TILE���ݶ����Դ�
	GsLoadObjChar(ani_Char,OBJ_MODE0_VRAM);
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
    if((frames%2)==0)
           {myspr.obj.CharNo=anidir+16*(anicnt%2);anicnt++;}   //����OBJ��֡������OBJ����
    if(frames>=65535) frames=0; else frames++;  //��ֹ֡�����
    
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

		if(Cont & U_KEY) {myspr.obj.VPos--;anidir=0;}
		if(Cont & D_KEY) {myspr.obj.VPos++;anidir=64;}
		if(Cont & L_KEY) {myspr.obj.HPos--;anidir=96;}
		if(Cont & R_KEY) {myspr.obj.HPos++;anidir=32;}
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
	myspr.obj.Size		=Gs_OAM_BIG;	//���ô�С,�޴�
	myspr.obj.CharNo	=0;				//����TILE��ʼ��
	myspr.obj.Pltt		=2;				//ѡ��2�ŵ�ɫ��
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

