INCDIR = include
CC = gcc
CFLAGS = -I $(INCDIR) -Wall -Werror -Wextra

SDIR = src
_SOURCES = main.c process_str.c usr_oput.c utilities.c
SOURCES = $(patsubst %,$(SDIR)/%,$(_SOURCES))

ODIR = obj
_OBJECTS = $(_SOURCES:.c=.o)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

TARGET = bin/build.test
RELEASE = bin/smart-buffering
INSTALL = /home/${USER}/.local/bin/smart-buffering

.PHONY: all release install clean fclean rclean iclean re rre ire

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "\n\033[1;34mSuccessfully created a test build in ./bin\033[0m!\n"

$(ODIR)/%.o: $(SDIR)/%.c $(DEPENDS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo created $@!

release: $(RELEASE)


$(RELEASE): $(TARGET)
	@if test -f $(RELEASE); then mv $(RELEASE) bin/.old/; fi
	@cp $(TARGET) $(RELEASE)
	@echo "\033[1;32m/!\\ MADE A RELEASE /!\\ \033[0m\n"

install: $(INSTALL)

$(INSTALL): $(RELEASE)
	@cp -f $(RELEASE) $(INSTALL)
	@echo "\033[1;31m/!\\ CREATED A COPY IN .LOCAL/BIN /!\\ \033[0m\n"
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET)

rclean: fclean
	@rm -f $(RELEASE)

iclean: rclean
	@rm -f $(INSTALL)

re: fclean all

rre: rclean release

ire: iclean install
