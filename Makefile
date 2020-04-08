all: 1x1px

CC=gcc

CFLAGS=
LIBS=

FLAGS=-O3 -pipe -s
DEBUGFLAGS=-Og -Wall -pipe -g

SOURCES=1x1px.c
OUT=1x1px

RM=/bin/rm
CP=/bin/cp

1x1px:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT) $(LIBS) $(FLAGS)

debug:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT) $(LIBS) $(DEBUGFLAGS)

clean:
	if [ -e "$(OUT)" ]; then $(RM) $(OUT); fi
