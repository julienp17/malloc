##
## EPITECH PROJECT, 2021
## Malloc
## File description:
## Makefile
##

CC			=	gcc

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=	malloc/malloc.c \
				malloc/first_malloc.c \
				malloc/add_block.c \
				malloc/bestfit.c \
				heap/heap.c \
				free/free.c \
				free/defragment.c \
				mem_block_wrapper.c \

SRC_UT		=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT		=	$(SRC_UT:.c=.o)
SRC_UT_D	=	tests/
SRC_UT_F	=

INC			=	-I./inc

CFLAGS		=	-W -Wall -Wextra -Werror -fpic $(INC)

LDFLAGS_UT  =	-lcriterion --coverage

DBFLAGS		=	-g -g3 -ggdb

LIB			=	libmy_malloc.so

BIN_UT		=	unit_tests

all: $(LIB)

.PHONY: all
$(LIB): $(SRC:.c=.o)
	$(CC) -shared -o $(LIB) $(SRC) $(CFLAGS)

.PHONY: perfect
perfect:
	$(CC) -o $(LIB) $(MAIN) $(SRC) $(CFLAGS) -Wpedantic

.PHONY: debug
debug:
	$(CC) -o $(LIB) $(MAIN) $(SRC) $(CFLAGS) $(DBFLAGS)

.PHONY: tests_run
tests_run: clean $(SRC) $(OBJ_UT)
	$(CC) -o $(BIN_UT) $(SRC) $(OBJ_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(BIN_UT)

.PHONY: coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_UT)
	rm -f *.o
	rm -f *.gc*

.PHONY: fclean
fclean: clean
	rm -f $(LIB)
	rm -f $(BIN_UT)

.PHONY: re
re: fclean all