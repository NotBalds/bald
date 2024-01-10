#include <argh.h>
#include <iostream>
#include <unistd.h>

using namespace std;

class ProjectParser {
private:
	void new_project(argh::parser parser) {
		string name = parser[3];

		cout << "Executing mkdir...\n";
		system(("mkdir -p " + name + "/src/").c_str());
		cout << "Changing dir...\n";
		chdir(name.c_str());
		cout << "Creating code and baldfile";
		system("touch src/main.cpp baldfile");

			
	}
public:
	void parse(argh::parser parser) { 
		if (parser[2] == "new") {
			new_project(parser);
		}
	}
};
