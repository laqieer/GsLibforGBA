@echo off
@echo #test > dir.cfg
if exist Makedepend goto make
ren makefile Makefile.bak
@copy %GSDIR%\system\Makedep Makefile
nmake -nologo /I 
del Makefile
ren Makefile.bak Makefile

:make
@echo include %GSDIR%\system\system.mak > dir.cfg
nmake -nologo /I %1
@echo on