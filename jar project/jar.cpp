//
//  JarType.cpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
     - 2/3/18 - Created the jar.cpp file. Added contructor,initToEmpty(),quantity(),add(),destructor methods
     - 2/10/18 - Added two different constructors with arguments int and char. Added subtract method.
 
*/


#include <iostream>
#include "jar.hpp"
using namespace std;
JarType::JarType() {
    numUnits = 0;
    cout << "Rinsing jar" << endl;
    
}

JarType::JarType(int units) {
    if (units < 0) {
        throw invalid_argument( "received negative value" );
    } else {
        numUnits = units;
        cout << "Rinsing jar" << endl;
        cout << "Jar filled with " << numUnits << endl;
    }
}

JarType::JarType(char option) {
    if (option == 'p') {
        numUnits = 16;
        cout << "Jar filled with " << numUnits << endl;
    } else if ( option == 'q') {
        numUnits = 32;
        cout << "Jar filled with " << numUnits << endl;
    } else {
        cout << "Invalid prefilled data type";
    }
}

void JarType::initToEmpty() {
    numUnits = 0;
}

int JarType::quantity() const {
    return numUnits;
}

void JarType::add(int n) {
    if (n >= 0){
        numUnits += n;

    }
}

void JarType::substract(int n) {
    if (n >= 0) {
        numUnits -= n;
    }
}

JarType::~JarType() {
    cout << "Destroying jar" << endl;
}
