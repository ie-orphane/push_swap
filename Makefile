BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

NAME = push_swap
BONUS = checker


SRCS_DIR = srcs

_SRCS = array_1.c array_2.c array_3.c array_4.c \
		stack_1.c stack_2.c stack_3.c \
		sort.c utils.c int.c main.c
SRCS = $(addprefix $(SRCS_DIR)/,$(_SRCS_BONUS))

# _SRCS_BONUS =
# SRCS_BONUS = $(addprefix $(SRCS_DIR)/,$(_SRCS_BONUS))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(_SRCS:.c=.o))
# OBJS_BONUS = $(addprefix $(OBJS_DIR)/,$(_SRCS_BONUS:.c=.o))


INCLUDE_DIR = include
_INCLUDES = main.h ansi.h array.h int.h stack.h
INCLUDES = $(addprefix $(INCLUDE_DIR)/,$(_INCLUDES))

LIB = libft

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -O3
IFLAGS =  -I$(INCLUDE_DIR) -I$(LIB)
LFLAGS = -L$(LIB) -l$(subst lib,,$(LIB)) # -fsanitize=address -g3

DEV_NULL = 1> /dev/null
NO_PRINT = --no-print-directory


all : $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "🔗 $(CYAN)$(notdir $(OBJS)) $(BLACK)=> $(YELLOW)$(NAME)$(RESET)"


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "🔨 $(BLUE)$(notdir $<) $(BLACK)=> $(CYAN)$(notdir $@)$(RESET)"

$(LIB):
	@$(MAKE) -C $@ $(DEV_NULL)
	@echo "🏗️  $(MAGENTA)$@$(RESET)"

# bonus: $(BONUS)

# $(BONUS): $(LIB_FILES) $(OBJS_BONUS)
# 	@echo "🔗 $(CYAN)$(notdir $(OBJS_BONUS)) $(BLACK)=> $(YELLOW)$(NAME)$(RESET)"
# 	@touch $(BONUS)
# 	@$(CC) $(OBJS_BONUS) $(LIB_FLAGS) -o $(NAME)

clean :
	@$(MAKE) -C $(LIB) clean $(DEV_NULL)
	@echo "🗑  $(BLACK)$(LIB)$(RESET)"
	@$(RM) $(OBJS_DIR)
	@echo "🧹 $(BLACK)$(notdir $(OBJS))$(RESET)"

fclean : clean
	@$(RM) $(NAME) $(BONUS)
	@echo "🧹 $(BLACK)$(NAME)$(RESET)"
	@$(MAKE) -C $(LIB) fclean $(DEV_NULL)

re : fclean all

run :
	@$(MAKE) $(NO_PRINT) $(DEV_NULL)
	@./$(NAME) $(ARGS)

count :
	@$(MAKE) $(NO_PRINT) run | wc -l

check :
	@$(MAKE) $(NO_PRINT) run | ./checker_linux $(ARGS)

exe :
	@$(MAKE) $(NO_PRINT) run
	@echo "---"
	@$(MAKE) $(NO_PRINT) count
	@$(MAKE) $(NO_PRINT) check

valgrind :
	@$(MAKE) $(NO_PRINT) $(DEV_NULL)
	@valgrind ./$(NAME) $(ARGS)

.PHONY : all clean fclean re $(LIB) run count check exe
