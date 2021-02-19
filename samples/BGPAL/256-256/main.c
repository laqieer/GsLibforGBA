//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      MODE0下的多层256色BG的显示
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
	
        //从PAL里自由分配给BG1 56种颜色，从0(0-255)开始(颜色数可以从PAL的文件里数出来)
	GsLoadBgPalEx(win_Palette,0,56);
	//载入BG1的MAP数据
        GsLoadBgMap ( win_Map   , sizeof(win_Map)   , 28 );
	//载入BG1的TILE数据
        GsLoadBgTile( win_Tiles , sizeof(win_Tiles) , 2  );
	//设置BG1的寄存器
        GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 2 ,28 , 0);

        //从PAL里自由分配给BG0 56种颜色，从0(0-255)开始
	//关键是两个BG的PAL地址不能重叠!!!
        GsLoadBgPalEx(img_Palette,56,32);
	GsLoadBgMap ( img_Map   , sizeof(img_Map)   , 30 );
	GsLoadBgTile( img_Tiles , sizeof(img_Tiles) , 0  );
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 0 ,30 , 0);         
        
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
