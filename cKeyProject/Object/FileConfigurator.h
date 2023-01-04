//
// Created by Yapix on 26/02/2017.
//

#ifndef CKEYPROJECT_FILECONFIGURATOR_H
#define CKEYPROJECT_FILECONFIGURATOR_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class FileConfigurator : public std::string {

	private:

		std::map<std::string, std::string> contents;
		std::string fName;

	public:

		FileConfigurator(const std::string &fName);

		void removeComment(std::string &line) const;
		bool onlyWhitespace(const std::string &line) const;
		bool validLine(const std::string &line) const;
		void extractKey(std::string &key, size_t const &sepPos, const std::string &line) const;
		void extractValue(std::string &value, size_t const &sepPos, const std::string &line) const;
		void extractContents(const std::string &line);
		void parseLine(const std::string &line);
		bool keyExists(const std::string &key) const;
		void exitWithError(const std::string &error);
		void ExtractKeys();
};

#endif //CKEYPROJECT_FILECONFIGURATOR_H
