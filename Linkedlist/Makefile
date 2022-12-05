TARGET_EXEC:=main
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(CC) -o main $^

$(OBJS): $(SRCS)
	$(CC) -c $^

clean: 
	rm -f $(TARGET_EXEC) $(OBJS)