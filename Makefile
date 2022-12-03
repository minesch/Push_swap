NAME = push_swap
BONUS = checker
CC = cc
OBJS_DIR = objs
BONUS_OBJS_DIR = objs_bonus
SRCS_DIR = src
BONUS_DIR = src_bonus
FLAGS =  -Wall -Werror -Wextra -g -Iincludes #-fsanitize=address
SRCS = $(wildcard $(SRCS_DIR)/*.c)
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUS_DIR)/%.c, $(BONUS_OBJS_DIR)/%.o, $(BONUS_SRCS))
RM = rm -rf
MKDIR = mkdir -p
LIBFT = ./libft

L_LIBFT = $(LIBFT)/libft.a
.DEFAULT_GOAL = all
all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(BONUS_OBJS_DIR):
	$(MKDIR) $(BONUS_OBJS_DIR)

$(NAME):  $(OBJS) | $(OBJS_DIR)
		  make bonus -C ./libft
		$(CC) $(L_LIBFT) $(FLAGS) -o $(NAME) $(OBJS)

$(LIB_LIBFT):
	make bonus -C ./libft

bonus:	all $(BONUS)

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c | $(BONUS_OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(BONUS): $(BONUS_OBJS) | $(BONUS_OBJS_DIR)
	$(CC) $(L_LIBFT) $(FLAGS) -o $(BONUS) $(BONUS_OBJS)
clean:
	$(RM) $(OBJS_DIR) $(BONUS_OBJS_DIR)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus push
