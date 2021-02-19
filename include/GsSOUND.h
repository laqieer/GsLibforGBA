#ifndef SOUND_H
#define SOUND_H



#define SOUND_LEFT 0
#define SOUND_RIGHT 1

//ͨ���ţ� ��/��λ	�� ����Դ��  Ƶ��
//direct sound
extern void GsPlaySound(u8 no,u8 lh,const u8 *sound, u16 sampleRate);
extern void GsSetDSoundVol(u8 left, u8 right);
extern void GsSwitchSOUND(u8 no,u8 lr,u8 stat);



//sound ctrl
extern void GsOpenSound(u8 sno);		// ����������
extern void GsSetSound1(GsSound1Cnt *ps1cnt);	//��������1
extern void GsSetSound2(GsSound2Cnt *ps2cnt);	//��������2
extern void GsSetSound3(GsSound3Cnt *ps3cnt);	//��������3
extern void GsSetSound4(GsSound4Cnt *ps4cnt);	//��������4

typedef struct GsSoundEffect
{
	u8 SoundNo;				//ͨ����
	u32 SndCnt0;			//������0
	u32 SndCnt1;			//������1
}GsSoundEffect;

void GsPlaySE(const GsSoundEffect *pse);			//����Ч����

void GsInitMod();
#endif