CC=gcc
CFLAGS= -O2 -Wall -Werror -Wpedantic -flto -I$(IDIRT) -I$(IDIR) -lcunit

MAIN_PROGRAM=../obj/swordx.o
COMMON_O = $(filter-out $(MAIN_PROGRAM), $(wildcard ../obj/*.o))

BDIR=bin
ODIR=obj
IDIR=../inc
IDIRT=inc

_OBJ = test.o test_trie.o test_word_utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = utils.h trie.h word_utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DEPST = test_trie.h test_word_utils.h
DEPST = $(patsubst %,$(IDIRT)/%,$(_DEPST))

vpath %.c src


test: $(OBJ) $(COMMON_O)
	$(CC) -o $(BDIR)/test $^ $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS) $(DEPST)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean all

clean:
	rm -f $(BDIR)/* $(ODIR)/*

all: test