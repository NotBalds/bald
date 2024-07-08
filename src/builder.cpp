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
	int build() {
		BaldfileParser baldfile_parser(_directory + "/baldfile.toml");
		cout << "[.] Starting to build " << baldfile_parser.projectName() << "...\n";
		string cmd;
		cmd += baldfile_parser.compiler() + " ";
		if (baldfile_parser.standartEnabled()) cmd += "--std=" + baldfile_parser.cppStandart() + " ";
		cmd += "-o" + baldfile_parser.outputFile() + " ";
		for (string src : baldfile_parser.sourceFiles()) {
			cmd += src + " ";
		}
		for (string option : baldfile_parser.compilerOptions()) {
			cmd += option + " ";
		}
		for (string dir : baldfile_parser.includeDirs()) {
			cmd += "-I" + dir + " ";
		}
		cout << "[.] Ended generating command...\n";
		int code = system(cmd.c_str());
		if (code != 0) {
			return 1;
		}
		cout << "[+] Builded successfully, output: " << baldfile_parser.outputFile() << '\n';
		return 0;
	}
};
