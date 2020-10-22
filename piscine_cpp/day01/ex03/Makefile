# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/07/08 19:16:17 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =	-Wall -Wextra -Werror
CPPFLAGS =	-I./includes/

HEAD = ./includes/Zombie.hpp \
		./includes/ZombieHorde.hpp

CC =		g++

NAME = graveyard

SRC_PATH = ./srcs

SRC_NAME = main.cpp \
		Zombie.cpp \
		ZombieHorde.cpp

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs

OBJ_NAME = $(SRC_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# Allez savoir pourquoi, meme lorque '$(NAME)' existe deja,
# 'all' s'evertue a appeler la regle correspondante
all: $(NAME)

# L'appel de 'libft' permet d'actualiser '$(LIBFT)'
# afin qu'eventuellement '$(NAME)' se lance lors du prochain appel de 'make'
#
# Les regles appelee par l'intermediaire d'autres regles s'executent quoi
# qu'il arrive, et quoi qu'il arrive les regles les appelant s'executent

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)

# Autre solution de creation du dossier '$(OBJ_PATH)' :
#	@mkdir -p $(OBJ_PATH) 2> /dev/null
# dans la dependance '$(OBJ_PATH)'
# Dans ce cas 'mkdir' est appele lors de la compilation de chaque fichier source

# Il est necessaire d'employer l'option '-o' de 'gcc' de la maniere qui suit
# pour que les fichiers objets se placent dans le repertoire '$(OBJ_PATH)'

# Par ailleurs il egalement necessaire de placer le '/' comme c'est la cas
# et de ne pas l'inclure dans dans la variable '$(OBJ_PATH)'
# car autrement allez savoir pourquoi la commande 'make re' revoie une erreur

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEAD) | $(OBJ_PATH)
	$(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

clean:
	rm -f $(OBJ)
	rm -df $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
