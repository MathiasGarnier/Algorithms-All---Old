#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {

	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "\n"));
	return out;
}

void saveInFile(const std::string filename, std::vector<std::string> content);
void appendOnSavedFile(std::ofstream& file, std::string id, std::vector<std::string> content);


void overwriteSection(std::string filename, std::string sectionID, std::vector<std::string> newSectionContent);
bool idExistInFile(std::string filename, std::string id);

std::string readFile(std::string filename);

std::size_t countSubstring(const std::string& str, const std::string& sub);

int main() {

	std::vector<std::string> thingsV;
	std::string thingsS;

	bool allowed = true;

	std::ofstream saveFile("save.txt", std::ios_base::app | std::ios_base::out);

	std::cout << "Speak :" << std::endl;

	while (allowed) {

		std::getline(std::cin, thingsS);
		thingsV.push_back(thingsS);

		if(thingsS.find("/save") != std::string::npos) {

			std::size_t spaceOccurrence = countSubstring(thingsS, " ");
			if(spaceOccurrence == 1) {

				thingsS.erase(thingsS.begin() + 5);
				thingsS.erase(thingsS.begin(), thingsS.begin() + 5 );

				if (idExistInFile("save.txt", "[START_SAVE=" + thingsS)) {

					std::cout << "OVERWRITING" << std::endl;
					overwriteSection("save.txt", thingsS, thingsV);
				}

				std::cout << "OVERWRITING DONE" << std::endl;
				thingsV.pop_back();

				appendOnSavedFile(saveFile, thingsS, thingsV);

				thingsV.clear();
			}
		}

		/*if(thingsS.find("/load") != std::string::npos) {

			std::size_t spaceOccurence = countSubstring(thingsS, " ");
			if(spaceOccurence == 1) {

				thingsS.erase(thingsS.begin() + 5);
				thingsS.erase(thingsS.begin(), thingsS.begin() + 5);

				if( thingsS exist in save file)
			}
		} */

		if(thingsS == "/exit") {

			allowed = false;
			thingsV.pop_back();
		}
	}


	return 0;
}

void saveInFile(const std::string filename, std::vector<std::string> content) {

	std::ofstream file(filename);

	file << content;
}

void appendOnSavedFile(std::ofstream& file, std::string id, std::vector<std::string> content) {

	file << "[START_SAVE=" + id + "]\n"; //Start file + id

		file << "\t<content> : {\n"; //Content start
		for (std::size_t i = 0; i < content.size(); ++i) {
			file << "\t\t\t\t" << content.at(i) << "\n";
		}
		file << "\t\t\t\t};\n";

	file << "[END_SAVE=" + id + "]\n\n"; //End file + id
}

void overwriteSection(std::string filename, std::string sectionID, std::vector<std::string> newSectionContent) {

	std::cout << "IN OVERWRITING FUNCTION" << std::endl;

	if(idExistInFile(filename, "[START_SAVE=" + sectionID)) {

		std::cout << "IN IF STATEMENT" << std::endl;
		/* Hard O.o

		std::string filecontent = readFile(filename); //Get file content before erasing. To use it later.
		std::ofstream outfile(filename, std::ios_base::app | std::ios_base::trunc); //Erasing file

		//Modifying file content, adding new id and new content
		std::string startId = "[START_SAVE=" + sectionID;
		std::string section = startId + "]\n\t<content> : {\n";
		std::string endId = "[END_SAVE=" + sectionID + "]\n\n";

		std::size_t index1 = filecontent.size() - filecontent.find_first_of(startId);
		std::size_t index2 = filecontent.size() - filecontent.find_first_of(section);
		std::size_t index3 = filecontent.size() - filecontent.find_first_of(endId);

		//Erasing old section
		//filecontent.erase(filecontent.begin() + filecontent.find_first_of(startId), filecontent.begin() + filecontent.find_first_of(endId));


		filecontent.insert(index1, newSectionID);
		for (std::size_t i = 0; i < newSectionContent.size(); ++i)
			filecontent.insert(index2, newSectionContent.at(i) + "\n");


		outfile << filecontent;
		filecontent.clear();

		*/

		std::string filecontent = readFile(filename); //Get file content.
		std::ofstream outfile(filename); //Overwriting file.

		std::cout << filecontent << std::endl;

		//At this moment, there is none content in 'outfile'. So, we had to delete last section(id, content) and add a new section(id, content).

		//Firstly, we will delete last section(id, content) (entirely).

		std::string startSection = "[START_SAVE=" + sectionID + "]";
		std::string endSection = "[END_SAVE=" + sectionID + "]";

		std::cout << "[" << filecontent.find(startSection) << ".." << filecontent.find(endSection) << "]" << std::endl;

		filecontent.erase(filecontent.begin() + filecontent.find(startSection),
						  filecontent.end() - filecontent.find(startSection)); //Erase the section.

		std::cout << filecontent;

		//The last thing is to update the string and add the new section(id, content).

		//Now, we only had to 'upload' new content into the file.
		outfile << filecontent;

	} else return;
}

bool idExistInFile(std::string filename, std::string id) {

	std::string filecontent = readFile(filename);
	std::string idPos = "[START_SAVE=" + id + "]";

	if(filecontent.find(idPos)) return true;
	else return false;
}


std::string readFile(std::string filename) {

	std::fstream file;
	file.open(filename, std::fstream::in);

	std::string tmp, filecontent;

	while(std::getline(file, tmp)) {

		filecontent += tmp;
	}

	return filecontent;
}

std::size_t countSubstring(const std::string& str, const std::string& sub) {

    if (sub.length() == 0) return 0;
    std::size_t count = 0;

    for (std::size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length()))
    		++count;

    return count;
}
