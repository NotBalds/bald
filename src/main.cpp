#include <iostream>
#include <argh.h>

#include "project.cpp"

using namespace std;

int main(int, char* argv[]) {
	argh::parser parser(argv);
	
	if (parser[1] == "project") {
		ProjectParser prs;
		prs.parse(parser);
	}
}
