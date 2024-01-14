#pragma once

#include <toml.hpp>

using namespace toml;
using namespace std;

class BaldfileParser {
private:
	table _data;
public:
	BaldfileParser(string filename) {
		_data = parse_file(filename);
	}
	string projectName() {
		return _data["project"]["name"].value_or("Unknown");
	}
	vector<string> sourceFiles() {
		vector<string> res;
		auto tmp = _data["sources"]["files"].as_array();
		for (auto& file : *tmp) {
			res.push_back(file.value_or(""));
		}
		return res;
	}
	vector<string> compilerOptions() {
		vector<string> res;
		auto tmp = _data["compiler"]["options"].as_array();
		for (auto& file : *tmp) {
			res.push_back(file.value_or(""));
		}
		return res;
	}
	string compiler() {
		return _data["compiler"]["language"].value_or("clang++");
	}
	string cppStandart() {
		return _data["compiler"]["standard"].value_or("c++17");
	}
	bool standartEnabled() {
		return _data["compiler"]["enableStdOption"].value_or(true);
	}
	string outputFile() {
		return _data["output"]["name"].value_or("out");
	}
	vector<string> includeDirs() {
		vector<string> res;
		auto tmp = _data["includes"]["dirs"].as_array();
		for (auto& file : *tmp) {
			res.push_back(file.value_or(""));
		}
		return res;
	}
	
};
