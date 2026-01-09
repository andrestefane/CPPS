# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 18:37:30 by astefane          #+#    #+#              #
#    Updated: 2026/01/05 18:40:59 by astefane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = \
		main.cpp \
		ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME = ClapTrap

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
