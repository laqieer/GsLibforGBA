//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      map demo1		MODE0
// 
// ����:      EyesOnMe   
//
// ʹ��:      GsLoadmap     ����map
//
// ʹ��:      
//
// ʹ��:      
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include "gfx\master.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	0					//Ĭ��TILE����λ��
#define locate 30                                                //Ĭ��MAP����λ��

//����
void queryKey();							//��ѯ����
//������ʾBG����
int fx,fy;

//������ʾ�����˼���
u8 msc=0;
									//����X��Y
//�ж�������
const IntrFuncp IntrTable[14];

//������
int AgbMain()
{

	u16 timer;					
	
	
	

	GsBGAffine bgaff;

	//����BGģʽΪ0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_2D_MAP);
	//��ʼ��BG
	GsInitBG();
	//����BGPAL
	GsLoadBgPal(master_Palette,256);
	
	//����BGMAP ��30��λ��
	GsLoadBgMap ( sample_Map   , sizeof(sample_Map)   , locate );
	
	//����BGTILE
	GsLoadBgTile( sample_Tiles , sizeof(sample_Tiles) , DefaultCharBase  );
	
	//����BG�Ĵ���
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, DefaultCharBase ,locate , 1);

	//�������ȼ�	��ʽ�� GsBgPriority(������,���ȼ�);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//��ѭ��
	while(1)								
	{

	//��ѯ����
	if(timer%20==0)						
		queryKey();

	//���þ���
	 GsBgOffset(0,fx,fy);
		
	//�ȴ�ͬ��
	GsWaitSync();

	timer++;							//��ʱ
	if(timer>65535) timer=0;			//�������
	}
        
        return 0;
}

void queryKey()
{
    KeyRead();						//������

		if(Cont & U_KEY)			
		fy--;
			
		if(Cont & D_KEY)
		fy++;
		if(Cont & L_KEY)
		fx--;

		if(Cont & R_KEY)
		fx++;


		if(Trg & R_BUTTON) 
        {
			msc++;
			GsSetMosaic(msc,msc,0,0);
		}
		if(Cont & L_BUTTON);
		   
		if(Trg & A_BUTTON);
		if(Trg & START_BUTTON);
	    if(Trg & SELECT_BUTTON);
	
}
