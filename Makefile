# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by yyefimov          #+#    #+#              #
#    Updated: 2017/03/12 21:39:03 by yyefimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

FLAGS = -Wall -Wextra -Werror

SRC =	main.cpp\
	src/Computor.cpp

BINS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(BINS)
	g++ -o $(NAME) $(BINS)

%.o: %.cpp
	g++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(BINS)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
