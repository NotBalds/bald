all: build install

build:
	g++ -oout ./src/*.cpp -I./include

install:
	cp ./out ~/.local/bin/bald
	chmod +x ~/.local/bin/bald
