//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      MODE3�����16BITͼƬ��DMA���� 
// 
// ����:      EyesOnMe   
//
// ʹ��:      �޸��ж������� IntrTable
//
// ʹ��:      GsOpenIRQ�������ж�
//
// ʹ��:      DmaArrayCopyIf��DMA������ͼƬ
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����OBJͼ������
#include "gfx\tree.c"

//����
void queryKey();							//��ѯ����
							



//�ж�������
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


//������
int AgbMain()
{

	//���������ж�����
	GsOpenIRQ();

	//����BGģʽΪ0
	GsSetMode( MODE_3);					
	
        //ʹ��3��DMAͨ������ͼƬ
        DmaArrayCopyIf(3,tree_RawBitmap,BG_BITMAP0_VRAM,16);
	
	
	//��ѭ��
	while(1)								
	{
         //�ȴ�ͬ��
	GsWaitSync();
	}


	return 0;
}


void queryKey()
{
    KeyRead();						//������

	if(Cont & B_BUTTON);


	if(Cont & R_BUTTON);
   
	if(Cont & L_BUTTON);  
   
        if(Trg & A_BUTTON);
   
        if(Trg & START_BUTTON);

        if(Trg & SELECT_BUTTON);
}



