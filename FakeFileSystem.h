//
// Created by Mathias Garnier on 20/07/2016.
//

#ifndef TEST_FAKEFILESYSTEM_H
#define TEST_FAKEFILESYSTEM_H

#include <iostream>
#include <string>
#include <vector>

class FakeFileSystem : public std::string {

public:
    std::vector<std::string> fileName;
    std::string File;
    bool exist;

    FakeFileSystem getName(std::string name);
};


std::string createFile(FakeFileSystem f);

#endif //TEST_FAKEFILESYSTEM_H
