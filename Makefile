all: install go
pll: path go

install:
	@make -sC Pathfinder -f Makefile all

path:
	@make -sC Pathfinder -f Makefile pathfinder

go:
	@./Pathfinder/pathfinder text.txt

cpp:
	@g++ -std=c++2a -Ofast -march=native -pipe -fomit-frame-pointer -flto *.cpp
