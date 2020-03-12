# Makefile for Piledriver compiler & translator

# Target : dependencies
#			flags target dependency1 dependency 2 ...

CC=g++
CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter -Wno-reorder -w 
CPPFLAGS += -I include

all : clean bin/piledriver 

parser : src/parser.tab.cpp src/parser.tab.hpp

#lexer : src/lexer.yy.cpp

piledriver : bin/piledriver

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v --report=all -d src/parser.y -o src/parser.tab.cpp -g

# builds lexer and parser
src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

# # builds the lexer (standalone)
# src/lexer.yy.cpp : src/lexer.flex
# 	flex -o src/lexer.yy.cpp src/lexer.flex

src/lexer : src/lexer.yy.o 
	$(CC) $(CPPFLAGS) -o lexer  src/lexer.yy.o

bin/piledriver : src/parser.tab.o src/lexer.yy.o include/ast/ast_translator.o include/ast/codegen/ast_compiler.o src/c_compiler.o 
	mkdir -p bin
	$(CC) $(CPPFLAGS) -o bin/c_compiler $^


clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp
	rm -f src/*.output
	rm -f src/*.dot
	rm -f src/*.tab.hpp
	rm -f include/ast/*.o
	rm -f include/ast/codegen/*.o
	

bin/c_compiler: all