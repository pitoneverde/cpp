CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -O3 -std=c++98
NAME		= megaphone

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re