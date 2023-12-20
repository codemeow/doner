PROGRAM_NAME := doner

CC           := gcc
WINCC        := x86_64-w64-mingw32-gcc
RM           := rm

DIR_SRC      := code
SRC          := $(shell find $(DIR_SRC) -type f -name '*.c' | xargs echo)

CFLAGS       := -Wall -Wextra -Werror -std=c99 -O3
DFLAGS       := -D _GNU_SOURCE
LDFLAGS      := -l m

CNIXFLAGS    := -D TARGET_NIX
CWINFLAGS    := -D TARGET_WIN

.PHONY: all clean

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(SRC)
	$(CC) $(CFLAGS) $(CNIXFLAGS) $(DFLAGS) $(SRC) -o $@ $(LDFLAGS)

$(PROGRAM_NAME).exe: $(SRC)
	$(WINCC) $(CFLAGS) $(CWINFLAGS) $(DFLAGS) $(SRC) -o $@ $(LDFLAGS)

clean:
	$(RM) -f $(PROGRAM_NAME)
	$(RM) -f $(PROGRAM_NAME).exe
