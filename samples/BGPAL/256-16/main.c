//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      MODE0�µ�16ɫ��256ɫBG����ʾ
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



				//Ĭ��TILE����λ��

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

        //����BG0��16ɫPAL��6�ŵ�ɫ��
	GsLoadBgPal16(img_Palette,6);
        //����BG0��MAP����
	GsLoadBgMap ( img_Map   , sizeof(img_Map)   , 30 );
	//ָ��BG0�ĵ�ͼʹ��6��ɫ��
        GsLoadBgMapSelectPal( img_Map   , sizeof(img_Map)   , 30 ,6);
        //����BG0��TILE����
	GsLoadBgTile( img_Tiles , sizeof(img_Tiles) , 0  );
	//����BG0�ļĴ���
        GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,30 , 0);
	
	//��������BG0�ĵ�ͼPAL(��ɫ�������Լ���)   ��ʽ����ɫ�壬��ʼ��ַ������
        //��Ϊ256ɫͼƬһ��������ò���256����ɫ���������ɷ�����ɫ�����ڽ�ʡPAL
	GsLoadBgPalEx(win_Palette,0,56);
	GsLoadBgMap ( win_Map   , sizeof(win_Map)   , 28 );
	GsLoadBgTile( win_Tiles , sizeof(win_Tiles) , 1  );
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 1 ,28 , 0);
         
        
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
