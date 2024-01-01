# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 18:38:13 by ayael-ou          #+#    #+#              #
#    Updated: 2024/01/01 22:06:10 by ayael-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PmergeMe

SRC_DIR = ./
SRCS = 	main.cpp\
		Pmerge.cpp\
		TriSpecial.cpp\
		TriSpecial.List.cpp\

OBJS = ${SRCS:.cpp=.o}
CC = c++
RM = rm -rf

%.o: %.cpp
	${CC} -c $< -o $@ -Wall -Wextra -Werror -g3

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re