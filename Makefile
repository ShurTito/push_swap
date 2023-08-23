#./push_swap 58 65 25 11 8 9 2 1 66 42 14 59

NAME = push_swap

NAME_BONUS = checker

SRC = src/push_swap.c src/check_arg_int.c src/push_swap_utils.c src/push_swap_moves.c\
	src/push_swap_moves_2.c src/push_swap_moves_3.c src/algorithm.c src/algorithm_utils.c\
	src/algorithm_utils_2.c src/algorithm_utils_3.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = srcb/checker.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP = push_swap.a

PUSH_SWAP_BONUS = checker.a

LIB = ar rcs

RM = rm -fr

$(NAME) :	$(OBJ) $(LIBFT)
			@$(LIB) $(PUSH_SWAP) $(OBJ)
			@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(OBJ) $(LIBFT)
			@$(LIB) $(PUSH_SWAP_BONUS) $(OBJ_BONUS) $(OBJ)
			@$(CC) $(CFLAGS) $(PUSH_SWAP_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJ):	src/%.o : src/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS):	srcb/%.o : srcb/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)

all : $(NAME)

bonus : $(NAME_BONUS)

clean:
			@$(RM) $(OBJ) $(OBJ_BONUS)
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@$(RM) $(NAME) $(NAME_BONUS) $(OBJ) $(OBJ_BONUS) $(LIBFT) $(PUSH_SWAP) $(PUSH_SWAP_BONUS)
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

.PHONY : all re fclean clean bonus		