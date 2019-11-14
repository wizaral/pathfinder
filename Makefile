CC = clang

all: install go

go:
	@./Pathfinder/pathfinder

install:
	@make -s -C Pathfinder -f Makefile all