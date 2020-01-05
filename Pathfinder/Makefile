CC = clang
LIB = libmx.a
NAME = pathfinder

RAW = algorithm clear_info create_routes main print_routes

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addprefix mx_, $(addsuffix .c, $(RAW))))
OBJ = $(addprefix $(OBJ_DIR), $(addprefix mx_, $(addsuffix .o, $(RAW))))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
OFLAGS = -Ofast -march=native
DFLAGS = -g -fsanitize=address

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# install
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# debug
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall install