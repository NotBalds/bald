#include <iostream>
#include <argh.h>

#include "builder.cpp"
#include "runner.cpp"
#include "cleaner.cpp"

using namespace std;

inline bool exists (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void write_baldfile () {
	ofstream file("baldfile.toml");
file << "[project]\n\
name = \"MyProject\"\n\
\n\
[sources]\n\
files = [\"src/main.cpp\"]\n\
\n\
[includes]\n\
dirs = []\n\
\n\
[compiler]\n\
language = \"g++\"\n\
enableStdOption = true\n\
standard = \"c++17\"\n\
options = []\n\
\n\
[output]\n\
name = \"my_app\"\n\
";
}

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "init") {
		string dir = get_current_dir_name();
		cout << "[.] Creating baldfile\n";
		write_baldfile();
		cout << "[+] Done!\n";
	}

	else if (!exists("baldfile.toml")) {
		cout << "[!] Baldfile not exists, use 'bald init' to create it!\n";
		return 0;
	}
	
	else if (parser[1] == "build") {
		Builder builder;
		builder.build();
	}
	else if (parser[1] == "run") {
		Runner runner;
		runner.run();
	}
	else if (parser[1] == "clean") {
		Cleaner cleaner;
		cleaner.clean();
	}
	else if (parser[1] == "") {
		Builder builder;
		Runner runner;
		Cleaner cleaner;

		int code = builder.build();
		if (code != 0) {
			cout << "[!] Error while building project, please check output!\n";
			return 0;
		}
		runner.run();
		cleaner.clean();
	}
	else {
		cout << "[!] Error: No such command, usage: bald <build|run|clean>\n";
	}
}
