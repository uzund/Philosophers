# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2023/02/21 23:27:53 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	=	libft.a
LIBFT 	=	libft.h
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS 	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

all:		$(NAME) 

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			@echo "\n✅ Libft Done!"
clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
										
.PHONY:	all clean fclean re 
