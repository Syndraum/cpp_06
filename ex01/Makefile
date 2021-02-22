SRCS = main.cpp Data.cpp

OBJS = ${SRCS:.cpp=.o}

CC = clang++

CFLAG = -Wall -Werror -Wextra

RM = rm -f

NAME = serialization

all:	${NAME}

.cpp.o:
	${CC} ${CFLAG} -c  $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAG} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all