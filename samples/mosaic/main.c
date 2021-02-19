//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      map demo1		MODE0
// 
// 作者:      EyesOnMe   
//
// 使用:      GsLoadmap     载入map
//
// 使用:      
//
// 使用:      
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\master.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	0					//默认TILE载入位置
#define locate 30                                                //默认MAP载入位置

//函数
void queryKey();							//查询键盘
//用来表示BG卷轴
int fx,fy;

//用来表示马塞克级别
u8 msc=0;
									//卷轴X，Y
//中断向量表
const IntrFuncp IntrTable[14];

//主函数
int AgbMain()
{

	u16 timer;					
	
	
	

	GsBGAffine bgaff;

	//设置BG模式为0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_2D_MAP);
	//初始化BG
	GsInitBG();
	//载入BGPAL
	GsLoadBgPal(master_Palette,256);
	
	//载入BGMAP 到30号位置
	GsLoadBgMap ( sample_Map   , sizeof(sample_Map)   , locate );
	
	//载入BGTILE
	GsLoadBgTile( sample_Tiles , sizeof(sample_Tiles) , DefaultCharBase  );
	
	//设置BG寄存器
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, DefaultCharBase ,locate , 1);

	//设置优先级	格式： GsBgPriority(背景号,优先级);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//主循环
	while(1)								
	{

	//查询键盘
	if(timer%20==0)						
		queryKey();

	//设置卷轴
	 GsBgOffset(0,fx,fy);
		
	//等待同步
	GsWaitSync();

	timer++;							//计时
	if(timer>65535) timer=0;			//溢出保护
	}
        
        return 0;
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
