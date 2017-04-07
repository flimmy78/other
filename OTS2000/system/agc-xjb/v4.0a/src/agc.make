## -*- Makefile -*-
##
## User: ems
## Time: 2007-5-8 21:23:33
## Makefile created by the Native Languages Module.
##
## This file is generated automatically -- Changes will be lost if regenerated
##


#### Compiler and tool definitions shared by all build targets #####
include ../../../global.make

CFLAGS = $(BASICOPTS) -c

# Define the target directories.
TARGETDIR=.
TARGET=agc-xjb.$(SUFFIX)

all: $(TARGETDIR)/$(TARGET)

OBJS =  \
	$(TARGETDIR)/agc.o 
	
USERLIBS = ../../../dps/v4.0a/lib/dpslib.lib ../../../lan/v4.0a/lib/lan.lib ../../../dms/v4.0a/lib/dblib.lib ../../../dps/v4.0a/lib/ipclib.lib $(SYSLIBS) 
DEPLIBS =    
LDLIBS = $(USERLIBS)


# Link or archive
$(TARGETDIR)/$(TARGET): $(TARGETDIR) $(OBJS) $(DEPLIBS)
	$(LINK) -o $@ $(OBJS) $(LDLIBS)


# Compile source files into .o files
$(TARGETDIR)/agc.o: $(TARGETDIR) agc.c
	$(COMPILE) $(CFLAGS) $(CPPFLAGS) -o $@ agc.c


#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR)/$(TARGET) \
		$(OBJS)
		
# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state

