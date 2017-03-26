Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11

PROGS = SetTest BagTest

OBJS = $(addprefix $(BINDIR)/, $(PROGS))

all: $(OBJS)

$(BINDIR)/SetTest: SetTest.o Set.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/BagTest: SetTest.o Bag.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/Bag:

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

