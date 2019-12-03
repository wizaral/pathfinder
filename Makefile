CC = clang

install:
	@make -sC Pathfinder -f Makefile all

go:
	@./Pathfinder/pathfinder

all: install go