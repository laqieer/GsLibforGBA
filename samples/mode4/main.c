//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      MODE3下真彩16BIT图片的DMA传输 
// 
// 作者:      HuangYZ   
//
// 使用:      修改中断向量表 IntrTable
//
// 使用:      GsOpenIRQ打开所有中断
//
// 使用:      DmaArrayCopyIf用DMA来传输图片
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//载如OBJ图形数据
#include "gfx\master.pal.c"
#include "gfx\sb.raw.c"



//函数
void queryKey();							//查询键盘
							



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
	GsSetMode(MODE_4);					
	GsLoadBgPal(master_Palette,256);

	//主循环
	while(1)								
	{
       GsSortImage((u16*)sb_Bitmap,sizeof(sb_Bitmap));      
         GsFlip();
         
	 GsWaitSync();
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//读键盘

	if(Cont & B_BUTTON);


	if(Cont & R_BUTTON);
   
	if(Cont & L_BUTTON);  
   
        if(Trg & A_BUTTON);
   
        if(Trg & START_BUTTON);

        if(Trg & SELECT_BUTTON);
}



