# GsLIB System PATH
# GsLIB��װ·��
GsINC	=  $(GSDIR)\include
GsLIB	=  $(GSDIR)\lib


ASFLAGS = -CPU ARM7TDMI -Littleend

CFLAGS	= -c -Wall -I "$(GsINC)" -cpu ARM7TDMI -fpu none -W -apcs /narrow/noswst -Otime

LDFLAGS = -bin -errors log.txt -map -ro-base 0x08000000 -rw-base 0x03000000


CC      =       zarmcc
CP      =       zarmcpp
LD      =       zarmlink
AS      =       zarmasm

#��Ϸ�����ļ�

LIBFILE = "$(GsLIB)\GsLIB.a"

VBOY 	= "$(GSDIR)\tools\vgba.exe"

SFILES	= "$(GsINC)\boot.s"

BOOTFILES	=	boot.o

OFILES		=	$(CFILES:.c=.o)

DEPENDFILE =   Makedepend

$(TARGET).bin:$(BOOTFILES) $(OFILES)
	$(LD)  $(LDFLAGS) -first $(BOOTFILES) $(OFILES) $(LIBFILE) -o $(TARGET).bin $(OFILES) $(BOOTFILES)
$(BOOTFILES):$(SFILES)
	$(AS) $(ASFLAGS) $(SFILES) -o boot.o

$(OFILES):$(@:.o=.c)
	$(CC) -I"$(GsINC)" $(CFLAGS) $(@:.o=.c) -o $@

.PHONY:all clean $(TARGET).bin

all:$(TARGET).bin

clean:
	@-if exist *.bin del *.bin
	@-if exist log.txt del log.txt
	@-if exist *.o del *.o
	@-if exist dir.cfg del dir.cfg
	@-if exist Makedepend del Makedepend
	@echo All generated files have been cleaned!!!
vba:all
	$(VBOY) $(TARGET).bin

!INCLUDE Makedepend
