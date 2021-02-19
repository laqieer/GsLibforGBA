//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      MODE0下的16色和256色BG的显示
// 
// 作者:      EyesOnMe   
//
// 使用:      GsLoadmap     载入map
//
// 使用:      GsLoadtils    载入TILES
//
// 使用:      GsLoadBgPalEx  自由分配颜色数(用于256色图片,节省256色的PAL空间)
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\img.pal.c"
#include "gfx\img.map.c"
#include "gfx\img.raw.c"

#include "gfx\win.pal.c"
#include "gfx\win.raw.c"
#include "gfx\win.map.c"



				//默认TILE载入位置

//函数
void queryKey();		//查询键盘
							
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

        //载入BG0的16色PAL到6号调色盘
	GsLoadBgPal16(img_Palette,6);
        //载入BG0的MAP数据
	GsLoadBgMap ( img_Map   , sizeof(img_Map)   , 30 );
	//指定BG0的地图使用6号色盘
        GsLoadBgMapSelectPal( img_Map   , sizeof(img_Map)   , 30 ,6);
        //载入BG0的TILE数据
	GsLoadBgTile( img_Tiles , sizeof(img_Tiles) , 0  );
	//设置BG0的寄存器
        GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,30 , 0);
	
	//自由载入BG0的地图PAL(颜色数可以自己定)   格式：调色板，其始地址，数量
        //因为256色图片一般情况下用不到256种颜色，所以自由分配颜色有利于节省PAL
	GsLoadBgPalEx(win_Palette,0,56);
	GsLoadBgMap ( win_Map   , sizeof(win_Map)   , 28 );
	GsLoadBgTile( win_Tiles , sizeof(win_Tiles) , 1  );
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 1 ,28 , 0);
         
        
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
