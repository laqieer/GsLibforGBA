// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
//������������( MODE4 )
#include <GsText.h>

//����
static void queryKey();							//��ѯ����
//����

//�ж�������
const IntrFuncp IntrTable[14]=
{
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy,dummy,dummy,
	dummy,dummy
};

//������
int AgbMain()
{

	u16 timer;					
	int i;

	//����BGģʽΪ4
	GsSetMode( MODE_4 );

	BGPaletteMem[1]=0xffff;

	
	

	while(1)								
	{

	//��ѯ����
	if(timer%20==0)						
		queryKey();


	GsTextOut(20,40,"���,����",1);
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
    KeyRead();						//������


  	if (Cont & U_KEY);
	if (Cont & D_KEY);
	if (Cont & R_KEY);
	if (Cont & L_KEY);
	if ( Cont & R_BUTTON );
	if ( Cont & L_BUTTON );
	
}
