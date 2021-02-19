//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      map demo2		MODE1
// 
// 作者:      HuangYZ   
//
// 使用:      GsLoadmap     载入map
//
// 使用:      GsLoadtils    载入TILES
//
// -------------- 最好使用IGBA测试本DEMO ---------------------------
// 包括3个步骤:
//	1		初始化BGCNT，BGAFFINE参数
//	2		创建变化参数对象
//  3		主循环里通过变化参数改变BGAFFINE寄存器达到效果
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
#include "gfx\sam.pal.c"
#include "gfx\sample.map.c"
#include "gfx\sample.raw.c"


#define DefaultCharBase	3					//默认TILE载入位置
#define DefaultMapBase	8					//默认MAP载入位置

//函数
static void queryKey();							//查询键盘
//变量

GsBGAffine affe;							//设置BG变化参数

//中断向量表
const IntrFuncp IntrTable[14]=
{
	queryKey,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy
};

//主函数
int AgbMain()
{

	GsBGAffine bgaff;

	//打开所有中断
	GsOpenIRQ();
	//设置BG模式为0
	GsSetMode( MODE_1 |DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();	//初始化BG

	GsLoadBgPal ( sam_Palette	 , 256	);//载入BGPAL
	GsLoadBgMap ( (u16*)sam_Map		 , sizeof(sam_Map)   , DefaultMapBase   );//载入BGMAP 到8号位置
	GsLoadBgTile( sam_Tiles		 , sizeof(sam_Tiles) , DefaultCharBase  );//载入BGTILE


	//设置BG2
	GsSetBg(2 , Gs_BG_AFFINE_SIZE_128x128 , Gs_BG_COLOR256, DefaultCharBase ,DefaultMapBase , ON);
	//把BG2设置成平铺
	GsSetBgLoop(2,TRUE);	

	//设置优先级	格式： GsBgPriority(背景号,优先级);
	GsBgPriority(2,0);

	//初始化BG2
	GsBgAffineRegInit(2);

	//初始化 变化对象
	GsBgAffineInit(&affe);

	

	while(1)								
	{
	//等待同步
	GsWaitSync();
	}

	return 0;
}

void queryKey()
{
    KeyRead();						//读键盘


    if( Cont & B_BUTTON )
    {

	    //  Scale using + Cotrol Pad

	if (Cont & U_KEY)
	{
	    affe.bg_scale_y += 0x10;
	}
	if (Cont & D_KEY)
	{
	    affe.bg_scale_y -= 0x08;
	}
	if (Cont & L_KEY)
	{
	    affe.bg_scale_x -= 0x08;
	}
	if (Cont & R_KEY)
	{
	    affe.bg_scale_x += 0x10;
	}

    }
    else
    {

	    //  Move using + Control Pad

	if (Cont & U_KEY)
	{
	    affe.bg_pos_y -= 2;
	}
	if (Cont & D_KEY)
	{
	    affe.bg_pos_y += 2;
	}
	if (Cont & R_KEY)
	{
	    affe.bg_pos_x += 2;
	}
	if (Cont & L_KEY)
	{
	    affe.bg_pos_x -= 2;
	}


    }

		    // Rotate using LR button 

	if ( Cont & R_BUTTON )
	{
	    ++affe.bg_rotate ;
	}
	if ( Cont & L_BUTTON )
	{
	    affe.bg_rotate = affe.bg_rotate+0xff;
	}

	GsBgAffine(2,&affe);		//产生变化数据

	GsBgMakeAffine(2,&affe);	//设置变化
		

	
}
