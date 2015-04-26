APP = gridTest

GIT_VERSION = $(shell git describe --dirty --always --tags)
CFLAGS = -Wall -O3 -DVERSION=\"$(GIT_VERSION)\"
CC = gcc

default: $(APP)

$(APP): main.c disco.c discoStat.c oneD.c
	$(CC) $(CFLAGS) -lm -o $@ $^

clean:
	rm -f $(APP)
