Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11

PROGS = Set \
	Bag

OBJS = $(addprefix $(BINDIR)/, $(PROGS))

all: $(OBJS)

$(BINDIR)/Set: Set.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/Bag:

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

