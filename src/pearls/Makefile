Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11


all: $(BINDIR)/0102_bitvectors

$(BINDIR)/0102_bitvectors: bitvectors.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

