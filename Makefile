# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:54:21 by nrossa            #+#    #+#              #
#    Updated: 2023/11/08 04:33:46 by nrossa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean norme

NAME = so_long
MLX_DIR = ./minilibx-linux/
MLX = $(MLX_DIR)libmlx_Linux.a
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
MM_DIR = ./map_management/
WM_DIR = ./window_maker/
SS_DIR = ./skin_select/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -lmlx -lX11 -lXext
RM = /bin/rm -f

HDR = so_long.h define.h $(MM_DIR)map_management.h $(WM_DIR)window_maker.h $(SS_DIR)skin_select.h
SRC = so_long.c $(addprefix $(MM_DIR), $(MM_SRC)) $(addprefix $(WM_DIR), $(WM_SRC)) $(addprefix $(SS_DIR), $(SS_SRC))
MM_SRC = ft_check_map.c ft_get_map.c ft_check_extension.c ft_find_path.c ft_map_error.c ft_map_utils.c
SS_SRC = ft_skin_select.c ft_skin_error.c ft_check_skin.c ft_check_sprite.c ft_skin_utils.c
WM_SRC = ft_window_maker.c ft_set_img.c ft_put_img.c ft_draw_img.c ft_unset_img.c ft_set_map.c ft_render.c ft_hook.c ft_move.c ft_attack.c ft_winmaker_utils.c
OBJS = $(SRC:.c=.o)

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
WHITE = \033[37m
NC = \033[0m

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(RED)Compilation in progress...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LIBFLAGS)
	@echo "$(GREEN)Compilation complete !$(NC)"

all: $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Creating libft...$(NC)"
	@make -s -C $(LIBFT_DIR) all

$(MLX):
	@echo "$(YELLOW)Creating libmlx...$(NC)"
	@chmod 777 $(MLX_DIR)configure
	@make -s -C $(MLX_DIR)

bonus: $(NAME)

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@make -s -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "$(GREEN)Cleaning complete !$(NC)"

fclean: clean
	@echo "$(YELLOW)Cleaning libft library...$(NC)"
	@make -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(GREEN)Cleaning complete !$(NC)"

re: fclean all

norme:
	@echo "$(YELLOW)Checking Norme...$(NC)"
	@norminette $(SRC) $(HDR)
	@echo "$(GREEN)Checking complete !$(NC)"

compilation: $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -g -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(LIBFLAGS)

noflags: $(LIBFT) $(MLX)
	@$(CC) -g -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(LIBFLAGS)

def: $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -g -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(LIBFLAGS) -D SKIN_DIR="\"./skin/\""
