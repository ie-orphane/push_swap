NAME = libft.a

RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
_SRCS = ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c \
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_memset.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_bzero.c ft_calloc.c ft_atoi.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
		ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_printf.c ft_printfput.c get_next_line.c
SRCS = $(addprefix $(SRCS_DIR)/,$(_SRCS))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
