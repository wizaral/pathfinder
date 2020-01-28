all: install go
pll: path go

install:
	@make -sC C_part -f Makefile all

uninstall:
	@make -sC C_part -f Makefile uninstall

path:
	@make -sC C_part -f Makefile pathfinder

go:
	@./C_part/pathfinder text.txt

cpp:
	@g++ -std=c++2a -Ofast -march=native -pipe -fomit-frame-pointer -flto \
	CPP_part/*.cpp -o CPP_part/pathfinder
