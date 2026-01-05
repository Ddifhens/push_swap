
#COMPILATION VARIABLES
CC= cc
CFLAGS= -Wall -Werror -Wextra
DIR_GUARD=@mkdir -p $(@D)

#OUTPUTS
PSH=push_swap

#FILE AND DIRECTORIES VARIABLES
C_FILES=addendum errorcheck push push_utils pushops reverse rotate sortingb sortingp stackops swap
SRC_DIR:=src/
OBJ_DIR:=obj/
LIB:=lib/
LIBFT_DIR:=$(LIB)libft/
LIBFT:=libft.a
PRT_DIR:=$(LIB)ft_printf/
PRT:=libftprintf.a
BUILD_DIR:=build/

SRC:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(C_FILES)))
OBJ:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(C_FILES)))

#FORMATTING VARIABLES

GREEN="\\e[32m"
BLUE="\\e[34m"
RED="\\e[31m"

END="\\e[0m"

#MAKE RULES

$(NAME): all

all: $(BUILD_DIR)$(LIBFT) $(BUILD_DIR)$(PRT) $(PSH) 

$(BUILD_DIR)$(LIBFT):
	@make bonus -C $(LIBFT_DIR)
	$(DIR_GUARD)
	cp $(LIBFT_DIR)$(LIBFT) $(BUILD_DIR)
	@echo "\n$(BLUE)==========          Compiled Libft          ==========$(END)\n"

$(BUILD_DIR)$(PRT):
	@make -C $(PRT_DIR)
	$(DIR_GUARD)
	cp $(PRT_DIR)$(PRT) $(BUILD_DIR)
	@echo "\n$(BLUE)==========          Compiled printf          ==========$(END)\n"

$(PSH): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) \
		-L$(BUILD_DIR) -lft -lftprintf \
		-o $@


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(DIR_GUARD)
	$(CC) -g $(CFLAGS) -c $< \
		-Iinclude/ \
		-I$(LIBFT_DIR)inc/ \
		-I$(PRT_DIR)inc/ \
		-o $@

#CLEAN-UP

clean: 
	rm -rf $(OBJ_DIR)
	@echo "\n$(RED)==========          REMOVED TEMP          ==========$(END)\n"

fclean: clean
	rm -f $(PSH)
	rm -rf $(BUILD_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRT_DIR)
	@echo "\n$(RED)==========          REMOVED ALL          ===========$(END)\n" 

re: clean fclean all
#PHONY
.PHONY: all clean fclean re
