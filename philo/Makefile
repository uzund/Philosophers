# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 14:35:42 by duzun             #+#    #+#              #
#    Updated: 2023/02/28 15:30:44 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[0;31m
GREEN		= \033[0;32m
BLUE		= \033[0;34m
RESET		= \033[0m
END			= \033[0m

SRCS =  $(wildcard *.c)
				
NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -I includes
RM			=	rm -f
OBJS_DIR	= 	objs/
PROJECT_H	= 	philo.h
OBJS		=	$(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf	"\033[2K\r📶 ${RED}[DERLENİYOR! / COMPILING!]${RESET} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) makerun
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CFLAGS) ../libft/libft.a
	@echo "\n✅ ${GREEN}Çalıştırılabilir "philo" oluşturuldu ve kullanıma hazır!${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)"
	@echo " ${RED}Çalıştırmak için: ${BLUE}./philo <arguman> ${GREEN}  örnek: ./philo ${RESET}$(END)"
	@echo "\n✅ ${GREEN}Executable "philo" created and ready for use!${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)"
	@echo "${RED}To make it work: ${BLUE} ./philo <arguman> ${GREEN}  example: ./philo ${RESET}$(END)\n"

all: $(NAME)	

makerun:
	@make -C ../libft
 
clean:
	@make clean -C ../libft
	@rm -rf $(OBJS_DIR)
	@echo "\n🧽 ${GREEN}Clean: ${RED}Tüm \".o\" dosyaları kaldırıldı${RESET}$(END)"
	@echo "🧽 $(GREEN)Clean: $(RESET)Removed all the \".o\" files \n"

fclean: clean
	@make fclean -C ../libft
	@rm -f $(NAME)
	@echo "\n🧽 ${GREEN}Fclean: ${RED}Yürütülebilir dosyalar kaldırıldı${RESET}$(END)"
	@echo "🧽 $(GREEN)Fclean: $(RESET)Removed the executables \n"
	
re:	fclean all
				
.PHONY:	all clean fclean re				