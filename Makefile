install:
	@make -sC Pathfinder -f Makefile all

path:
	@make -sC Pathfinder -f Makefile pathfinder
	@make -sC Pathfinder -f Makefile clean

go:
	@./Pathfinder/pathfinder test.txt

all: install go
pll: path go