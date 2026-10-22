
# Part 1 - the administrator's toolkit: one small program per phenomenon
CFLAGS=-Wall -std=c99 -D_POSIX_C_SOURCE=200809L
INCLUDES=-I./inc

PROGS=fork_demo zombie_demo orphan_demo status_demo exec_demo hello redirect_demo

all: $(PROGS)

%_demo: src/%.o src/errExit.o
	@echo "Making executable: "$@
	@$(CC) $^ -o $@

hello: src/hello.o
	@echo "Making executable: "$@
	@$(CC) $^ -o $@

src/%.o: src/%.c
	@echo "Compiling: "$<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean
.SECONDARY:

clean:
	@rm -f src/*.o $(PROGS) demo.log
	@echo "Removed object files and executables..."
