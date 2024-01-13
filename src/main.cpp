#include <iostream>
#include <argh.h>

#include "project.cpp"
#include "builder.cpp"
#include "runner.cpp"

using namespace std;

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "project") {
		ProjectParser prs;
		prs.parse(parser);
	}
	if (parser[1] == "build") {
		Builder builder;
		builder.build();
	}
	if (parser[1] == "run") {
		Runner runner;
		runner.run();
	}
	if (parser[1] == "") {
		Builder builder;
		Runner runner;

		builder.build();
		runner.run();
	}
}
