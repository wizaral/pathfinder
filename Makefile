CC = clang
LIB = libmx.a
NAME = pathfinder

RAW = main

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addprefix mx_, $(addsuffix .c, $(RAW))))
OBJ = $(addprefix $(OBJ_DIR), $(addprefix mx_, $(addsuffix .o, $(RAW))))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -I$(addprefix $(LIB_DIR), $(LIB))

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(LIB):
	@make -s -C $(LIB_DIR) -f Makefile install

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

install: $(LIB) $(NAME)

clean:
	@make -s -C $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -s -C $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all