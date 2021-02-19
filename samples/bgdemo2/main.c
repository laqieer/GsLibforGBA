//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      map demo2		MODE1
// 
// ����:      HuangYZ   
//
// ʹ��:      GsLoadmap     ����map
//
// ʹ��:      GsLoadtils    ����TILES
//
// -------------- ���ʹ��IGBA���Ա�DEMO ---------------------------
// ����3������:
//	1		��ʼ��BGCNT��BGAFFINE����
//	2		�����仯��������
//  3		��ѭ����ͨ���仯�����ı�BGAFFINE�Ĵ����ﵽЧ��
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include "gfx\sam.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	3					//Ĭ��TILE����λ��
#define DefaultMapBase	8					//Ĭ��MAP����λ��

//����
static void queryKey();							//��ѯ����
//����

GsBGAffine affe;							//����BG�仯����

//�ж�������
const IntrFuncp IntrTable[14]=
{
	queryKey,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy
};

//������
int AgbMain()
{

	GsBGAffine bgaff;

	//�������ж�
	GsOpenIRQ();
	//����BGģʽΪ0
	GsSetMode( MODE_1 |DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();	//��ʼ��BG

	GsLoadBgPal ( sam_Palette	 , 256	);//����BGPAL
	GsLoadBgMap ( (u16*)sam_Map		 , sizeof(sam_Map)   , DefaultMapBase   );//����BGMAP ��8��λ��
	GsLoadBgTile( sam_Tiles		 , sizeof(sam_Tiles) , DefaultCharBase  );//����BGTILE


	//����BG2
	GsSetBg(2 , Gs_BG_AFFINE_SIZE_128x128 , Gs_BG_COLOR256, DefaultCharBase ,DefaultMapBase , ON);
	//��BG2���ó�ƽ��
	GsSetBgLoop(2,TRUE);	

	//�������ȼ�	��ʽ�� GsBgPriority(������,���ȼ�);
	GsBgPriority(2,0);

	//��ʼ��BG2
	GsBgAffineRegInit(2);

	//��ʼ�� �仯����
	GsBgAffineInit(&affe);

	

	while(1)								
	{
	//�ȴ�ͬ��
	GsWaitSync();
	}

	return 0;
}

void queryKey()
{
    KeyRead();						//������


    if( Cont & B_BUTTON )
    {

	    //  Scale using + Cotrol Pad

	if (Cont & U_KEY)
	{
	    affe.bg_scale_y += 0x10;
	}
	if (Cont & D_KEY)
	{
	    affe.bg_scale_y -= 0x08;
	}
	if (Cont & L_KEY)
	{
	    affe.bg_scale_x -= 0x08;
	}
	if (Cont & R_KEY)
	{
	    affe.bg_scale_x += 0x10;
	}

    }
    else
    {

	    //  Move using + Control Pad

	if (Cont & U_KEY)
	{
	    affe.bg_pos_y -= 2;
	}
	if (Cont & D_KEY)
	{
	    affe.bg_pos_y += 2;
	}
	if (Cont & R_KEY)
	{
	    affe.bg_pos_x += 2;
	}
	if (Cont & L_KEY)
	{
	    affe.bg_pos_x -= 2;
	}


    }

		    // Rotate using LR button 

	if ( Cont & R_BUTTON )
	{
	    ++affe.bg_rotate ;
	}
	if ( Cont & L_BUTTON )
	{
	    affe.bg_rotate = affe.bg_rotate+0xff;
	}

	GsBgAffine(2,&affe);		//�����仯����

	GsBgMakeAffine(2,&affe);	//���ñ仯
		

	
}
