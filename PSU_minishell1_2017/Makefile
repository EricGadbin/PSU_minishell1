##
## EPITECH PROJECT, 2018
## Project mysh
## File description:
## Build mysh binary.
##

MAIN_SRC	=	src/main.c

SRC	=		src/utilities.c \
			src/updateenv_and_cd.c \
			src/fork_and_exit.c \
			src/prompt_and_access.c \
			src/finder.c \
			src/utilities2.c \
			src/cleaner.c \
			src/env.c \
			src/check_setenv.c

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Wextra -W -Wall -I ./include/ -L./include/ -lgnl

LDFLAGS	=

NAME	=	mysh

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f units
	rm -f *.html
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re: fclean all

test_run:	CFLAGS += --coverage

test_run:	$(UT_OBJ)
		$(CC) -o units $(UT_OBJ) $(LDFLAGS) -lcriterion --coverage
		./units

cov:	test_run
	gcovr -r . --html -o coverage.html --html-details -e ".*tests/.*"
