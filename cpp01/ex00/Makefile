NAME = Zombie
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:%.cpp=%.o)

.SECONDARY:$(OBJS)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re