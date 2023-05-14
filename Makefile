SRCS	=	ft_getpath_bonus.c		\
			ft_pipexbonus.c			\
			ft_pipexutils_bonus.c		\
			ft_pipexutils1_bonus.c	\
			ft_pipexutils2_bonus.c	\
			ft_putstr_fd_bonus.c		\
			ft_split_bonus.c			\
			ft_strjoin_bonus.c		\
			ft_strlcpy_bonus.c		\
			ft_strlen_bonus.c			\
			ft_strncmp_bonus.c			\
			get_next_line_utils.c		\
			get_next_line.c				\
			ft_putendl_fd.c				\
			ft_pipexutils3_bonus.c
		
			
OBJS	= 	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	pipex

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:	
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME) 

bonus:	$(NAME)

re:		fclean all

.PHONY:	all clean fclean re
