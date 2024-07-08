all: build install clean

build:
	g++ -oout ./src/*.cpp -I./include --std=c++17

install:
	cp ./out ~/.local/bin/bald
	chmod +x ~/.local/bin/bald

clean:
	rm -rf ./out
