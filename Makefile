all: build install clean

build:
	g++ -oout ./src/*.cpp -I./include

install:
	rm -rf ~/.local/share/bald
	cp ./out ~/.local/bin/bald
	mkdir -p ~/.local/share/bald
	cp ./baldfile.template ~/.local/share/bald/
	cp ./main.cpp.template ~/.local/share/bald/
	chmod +x ~/.local/bin/bald

clean:
	rm -rf ./out
