//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      MODE3下真彩16BIT图片的淡入淡出
// 
// 作者:      EyesOnMe  
//
// 使用:      修改中断向量表 IntrTable
//
// 使用:      void GsSortImage(const u16 *IndexData, unsigned long size); 来传输图片
//
// 使用:      GsSetBright设置淡入淡出(按L和R键进行淡入淡出效果)
//                                   (TILE和BITMAP下用法相同)
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//载如OBJ图形数据
#include "gfx\tree.c"

//函数
void queryKey();							//查询键盘
							
s16 br=0;


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
	GsSetMode( MODE_3);					
	
       
    GsSortImage(tree_RawBitmap,sizeof(tree_RawBitmap));
	
	//硬件上选择当前模式下所有图层参加特效运算
        GsSetEffect(BLD_1ST_ALL,BLD_2ND_ALL);

	//主循环
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

	if(Cont & B_BUTTON);


	if(Trg & R_BUTTON) GsSetBright(br++);
   
	if(Trg & L_BUTTON) GsSetBright(br--);  
   
        if(Trg & A_BUTTON);
   
        if(Trg & START_BUTTON);

        if(Trg & SELECT_BUTTON);
}



