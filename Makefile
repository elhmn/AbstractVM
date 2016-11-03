# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/22 16:40:12 by bmbarga           #+#    #+#              #
#    Updated: 2016/10/22 17:16:52 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

MAIN_DIR = main_functions/
VM_DIR = vm/
OP_DIR = op/

MAIN = main.cpp test.cpp
VM = Vm.class.cpp
OP = IOperand.class.cpp

MAINS =  $(addprefix $(MAIN_DIR), $(MAIN))
VMS =  $(addprefix $(VM_DIR), $(VM))

SRC_OBJ = $(MAIN) $(VM)

SRC = 	$(MAINS) $(VMS)

OBJ = $(SRC_OBJ:.cpp=.o)

OBJDIR = ./objs/

REPS =  $(addprefix $(OBJ_DIR), $(REP))

SRCDIR = ./srcs/

OBJS = $(addprefix $(OBJDIR), $(OBJ))

SRCS = $(addprefix $(SRCDIR), $(SRC))

FLAG = -Wall -Werror -Wextra

INC_PATH = ./includes/

INCLUDES =	-I ./includes/ \
			-I $(addprefix $(INC_PATH), $(VM_DIR)) \
			-I $(addprefix $(INC_PATH), $(OP_DIR)) \

LIB =

CC = g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBMAC)

home: $(OBJS)
	$(CC) $(FLAG) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

$(OBJS): $(SRCS)
	$(CC) $(FLAG) -c $(SRCS) $(INCLUDES) &&  mv $(OBJ) $(OBJDIR)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ)
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
