#include <iostream>
#include <argh.h>

#include "builder.cpp"
#include "runner.cpp"
#include "cleaner.cpp"

using namespace std;

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "build") {
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
