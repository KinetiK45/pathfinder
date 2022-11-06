IDIR = inc
ODIR = obj
SDIR = src
LDIR = libmx
CC = clang
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
FLAGS = $(CCFLAGS) -I $(IDIR) -I $(LDIR)/$(IDIR)
NAME = pathfinder
LIB = libmx.a
DEPS := $(wildcard $(IDIR)/*.h)
SRCS := $(wildcard $(SDIR)/*.c)
OBJS = $(subst $(SDIR),$(ODIR),$(SRCS:.c=.o))

all: $(NAME)

$(LDIR)/$(LIB):
	@make -C $(LDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS) $(LDIR)/$(LIB)
	@$(CC) $(FLAGS) $^ -o $@

uninstall: clean
	@rm -f $(NAME)
	@make $@ -C $(LDIR)

clean:
	@rm -rf $(ODIR)
	@make $@ -C $(LDIR)

reinstall: uninstall all

.PHONY: clean uninstall reinstall
