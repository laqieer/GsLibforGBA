//-----------------------------------------------------------------//
//                     GsLIB  2.0                           
//
//
// ����:      map demo1		MODE0
// 
// ����:      HuangYZ   
//
// ʹ��:      GsLoadmap     ����map
//
// ʹ��:      GsLoadtils    ����TILES
//
// ʹ��:      GsGetTileSize ���TILES�����
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include <GsDebugText.h>
#include "gfx\master.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	0					//Ĭ��TILE����λ��

//����
void server();
void queryKey();							//��ѯ����
int fx,fy;									//����X��Y
//�ж�������
const IntrFuncp IntrTable[14]={
	server,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy
};

//������
int AgbMain()
{

	u16 timer;					
	
	u8  locate;					//�����õ�MAP������λ��
	u8  tileSize;				//�����õ�TILE��ռ���

	GsOpenIRQ();

	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();
	GsLoadBgPal(master_Palette,256);
	tileSize = GsGetTileSize(sample_Tiles);		
	locate   = DefaultCharBase + tileSize;		
	GsLoadBgMap ( sample_Map   , sizeof(sample_Map)   , locate );
	GsLoadBgTile( sample_Tiles , sizeof(sample_Tiles) , DefaultCharBase  );
	
	//����BG�Ĵ���
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, DefaultCharBase ,locate , 0);

	//�������ȼ�	��ʽ�� GsBgPriority(������,���ȼ�);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	
	
	srand(1);
	//��ѭ��
	while(1)								
	{
	}


	return 0;
}

void server()
{
	int i;
	queryKey();
	
	i=rand()*100;

	*(vu16*)0x4000020=i;
	GsBgOffset(0,fx,fy);
	GsOamCopy();
	GsWaitSync();

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


		if(Cont & R_BUTTON);
		if(Cont & L_BUTTON);
		   
		if(Trg & A_BUTTON);
		if(Trg & START_BUTTON);
	    if(Trg & SELECT_BUTTON);
}
