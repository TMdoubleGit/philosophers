NAME = philosophers

DIRSRC = ./srcs/philo/

DIRCINC = ./includes/

SRC =	init \
		libft \
		parsing \
		time \
		actions \
		display \
		
SRCS = $(addprefix ${DIRSRC}/, $(addsuffix .c, ${SRC}))

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3 -pthread

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "✅ philosophers has been created"

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@echo "✅ Directory is clean"

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@echo "✅ Directory is fclean"

re : fclean all

.PHONY : all clean fclean re bonus