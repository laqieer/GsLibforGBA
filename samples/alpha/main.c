//-----------------------------------------------------------------//
//                     GsLIB  2.6                          
//
//
// 名称:      ALPHA特效 
// 
// 作者:      HuangYZ   
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\ap_bg0.c"				//调色盘数据
#include "gfx\ap_bg0.map.c"			//MAP数据
#include "gfx\ap_bg0.raw.c"			//RAW数据

#include "gfx\ap_bg1.c"				//调色盘数据
#include "gfx\ap_bg1.map.c"			//MAP数据
#include "gfx\ap_bg1.raw.c"			//RAW数据

#include "gfx\ap_bg2.c"				//调色盘数据
#include "gfx\ap_bg2.map.c"			//MAP数据
#include "gfx\ap_bg2.raw.c"			//RAW数据


#define DefaultCharBase	1					//默认TILE载入位置

//函数
void initBG();								//载入所有BG
void server();								//中断服务程序
void queryKey();							//查询键盘
int fx,fy,eva,evb;									//卷轴X，Y
int fx1,fy1;									//卷轴X，Y
int fx2,fy2;									//卷轴X，Y



u16 nn;
//中断向量表
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

//主函数
int AgbMain()
{
//	打中断，设置显示模式，初始化BG
	GsOpenIRQ();
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();

//	载入BG	
	initBG();
	


//	使程序无限循环
	for(;;);

	return 0;
}

void queryKey()
{
	
    KeyRead();						//读键盘
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
		
		//设置卷轴
		GsBgOffset(0, fx,fy);
		//设置ALPHA参数
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
	u8  locate;					//用来得到MAP的载入位置
	u8  tileSize;				//用来得到TILE所占体积
	
	GsLoadBgPal16(ap_bg0_Palette,0);
	GsLoadBgPal16(ap_bg1_Palette,1);
	GsLoadBgPal16(ap_bg2_Palette,2);

	GsLoadBgMap ( ap_bg0_Map   , sizeof(ap_bg0_Map)   , 29 );
	GsLoadBgTile( ap_bg0_Tiles , sizeof(ap_bg0_Tiles) , 0  );

	GsLoadBgMap ( ap_bg1_Map   , sizeof(ap_bg1_Map)   , 30 );
	GsLoadBgTile( ap_bg1_Tiles , sizeof(ap_bg1_Tiles) , 1  );

	GsLoadBgMap ( ap_bg2_Map   , sizeof(ap_bg2_Map)   , 31 );
	GsLoadBgTile( ap_bg2_Tiles , sizeof(ap_bg2_Tiles) , 2  );
	
	//设置BG寄存器
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,29 , 0);
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 1 ,30 , 0);
	GsSetBg(2 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 2 ,31 , 0);

	//设置优先级	格式： GsBgPriority(背景号,优先级);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//设置特效
	*(vu16*)REG_BLDCNT|=BLD_A_BLEND_MODE;


	GsSetEffect(BLD_BG0_1ST|BLD_BG1_1ST|BLD_BG2_1ST,
		        BLD_BG0_2ND|BLD_BG1_2ND|BLD_BG2_2ND);




}

void server()
{
	queryKey();
	//等待同步
	GsWaitSync();
}