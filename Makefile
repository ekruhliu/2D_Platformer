# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 10:02:22 by ekruhliu          #+#    #+#              #
#    Updated: 2018/04/26 10:02:23 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = startGame

FLAGS = -c -Wall -Wextra -Werror -O3

SDL = -rpath @loader_path/libSDL/ -I libSDL/SDL2.framework/Headers -I libSDL/SDL2_image.framework/Headers -lm -framework SDL2 -framework SDL2_image -F ./libSDL

HEADER = ./Game.class.hpp

SRCS = ./main.cpp ./Game.class.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@ clang++ -o $(NAME) $(OBJ) $(SDL)
		@ echo "\033[1m\033[32mCompile!\033[0m"

%.o: %.c $(HEADER)
		@ clang++ $(FLAGS) -o  $@ $<

clean:
		@ rm -rf $(OBJ)
		@ echo "\033[1m\033[31mAll the object files have been deleted.\033[0m"

fclean: clean
		@ rm -rf $(NAME)
		@ echo "\033[1m\033[31m$(NAME) has been deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
