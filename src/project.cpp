#include <argh.h>
#include <iostream>
#include <unistd.h>

using namespace std;



class ProjectParser {
private:
	string _projects_path;
	void new_project(argh::parser parser) {
		string name = parser[3];

		cout << "Executing mkdir...\n";
		system(("mkdir -p " + _projects_path + name + "/src/").c_str());
		cout << "Changing dir...\n";
		chdir((_projects_path + name).c_str());
		cout << "Creating code and baldfile\n";
		system("touch src/main.cpp baldfile");
		cout << "Done! Use 'bald project open " + name + "' or 'cd " + _projects_path + name + "' to open project\n";
	}
	void open_project(argh::parser parser) {
		string name = parser[3];
		
		chdir((_projects_path + name).c_str());
		system("$SHELL");
	}
public:
	ProjectParser() {
		_projects_path = getenv("BALD");
		system(("mkdir -p " + _projects_path).c_str());
	}
	void parse(argh::parser parser) { 
		if (parser[2] == "new") {
			new_project(parser);
		}
		else if (parser[2] == "open") {
			open_project(parser);
		}
	}
};
