# Nombres de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include

# Directorios
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
BUILD_DIR = ./build

# Archivos fuente y objetos
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER = $(addprefix $(BUILD_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(BUILD_DIR)/, $(SRCS_CLIENT:.c=.o))
OBJS_SERVER_BONUS = $(addprefix $(BUILD_DIR)/, $(SRCS_SERVER_BONUS:.c=.o))
OBJS_CLIENT_BONUS = $(addprefix $(BUILD_DIR)/, $(SRCS_CLIENT_BONUS:.c=.o))

# Reglas principales
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(LIBFT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# Crear directorio de compilación si no existe
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compilar biblioteca Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compilar el servidor
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $@

# Compilar el cliente
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $@

# Compilar el servidor bonus
$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o $@

# Compilar el cliente bonus
$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $@

# Reglas para compilar archivos objeto
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re bonus

