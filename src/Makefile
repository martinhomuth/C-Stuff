Q = #@    						# quiet the make process

P = cstuff						# the application
P_OBJECTS = menu.o					# how the application is built
BINDIR = ../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC=gcc -std=c11						# use the newest standard by default

all: $(BINDIR)/$(P)

$(BINDIR)/$(P): $(P_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	$(Q)$(RM) $(BINDIR)/$(P)
	$(Q)$(RM) *.o
