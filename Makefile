# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:00:53 by tdieumeg          #+#    #+#              #
#    Updated: 2015/12/02 14:57:47 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binaries
CC		= /usr/bin/clang
RM		= /bin/rm
MAKE	= /usr/bin/make
MKDIR	= /bin/mkdir

# app name
NAME	= wolf3d

# dir
ROOT	= $(shell pwd)
OBJDIR	= $(ROOT)/objs
SRCDIR	= $(ROOT)/srcs
INCDIR	= $(ROOT)/includes
LIBDIR	= $(ROOT)/libft
LFTINC	= $(LIBDIR)/includes
MLXDIR	= $(ROOT)/minilibx_macos

# compil flags
CFLAGS	= -I $(INCDIR) -I $(LFTINC) -I $(MLXDIR) -Wall -Wextra -Werror -g
LIBS	= -L $(LIBDIR) -lft -lmlx -L minilibx_macos -framework OpenGL -framework AppKit

# source files
SRC		= main.c \
		  ft_create_matrix.c \
		  get_next_line.c \
		  maths.c \
		  ft_functions.c \
		  ft_img_fun.c \
		  ft_player_fun.c \
		  ft_wolf3d.c \
		  ft_raycast.c \
		  ft_can_move.c

# obj
OBJS	= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) -C $(MLXDIR)
	@echo "Compiling wold3d..."
	@$(CC) $(OBJS) -o $@ $(LIBS) $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $< -o $@ -c $(CFLAGS)

$(OBJDIR):
	@$(MKDIR) $@

clean:
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)

lib.fclean:
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
