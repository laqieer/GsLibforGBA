// ͷ�ļ�
//����Gslib for GBA ��
#include <GsGBA.h>
//������������( MODE4 )
#include <GsText.h>

//����
void queryKey();							//��ѯ����
void ou();
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
    KeyRead();						//������


  	if (Cont & U_KEY);
	if (Cont & D_KEY);
	if (Cont & R_KEY);
	if (Cont & L_KEY);
	if ( Cont & R_BUTTON );
	if ( Cont & L_BUTTON );
	
}

const char str1[]="������˵���������������ʮһ���͵�ʱ��";
const char str2[]="���ҹ�����ȫ�潨��С����ᡢ�ӿ��ƽ����";
const char str3[]="������������ִ������µķ�չ�׶Ρ����ʾ�";
const char str4[]="�Ρ����ʾ������ڷ�����̱仯������༫��";
const char str5[]="�;��ö༫���;���ȫ�򻯵������������з�";
const char str6[]="չ���Ƽ������������죬�ۺϹ�������������";
const char str7[]="�ҡ����Ʊ��ˣ��������ˡ����ǵ�����ᶨ��";
const char str8[]="վ��ʱ��������ǰͷ���Ž�ʹ���ȫ��������";
const char str9[]="��ʵ���ƽ��ִ������衢������ͳһ��ά";
const char strA[]="�������ƽ��ٽ���ͬ��չ��������ʷ�����";


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