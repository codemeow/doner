PROGRAM_NAME := doner

CC           := gcc
RM           := rm

DIR_SRC      := code
SRC          := $(shell find $(DIR_SRC) -type f -name '*.c' | xargs echo)

CFLAGS       := -Wall -Wextra -Werror -std=c99 -O3
DFLAGS       := -D _GNU_SOURCE
LDFLAGS      := -l m

.PHONY: all clean

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(SRC)
	$(CC) $(CFLAGS) $(DFLAGS) $(SRC) -o $@ $(LDFLAGS)

clean:
	$(RM) -f $(PROGRAM_NAME)
