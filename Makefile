all: build install clean

build:
	g++ -oout ./src/*.cpp -I./include

install:
	cp ./out ~/.local/bin/bald
	chmod +x ~/.local/bin/bald

clean:
	rm -rf ./out
