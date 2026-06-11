
SRCS = \
		main.cpp \
		PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME =  PmergeMe
SCRIPT = script.sh
REPO_URL = https://raw.githubusercontent.com/andrestefane/CPPS/main/cpp09/ex02
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SCRIPT)

script:
	@echo "Downloading test script..."
	@curl -o $(SCRIPT) $(REPO_URL)/$(SCRIPT)
	@chmod +x $(SCRIPT)
	@echo "Done! Run it with: ./$(SCRIPT)"

re: fclean all

.PHONY: all clean fclean re script
