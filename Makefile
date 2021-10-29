CC = gcc
# include -g3 -fsanitize=address in CFLAGS for memory leaks
CFLAGS = -Wall -Wextra -Werror 
DEPS = include/list.h
OBJFILES = src/main.o src/my_printf.o 

TARGET = my_printf
all: $(TARGET)
$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)
.PHONY: clean
clean:
	rm -f src/*.o $(TARGET)