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
		
		system(("cd " + _projects_path + name + "; $SHELL").c_str());
	}
	void init_project(string dir) {
		cout << "[.] Creating baldfile\n";
		system(("cp ~/.local/share/bald/baldfile.template " + dir + "/baldfile.toml").c_str());
		cout << "[+] Done! Use 'cd " + dir + "' to open project\n";
	}
public:
	ProjectParser() {
		ifstream file;
		system("cat ~/.config/bald/bald.config > ./bald.config");
		file.open("bald.config");
		file >> _projects_path;
		file.close();
		system("rm ./bald.config");
		system(("mkdir -p " + _projects_path).c_str());
	}
	void parse(argh::parser parser) { 
		if (parser[2] == "new") {
			new_project(parser);
		}
		else if (parser[2] == "open") {
			open_project(parser);
		}
		else if (parser[2] == "init") {
			init_project(get_current_dir_name());
		}
		else {
			cout << "[!] No or unknown command, usage: bald project <new|init|open> <name>\n";
		}
	}
};
