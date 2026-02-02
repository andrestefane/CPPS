# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 15:28:23 by astefane          #+#    #+#              #
#    Updated: 2026/02/02 18:22:51 by astefane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
		Main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME = Bureaucrat

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
