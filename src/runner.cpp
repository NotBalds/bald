#include "baldfile_parser.cpp"
#include <unistd.h>
#include <iostream>

using namespace std;

class Runner {
private:
	string _directory;
public:
	Runner() {
		_directory = string(get_current_dir_name());
	}
	void run() {
		BaldfileParser baldfile_parser(_directory + "/baldfile.toml");
		cout << "Running " << baldfile_parser.projectName() << "...\n";
		cout << "==========START=OF=PROGRAM==========\n";
		system(baldfile_parser.outputFile().c_str());
		cout << "==========START=OF=PROGRAM==========\n";
	}
};
