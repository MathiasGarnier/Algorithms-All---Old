//
// Created by Yapix on 26/02/2017.
//

#include <cstdlib>
#include "FileConfigurator.h"

FileConfigurator::FileConfigurator(const std::string &fName) {

	this->fName = fName;
}


void FileConfigurator::removeComment(std::string &line) const {

	if (line.find("--") != line.npos)
	line.erase(line.find("--"));
}

bool FileConfigurator::onlyWhitespace(const std::string &line) const {

	return (line.find_first_not_of(' ') == line.npos);
}

bool FileConfigurator::validLine(const std::string &line) const {

	std::string temp = line;
	temp.erase(0, temp.find_first_not_of("\t "));

	if (temp[0] == '=') return false;

	for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
		if (temp[i] != ' ') return true;

	return false;
}

//Return the key identifier.
void FileConfigurator::extractKey(std::string &key, size_t const &sepPos, const std::string &line) const {

	key = line.substr(0, sepPos);

	if (key.find('\t') != line.npos || key.find(' ') != line.npos)
		key.erase(key.find_first_of("\t "));
}

//Return the second part of the expression.
void FileConfigurator::extractValue(std::string &value, size_t const &sepPos, const std::string &line) const {

	value = line.substr(sepPos + 1);

	value.erase(0, value.find_first_not_of("\t("));
	value.erase(value.find_last_not_of("\t)") + 1);

}

void FileConfigurator::extractContents(const std::string &line) {

	std::string temp = line;

	temp.erase(0, temp.find_first_not_of("\t "));
	size_t sepPos = temp.find('=');

	std::string key, value;
	extractKey(key, sepPos, temp);
	extractValue(value, sepPos, temp);

	if (!keyExists(key))
		contents.insert(std::pair<std::string, std::string>(key, value));
	else
		exitWithError("FileConfigurator: Can only have unique key names!\n");
}

void FileConfigurator::parseLine(const std::string &line) {

	if (line.find('=') == line.npos)
		exitWithError("FileConfigurator: Couldn't find separator on a line: \n");

	if (!validLine(line))
		exitWithError("FileConfigurator: Bad format for a line.\n");

	extractContents(line);
}

bool FileConfigurator::keyExists(const std::string &key) const {

	return contents.find(key) != contents.end();
}

void FileConfigurator::exitWithError(const std::string &error) {

	std::cout << error;
	std::cin.ignore();
	std::cin.get();

	exit(EXIT_FAILURE);
}

void FileConfigurator::ExtractKeys() {

	std::ifstream file;
	file.open(fName.c_str());

	if (!file)
		exitWithError("FileConfigurator: File " + fName + " couldn't be found!\n");

	std::string line;

	while (std::getline(file, line)) {

	std::string temp = line;

		if (temp.empty())
			continue;

			removeComment(temp);

		if (onlyWhitespace(temp))
			continue;

		parseLine(temp);
		std::cout << line << " ";
	}
	file.close();

}

