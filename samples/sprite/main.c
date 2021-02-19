//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      SPRITE DEMO 
// 
// 作者:      HuangYZ   
//
// 使用:      GsSortSPRITE(&myspr);
//	
//			  GsAffineSPRITE(&myspr,&myAff);//变幻这个OBJ
//	
//			  GsOamCopy();   //把OAM缓存拷贝到OAM RAM
//
// 
//
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//载如OBJ图形数据
#include "gfx\sprite.c"

//函数
void queryKey();							//查询键盘
void init_spr();							//初始化SPRITE

//全局变量
GsSPRITE			myspr;					//这个例子中使用的OBJ
GsSPRITEAffine		myAff;					//这个例子中使用的OBJ变化参数

//中断向量表
const IntrFuncp IntrTable[14] = 
{
	queryKey,	// V Blank interrupt 
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

	//允许所有中断请求
	GsOpenIRQ();

	//设置BG模式为0
	GsSetMode( MODE_0 |DISP_OBJ_CHAR_1D_MAP);					
	
	//从ROM里把调色盘数据读入PALRAM
	GsLoadObjPal(sprite_Palette,256);
	
	//从ROM里把TILE数据读入显存
	GsLoadObjChar( sprite_Char,OBJ_MODE0_VRAM );


	//精灵初始化
	init_spr();								

	//主循环
	while(1)								
	{

	//显示这个OBJ
	GsSortSPRITE(&myspr);
	//变幻这个OBJ
	GsAffineSPRITE(&myspr,&myAff);
	
	
	//把OAM缓存拷贝到OAM RAM
	GsOamCopy();
	//等待同步
	GsWaitSync();
		
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//读键盘

	if(Cont & B_BUTTON)
	{
		if(Cont & U_KEY)myAff.RatioY--;
		if(Cont & D_KEY)myAff.RatioY++;
		if(Cont & L_KEY)myAff.RatioX--;
		if(Cont & R_KEY)myAff.RatioX++;
	}
	else
	{
//移动坐标
	//	OBJ结构中的VPOS表示在垂直方向坐标
	//	OBJ结构中的HPOS表示在垂直方向坐标

		if(Cont & U_KEY)myspr.obj.VPos--;
		if(Cont & D_KEY)myspr.obj.VPos++;
		if(Cont & L_KEY)myspr.obj.HPos--;
		if(Cont & R_KEY)myspr.obj.HPos++;
	}

	if(Cont & R_BUTTON)
		myAff.Theta = (myAff.Theta-1)&0xff;
   
	if(Cont & L_BUTTON)
		myAff.Theta = (++myAff.Theta)&0xff;  
   
   if(Trg & A_BUTTON)
   {
	   if(myspr.obj.AffineMode&0x2==0x2)
		   myspr.obj.AffineMode|=0x2;
	   else
		   myspr.obj.AffineMode&=0x1;
   }


  if(Trg & START_BUTTON)
	  init_spr();

  if(Trg & SELECT_BUTTON);
  	  

}

void init_spr()							//初始化
{
	myspr.ID=0;							//载入位置
	
	myspr.obj.HPos		=50;			//设置h方向(横)坐标
	myspr.obj.VPos		=50;			//设置v方向(纵)坐标
	myspr.obj.Shape		=Gs_OAM_SQUARE; //设置OBJ形状为SQUARE
	myspr.obj.Size		=Gs_OAM_LARGE;	//设置大小,巨大
	myspr.obj.CharNo	=0;				//设置TILE开始号
	myspr.obj.Pltt		=0;				//选择0号调色盘
	myspr.obj.Priority	=0;				//优先级别为最高
	myspr.obj.ColorMode	=Gs_OAM_COLOR16;//16色
	myspr.obj.AffineMode=Gs_OAM_NORMAL; //设置模式为正常模式
	myspr.obj.Mosaic	=TRUE;			//允许马塞克特效


	myspr.obj.AffineMode=Gs_OAM_ROTATE_ENABLE;	//旋转/放缩允许
	myspr.obj.AffineParamNo_L=0;		//旋转/放缩变换,参数组0
	
	myAff.RatioX		=0x100;			//设置X方向放缩参数初始化
	myAff.RatioY		=0x100;			//设置Y方向放缩参数初始化
	myAff.Theta			=0;				//设置旋转参数初始化
}

