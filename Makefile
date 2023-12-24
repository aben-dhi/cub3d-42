NAME	= cub3D

SRCS	= cub3d.c parsing/map_check.c utils.c parsing/partition.c parsing/partition_p2.c parsing/save_map.c parsing/check_shape.c

LIBFTSRC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c\
libft/ft_bzero.c libft/ft_memcpy.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c    libft/ft_strchr.c libft/ft_strrchr.c\
libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_atoi.c libft/ft_substr.c libft/ft_memcmp.c\
libft/ft_strtrim.c libft/ft_strjoin.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_split.c libft/ft_striteri.c\
libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstadd_back.c libft/ft_lstlast.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c\
libft/ft_isspace.c

MLXSRC	= 

GNLSRC	= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o) $(LIBFTSRC:.c=.o)  $(GNLSRC:.c=.o) #$(MLXSRC:.c=.o)

CC		= cc

FLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g

MLX		= -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g

.PHONY = all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(MLX) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all