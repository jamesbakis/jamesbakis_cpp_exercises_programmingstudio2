.default: all

all: class5_example

clean:
	rm -f class5_example *.o

class5_example: class5_main.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^