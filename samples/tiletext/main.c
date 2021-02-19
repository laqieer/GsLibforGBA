// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>
//载入点阵字体库( MODE4 )
#include <GsText.h>

//函数
void queryKey();							//查询键盘
void ou();
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

	BGPaletteMem[1]=0xffff;

	GsOpenIRQ();
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	GsInitBG();
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 1 ,5 , 0);
	GsSetBg(1 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 1 ,5 , 0);
	GsSetBg(2 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR256, 1 ,5 , 0);
	
	GsTileTextInit(3,3,6,0);
	
	GsBgPriority(3,0);	
	ou();

	while(1)								
	{GsWaitSync();}
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

const char str1[]="江泽民说，当人类社会跨入二十一世纪的时候";
const char str2[]="，我国进入全面建设小康社会、加快推进社会";
const char str3[]="主进社会主义现代化的新的发展阶段。国际局";
const char str4[]="段。国际局势正在发生深刻变化。世界多极化";
const char str5[]="和经济多极化和经济全球化的趋势在曲折中发";
const char str6[]="展，科技进步日新月异，综合国力竞争日趋激";
const char str7[]="烈。形势逼人，不进则退。我们党必须坚定地";
const char str8[]="站在时代潮流的前头，团结和带领全国各族人";
const char str9[]="民，实现推进现代化建设、完成祖国统一、维";
const char strA[]="护世界和平与促进共同发展这三大历史任务大";


void ou()
{

	GsTileTextOut(0,0,str1,0x1);
	GsTileTextOut(0,11,str2,0x1);
	GsTileTextOut(0,22,str3,0x1);
	GsTileTextOut(0,33,str4,0x1);
	GsTileTextOut(0,44,str5,0x1);
	GsTileTextOut(0,55,str6,0x1);
	GsTileTextOut(0,66,str7,0x1);
	GsTileTextOut(0,77,str8,0x1);
	GsTileTextOut(0,88,str9,0x1);
}