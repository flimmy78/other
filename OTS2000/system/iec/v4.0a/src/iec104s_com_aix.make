## -*- Makefile -*-
##
## Project: /home/ems/system/iec/v4.0a/src/iec104s_com.prd
## User: ems
## Time: 06/04/21 11:50:11
## Makefile created by Sun WorkShop.
##
## This file is generated automatically -- DO NOT EDIT.
##



project: /home/ems/system/iec/v4.0a/src/iec104s_com.dxe 

##### Compilers and tools definitions shared by all build objects #####
#CC=/opt/SUNWspro/bin/../WS6U1/bin/cc
CC = gcc
BASICOPTS = -g
CFLAGS = $(BASICOPTS)

COMPILE.c = $(CC)
CFLAGS_IEC104S_COM.DXE = $(CFLAGS) -c
CPPFLAGS_IEC104S_COM.DXE = $(CPPFLAGS)

LINK.c = $(COMPILE.c) $(LDFLAGS) $(TARGET ARCH)


###### Target: /home/ems/system/iec/v4.0a/src/iec104s_com.dxe ######
TARGETDIR_IEC104S_COM.DXE=/home/ems/system/iec/v4.0a/src
CPPFLAGS_IEC104S_COM.DXE += \
	-I/usr/openwin/include \
	-I/usr/dt/include 
OBJS_IEC104S_COM.DXE = \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_app_fun.o \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_com.o \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_fun.o \
	/home/ems/system/dms/v4.0a/lib/dblib.lib \
	/home/ems/system/dps/v4.0a/lib/ipclib.lib \
	/home/ems/system/lan/v4.0a/lib/lan.lib 


# Link or archive
/home/ems/system/iec/v4.0a/src/iec104s_com.dxe: $(OBJS_IEC104S_COM.DXE) 
	$(LINK.c) -o $@ $(OBJS_IEC104S_COM.DXE) \
	/home/ems/system/dms/v4.0a/lib/dblib.lib \
	/home/ems/system/dps/v4.0a/lib/ipclib.lib /home/ems/system/dps/v4.0a/lib/dpslib.lib -lm -lnsl -lthread -lpthread #-lsocket
## .a's were added twice to link line to make sure they are found in a link.


# Compile source files into .o's
$(TARGETDIR_IEC104S_COM.DXE)/iec104s_app_fun.o: iec104s_app_fun.c
	$(COMPILE.c) $(CFLAGS_IEC104S_COM.DXE) $(CPPFLAGS_IEC104S_COM.DXE) -o $(TARGETDIR_IEC104S_COM.DXE)/iec104s_app_fun.o iec104s_app_fun.c
$(TARGETDIR_IEC104S_COM.DXE)/iec104s_com.o: iec104s_com.c
	$(COMPILE.c) $(CFLAGS_IEC104S_COM.DXE) $(CPPFLAGS_IEC104S_COM.DXE) -o $(TARGETDIR_IEC104S_COM.DXE)/iec104s_com.o iec104s_com.c
$(TARGETDIR_IEC104S_COM.DXE)/iec104s_fun.o: iec104s_fun.c
	$(COMPILE.c) $(CFLAGS_IEC104S_COM.DXE) $(CPPFLAGS_IEC104S_COM.DXE) -o $(TARGETDIR_IEC104S_COM.DXE)/iec104s_fun.o iec104s_fun.c


###### clean target: deletes generated files ######
clean:
	$(RM) \
	/home/ems/system/iec/v4.0a/src/iec104s_com.dxe \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_app_fun.o \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_com.o \
	$(TARGETDIR_IEC104S_COM.DXE)/iec104s_fun.o 

# Enable dependency checking
#.KEEP_STATE:
#.KEEP_STATE_FILE: /home/ems/system/iec/v4.0a/src/.make.state.Makefile.ems.iec104s_com
