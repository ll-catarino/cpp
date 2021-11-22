SRCS=$(wildcard *.cpp)

main: $(SRCS) 
	g++ *.cpp -g -o $@

run: main
	./main