//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      MODE3�����16BITͼƬ�ĵ��뵭��
// 
// ����:      EyesOnMe  
//
// ʹ��:      �޸��ж������� IntrTable
//
// ʹ��:      void GsSortImage(const u16 *IndexData, unsigned long size); ������ͼƬ
//
// ʹ��:      GsSetBright���õ��뵭��(��L��R�����е��뵭��Ч��)
//                                   (TILE��BITMAP���÷���ͬ)
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����OBJͼ������
#include "gfx\tree.c"

//����
void queryKey();							//��ѯ����
							
s16 br=0;


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
	
       
    GsSortImage(tree_RawBitmap,sizeof(tree_RawBitmap));
	
	//Ӳ����ѡ��ǰģʽ������ͼ��μ���Ч����
        GsSetEffect(BLD_1ST_ALL,BLD_2ND_ALL);

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


	if(Trg & R_BUTTON) GsSetBright(br++);
   
	if(Trg & L_BUTTON) GsSetBright(br--);  
   
        if(Trg & A_BUTTON);
   
        if(Trg & START_BUTTON);

        if(Trg & SELECT_BUTTON);
}



