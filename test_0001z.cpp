#include <iostream>

int main()
{
    std::wcout << "Hello it\'s me" << std::endl; //Normal message
	std::wcerr << "Fuck an error" << std::endl; //Error message
	std::wclog << "Logger log yolo" << std::endl; //Log message


	std::wcout << std::hex;
	std::wcout << 5867 << std::endl;
	std::wcout << 5487898 << std::endl;
}
