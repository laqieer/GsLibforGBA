// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
//载入点阵字体库( MODE4 )
#include <GsText.h>

//函数
static void queryKey();							//查询键盘
//变量

//中断向量表
const IntrFuncp IntrTable[14]=
{
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy
};

//主函数
int AgbMain()
{

	u16 timer;					
	int i;

	//设置BG模式为4
	GsSetMode( MODE_4 );

	BGPaletteMem[1]=0xffff;

	
	

	while(1)								
	{

	//查询键盘
	if(timer%20==0)						
		queryKey();


	GsTextOut(20,40,"你好,世界",1);
	GsTextOut(20,60,"hello world",1);



	
	GsWaitSync();
	GsFlip();

	timer++;								//increase timer
	if(timer>65535)timer=0;					//overflow protect
	}

	return 0;
}

void queryKey()
{
    KeyRead();						//读键盘


  	if (Cont & U_KEY);
	if (Cont & D_KEY);
	if (Cont & R_KEY);
	if (Cont & L_KEY);
	if ( Cont & R_BUTTON );
	if ( Cont & L_BUTTON );
	
}
