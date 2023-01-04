#include <iostream>
#include <math.h>

int main()
{
    std::wcout << "Sent" << std::endl; //Normal message

	for(int i = 0; i < 255; i+= 5){

        std::wcout << std::hex;
        std::wcout << i;
    }
}
