NAME = libft.a

CC = clang

CFLAGS =  -c -Wall -Werror -Wextra

HEADER = libft.h

SRCS =  ft_bzero.c ft_strlcat.c \
		ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c \
		ft_toupper.c ft_memset.c \
		ft_tolower.c ft_strrchr.c\
		ft_strncmp.c ft_strdup.c \
		ft_strchr.c ft_strlen.c \
		ft_calloc.c ft_memmove.c \
		ft_strtrim.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c\
		ft_atoi.c ft_strlcpy.c \
		ft_strnstr.c ft_putnbr_fd.c \
		ft_strmapi.c ft_strjoin.c \
		ft_substr.c ft_itoa.c \
        ft_striteri.c ft_split.c \

OBJS = $(SRCS:.c=.o)

all: $(SRCS) $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette

.PHONY: all clean fclean re norm