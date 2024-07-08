#include <iostream>
#include <argh.h>

#include "builder.cpp"
#include "runner.cpp"
#include "cleaner.cpp"

using namespace std;

inline bool exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "init") {
		string dir = get_current_dir_name();
		cout << "[.] Creating baldfile\n";
		int code = system(("cp ~/.local/share/bald/baldfile.template " + dir + "/baldfile.toml").c_str());
		if (code != 0) {
			cout << "[!] Error while creating baldfile!\n";
			return 0;
		}
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
