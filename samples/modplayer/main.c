#include <GsGBA.h>
#include "data.h"

IntrFuncp IntrTable[14] =				//这里千万不能用 const 否则会出错
{
	dummy,		// V Blank interrupt 
    dummy,		// H Blank interrupt
    dummy,      // V Counter interrupt
	dummy,		// Timer 0 interrupt
	dummy,		// Timer 1 interrupt
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

void AgbMain()
{
//	GsOpenIRQ();
	GsInitMOD();				//初始化MOD音源


NMOD_SetMasterVol(64,0);
NMOD_SetMasterVol(64,1);
NMOD_SetMasterVol(64,2);
NMOD_SetMasterVol(64,3);
//NMOD_Play((u32)(&module));
NMOD_Play((u32)(&sho));

for(;;)
	{

	  GsWaitSync();
	}
NMOD_Stop();
for(;;);
}