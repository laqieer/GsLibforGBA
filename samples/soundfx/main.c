//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      SOUND Ч��
// 
// ����:      HuangYZ   
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>

//����
void queryKey();							//��ѯ����


//����Ч��
const GsSoundEffect sndFX={1,0xf1400008,0x0000876b};


//�ж�������
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


//������
int AgbMain()
{
	GsOpenIRQ();
	GsOpenSound(SOUND_DMG_ON);			//OPEN all sound
	
	
	while(1);
	
	return 0;
}

void queryKey()
{

    KeyRead();						//������
	if(Trg & A_BUTTON)
			GsPlaySE(&sndFX);		//����Ч����
}
