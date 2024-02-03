#include <iostream>
#include <argh.h>

#include "project.cpp"
#include "builder.cpp"
#include "runner.cpp"
#include "cleaner.cpp"

using namespace std;

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "project") {
		ProjectParser prs;
		prs.parse(parser);
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

		builder.build();
		runner.run();
		cleaner.clean();
	}
	else {
		cout << "[!] Error: No such command, usage: bald <project|build|run|clean>\n";
	}
}
