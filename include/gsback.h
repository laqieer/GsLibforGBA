// ���� GSLIB 2.6

#ifndef _GsBack_
#define _GsBack_

#define SRAMCURRENT 0
#define	SRAMBEGIN	1
#define SRAMEND		2


extern u8 *p_SramPos;				

void GsSramInit();

int  GsSramReadWord();			//���ֲ���
void  GsSramWriteWord(int word);

char GsSramReadChar();				//���ֽڲ���
void GsSramWriteChar(char c);

short GsSramReadHalfWord();				//�԰��ֲ���
void GsSramWriteHalfWord(short s);

void GsSramRead(u8 *buffer,long length);//���ṹ���ȡ
void GsSramWrite(u8 *buffer,long length);//���ṹ��д

void GsSramReadHuge(u8 *buffer,long size,long count);//���ṹ���ȡ
void GsSramWriteHuge(u8 *buffer,long size,long count);//���ṹ��д
 
void GsSramSeek(u8 flag,int step);		//ָ���ƶ�
void GsSramSeektoBegin();					//ָ���ƶ���SRAMͷ��
void GsSramSeektoEnd();				//ָ���ƶ���SRAM�ײ�

#endif