#include "baldfile_parser.cpp"
#include <unistd.h>
#include <iostream>

using namespace std;

class Builder {
private:
	string _directory;
public:
	Builder() {
		_directory = string(get_current_dir_name());
	}
	void build() {
		BaldfileParser baldfile_parser(_directory + "/baldfile.toml");
		cout << "Starting to build " << baldfile_parser.projectName() << "...\n";
		string cmd;
		cmd += baldfile_parser.compiler() + " ";
		cmd += "--std=" + baldfile_parser.cppStandart() + " ";
		cmd += "-o" + baldfile_parser.outputFile() + " ";
		for (string option : baldfile_parser.compilerOptions()) {
			cmd += option + " ";
		}
		for (string dir : baldfile_parser.includeDirs()) {
			cmd += "-I" + dir + " ";
		}
		for (string src : baldfile_parser.sourceFiles()) {
			cmd += src + " ";
		}
		cout << "Ended generating command: " << cmd << '\n';
		system(cmd.c_str());
		cout << "Builded successfully, output: " << baldfile_parser.outputFile() << '\n';
	}
};
