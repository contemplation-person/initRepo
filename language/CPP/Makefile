CXX = g++
CXXFLAGS = -Wall -Wextra -Werror

.PONY: all re clean	

all:
	@g++ $(CXXFLAGS) test.cpp
	./a.exe < example.txt

clean:
	@rm -rf ./a.exe

re:
	@make clean
	@make all