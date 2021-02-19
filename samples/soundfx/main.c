//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// 名称:      SOUND 效果
// 
// 作者:      HuangYZ   
//
//-----------------------------------------------------------------//

// 头文件
//载入Gslib for GBA 库
#include <GsGBA.h>

//函数
void queryKey();							//查询键盘


//声音效果
const GsSoundEffect sndFX={1,0xf1400008,0x0000876b};


//中断向量表
const IntrFuncp IntrTable[14]=
{
	queryKey,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy
};


//主函数
int AgbMain()
{
	GsOpenIRQ();
	GsOpenSound(SOUND_DMG_ON);			//OPEN all sound
	
	
	while(1);
	
	return 0;
}

void queryKey()
{

    KeyRead();						//读键盘
	if(Trg & A_BUTTON)
			GsPlaySE(&sndFX);		//播放效果音
}
