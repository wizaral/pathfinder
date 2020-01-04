CC = clang

install:
	@make -sC Pathfinder -f Makefile all

path:
	@make -sC Pathfinder -f Makefile pathfinder

go:
	@./Pathfinder/pathfinder

all: install go