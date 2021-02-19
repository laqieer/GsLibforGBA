//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      MODE3�����16BITͼƬ��DMA���� 
// 
// ����:      HuangYZ   
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
#include "gfx\master.pal.c"
#include "gfx\sb.raw.c"



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
	GsSetMode(MODE_4);					
	GsLoadBgPal(master_Palette,256);

	//��ѭ��
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
    KeyRead();						//������

	if(Cont & B_BUTTON);


	if(Cont & R_BUTTON);
   
	if(Cont & L_BUTTON);  
   
        if(Trg & A_BUTTON);
   
        if(Trg & START_BUTTON);

        if(Trg & SELECT_BUTTON);
}



