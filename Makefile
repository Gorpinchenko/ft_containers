S_DIR		= ./srcs

SRCS_FILES	=
SRCS_FILES1	= main.cpp
SRCS_FILES2	= main2.cpp

SRCS1		= $(addprefix $(S_DIR)/, $(SRCS_FILES)) $(SRCS_FILES1)
SRCS2		= $(addprefix $(S_DIR)/, $(SRCS_FILES)) $(SRCS_FILES2)

OBJS1		= $(SRCS1:%.cpp=%.o)
OBJS2		= $(SRCS2:%.cpp=%.o)

HEADER		= vector.hpp \
				stack.hpp \
				map.hpp \
				set.hpp \
				tree.hpp \
				utils.hpp\
				vector_iterator.hpp \
				vector_reverse_iterator.hpp \
				vector_const_iterator.hpp \
				vector_const_reverse_iterator.hpp

INCLUDES	= $(addprefix -I, $(S_DIR) )

NAME1		= test
NAME2		= my_test

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
			$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

all:		$(NAME1)

$(NAME1):	$(OBJS1)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS1) $(LIB) $(LIB_DIR) -o $@

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS2) $(LIB) $(LIB_DIR) -o $@

$(OBJS1):	$(addprefix $(S_DIR)/, $(HEADER))
$(OBJS2):	$(addprefix $(S_DIR)/, $(HEADER))

clean:
			rm -f $(OBJS1)
			rm -f $(OBJS2)

fclean:		clean
			rm -f $(NAME1)
			rm -f $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re
