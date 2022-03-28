##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Create an archive of the library
##

CC	=	gcc

SRC	=	./src/handle_main_errors.c	\
		./src/eval_expr.c	\
		./src/calculations.c	\
		./src/number.c	\
		./src/close_par.c	\
		./src/handle_calculations_error.c	\
		./src/usage.c	\
		./src/eval_expr_infin/eval_expr_infin.c	\
		./src/eval_expr_infin/infin_add.c	\
		./src/eval_expr_infin/infin_sub.c	\
		./src/eval_expr_infin/parse_numbers.c	\
		./src/eval_expr_infin/find_sign.c

MAIN	=	./main.c

TESTSRC	=	./tests/test_eval_expr.c	\
		./tests/test_infin_add.c	\
		./tests/infin_sub/test_find_greatest_str.c	\
		./tests/infin_sub/test_get_size_longest_str.c	\
		./tests/infin_sub/test_infin_sub_find_sign.c

OBJ	=	$(SRC:.c=.o)

OBJMAIN	=	$(MAIN:.c=.o)

OBJTEST	=	$(TESTSRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -W

LFLAGS	=	-L./lib -lmy

LIB_PATH	=	./lib/my

HEADER_PATH     =       ./include

CPPFLAGS	=	-I./include

COVFLAGS	=	--coverage -lcriterion

NAME	=	calc

NAMETEST	=	unit-tests

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJMAIN)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -g3 -o $(NAME) $(OBJ) $(OBJMAIN) $(LFLAGS) $(CFLAGS)

debug:	$(OBJ) $(OBJTEST)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAMETEST) $(OBJ) $(OBJTEST) $(CPPFLAGS) $(LFLAGS) $(COVFLAGS)
	valgrind ./unit-tests

tests_run:	$(OBJ) $(OBJTEST)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAMETEST) $(OBJ) $(OBJTEST) $(CPPFLAGS) $(LFLAGS) $(COVFLAGS)
	./unit-tests

clean:
	$(MAKE) -C $(LIB_PATH) fclean
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)
	$(RM) $(OBJTEST)


fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAMETEST)
	$(RM) $(OBJTEST)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *~

re:	fclean all
