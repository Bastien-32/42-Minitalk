# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badal-la <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 14:10:11 by badal-la          #+#    #+#              #
#    Updated: 2025/01/30 17:44:51 by badal-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    LIBRARY                                   #
# **************************************************************************** #

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
INCLUDE_DIR = includes

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# **************************************************************************** #
#                                  MANDATORY                                   #
# **************************************************************************** #

MANDATORY_DIR = mandatory

SRC_CLIENT = $(MANDATORY_DIR)/client.c \
             $(MANDATORY_DIR)/server_utils.c

SRC_SERVER = $(MANDATORY_DIR)/server.c \
             $(MANDATORY_DIR)/server_utils.c

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)

NAME_CL = client
NAME_SERV = server

# **************************************************************************** #
#                                   BONUS                                      #
# **************************************************************************** #

BONUS_DIR = bonus

SRC_CLIENT_BONUS = $(BONUS_DIR)/client_bonus.c \
                   $(BONUS_DIR)/server_bonus_utils.c

SRC_SERVER_BONUS = $(BONUS_DIR)/server_bonus.c \
                   $(BONUS_DIR)/server_bonus_utils.c

OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

NAME_CL_BONUS = client_bonus
NAME_SERV_BONUS = server_bonus

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(INCLUDE_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

# **************************************************************************** #
#                               MANDATORY RULES                                #
# **************************************************************************** #

all: $(LIBFT) $(PRINTF) $(NAME_CL) $(NAME_SERV)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "✅ Libft compiled"

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "✅ ft_printf compiled"

$(NAME_CL): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(INCLUDE) \
		-L $(LIBFT_DIR) -lft \
		-L $(PRINTF_DIR) -lftprintf \
		-o $(NAME_CL)
	@echo "✅ Client compiled"

$(NAME_SERV): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(INCLUDE) \
		-L $(LIBFT_DIR) -lft \
		-L $(PRINTF_DIR) -lftprintf \
		-o $(NAME_SERV)
	@echo "✅ Server compiled"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# **************************************************************************** #
#                                BONUS RULES                                   #
# **************************************************************************** #

bonus: $(LIBFT) $(PRINTF) $(NAME_CL_BONUS) $(NAME_SERV_BONUS)

$(NAME_CL_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(INCLUDE) \
		-L $(LIBFT_DIR) -lft \
		-L $(PRINTF_DIR) -lftprintf \
		-o $(NAME_CL_BONUS)
	@echo "✅ Client bonus compiled"

$(NAME_SERV_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(INCLUDE) \
		-L $(LIBFT_DIR) -lft \
		-L $(PRINTF_DIR) -lftprintf \
		-o $(NAME_SERV_BONUS)
	@echo "✅ Server bonus compiled"

# **************************************************************************** #
#                                CLEAN RULES                                   #
# **************************************************************************** #

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@echo "✅ Object files removed"

fclean:
	@rm -f $(NAME_CL) $(NAME_SERV) $(NAME_CL_BONUS) $(NAME_SERV_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@echo "✅ Executable files removed"

re: fclean all

# **************************************************************************** #
#                                  PHONY RULES                                 #
# **************************************************************************** #

.PHONY: all bonus clean fclean re
