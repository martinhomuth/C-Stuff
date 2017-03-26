Q = #@    						# quiet the make process

P = cstuff						# the application
P_OBJECTS = menu.o					# how the application is built
BINDIR = ../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS = -lX11 -lm
# use the newest standard by default
CC=gcc -std=c11

.PHONY: pearls oopc

all: $(BINDIR)/$(P) $(BINDIR)/gcd $(BINDIR)/fraction $(BINDIR)/convert pearls oopc

pearls:
	$(Q)$(MAKE) -C pearls

oopc:
	$(Q)$(MAKE) -C oopc

$(BINDIR)/$(P): $(P_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

$(BINDIR)/gcd: euklid_test.o euklid.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/fraction: euklid.o fraction.o fraction_test.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/convert: convert_test.o number_util.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o
