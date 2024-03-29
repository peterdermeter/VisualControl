#############################################################################
# Makefile for building: Visual_Control_Endoscope
# Generated by qmake (2.01a) (Qt 4.8.5) on: So 15. Sep 11:15:47 2013
# Project:  Visual_Control_Endoscope.pro
# Template: app
# Command: c:\QtSDK\Desktop_Qt4.8.5\bin\qmake.exe -spec c:\QtSDK\Desktop_Qt4.8.5\mkspecs\win32-msvc2010 CONFIG+=release -o Makefile Visual_Control_Endoscope.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = c:\QtSDK\Desktop_Qt4.8.5\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: Visual_Control_Endoscope.pro  c:\QtSDK\Desktop_Qt4.8.5\mkspecs\win32-msvc2010\qmake.conf c:\QtSDK\Desktop_Qt4.8.5\mkspecs\qconfig.pri \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\modules\qt_webkit_version.pri \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt_functions.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt_config.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\exclusive_builds.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\default_pre.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\default_pre.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\release.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\debug_and_release.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\default_post.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\default_post.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\serialport.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\rtti.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\exceptions.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\stl.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\shared.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\embed_manifest_exe.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\embed_manifest_dll.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\warn_on.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\thread.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\moc.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\windows.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\resources.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\uic.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\yacc.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\lex.prf \
		c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\include_source_dir.prf \
		c:\QtSDK\Desktop_Qt4.8.5\lib\qtmain.prl \
		c:\QtSDK\Desktop_Qt4.8.5\lib\QtSerialPort.prl
	$(QMAKE) -spec c:\QtSDK\Desktop_Qt4.8.5\mkspecs\win32-msvc2010 CONFIG+=release -o Makefile Visual_Control_Endoscope.pro
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\qconfig.pri:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\modules\qt_webkit_version.pri:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt_functions.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt_config.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\exclusive_builds.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\default_pre.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\default_pre.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\release.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\debug_and_release.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\default_post.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\default_post.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\serialport.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\rtti.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\exceptions.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\stl.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\shared.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\embed_manifest_exe.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\embed_manifest_dll.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\warn_on.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\qt.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\thread.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\moc.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\win32\windows.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\resources.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\uic.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\yacc.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\lex.prf:
c:\QtSDK\Desktop_Qt4.8.5\mkspecs\features\include_source_dir.prf:
c:\QtSDK\Desktop_Qt4.8.5\lib\qtmain.prl:
c:\QtSDK\Desktop_Qt4.8.5\lib\QtSerialPort.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec c:\QtSDK\Desktop_Qt4.8.5\mkspecs\win32-msvc2010 CONFIG+=release -o Makefile Visual_Control_Endoscope.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
	-$(DEL_FILE) ".\Visual_Control_Endoscope.intermediate.manifest"
	-$(DEL_FILE) Visual_Control_Endoscope.exp
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

release-mocclean: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
