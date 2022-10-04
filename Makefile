#Комментарии
NAME 		= so_long
SRCS 		= $(wildcard src/*.c)
OBJS 		= $(SRCS:.c=.o)
INCLUDES	= ./includes
CC	 		=	cc #CC: Program for compiling C programs; default cc
RM			=	rm -f
CFLAGS		= -Wall -Wextra -Werror

#target: dependencies
#	commands to make target

 %.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -Imlx -c $< -o $@
# $<  the first parameter to the rule  
#	equivalent to %.c

# $@ the name of the target to be built by the rule
#  	equivalent to %.o

#all: library.cpp main.cpp
#  $@ evaluates to all
#  $< evaluates to library.cpp
#  $^ evaluates to library.cpp main.cpp


all	:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re