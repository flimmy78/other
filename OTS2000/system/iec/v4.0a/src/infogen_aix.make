## -*- Makefile -*-
##
## Project: infogen.prd
## User: ems
## Time: 06/04/20 15:37:00
## Makefile created by Sun WorkShop.
##
## This file is generated automatically -- DO NOT EDIT.
##



project: /home/ems/system/iec/v4.0a/src/infogen.dxe 

##### Compilers and tools definitions shared by all build objects #####
#CC=/opt/SUNWspro/bin/../WS6U1/bin/cc
CC = gcc
BASICOPTS = -g
CFLAGS = $(BASICOPTS)

COMPILE.c = $(CC)
CFLAGS_INFOGEN.DXE = $(CFLAGS) -c
CPPFLAGS_INFOGEN.DXE = $(CPPFLAGS)

LINK.c = $(COMPILE.c) $(LDFLAGS) $(TARGET ARCH)

###### Target: infogen.dxe ######
TARGETDIR_INFOGEN.DXE=/home/ems/system/iec/v4.0a/src
CPPFLAGS_INFOGEN.DXE += \
	-I/usr/openwin/include \
	-I/usr/dt/include 
OBJS_INFOGEN.DXE = \
	$(TARGETDIR_INFOGEN.DXE)/infogen.o \
	/home/ems/system/dms/v4.0a/lib/dblib.lib \
	/home/ems/system/dps/v4.0a/lib/ipclib.lib


# Link or archive
/home/ems/system/iec/v4.0a/src/infogen.dxe: $(OBJS_INFOGEN.DXE) 
	$(LINK.c) -o $@ $(OBJS_INFOGEN.DXE) \
	/home/ems/system/dms/v4.0a/lib/dblib.lib \
	/home/ems/system/dps/v4.0a/lib/ipclib.lib -lnsl -lpthread #-lsocket
## .a's were added twice to link line to make sure they are found in a link.


# Compile source files into .o's
$(TARGETDIR_INFOGEN.DXE)/infogen.o: infogen.c
	$(COMPILE.c) $(CFLAGS_INFOGEN.DXE) $(CPPFLAGS_INFOGEN.DXE) -o $(TARGETDIR_INFOGEN.DXE)/infogen.o infogen.c


###### clean target: deletes generated files ######
clean:
	$(RM) \
	/home/ems/system/iec/v4.0a/src/infogen.dxe \
	$(TARGETDIR_INFOGEN.DXE)/infogen.o 

# Enable dependency checking
#.KEEP_STATE:
#.KEEP_STATE_FILE: /home/ems/system/iec/v4.0a/src/.make.state.Makefile.ems.infogen
