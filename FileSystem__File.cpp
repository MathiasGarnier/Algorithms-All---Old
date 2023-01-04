#include <iostream>
#include <string>

/* g++ main.cpp -o main */

namespace FileSystem {

	class File {
		
		private:
		
			std::string fileIdentifier;
			unsigned int fileSize;
			std::string fileContent;
			
			bool fileHasContent;
			
		public:
		
			File(std::string _fileIdentifier) {
				
				fileHasContent = false;
				
				fileIdentifier = _fileIdentifier;
			}
			
			File(std::string _fileIdentifier, std::string _fileContent) {
				
				fileHasContent = true;
				
				fileIdentifier = _fileIdentifier;
				fileContent = _fileContent;
				
				fileSize = _fileContent.size();
			}
			
			void writeFile(char mode, std::string newContent) {
				
				/* 
				 *	'w'	-> write(delete all content saved before), 'a' -> append, 
				 */
				 
				fileHasAlreadyContent:
				if (fileHasContent) {
					
					switch (mode) {
						
						case 'w':
							
							fileContent = newContent;
							fileSize = fileContent.size();
							break;
							
						case 'a':
						
							fileContent.append(newContent);
							fileSize = fileContent.size();
							break;
							
						default:
				
							std::cout << "Please use a valid mode parameter.";
							break;
					}
				} else {
					
					fileHasContent = true;
					goto fileHasAlreadyContent; /* IT'S TIME TO DINAUSAUR ! Yeahhhh boyyy. */
				}
			}
			
			std::string readFile() {
			
				if (fileHasContent) return fileContent;
				else return "Sorry, we can not read this file.";
			}
		
			unsigned int getSize() {
			
				if (fileHasContent) return fileSize;
				else return 0;

			}
	};
}

int main() {

	/* Unitary test */
	FileSystem::File first("jesuisunfichier.txt");
	std::cout << "(0.0) " << first.readFile() << std::endl << first.getSize() << std::endl;
	first.writeFile('w', "Salut ca va ?");
	std::cout << "(0.1) " << first.readFile() << std::endl << first.getSize() << std::endl;
	
	FileSystem::File second("jesuisunautrefichier.txt", "hi I am the content");
	std::cout << "(1.0) " << second.readFile() << std::endl << second.getSize() << std::endl;
	second.writeFile('a', "Bonjour je suis Jaffar");
	std::cout << "(1.1) " << second.readFile() << std::endl << second.getSize() << std::endl;
	
	return 0;
}
