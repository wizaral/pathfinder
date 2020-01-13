NAME = libmx.a
CC = clang

algorithm = binary_search checksort linear_search quicksort_rec quicksort     \
	sort_rec sort

file = get_file_length file_to_str read_line

flist = fcheck_cycle fcheck_size fcheck_tail fclear_list fcreate_list         \
	fcreate_node fdelete_list fforeach_list flist_to_array fpop_back          \
	fpop_front fpop_index fpush_back fpush_front fpush_index fsort_list

list = clear_list create_list create_node delete_list foreach_list_reverse    \
	foreach_list list_to_array pop_back pop_front pop_index push_back         \
	push_front push_index sort_list

memory = memccpy memchr memcmp memcpy memdup memmem memmove memrchr memset    \
	realloc

print = print_strarr print_unicode printchar printnum printstr printunum

queue = clear_queue create_queue delete_queue dequeue enqueue foreach_queue   \
	front rear

stack = clear_stack create_stack delete_stack foreach_stack pop push top

string = atoll atoull count_substr count_words del_extra_spaces del_strarr    \
	get_char_index get_substr_index hex_to_nbr itoa nbr_to_hex replace_substr \
	str_reverse strcat strchr strcmp strcpy strdel strdup strjoin strlen      \
	strncmp strncpy strndup strnew strsplit strstr strtrim tolower toupper

type = isalpha isdigit ishex islower isspace isupper

utils = factorial foreach get_num_length isprime pow sigma sqrt_natural sqrt  \
	sum_digits swap

vector = assign_vector at clear_vector copy_vector create_vector              \
	delete_vector erase foreach_vector get_back get_front insert pop_backward \
	push_backward reverse_vector

RAW = $(addprefix algorithm/mx_, $(algorithm)) $(addprefix file/mx_, $(file)) \
	$(addprefix flist/mx_, $(flist)) $(addprefix list/mx_, $(list))           \
	$(addprefix memory/mx_, $(memory)) $(addprefix print/mx_, $(print))       \
	$(addprefix queue/mx_, $(queue)) $(addprefix stack/mx_, $(stack))         \
	$(addprefix string/mx_, $(string))                                        \
	$(addprefix type/mx_, $(type)) $(addprefix utils/mx_, $(utils))           \
	$(addprefix vector/mx_, $(vector))

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc
CFLAGS = -Ofast -march=native -pipe -fomit-frame-pointer -flto                \
	-ffunction-sections -fdata-sections
# check -Wl, --gc-sections flags !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

DFLAGS = -O0 -g -fsanitize=address

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/algorithm $(OBJ_DIR)/file                 \
	$(OBJ_DIR)/flist $(OBJ_DIR)/list $(OBJ_DIR)/memory $(OBJ_DIR)/print       \
	$(OBJ_DIR)/queue $(OBJ_DIR)/stack $(OBJ_DIR)/string $(OBJ_DIR)/type       \
	$(OBJ_DIR)/utils $(OBJ_DIR)/vector

# install
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) -o $@ -c $<

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) -o $@ -c $<

# debug
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(WFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

install: $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

uninstall:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all