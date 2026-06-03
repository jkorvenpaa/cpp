NAME = easyfind
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

SRC_DIR = src
INC_DIR = incl
OBJ_DIR = obj

INCLUDES = -I$(INC_DIR)

.SECONDARY:$(OBJS)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re