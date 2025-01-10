# Nombres de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client

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
OBJS_SERVER = $(addprefix $(BUILD_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(BUILD_DIR)/, $(SRCS_CLIENT:.c=.o))

# Reglas principales
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

# Crear directorio de compilación si no existe
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compilar biblioteca Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compilar el servidor
$(NAME_SERVER): $(BUILD_DIR) $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

# Compilar el cliente
$(NAME_CLIENT): $(BUILD_DIR) $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# Reglas para compilar archivos objeto
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstruir todo
re: fclean all

# Regla para archivos bonus (si es necesario)
bonus: 

.PHONY: all clean fclean re bonus

