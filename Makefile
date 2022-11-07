NAME = push_swap
CC = cc
INC = ./includes
LIBFT = ./libft

LIB_LIBFT = $(LIBFT)/libft.a
OBJS_DIR = obj
SRC_DIR = src
FLAGS = -I $(INC)
LINKERS = -L$(LIBFT) -lft

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC))

RM = rm -rf
MKDIR = mkdir -p
.DEFAULT_GOAL = all

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR) :
	$(MKDIR) $(OBJS_DIR)

all : $(NAME)

$(NAME): $(LIB_LIBFT) $(OBJ) | $(OBJS_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LINKERS)

$(LIB_LIBFT):
	make bonus -C ./libft

clean:
	$(RM) $(OBJS_DIR)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus
