###############################################################################
##                                                                           ##
##         Makefile for example and test-program for findProcesses()         ##
##                                                                           ##
##---------------------------------------------------------------------------##
## File:   ~/example/pidof/makefile                                          ##
## Author: Ulrich Becker                                                     ##
## Date:   17.01.2017                                                        ##
###############################################################################
BASEDIR = ../../src
SOURCES = test.c $(BASEDIR)/find_process.c
EXE_NAME = t1

VPATH= $(BASEDIR)
INCDIR = $(BASEDIR)
CFLAGS = -g -O0

CC     ?= gcc
CFLAGS += $(addprefix -I,$(INCDIR))

OBJDIR=.obj


OBJ = $(addprefix $(OBJDIR)/,$(addsuffix .o,$(notdir $(basename $(SOURCES)))))

.PHONY: all 
all: $(EXE_NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c $(SOURCES) $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE_NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(EXE_NAME) core
	rmdir $(OBJDIR)
	
#=================================== EOF ======================================
