# GsLIB System PATH
# GsLIB安装路径
GsINC	=	$(GSDIR)\include
GsLIB	=	$(GSDIR)\lib


ASFLAGS	=	-CPU ARM7TDMI -Littleend -32

CFLAGS	=	-c -Wall -I "$(GsINC)" -cpu ARM7TDMI -fpu none -W -apcs /narrow/noswst -Otime

LDFLAGS	=	-bin  -errors log.txt -map -ro-base 0x08000000 -rw-base 0x03002bd0


CC	=	armcc
CP	=	armcpp
LD	=	armlink
AS	=	armasm

#游戏所用文件

LIBFILE	=	"$(GsLIB)\GsLIB.a"

VBOY	=	"$(GSDIR)\tools\vgba.exe"

SFILES	=	"$(GsINC)\boot.s"

ASFILES	=	$(SFILES) $(ASFILES)

BOOTFILES	=	boot.o

SOFILES	=	$(ASFILES:.s=.o)

OFILES	=	$(OFILES) $(CFILES:.c=.o)

DEPENDFILE	=	Makedepend

$(TARGET).bin:$(SOFILES) $(OFILES)
	$(LD)  $(LDFLAGS) -first $(BOOTFILES) $(OFILES) $(SOFILES) $(USROFILES) $(LIBFILE) -o $(TARGET).bin

#$(BOOTFILES):$(SFILES)
#	$(AS) $(ASFLAGS) $(SFILES) -o boot.o

$(SOFILES):$(@:.o=.s)
	$(AS) $(ASFLAGS) $(@:.o=.s) -o $@

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
