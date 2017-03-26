Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11

PROGS = SetTest

OBJS = $(addprefix $(BINDIR)/, $(PROGS))

all: $(OBJS)

$(BINDIR)/SetTest: SetTest.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/Bag:

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

