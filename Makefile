NAME:= fdf

MLX_DIR:= minilibx-linux
MLX:= $(MLX_DIR)/libmlx.a

LFT_DIR:= libft
LFT:= $(LFT_DIR)/libft.a

CFLAGS:= -Wall -Wextra -Werror -g -o0
LIB_FLAGS:= -lm -lXext -lX11

SRC_DIR:= src
OBJ_DIR:= obj

SRC_FILES:= main utils window draw
SRC:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC_FILES)))
OBJ:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(MLX) $(LFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJ) $(MLX) $(LFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LFT):
	$(MAKE) -C $(LFT_DIR)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LFT_DIR)
	rm -f $(NAME)

re: fclean all
