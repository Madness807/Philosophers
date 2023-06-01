#***** Name *****#

NAME			=		philo

#***** Sources / Objs *****#

SRC				=		srcs/main.c\
						srcs/init.c\
						srcs/routine.c\
						utils/utils.c\
						srcs/status.c\
						srcs/free_exit.c\

OBJS			=		$(addprefix obj/, $(SRC:.c=.o))

MAKEFLAGS += --no-print-directory

#***** Couleurs *****#

GREEN			=		\033[1;32m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m
BG_G			=		\033[42m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
TEST			=		echo "Run test\n"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_G)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Logo *****#

MSHELL			=		echo "$(GREEN) \t     __  ______    ____  _   __________________\n\
\t    /  |/  /   |  / __ \/ | / / ____/ ___/ ___/\n\
\t   / /|_/ / /| | / / / /  |/ / __/  \__ \\__ \ \n\
\t  / /  / / ___ |/ /_/ / /|  / /___ ___/ /__/ / \n\
\t /_/  /_/_/  |_/_____/_/ |_/_____//____/____/   $(ENDCOLOR)\n"

#***** Flags *****#

GCC				=		gcc -g
CFLAGS			=		-g -Wall -Wextra -Werror
L				=		$(CFLAGS)  -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : start logo $(NAME)

start:
			@$(START)

logo :
			@$(MSHELL)	

obj/%.o:	%.c 
			mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	${OBJS}
			@$(BS_N)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
			@$(END_COMP)

l :
			$(GCC) $(L) $(SRC) -o $(NAME)

#***** Clean *****#

clean:
			@$(S_OBJS)
			@${RM} -r obj

fclean:		clean
			@$(S_NAME)
			@${RM} ${NAME}
			@echo "Succes cleaning"

re:			fclean all

.PHONY:		all clean fclean