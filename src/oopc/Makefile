Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc -std=c11

PROGS = set \
	bag

OBJS = $(addprefix $(BINDIR)/, $(PROGS))

all: $(OBJS)

$(BINDIR)/set: set.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/bag:

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

