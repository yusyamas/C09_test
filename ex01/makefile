NAME = libft.a
SRCDIR = ./srcs
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJDIR = ./srcs
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
INCDIR = -I./includes
CFLAG = -Wall -Wextra -Werror

.PHONY = all clean fclean re libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar r $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -o $@ -c $<

libft.a:	all

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

