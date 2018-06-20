# Typical directories to use
BDIR	=	bin
IDIR	=	inc
ODIR	=	obj
LDIR	=	lib
SDIR	=	src

# Some useful flags
CC		=	gcc
CFLAGS	=	-I$(IDIR) -Wall -ansi -g

# Binutils libraries
LIBS	=	-lm

# Specify dependencies
_DEPS	=	client.h
DEPS	=	$(patsubst %,$(IDIR)/%,$(_DEPS))

# Specify objects/shared objects
_OBJ	=	client.o
OBJ		=	$(patsubst %,$(ODIR)/%,$(_OBJ))

# Rules for objects
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rules for binaries
client: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

# General rule
all: client

# Don't interpret any file called "clean"!
.PHONY: clean

# General rule to clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f $(BDIR)/*
