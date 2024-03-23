# Mutilple Thread

CC := gcc
CFLAGS := -pthread

all:
	$(CC) -o exam program.c $(CFLAGS)

clean:
	rm -rf  exam
