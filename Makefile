all: build install clean

build:
	g++ -oout ./src/*.cpp -I./include --std=c++17

install:
	mkdir -p ~/.config/bald/
	test -f ~/.config/bald/bald.config || echo "~/coding/" > ~/.config/bald/bald.config
	rm -rf ~/.local/share/bald
	cp ./out ~/.local/bin/bald
	mkdir -p ~/.local/share/bald
	cp ./baldfile.template ~/.local/share/bald/
	chmod +x ~/.local/bin/bald

clean:
	rm -rf ./out
