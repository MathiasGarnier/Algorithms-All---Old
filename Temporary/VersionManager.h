#ifndef VERSIONMANAGER_H_INCLUDED
#define VERSIONMANAGER_H_INCLUDED

#include <iostream>

#include "version.h"

namespace VersionManager {

    void make() {

        std::cout << "Version : " << AutoVersion::STATUS << " " << AutoVersion::FULLVERSION_STRING << std::endl;
        std::cout << "Last update : " << AutoVersion::DATE << "/" << AutoVersion::MONTH << "/" << AutoVersion::YEAR << std::endl;
        std::cout << "Number of builds : " << AutoVersion::BUILDS_COUNT << std::endl << std::endl;
    }
}

#endif // VERSIONMANAGER_H_INCLUDED
