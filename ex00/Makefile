# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 17:00:07 by ayael-ou          #+#    #+#              #
#    Updated: 2023/12/24 14:25:11 by ayael-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc

SRC_DIR = ./
SRCS = 	main.cpp\
		BitcoinExchange.cpp\

OBJS = ${SRCS:.cpp=.o}
CC = c++
RM = rm -rf

%.o: %.cpp
	${CC} -c $< -o $@ -std=c++98 -Wall -Wextra -Werror -g3

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re