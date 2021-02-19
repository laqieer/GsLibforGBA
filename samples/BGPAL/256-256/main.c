//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      MODE0�µĶ��256ɫBG����ʾ
// 
// ����:      EyesOnMe   
//
// ʹ��:      GsLoadmap     ����map
//
// ʹ��:      GsLoadtils    ����TILES
//
// ʹ��:      GsLoadBgPalEx  ���ɷ�����ɫ��(����256ɫͼƬ,��ʡ256ɫ��PAL�ռ�)
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include "gfx\img.pal.c"
#include "gfx\img.map.c"
#include "gfx\img.raw.c"

#include "gfx\win.pal.c"
#include "gfx\win.raw.c"
#include "gfx\win.map.c"



				

//����
void queryKey();		//��ѯ����

//�ж�������
const IntrFuncp IntrTable[14];


//������
int AgbMain()
{

	
	

	//����BGģʽΪ0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	//��ʼ��BG
	GsInitBG();

	//����BGPAL
	
        //��PAL�����ɷ����BG1 56����ɫ����0(0-255)��ʼ(��ɫ�����Դ�PAL���ļ���������)
	GsLoadBgPalEx(win_Palette,0,56);
	//����BG1��MAP����
        GsLoadBgMap ( win_Map   , sizeof(win_Map)   , 28 );
	//����BG1��TILE����
        GsLoadBgTile( win_Tiles , sizeof(win_Tiles) , 2  );
	//����BG1�ļĴ���
        GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 2 ,28 , 0);

        //��PAL�����ɷ����BG0 56����ɫ����0(0-255)��ʼ
	//�ؼ�������BG��PAL��ַ�����ص�!!!
        GsLoadBgPalEx(img_Palette,56,32);
	GsLoadBgMap ( img_Map   , sizeof(img_Map)   , 30 );
	GsLoadBgTile( img_Tiles , sizeof(img_Tiles) , 0  );
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 0 ,30 , 0);         
        
	//���ø�BG������Ȩ
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//��ѭ��
	while(1)								
	{
         queryKey();
         //�ȴ�ͬ��
	 GsWaitSync();
        }
         return 0;
}

void queryKey()
{
    KeyRead();						//������

		if(Cont & U_KEY)			
		
			
		if(Cont & D_KEY)
		
		if(Cont & L_KEY)
		

		if(Cont & R_KEY)
		


		if(Cont & R_BUTTON);
		if(Cont & L_BUTTON);
		   
		if(Trg & A_BUTTON);
		if(Trg & START_BUTTON);
	    if(Trg & SELECT_BUTTON);
}
