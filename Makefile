# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 16:04:40 by mdelphia          #+#    #+#              #
#    Updated: 2019/08/29 14:37:48 by mdelphia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ./src/

WAY_LIB = ./libft/

INC = ./includ/

C_FILE = ft_dirlist_new.c ft_error_opendir.c ft_flag_r.c ft_free_dirlist.c \
		 ft_free_flaglist.c ft_lenelements.c ft_ls.c ft_onedir.c \
		 ft_passwd_write.c ft_putres.c ft_rights.c ft_sort.c ft_sortdir.c \
		 ft_strtime.c ft_write_flag_log.c ft_write_flag_other.c \
		 ft_write_flag_si.c ft_write_flags.c ft_write_maj_min.c \
		 ft_put_flag_go.c ft_group.c ft_dirrent_write.c ft_onefile.c \
		 ft_isfile_or_no.c ft_sort_start_namedir.c ft_nextlist.c \
		 ft_put_permitionfile.c

FILE_C = $(addprefix $(SRC), $(C_FILE))

FILE_O = $(C_FILE:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

LIB = $(WAY_LIB)libft.a

HED = -I $(INC) -I $(WAY_LIB)

GCC_O = gcc -o $(NAME) $(FILE_O) $(LIB) -g

all: $(NAME)

$(NAME): $(LIB) $(FILE_O)
	$(GCC_O)

%.o: $(SRC)%.c
	gcc -o $@ -c $< $(FLAGS) $(HED)

$(LIB):
	make -C $(WAY_LIB)

clean:
	make clean -C $(WAY_LIB)
	rm -f $(FILE_O)

fclean: clean
	make fclean -C $(WAY_LIB)
	rm -f $(NAME)

re: fclean all
