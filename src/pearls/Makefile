Q = #@

BINDIR = ../../bin
CFLAGS = -Wall -pedantic -Werror -g
LDLIBS =
CC = gcc --std=c11


all: $(BINDIR)/0102_bitvector_test \
	$(BINDIR)/0202_bitmap_sort \
	$(BINDIR)/gen_numbers \
	$(BINDIR)/gen_unique_numbers \
	$(BINDIR)/020601_anagram_dict \
	$(BINDIR)/0301_tax_income \
	$(BINDIR)/0301_tax_income_test

$(BINDIR)/gen_numbers: generate_numbers.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/gen_unique_numbers: generate_unique_numbers.o bitvectors.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/0102_bitvector_test: bitvector_test.o bitvectors.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/0202_bitmap_sort: bitmap_sort.o bitvectors.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/020601_anagram_dict: anagram_dict.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BINDIR)/0301_tax_income: tax_income_standalone.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

tax_income_standalone.o: tax_income.c
	$(CC) $(CFLAGS) -DSTANDALONE_BIN -c $^ -o $@

$(BINDIR)/0301_tax_income_test: tax_income_test.o tax_income.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)


clean:
	$(Q)$(RM) $(BINDIR)/*
	$(Q)$(RM) *.o

