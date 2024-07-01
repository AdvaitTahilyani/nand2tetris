CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -O0
EXTRA_CXX_FLAGS=-Wall -Wextra -Werror -pedantic -Wno-error=unused-parameter

exec: bin/exec
tests: bin/tests

bin/exec : ./includes/parser.hpp ./includes/code.hpp ./src/code.cc ./src/parser.cc ./src/driver.cc
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(EXTRA_CXX_FLAGS) ./src/parser.cc ./src/code.cc ./src/driver.cc -o ./bin/exec

.DEFAULT_GOAL := exec
.PHONY: clean exec

clean:
	rm -fr bin/* obj/*
