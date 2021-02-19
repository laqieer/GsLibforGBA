//-----------------------------------------------------------------//
//                     GsLIB  2.6                          
//
//
// ����:      ALPHA��Ч 
// 
// ����:      HuangYZ   
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include "gfx\ap_bg0.c"				//��ɫ������
#include "gfx\ap_bg0.map.c"			//MAP����
#include "gfx\ap_bg0.raw.c"			//RAW����

#include "gfx\ap_bg1.c"				//��ɫ������
#include "gfx\ap_bg1.map.c"			//MAP����
#include "gfx\ap_bg1.raw.c"			//RAW����

#include "gfx\ap_bg2.c"				//��ɫ������
#include "gfx\ap_bg2.map.c"			//MAP����
#include "gfx\ap_bg2.raw.c"			//RAW����


#define DefaultCharBase	1					//Ĭ��TILE����λ��

//����
void initBG();								//��������BG
void server();								//�жϷ������
void queryKey();							//��ѯ����
int fx,fy,eva,evb;									//����X��Y
int fx1,fy1;									//����X��Y
int fx2,fy2;									//����X��Y



u16 nn;
//�ж�������
const IntrFuncp IntrTable[14] = 
{
	server,	// V Blank interrupt 
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
//	���жϣ�������ʾģʽ����ʼ��BG
	GsOpenIRQ();
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();

//	����BG	
	initBG();
	


//	ʹ��������ѭ��
	for(;;);

	return 0;
}

void queryKey()
{
	
    KeyRead();						//������
	if(Cont)
	{

		if(Cont & U_KEY)			
			fy++;
		if(Cont & D_KEY)
			fy--;
		if(Cont & L_KEY)
			fx++;
		if(Cont & R_KEY)
			fx--;
		
		//���þ���
		GsBgOffset(0, fx,fy);
		//����ALPHA����
		GsSetAlpha(eva,evb);

		
	if(Cont & R_BUTTON)
	{
		evb++;
		eva--;
	}
	if(Cont & L_BUTTON)
	{
		evb--;
		eva++;
	}
	if(Cont & A_BUTTON)eva++;
	if(Cont & B_BUTTON)eva--;
	if(Cont & START_BUTTON)
	{
		eva=16;
		evb=0;
	}
	if(Cont & SELECT_BUTTON)
	{
		eva=0;
		evb=16;
	}
	}
	
	
}

void initBG()
{
	u8  locate;					//�����õ�MAP������λ��
	u8  tileSize;				//�����õ�TILE��ռ���
	
	GsLoadBgPal16(ap_bg0_Palette,0);
	GsLoadBgPal16(ap_bg1_Palette,1);
	GsLoadBgPal16(ap_bg2_Palette,2);

	GsLoadBgMap ( ap_bg0_Map   , sizeof(ap_bg0_Map)   , 29 );
	GsLoadBgTile( ap_bg0_Tiles , sizeof(ap_bg0_Tiles) , 0  );

	GsLoadBgMap ( ap_bg1_Map   , sizeof(ap_bg1_Map)   , 30 );
	GsLoadBgTile( ap_bg1_Tiles , sizeof(ap_bg1_Tiles) , 1  );

	GsLoadBgMap ( ap_bg2_Map   , sizeof(ap_bg2_Map)   , 31 );
	GsLoadBgTile( ap_bg2_Tiles , sizeof(ap_bg2_Tiles) , 2  );
	
	//����BG�Ĵ���
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,29 , 0);
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 1 ,30 , 0);
	GsSetBg(2 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 2 ,31 , 0);

	//�������ȼ�	��ʽ�� GsBgPriority(������,���ȼ�);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//������Ч
	*(vu16*)REG_BLDCNT|=BLD_A_BLEND_MODE;


	GsSetEffect(BLD_BG0_1ST|BLD_BG1_1ST|BLD_BG2_1ST,
		        BLD_BG0_2ND|BLD_BG1_2ND|BLD_BG2_2ND);




}

void server()
{
	queryKey();
	//�ȴ�ͬ��
	GsWaitSync();
}