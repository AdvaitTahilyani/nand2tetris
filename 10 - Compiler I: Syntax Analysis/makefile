CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -O0
EXTRA_CXX_FLAGS=-g -Wall -Wextra -Werror -pedantic -Wno-error=unused-parameter

exec: bin/exec
tests: bin/tests

bin/exec : ./includes/tokenizer.hpp ./includes/compiler.hpp ./includes/helpers.hpp ./src/compiler.cc ./src/tokenizer.cc ./src/helpers.cc ./src/driver.cc
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(EXTRA_CXX_FLAGS) ./src/tokenizer.cc ./src/compiler.cc ./src/helpers.cc ./src/driver.cc -o ./bin/exec
.DEFAULT_GOAL := exec
.PHONY: clean exec

clean:
	rm -fr bin/* obj/*
