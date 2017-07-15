# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/06 14:07:33 by dnelson           #+#    #+#              #
#    Updated: 2017/07/15 16:35:55 by dnelson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c \


OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit

LIBFT = ./libft/libft.a
LIBINC = -I./libft/includes
LIBLINK = -L./libft -lft

MINILIBX = ./minilibx/libmlx.a

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj libft minilibx $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

minilibx: $(MINILIBX)

$(MINILIBX):
	@make -C ./minilibx

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(LIBLINK) $(MLX_FLAGS)
	@echo "Wolf3d Compilation complete"
clean:
	@rm -rf $(OBJDIR)
	@make -C ./libft clean
	@echo "Wolf3d Object Files Removed"
fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx clean
	@echo "Wolf3d exe file removed"
re: fclean all
