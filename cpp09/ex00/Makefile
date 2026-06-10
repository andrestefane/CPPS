SRCS = \
		main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

NAME = btc
SCRIPT = script.sh
CSV = data.csv
REPO_URL = https://raw.githubusercontent.com/andrestefane/CPPS/main/cpp09/ex00

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SCRIPT) $(CSV)

re: fclean all

script:
	@echo "Downloading test script..."
	@curl -o $(SCRIPT) $(REPO_URL)/$(SCRIPT)
	@chmod +x $(SCRIPT)
	@echo "Done! Run it with: ./$(SCRIPT)"

csv:
	@echo "Downloading data.csv..."
	@curl -o $(CSV) $(REPO_URL)/$(CSV)
	@echo "Done!"

.PHONY: all clean fclean re script csv