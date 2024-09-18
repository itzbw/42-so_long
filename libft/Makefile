NAME	=	libft.a

SRCS	=	ft_strchr.c		ft_strlcat.c	ft_strlen.c\
			ft_strrchr.c	ft_strncmp.c	ft_calloc.c\
			ft_strnstr.c	ft_strlcpy.c\
			ft_strdup.c		ft_substr.c\
			ft_strjoin.c	ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c\
			ft_strmapi.c	ft_strtrim.c\
			get_next_line.c

HEADER	=	./includes/libft.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I./includes

RM		=	rm -f

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJS) $(B_OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all