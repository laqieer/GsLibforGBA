//-----------------------------------------------------------------//
//                     GsLIB  2.6                           
//
//
// ����:      CAMERA
// 
// ����:      HuangYZ   
//
//-----------------------------------------------------------------//

// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
#include "gfx\sample.c"

#define sample_H 1024
#define sample_V 512

#define sample_Map_pos	30

//����
void queryKey();							//��ѯ����

//�ж�������
const IntrFuncp IntrTable[14]=
{
	queryKey,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
	dummy,dummy,
};



//����һ�������

GsCameraMan Camera={sample_Map,					//MAP����Դ
					sample_H/8,sample_V/8,		//����ͼƬ�Ĵ�С
					sample_Map_pos,				//����MAP���ݵı���λ��
					0,							//����X����ĳ�ʼλ��
					0							//����Y����ĳ�ʼλ��
					};	

//������
int AgbMain()
{
	//����BGģʽΪ0
	GsSetMode( MODE_0 | DISP_OBJ_CHAR_1D_MAP);
	//��ʼ��
	GsOpenIRQ();
	GsInitBG();
	//����BGPAL
	GsLoadBgPal16(sample_Palette,0);
		
	//����BGTILE��0��
	GsLoadBgTile( sample_Character , sizeof(sample_Character) , 0  );
	
	//����BG�Ĵ���
	GsSetBg(0 , Gs_BG_TEXT_SIZE_256x256 , Gs_BG_COLOR16, 0 ,sample_Map_pos, 0);

	//�������ȼ�	��ʽ�� GsBgPriority(������,���ȼ�);
	GsBgPriority(0,0);
	GsBgPriority(1,1);
	GsBgPriority(2,2);
	GsBgPriority(3,3);

	while(1);
	
	return 0;
}

void queryKey()
{
		KeyRead();						//������

		if(Cont & U_KEY)			
			Camera.offsetY--;			//�ƶ������
					
		if(Cont & D_KEY)
			Camera.offsetY++;			//�ƶ������
		
		if(Cont & L_KEY)
			Camera.offsetX--;			//�ƶ������
		
		if(Cont & R_KEY)
			Camera.offsetX++;			//�ƶ������

		GsSetCamera(0,&Camera);			//���������
		
		
		GsWaitSync();					//�ȴ�ͬ��
		
}
