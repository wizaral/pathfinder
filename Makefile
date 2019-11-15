CC = clang

install:
	@make -s -C Pathfinder -f Makefile all

go:
	@./Pathfinder/pathfinder

all: install go