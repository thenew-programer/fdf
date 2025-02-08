CC			= cc
#CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -I /usr/include/minilibx-linux -O3
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -O3
#LDFLAGS		= -L$(LIBFT_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz -L /usr/include/minilibx-linux -lmlx_Linux
LDFLAGS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
RM			= rm -rf

SRCS_DIR	= src
OBJS_DIR	= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= mlx_linux
HEAD		= inc

SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME		= fdf

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@echo "Building libft"
			@make all bonus -C $(LIBFT_DIR)

bonus:		re

clean:
			$(RM) $(OBJS_DIR)
			@echo "Cleaning libft"
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			@echo "Fcleaning libft"
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: all clean fclean re bonus
