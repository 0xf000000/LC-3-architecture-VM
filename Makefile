all: build






build:
	g++ -I /Users/leon/code/VM/includes ./src/*.cpp -Wall -O2 -o VM
	mv ./VM ./bin





clean:
	rm ./bin/*
