all: 1x1px

CC=gcc

CFLAGS=``
LIBS=``

FLAGS=-O2 -pipe -s
DEBUGFLAGS=-Og -Wall -pipe -g

SOURCES=1x1px.c
OUT=1x1px

RM=`which rm`
CP=`which cp`

1x1px:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT) $(LIBS) $(FLAGS)

debug:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT) $(LIBS) $(DEBUGFLAGS)

clean:
	if [ -e "$(OUT)" ]; then $(RM) $(OUT); fi
