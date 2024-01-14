echo "_____             _         _ "
sleep 0.09
echo "|  _  |           | |       | |"
sleep 0.1
echo "| |_| |_   _____  | |  _____| |"
sleep 0.125
echo "|  __   | /  _  | | | /  __   |"
sleep 0.25
echo "| |__|  | | |_| | | | | |__|  |"
sleep 0.5
echo "|_______| \\__/|_| \\_\\ \\____/|_|"
sleep 1

echo ""
echo "Welcome to the club, dude -_-"
sleep 2
echo "Bald is c++ project building system." 
sleep 3
echo "It uses TOML"
sleep 1
echo "Let me install it for you"
sleep 3
echo "First, let's check dependencies"
(g++ --version > /dev/null &&
make --version > /dev/null &&
git --version > /dev/null) &&
(
sleep 3
echo "You have dependencies"
sleep 2
echo "Then, let's clone the repo"
sleep 3
git clone https://github.com/NotBalds/bald
sleep 2
echo "cd..."
cd bald
sleep 2
echo "And run make"
make
sleep 3
echo ""
echo ""
echo ""
echo ""
echo ""
echo ""
echo "Installation finished, read https://github.com/NotBalds/bald/blob/README.md for usage!")
