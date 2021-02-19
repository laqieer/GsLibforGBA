//-----------------------------------------------------------------//
//                     GsLIB  2.0                           
//
//
// 名称:      map demo1		MODE0
// 
// 作者:      HuangYZ   
//
// 使用:      GsLoadmap     载入map
//
// 使用:      GsLoadtils    载入TILES
//
// 使用:      GsGetTileSize 算出TILES的体积
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include <GsDebugText.h>
#include "gfx\master.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	0					//默认TILE载入位置

//函数
void server();
void queryKey();							//查询键盘
int fx,fy;									//卷轴X，Y
//中断向量表
const IntrFuncp IntrTable[14]={
	server,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy
};

//主函数
int AgbMain()
{

	u16 timer;					
	
	u8  locate;					//用来得到MAP的载入位置
	u8  tileSize;				//用来得到TILE所占体积

	GsOpenIRQ();

	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();
	GsLoadBgPal(master_Palette,256);
	tileSize = GsGetTileSize(sample_Tiles);		
	locate   = DefaultCharBase + tileSize;		
	GsLoadBgMap ( sample_Map   , sizeof(sample_Map)   , locate );
	GsLoadBgTile( sample_Tiles , sizeof(sample_Tiles) , DefaultCharBase  );
	
	//设置BG寄存器
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, DefaultCharBase ,locate , 0);

	//设置优先级	格式： GsBgPriority(背景号,优先级);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	
	
	srand(1);
	//主循环
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
    KeyRead();						//读键盘

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
