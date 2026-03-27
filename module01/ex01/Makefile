CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -O3 -std=c++98
NAME		= zombies

SRCS		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPENDS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPENDS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPENDS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re