//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      MODE0下的多层16色BG的显示
// 
// 作者:      EyesOnMe   
//
// 使用:      GsLoadmap     载入map
//
// 使用:      GsLoadtils    载入TILES
//
// 使用:      GsLoadBgPal16 载入16色BG的PAL数据
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\img_p.c"
#include "gfx\img.map.c"
#include "gfx\img.raw.c"

#include "gfx\win_p.c"
#include "gfx\win.raw.c"
#include "gfx\win.map.c"





//函数
void queryKey();

//中断向量表
const IntrFuncp IntrTable[14];

//主函数
int AgbMain()
{

	
	

	//设置BG模式为0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	//初始化BG
	GsInitBG();

	//载入BGPAL

	//载入16色BG0的PAL到0号色盘
        GsLoadBgPal16(IMG_p_Palette,0);
        //载入BG0的MAP数据
        GsLoadBgMap ( img_Map   , sizeof(img_Map)   , 30 );
	//载入BG0的TILE数据
        GsLoadBgTile( img_Tiles , sizeof(img_Tiles) , 0  );
	//设置BG0寄存器
        GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,30 , 0);
	
        //载入16色BG1的PAL到1号色盘
	GsLoadBgPal16(win_p_Palette,1);
	GsLoadBgMap ( win_Map   , sizeof(win_Map)   , 28 );
	GsLoadBgTile( win_Tiles , sizeof(win_Tiles) , 1  );
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 1 ,28 , 0);

   
        //设置各BG的优先权
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	//主循环
	while(1)								
	{
         queryKey(); 
        
         //等待同步
	 GsWaitSync();
        }
        return 0;
}


void queryKey()
{
    KeyRead();						//读键盘

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
