#ifndef _GSDEBUGTEXT_H_
#define _GSDEBUGTEXT_H_

extern void GsDebugTextInit(u8 bgno, u8 tileloc, u8 screenoffset, u8 palno, u8 colno);//��ʼ���ı���
//��һ������Ҫ������ַ���ͼ���
//�ڶ��������ֿ�����Ŀ�� 0 - 31 ���ֿ��СΪ1184Byte
//����������MAP���ݵ������� 0 - 31 ��MAP����Ϊ2KByte
//���Ĳ������ַ��õĵ�ɫ��ţ����ַ��õ��õ�ɫ���1��ɫ���ڶ�����ɫ

extern void GsDebugTextOut(u8 x, u8 y, char *format,u32 age1, u32 age2);//����ַ���
//��һ��������0-29���ڶ���������0-19��
//����������������ַ�����֧�ֵĸ�ʽ����%u,%d,%x,\n,\b,%u�����޷������������%s�����з����������,%x����16������ʾ,nΪ����,\bΪ�˸�
//���������Ҫ�������ֵ�ı�������û�������ֵʱҪ��0��䣬�������� 

extern void GsClearDebugText(void);
//���д����Ļ�ϵ�����

extern void GsCloseDebugText(void);
//�ر��ı�ϵͳ������ֿ��MAP������
#endif