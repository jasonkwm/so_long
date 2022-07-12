NAME := so_long

SRCS_DIR := ./src
OBJS_DIR := ./obj

SRCS := main.c arts.c hooks.c loops.c maps.c \
		utils.c check1.c check2.c hook_utils.c exit.c

OBJS := ${SRCS:%.c=${OBJS_DIR}/%.o}

CC := gcc -Wall -Werror -Wextra #-fsanitize=address -g3

# -L "folder" to looks for library in the folder
# -l(ft) to link library file. l replaces lib
LIB := -lft -L./libft

all : ${NAME}

# -I is to look for header file in the folder
${NAME} : ${OBJS}
	make -C ./libft
	${CC} -Iincludes -Ilibft -lmlx -framework OpenGL -framework AppKit ${OBJS} ${LIB} -o $@

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c
	mkdir -p ${OBJS_DIR}
	${CC} -Iincludes -Ilibft -Imlx -c $< -o $@

clean :
	@rm -rf ${OBJS_DIR}
	@make clean -C ./libft

fclean : clean
	@make fclean -C ./libft
	@rm -rf ${NAME}

re : clean fclean all