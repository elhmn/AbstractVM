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
STACK_DIR = stack/
EXCEP_DIR = exceptions/
FACT_DIR = factory/

MAIN = main.cpp test.cpp
VM = Vm.class.cpp
OP = Operand.class.cpp
STACK = Stack.class.cpp
EXCEP = DivExcep.class.cpp ModExcep.class.cpp WrongTypeExcep.class.cpp
FACT = Factory.class.cpp

MAINS =  $(addprefix $(MAIN_DIR), $(MAIN))
VMS =  $(addprefix $(VM_DIR), $(VM))
OPS =  $(addprefix $(OP_DIR), $(OP))
STACKS =  $(addprefix $(STACK_DIR), $(STACK))
EXCEPS =  $(addprefix $(EXCEP_DIR), $(EXCEP))
FACTS =  $(addprefix $(FACT_DIR), $(FACT))

SRC_OBJ = $(MAIN) $(VM) $(OP) $(STACK) $(EXCEP) $(FACT)

SRC = 	$(MAINS) $(VMS) $(OPS) $(STACKS) $(EXCEPS) $(FACTS)

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
			-I $(addprefix $(INC_PATH), $(STACK_DIR)) \
			-I $(addprefix $(INC_PATH), $(EXCEP_DIR)) \
			-I $(addprefix $(INC_PATH), $(FACT_DIR))

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
