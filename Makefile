all: build install clean

build:
	clang++ -oout ./src/*.cpp -I./include

install:
	mkdir -p ~/.config/bald/
	! test -f ~/.config/bald/bald.config && echo "~/coding/" > ~/.config/bald/bald.config
	rm -rf ~/.local/share/bald
	cp ./out ~/.local/bin/bald
	mkdir -p ~/.local/share/bald
	cp ./baldfile.template ~/.local/share/bald/
	cp ./main.cpp.template ~/.local/share/bald/
	chmod +x ~/.local/bin/bald

clean:
	rm -rf ./out
