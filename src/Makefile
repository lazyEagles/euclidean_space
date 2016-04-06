
IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -lm -g

BDIR=../bin
ODIR=../obj
TDIR=../test

# add *.h to _DEPS
_DEPS=
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#$(BDIR)/%: $(ODIR)/%.o 
#	$(CC) -o $@ $(ODIR)/*.o $(CFLAGS)

#$(TDIR)/%: $(ODIR)/%.o $(TDIR)/*.c
#	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o; find $(BDIR) -type f -not -name '.md' | xargs rm; find $(TDIR) -type f -not -name '.md' | args rm
