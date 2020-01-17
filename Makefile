install:
	@make -sC Pathfinder -f Makefile all

path:
	@make -sC Pathfinder -f Makefile pathfinder
	@make -sC Pathfinder -f Makefile clean

go:
	@./Pathfinder/pathfinder text.txt

all: install go
pll: path go

cpp:
	@g++ -std=c++2a -Ofast -march=native -pipe -fomit-frame-pointer -flto *.cpp
