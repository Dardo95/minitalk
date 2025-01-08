NAME = libft.a

AR = ar -rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =           ft_atoi.c \
                ft_bzero.c \
                ft_calloc.c \
                ft_isalnum.c \
                ft_isalpha.c \
                ft_isascii.c \
                ft_isdigit.c \
                ft_isprint.c \
                ft_itoa.c \
                ft_lstadd_back_bonus.c \
                ft_lstadd_front_bonus.c \
                ft_lstclear_bonus.c \
                ft_lstdelone_bonus.c \
                ft_lstiter_bonus.c \
                ft_lstlast_bonus.c \
                ft_lstmap_bonus.c \
                ft_lstnew_bonus.c \
                ft_lstsize_bonus.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_memcpy.c \
                ft_memmove.c \
                ft_memset.c \
                ft_printf.c \
                ft_printf_num.c \
                ft_putchar_fd.c \
                ft_putendl_fd.c \
                ft_putnbr_fd.c \
                ft_putstr_fd.c \
                ft_split.c \
                ft_strchr.c \
                ft_strdup.c \
                ft_striteri.c \
                ft_strjoin.c \
                ft_strlcat.c \
                ft_strlcpy.c \
                ft_strlen.c \
                ft_strmapi.c \
                ft_strncmp.c \
                ft_strnstr.c \
                ft_strrchr.c \
                ft_strtrim.c \
                ft_substr.c \
                ft_tolower.c \
                ft_toupper.c \
                get_next_line.c \
                get_next_line_bonus.c \

BUILD_DIR = build
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

all: $(NAME)

# Crear la biblioteca
$(NAME): $(OBJ)
	@echo "Creando $(NAME)..."
	$(AR) $(NAME) $(OBJ)

# Regla para compilar los archivos .c en .o dentro de $(BUILD_DIR)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $< -c

clean:
	@echo "Limpiando archivos objeto..."
	rm -rf $(BUILD_DIR)

fclean: clean
	@echo "Eliminando $(NAME)..."
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL = all

.PHONY: all clean fclean re
