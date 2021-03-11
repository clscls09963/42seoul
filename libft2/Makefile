# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 22:54:09 by hyeykim           #+#    #+#              #
#    Updated: 2021/01/15 18:29:39 by hyeykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
	   ft_atoi.c\
	   ft_bzero.c\
	   ft_memset.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_strlcpy.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_strlcat.c\
	   ft_strlen.c\
	   ft_strrchr.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_strmapi.c\
	   ft_itoa.c\
	   ft_split.c

BONUS = \
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
	  
OBJS = $(SRCS:.c=.o)
OBJS1 = $(BONUS:.c=.o)

NAME = libft.a
CC	=	gcc
CF 	=	-Wall -Wextra -Werror

.c.o	:
	$(CC) $(CF) -c $(<) -o $(<:.c=.o)

$(NAME) :	$(OBJS)
	ar rc $(NAME) $(OBJS)

all		: $(NAME)

bonus : $(OBJS) $(OBJS1)
	ar rc $(NAME) $(OBJS) $(OBJS1)

clean :	
	rm -f $(OBJS) $(OBJS1)

fclean : clean
	rm -f $(NAME) 

re	: fclean all

.PHONY : all clean fclean re
