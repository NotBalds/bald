#include <argh.h>
#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;



class ProjectParser {
private:
	string _projects_path;
	void new_project(argh::parser parser) {
		string name = parser[3];

		cout << "[.] Executing mkdir...\n";
		system(("mkdir -p " + _projects_path + name + "/src/").c_str());
		cout << "[.] Creating code and baldfile\n";
		system(("cp ~/.local/share/bald/baldfile.template " + _projects_path + name + "/baldfile.toml").c_str());
		system(("cp ~/.local/share/bald/main.cpp.template " + _projects_path + name + "/src/main.cpp").c_str());
		cout << "[+] Done! Use 'bald project open " + name + "' or 'cd " + _projects_path + name + "' to open project\n";
	}
	void open_project(argh::parser parser) {
		string name = parser[3];
		
		chdir((_projects_path + name).c_str());
		system("$SHELL");
	}
public:
	ProjectParser() {
		ifstream file;
		file.open("~/.config/bald/bald.config");
		file >> _projects_path;
		file.close();
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
