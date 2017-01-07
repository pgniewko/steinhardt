RM          := rm -f
MKDIR	    := mkdir -p
# C compiler
CC	     	:= g++-4.9

STATIC		:=libsteinhardt.a

SRC			:=./src

CFLAGS 		:= -O3 -Wall
LDLIBS   	:= -lm -lgsl -lgslcblas

SOURCES	     := $(shell find $(SRC) -type f -name "*.c")
HEADERS	     := $(shell find $(SRC) -type f -name "*.h")
OBJECTS      := $(SOURCES:.c=.o)

PREFIX   := /usr/local


$(STATIC): $(OBJECTS)
	@echo "[Link (Static)]"
	ar -rcs $@ $^
	ranlib $@

.c.o:
	@echo [Compile] $<
	$(CC) -c $(CFLAGS) $< -o $@


PHONY: build clean install

build: $(STATIC)
	@echo [Building]

clean:
	@echo [Cleaning]
	$(RM) $(STATIC) $(OBJECTS) 

install: $(STATIC)
	@echo [Installing] $<
	sudo install -m 755 $(STATIC) $(PREFIX)/lib
	sudo install -m 755 $(HEADERS) $(PREFIX)/include

