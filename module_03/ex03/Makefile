CCXX = c++

SRCS_RAW =	main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp

OBJS_DIR = objs/

SRCS_DIR = ./

SRCS = $(SRCS_RAW)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_RAW:.cpp=.o))

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = a.out

all: 
	@$(MAKE) --no-print-directory -j $(NAME)

$(NAME) : $(OBJS)
	$(CCXX) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CCXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
