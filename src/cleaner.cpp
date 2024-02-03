#include "baldfile_parser.cpp"
#include <iostream>
#include <unistd.h>

using namespace std;

class Cleaner {
private:
	string _directory;
public:
	Cleaner() {
		_directory = string(get_current_dir_name());
	}
	void clean() {
		BaldfileParser baldfile_parser(_directory + "/baldfile.toml");
		cout << "[.] Cleaning in " << baldfile_parser.projectName() << "...\n";
		system(("rm -rf " + baldfile_parser.outputFile()).c_str());
		cout << "[!] Cleaned successfully!\n";
	}
};
