//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      CAMERA
// 
// 作者:      HuangYZ   
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\sample.c"

#define sample_H 1024
#define sample_V 512

#define sample_Map_pos	30

//函数
void queryKey();							//查询键盘

//中断向量表
const IntrFuncp IntrTable[14]=
{
	queryKey,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
};



//设置一个摄像机

GsCameraMan Camera={sample_Map,					//MAP数据源
					sample_H/8,sample_V/8,		//设置图片的大小
					sample_Map_pos,				//设置MAP数据的保存位置
					0,							//卷轴X方向的初始位置
					0							//卷轴Y方向的初始位置
					};	

//主函数
int AgbMain()
{
	//设置BG模式为0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	//初始化
	GsOpenIRQ();
	GsInitBG();
	//载入BGPAL
	GsLoadBgPal16(sample_Palette,0);
		
	//载入BGTILE到0区
	GsLoadBgTile( sample_Character , sizeof(sample_Character) , 0  );
	
	//设置BG寄存器
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,sample_Map_pos, 0);

	//设置优先级	格式： GsBgPriority(背景号,优先级);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	while(1);
	
	return 0;
}

void queryKey()
{
		KeyRead();						//读键盘

		if(Cont & U_KEY)			
			Camera.offsetY--;			//移动摄像机
					
		if(Cont & D_KEY)
			Camera.offsetY++;			//移动摄像机
		
		if(Cont & L_KEY)
			Camera.offsetX--;			//移动摄像机
		
		if(Cont & R_KEY)
			Camera.offsetX++;			//移动摄像机

		GsSetCamera(0,&Camera);			//设置摄像机
		
		
		GsWaitSync();					//等待同步
		
}
