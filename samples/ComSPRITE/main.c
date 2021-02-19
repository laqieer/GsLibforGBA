//-----------------------------------------------------------------//
//                     GsLIB  2.6                          
//
//
// 名称:      组合SPRITE
// 
// 作者:      HuangYZ   
//
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//载入图片资料
#include "gfx\sprite.c"
#include "gfx\death.raw.c"
#include "gfx\death_pal.c"
//载入组合OBJ设置文件
#include "death.h"


#define GtObjOamBase		0				//设置组合OBJ的载入OAM开始位置

//函数
void queryKey();							//查询键盘
void loaddeath();
void Animdeath();
void process();

//中断向量表
const IntrFuncp IntrTable[14] = 
{
	process,	// V Blank interrupt 
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

u8 frame;

u8 deathx,deathy;
s8 dx,dy;
GsSPRITEAffine deathAffine;

//主函数
int AgbMain()
{
	
	//允许所有中断请求
	GsOpenIRQ();
	
	GsSetMode( MODE_0 |DISP_OBJ_CHAR_2D_MAP);					

	GsLoadObjPal(death_Palette,256);
	
	//从ROM里把TILE数据读入显存
	//源地址,长,宽,偏移量
	GtLoadObjChar2D(death_Bitmap,128,128,0);
	
	//精灵初始化
	
	//坐标
	deathx=80;
	deathy=80;

	loaddeath();

	//主循环
	for(;;)								
	{
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//读键盘


	if(Cont & U_KEY)dy=-1;
	if(Cont & D_KEY)dy=1;
	if(Cont & L_KEY)dx=-1;
	if(Cont & R_KEY)dx=1;

	if(Trg & R_BUTTON);
	if(Trg & L_BUTTON);
	if(Trg & A_BUTTON)			
		GtSPRFlipH(&death,GtObjOamBase,8);			//设置H翻转
		
	if(Trg & B_BUTTON);


	if(Cont & B_BUTTON)
	{
		if(Cont & U_KEY)deathAffine.RatioY--;
		if(Cont & D_KEY)deathAffine.RatioY++;
		if(Cont & L_KEY)deathAffine.RatioX--;
		if(Cont & R_KEY)deathAffine.RatioX++;
		
	}

	if(Cont & R_BUTTON)
	{
		deathAffine.Theta = (deathAffine.Theta-=2)&0xff;
		GtSPRRotate(&death,GtObjOamBase,0,&deathAffine,0,deathx,deathy,1);

	}
   
	if(Cont & L_BUTTON)
	{
		deathAffine.Theta = (deathAffine.Theta+=2)&0xff;  
		GtSPRRotate(&death,GtObjOamBase,0,&deathAffine,0,deathx,deathy,1);


	}

	
}

void loaddeath()
{
	//初始化    组合OBJ,  在OAM中的位置   属性         调色盘号    优先级
	GtSPRCreate(&death,   GtObjOamBase , Gs_OAM_NORMAL, 0   ,       2);
	
	
	//设置0号部件有旋转属性
	GtSPRSetAffine(&death,GtObjOamBase,0);
	
	//设置坐标
	GtSPRSetXY(&death,GtObjOamBase,deathx,deathy);

	//设置参数
	deathAffine.RatioX		=0x100;			//设置X方向放缩参数初始化
	deathAffine.RatioY		=0x100;			//设置Y方向放缩参数初始化
	deathAffine.Theta		=0;				//设置旋转参数初始化
}

void process()
{
		dx=0;dy=0;


		queryKey();
		frame++;
		
		//动画组合OBJ的第8个部分
		GtSPRAnimate(&death,GtObjOamBase,8,frame>>3);
		//动画组合OBJ的第9个部分
		GtSPRAnimate(&death,GtObjOamBase,9,frame>>3);

		//移动
		GtSPRMove(&death,GtObjOamBase,dx,dy);

		GsOamCopy();
		GsWaitSync();
}


