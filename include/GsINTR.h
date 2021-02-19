#ifndef GsGBA_DMA_H
#define GsGBA_DMA_H


//---------------------------------------------------------
//DMA

//����DMA	//DMA��    Դ	Ŀ		������
#define DmaSet(DmaNo, Srcp, Destp, DmaCntData)          \
{                                                       \
    vu32 *(DmaCntp) = (vu32 *)REG_DMA##DmaNo;           \
    DmaCntp[0] = (vu32 )(Srcp);                         \
    DmaCntp[1] = (vu32 )(Destp);                        \
    DmaCntp[2] = (vu32 )(DmaCntData);                   \
}
//DMA���	
#define DmaClear(DmaNo, Data, Destp, Size, Bit)             \
{                                                           \
    vu##Bit Tmp = (vu##Bit )(Data);                         \
    DmaSet(DmaNo, &Tmp, Destp, (                            \
        DMA_ENABLE         | DMA_TIMMING_IMM |              \
        DMA_SRC_FIX        | DMA_DEST_INC    |              \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)));   \
}
//������ж�
#define DmaClearIf(DmaNo, Data, Destp, Size, Bit)           \
{                                                           \
    vu##Bit Tmp = (vu##Bit )(Data);                         \
    DmaSet(DmaNo, &Tmp, Destp, (                            \
        DMA_ENABLE         | DMA_TIMMING_IMM |              \
        DMA_IF_ENABLE      |                                \
        DMA_SRC_FIX        | DMA_DEST_INC    |              \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)));   \
}
//DMA�������
#define DmaArrayClear(  DmaNo, Data, Destp, Bit)            \
        DmaClear(       DmaNo, Data, Destp, sizeof(Destp), Bit)
//DMA����������ж�
#define DmaArrayClearIf(DmaNo, Data, Destp, Bit)            \
        DmaClearIf(     DmaNo, Data, Destp, sizeof(Destp), Bit)


/*------------------------------------------------------------------*/
/*                      DMA Copy                                    */
/*------------------------------------------------------------------*/

#define DmaCopy(DmaNo, Srcp, Destp, Size, Bit)              \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_IMM |              \
        DMA_SRC_INC        | DMA_DEST_INC    |              \
        DMA_##Bit##BIT_BUS | ((Size)/((Bit)/8) & 0xffff)))

#define DmaCopyIf(DmaNo, Srcp, Destp, Size, Bit)            \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_IMM |              \
        DMA_IF_ENABLE      |                                \
        DMA_SRC_INC        | DMA_DEST_INC    |              \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)))

#define DmaArrayCopy(  DmaNo, Srcp, Destp, Bit)             \
        DmaCopy(       DmaNo, Srcp, Destp, sizeof(Srcp), Bit)

#define DmaArrayCopyIf(DmaNo, Srcp, Destp, Bit)             \
        DmaCopyIf(     DmaNo, Srcp, Destp, sizeof(Srcp), Bit)

#define DmaArrayCopyLimit( DmaNo , Srcp, Destp,size, Bit)   \
	DmaCopy(       DmaNo, Srcp, Destp, size*(Bit==16?2:4), Bit)

#define H_DmaCopy(DmaNo, Srcp, Destp, Size, Bit)            \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_H_BLANK |          \
        DMA_SRC_INC        | DMA_DEST_RELOAD     |          \
        DMA_CONTINUOUS_ON  |                                \
        DMA_##Bit##BIT_BUS | ((Size)/((Bit)/8) & 0xffff)))

#define H_DmaCopyIf(DmaNo, Srcp, Destp, Size, Bit)          \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_H_BLANK |          \
        DMA_IF_ENABLE      |                                \
        DMA_SRC_INC        | DMA_DEST_RELOAD     |          \
        DMA_CONTINUOUS_ON  |                                \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)))

#define H_DmaArrayCopy(  DmaNo, Srcp, Destp, Bit)           \
        H_DmaCopy(       DmaNo, Srcp, Destp, sizeof(Srcp), Bit)

#define H_DmaArrayCopyIf(DmaNo, Srcp, Destp, Bit)           \
        H_DmaCopyIf(     DmaNo, Srcp, Destp, sizeof(Srcp), Bit)


#define V_DmaCopy(DmaNo, Srcp, Destp, Size, Bit)            \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_V_BLANK |          \
        DMA_SRC_INC        | DMA_DEST_INC        |          \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)))

#define V_DmaCopyIf(DmaNo, Srcp, Destp, Size, Bit)          \
                                                            \
    DmaSet(DmaNo, Srcp, Destp,  (                           \
        DMA_ENABLE         | DMA_TIMMING_V_BLANK |          \
        DMA_IF_ENABLE      |                                \
        DMA_SRC_INC        | DMA_DEST_INC        |          \
        DMA_##Bit##BIT_BUS | ((Size)/(Bit/8) & 0xffff)))

#define V_DmaArrayCopy(  DmaNo, Srcp, Destp, Bit)           \
        V_DmaCopy(       DmaNo, Srcp, Destp, sizeof(Srcp), Bit)

#define V_DmaArrayCopyIf(DmaNo, Srcp, Destp, Bit)           \
        V_DmaCopyIf(     DmaNo, Srcp, Destp, sizeof(Srcp), Bit)

#if 1
#define DmaSound(DmaNo, Srcp, FifoName)                             \
{                                                                   \
    u8    i;                                                        \
    *((u8 *)(REG_SOUNDCNT + 3)) |= SOUND_##FifoName##_FIFO_RESET;   \
    for (i=0; i<8; i++)                                             \
        *(u32 *)REG_FIFO_##FifoName = ((u32 *)Srcp)[i];             \
    DmaSet( DmaNo, (u32 *)Srcp + 8, REG_FIFO_##FifoName, (          \
        DMA_ENABLE         | DMA_TIMMING_SOUND |                    \
        DMA_CONTINUOUS_ON  |                                        \
        DMA_SRC_INC        |                                        \
        DMA_32BIT_BUS      | (4*4)/(32/8)))                         \
}

#define DmaSoundIf(DmaNo, Srcp, FifoName)                           \
{                                                                   \
    u8    i;                                                        \
    *((u8 *)(REG_SOUNDCNT + 3)) |= SOUND_##FifoName##_FIFO_RESET;   \
    for (i=0; i<8; i++)                                             \
        *(u32 *)REG_FIFO_##FifoName = ((u32 *)Srcp)[i];             \
    DmaSet( DmaNo, (u32 *)Srcp + 8, REG_FIFO_##FifoName, (          \
        DMA_ENABLE         | DMA_TIMMING_SOUND |                    \
        DMA_IF_ENABLE      |                                        \
        DMA_CONTINUOUS_ON  |                                        \
        DMA_SRC_INC        |                                        \
        DMA_32BIT_BUS      | (4*4)/(32/8)))                         \
}
#else
#define DmaSound(DmaNo, Srcp, FifoName)                             \
                                                                    \
    DmaSet( DmaNo, Srcp, REG_FIFO_##FifoName, (                     \
        DMA_ENABLE         | DMA_TIMMING_SOUND |                    \
        DMA_CONTINUOUS_ON  |                                        \
        DMA_SRC_INC        |                                        \
        DMA_32BIT_BUS      | (4*4)/(32/8)))

#define DmaSoundIf(DmaNo, Srcp, FifoName)                           \
                                                                    \
    DmaSet(DmaNo, Srcp, REG_FIFO_##FifoName, (                      \
        DMA_ENABLE         | DMA_TIMMING_SOUND |                    \
        DMA_IF_ENABLE      |                                        \
        DMA_CONTINUOUS_ON  |                                        \
        DMA_SRC_INC        |                                        \
        DMA_32BIT_BUS      | (4*4)/(32/8)))
#endif

// Set DMA for Direct Sound.
// DmaSoundIf generates an Interrupt Request when ending.
//
// Arguments:
//  DmaNo       DMA Number
//  Srcp        Source Address
//  FifoName    Destination Address


/*------------------------------------------------------------------*/
/*                      DMA End Wait                                */
/*------------------------------------------------------------------*/

#define DmaWait(DmaNo)                                      \
{                                                           \
    vu32 *(DmaCntp) = (vu32 *)REG_DMA##DmaNo;               \
    while (DmaCntp[2] & DMA_ENABLE) ;                       \
}

//* Wait for DMA End.
//
//* Arguments:
//  DmaNo       DMA Number


/*------------------------------------------------------------------*/
/*                      DMA Stop                                    */
/*------------------------------------------------------------------*/

#define DmaStop(DmaNo)                                      \
{                                                           \
    vDmaCnt *(DmaCntp) = (vDmaCnt *)REG_DMA##DmaNo;         \
    DmaCntp[2].Enable = 0;                                  \
}

//KEYS--------------------------------------------------------
extern vu16 Cont;
extern vu16 Trg;
void KeyInit( void );					//��ʼ������
void KeyRead( void );					//�õ�����

//INTR-----------------------------------------------------

//����ж�
#define IntrCheckSet(Flag)                              \
                                                        \
    *(vu16 *)INTR_CHECK_BUF = (vu16 )Flag

//�����жϷ����������
typedef void (*IntrFuncp)(void);

//--------------------- Local variables  ---------------------------
extern vu16 IntrCheck;	//  Interrupt check flag

extern u32	IntrMainBuf[0x200];	// Buffer for interrupt main routine
extern void intr_main(void);

void GsOpenIRQ(void);	//�жϳ�ʼ����

void dummy(void);		//�պ���
void V_Intr_Clear(void);	//���V�жϼ��
void V_Intr_Set(void);		//����V�жϼ��
void V_Wait(void);			//�ȴ�V�ж�����

//TIMER
void GsOpenTimerIRQ(int no);   //��ʱ���ж�
void GsStartTIMER(int no);		//��ʼ��ʱ
void GsSelectTM(int no,int htno);//ѡ��һ��Ӳ��ʱ��
void GsSetCount(int no ,u16 num);	//���ü�����ֵ




extern u8 gBaseAddrWRAM;

u8   *wram_pool_alloc(u32 _size);
void wram_pool_reset();


#endif