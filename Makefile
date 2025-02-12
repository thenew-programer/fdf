# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 14:28:19 by ybouryal          #+#    #+#              #
#    Updated: 2025/02/12 16:05:29 by ybouryal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		:= $(shell tput -Txterm setaf 2)
BOLD		:= $(shell tput bold);
RESET		:= $(shell tput -Txterm sgr0)

CC			= cc
#CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -I /usr/include/minilibx-linux -O3
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -O3
#LDFLAGS		= -L$(LIBFT_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz -L /usr/include/minilibx-linux -lmlx_Linux
LDFLAGS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -l$(MLXLIB) -L/usr/lib -lXext -lX11 -lm -lz
RM			= rm -rf

SRCS_DIR	= src
BSRCS_DIR	= src_bonus
OBJS_DIR	= obj
BOBJS_DIR	= obj_bonus
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLXLIB		= mlx_Linux
MLX_DIR		= mlx_linux
# MLX_DIR		= /usr/include/minilibx-linux
HEAD		= inc

MFILES		= movements.c color.c dealloc.c err.c hooks.c main.c project.c \
			  utils.c draw.c graphics.c map.c parser.c renderer.c
BFILES		= movements_1_bonus.c err_bonus.c graphics_bonus.c dealloc_bonus.c \
			  hooks_bonus.c map_bonus.c main_bonus.c menu_help_1_bonus.c \
			  project_bonus.c movements_2_bonus.c menu_help_2_bonus.c renderer_bonus.c \
			  color_bonus.c draw_bonus.c menu_bonus.c  parser_bonus.c utils_bonus.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(MFILES))
BSRCS		= $(addprefix $(BSRCS_DIR)/, $(BFILES))
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BOBJS		= $(patsubst $(BSRCS_DIR)/%.c, $(BOBJS_DIR)/%.o, $(BSRCS))

NAME		= fdf
BNAME		= fdf_bonus

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(OBJS) -o $@ $(LDFLAGS)
			@echo "$(BOLD)$(GREEN)$(NAME) compiled Successfully$(RESET)"

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $(NAME) ..."

bonus:		$(BNAME)

$(BNAME):	$(BOBJS) $(LIBFT)
			@$(CC) $(BOBJS) -o $@ $(LDFLAGS)
			@echo "$(BOLD)$(GREEN)$(BNAME) compiled successfully$(RESET)"

$(BOBJS_DIR)/%.o:	$(BSRCS_DIR)/%.c
			@mkdir -p $(BOBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $(BNAME) ..."

$(LIBFT):
			@$(MAKE) all bonus -C $(LIBFT_DIR)

clean:
			@$(RM) $(OBJS_DIR)
			@$(RM) $(BOBJS_DIR)
			@$(MAKE) clean -C $(LIBFT_DIR)
			@echo "Cleaning obj files."

fclean:	
			@echo "Cleaning all files."
			@$(MAKE) clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(MAKE) fclean -C $(LIBFT_DIR)

re:
			@echo "Rebuild $(NAME)"
			@$(MAKE) fclean
			@$(MAKE) all

.PHONY: all clean fclean re bonus
.SECONDARY:	$(OBJS) $(BOBJS) $(LIBFT)
