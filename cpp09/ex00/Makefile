SRCS = \
		main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME = btc
SCRIPT = test_ex00.sh
REPO_URL = https://raw.githubusercontent.com/TU_USUARIO/TU_REPO/main/ex00/$(SCRIPT)

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

script:
	@echo "Downloading test script..."
	@curl -o $(SCRIPT) $(REPO_URL)
	@chmod +x $(SCRIPT)
	@echo "Done! Run it with: ./$(SCRIPT)"

.PHONY: all clean fclean re script