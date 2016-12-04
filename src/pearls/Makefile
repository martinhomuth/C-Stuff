Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11


all: $(BINDIR)/0102_bitvector_test \
	$(BINDIR)/0202_bitmap_sort

$(BINDIR)/0102_bitvector_test: bitvector_test.o bitvectors.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)


clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

