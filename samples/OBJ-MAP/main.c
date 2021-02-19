//-----------------------------------------------------------------//
//                     GsLIB  2.0                           
//
//
// 名称:      SPRITE & MAP DEMO 
// 
// 作者:      EyesOnMe
//
// 使用:      GsSortSPRITE(&myspr);
//	
// 使用：     GsAffineSPRITE(&myspr,&myAff);//变幻这个OBJ
//	
// 使用：     GsOamCopy();   //把OAM缓存拷贝到OAM RAM
//
// 使用：     GsLoadtils    载入TILES
//
// 使用：     GsLoadBgMap   载入MAP
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//载如OBJ图形数据
#include "gfx\ani.c"

//载如BG图形数据
#include "gfx\text.raw.c"
#include "gfx\text.map.c"

#include "gfx\map.raw.c"
#include "gfx\map.map.c"


#include "gfx\master.pal.c"


//函数
void queryKey();							//查询键盘
void init_spr();							//初始化SPRITE

//全局变量
GsSPRITE			myspr;					//这个例子中使用的OBJ
GsSPRITEAffine		myAff;					//这个例子中使用的OBJ变化参数

u16 frames=0;     //总体帧数
u8 anicnt=0;      //OBJ的帧计数
u8 anidir=0;      //OBJ的指向方向

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
	GsSetMode(MODE_0|DISP_OBJ_CHAR_1D_MAP);					
	
        GsInitBG();  //初始化BG
        
 	GsLoadBgPal16(master_Palette,0);      //加载BG的16色调色板 
    
	GsLoadBgMap(map_Map,sizeof(map_Map),25);    //加载MAP到30位置
    GsLoadBgTile(map_Tiles,sizeof(map_Tiles),0);  //加在TILE到1位置


//		GsLoadBgMap(text_Map,sizeof(text_Map),28);    //加载MAP到30位置
  //      GsLoadBgTile(text_Tiles,sizeof(text_Tiles),1);  //加在TILE到1位置
 
   GsSetBg(1,Gs_BG_TEXT_SIZE_512x512,Gs_BG_COLOR16,0,25,0);  
        GsBgPriority(1,1);

        //从ROM里把调色盘数据读入PALRAM
	GsLoadObjPal16(ani_Palette,2);
	//从ROM里把TILE数据读入显存
	GsLoadObjChar(ani_Char,OBJ_MODE0_VRAM);
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
    if((frames%2)==0)
           {myspr.obj.CharNo=anidir+16*(anicnt%2);anicnt++;}   //根据OBJ的帧来更新OBJ内容
    if(frames>=65535) frames=0; else frames++;  //防止帧数溢出
    
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

		if(Cont & U_KEY) {myspr.obj.VPos--;anidir=0;}
		if(Cont & D_KEY) {myspr.obj.VPos++;anidir=64;}
		if(Cont & L_KEY) {myspr.obj.HPos--;anidir=96;}
		if(Cont & R_KEY) {myspr.obj.HPos++;anidir=32;}
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
	myspr.obj.Size		=Gs_OAM_BIG;	//设置大小,巨大
	myspr.obj.CharNo	=0;				//设置TILE开始号
	myspr.obj.Pltt		=2;				//选择2号调色盘
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

