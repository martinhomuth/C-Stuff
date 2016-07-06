Q = #@    						# quiet the make process

P = cstuff						# the application
P_OBJECTS = menu.o					# how the application is built
BINDIR = ../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS = -lX11
# use the newest standard by default
CC=gcc -std=c11

all: $(BINDIR)/$(P) $(BINDIR)/gcd

$(BINDIR)/$(P): $(P_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

$(BINDIR)/gcd: euklid_test.o euklid.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o
