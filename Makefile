PROGRAM_NAME = doner
OUTPUT_NAME = $(PROGRAM_NAME).elf

CC          = gcc
RM          = rm

DIR_SRC     = code

SRC         = $(DIR_SRC)/main.c

CFLAGS      = -Wall -Wextra -Werror -std=c99
LDFLAGS     = 

.PHONY: all clean

all: $(OUTPUT_NAME)

$(OUTPUT_NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

clean:
	$(RM) -f $(OUTPUT_NAME)
