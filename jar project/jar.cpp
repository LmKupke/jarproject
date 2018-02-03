//
//  JarType.cpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
     - 2/3/18 - Created the jar.cpp file. Added contructor,initToEmpty(),quantity(),add(),destructor methods
 
*/


#include <iostream>
#include "jar.hpp"
using namespace std;
JarType::JarType() {
    numUnits = 0;
    cout << "Rinsing jar" << endl;
}

void JarType::initToEmpty() {
    numUnits = 0;
}

int JarType::quantity() const {
    return numUnits;
}

void JarType::add(int n) {
    numUnits += n;
}
JarType::~JarType() {
    cout << "Destroying jar" << endl;
}
