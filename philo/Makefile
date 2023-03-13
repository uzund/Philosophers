# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 14:35:42 by duzun             #+#    #+#              #
#    Updated: 2023/03/14 00:08:30 by duzun            ###   ########.fr        #
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
CFLAGS		=	-Wall -Werror -Wextra -I.
RM			=	rm -f
OBJS_DIR	= 	objs/
PROJECT_H	= 	philo.h
OBJS		=	$(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf	"\033[2K\r📶 ${RED}[DERLENİYOR! / COMPILING!]${RESET} $(END)"

$(NAME): $(OBJECTS_PREFIXED) 
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CFLAGS)
	@echo "\n✅ ${GREEN}Çalıştırılabilir "philo" oluşturuldu ve kullanıma hazır!${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)"
	@echo "${RED}Çalıştırmak için: ${BLUE}./philo <arguman> ${GREEN}  örnek: ./philo 5 800 200 200 3 \
	\n\"./philo filozofların_sayısı, ölmek_için_zaman, yemek_için_zaman, uyumak_için_zaman, \[her_filozofun_kaç_kez_yemek_yemesi_gerektiği\]\" ${RESET}$(END)"
	@echo "\n✅ ${GREEN}Executable "philo" created and ready for use!${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)"
	@echo "${RED}To make it work: ${BLUE} ./philo <arguman> ${GREEN}  example:./philo 5 800 200 200 3 \
	\n\"./philo number_of_philophers, time_to_die, time_to_eat, time_to_sleep, \[number_of_times_each_philosophers_must_eath\]\" ${RESET}$(END)\n"

all: $(NAME)	
 
clean:
	@rm -rf $(OBJS_DIR)
	@echo "\n🧽 ${GREEN}Clean: ${RED}Tüm \".o\" dosyaları kaldırıldı${RESET}$(END)"
	@echo "🧽 $(GREEN)Clean: $(RESET)Removed all the \".o\" files \n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n🧽 ${GREEN}Fclean: ${RED}Yürütülebilir dosyalar kaldırıldı${RESET}$(END)"
	@echo "🧽 $(GREEN)Fclean: $(RESET)Removed the executables \n"
	
re:	fclean all
				
.PHONY:	all clean fclean re				