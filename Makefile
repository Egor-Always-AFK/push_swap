NAME = push_swap

LIBFT_NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h libft/libft.h

SRCS =  check_valid.c push_swap.c \
		algorithms/sort_3_and_5.c  algorithms/sort.c \
		algorithms/stack_into_array.c algorithms/help_functions.c \
		algorithms/big_sort.c algorithms/help_functions_2.c \

ACTIONS = actions/push.c actions/reverse_rotate.c \
		actions/rotate.c actions/swap.c \

LIBFT = libft/ft_bzero.c libft/ft_strlcat.c \
		libft/ft_isalnum.c libft/ft_isalpha.c \
		libft/ft_isascii.c libft/ft_isdigit.c \
		libft/ft_isprint.c libft/ft_memchr.c \
		libft/ft_memcmp.c libft/ft_memcpy.c \
		libft/ft_toupper.c libft/ft_memset.c \
		libft/ft_tolower.c libft/ft_strrchr.c\
		libft/ft_strncmp.c libft/ft_strdup.c \
		libft/ft_strchr.c libft/ft_strlen.c \
		libft/ft_calloc.c libft/ft_memmove.c \
		libft/ft_strtrim.c libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c libft/ft_putstr_fd.c\
		libft/ft_atoi.c libft/ft_strlcpy.c \
		libft/ft_strnstr.c libft/ft_putnbr_fd.c \
		libft/ft_strmapi.c libft/ft_strjoin.c \
		libft/ft_substr.c libft/ft_itoa.c \
        libft/ft_striteri.c libft/ft_split.c \

OBJS = $(SRCS:.c=.o)

OBJS_ACTION = $(ACTIONS:.c=.o)

OBJS_LIBFT = $(LIBFT:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME) : $(OBJS_LIBFT) $(HEADER)
	ar rcs $(LIBFT_NAME)  $(OBJS_LIBFT)

$(NAME) : $(OBJS) $(OBJS_ACTION) $(HEADER)
	gcc $(CFLAGS) $(OBJS) $(OBJS_ACTION) $(LIBFT_NAME) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

norm:
	norminette $(SRCS) $(LIBFT)

.PHONY: all clean fclean re norm