# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 13:49:00 by jihyukim          #+#    #+#              #
#    Updated: 2022/01/05 14:34:33 by jihyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/
NAME = libft.a
SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstite.c \
			 ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifndef	INCLUDE_BONUS
		OBJS_IN_USE = $(OBJS) $(BONUS_OBJS)
else
		OBJS_IN_USE = $(OBJS)
endif

all: 		bonus $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			ar cr $(NAME) $(OBJS);
			ranlib $(NAME);

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

bonus:		$(MAKE) INCLUDE_BONUS=1 $(NAME)

.PHONY:		all clean fclean re bonus


OBJS			= ${addprefix ${SRCS_DIR}, ${SRCNAME:.c=.o}}
OBJS_BONUS		= ${addprefix ${SRCS_DIR}, ${SRCNAME_BONUS:.c=.o}}
NAME			= libft.a
CC			= gcc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror
INCLUDES 		= ./libft.h
ifdef BONUS_Part
		OBJ_SWITCH = $(OBJS_BONUS)
else
		OBJ_SWITCH = $(OBJS)
endif
.c.o:
			${CC} ${CFLAGS} -c  -o  $@ $<
${NAME}:		${OBJ_SWITCH}
			ar cru ${NAME} ${OBJ_SWITCH} $@ $^
all:			bonus ${NAME}
clean:
			${RM} ${OBJS} ${OBJS_BONUS}
fclean:			clean
			${RM} ${NAME}
re:			fclean all
bonus:
			$(MAKE) BONUS_Part=1 $(NAME)
.PHONY:		all clean fclean re bonus