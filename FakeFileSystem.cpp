//
// Created by Mathias Garnier on 20/07/2016.
//

#include "FakeFileSystem.h"

std::string createFile(FakeFileSystem f) {

    if (!(f.exist)) {
        std::cout << "Creation du fichier..." << std::endl;
        f.fileName.push_back(f.File);
        return f;
    } else {
        std::cerr << "Ce fichier existe deja." << std::endl;
        const std::string ERROR = "Error 0000";
        return ERROR;
    }
}

FakeFileSystem getName(std::string name) {
    //TO BE CONTINUED
}
