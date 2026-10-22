
CFLAGS=-Wall -std=c99 -D_POSIX_C_SOURCE=200809L
INCLUDES=-I./inc

GENERATOR_SRCS=src/errExit.c src/generator.c
MULTIPLIER_SRCS=src/report.c src/multiplier.c

GENERATOR_OBJS=$(GENERATOR_SRCS:.c=.o)
MULTIPLIER_OBJS=$(MULTIPLIER_SRCS:.c=.o)

all: generator multiplier

generator: $(GENERATOR_OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o $@

multiplier: $(MULTIPLIER_OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o $@

.c.o:
	@echo "Compiling: "$<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean

clean:
	@rm -f src/*.o generator multiplier
	@echo "Removed object files and executables..."
