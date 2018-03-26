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
     - 3/18/18 - Added copy constructor for Jar implementation file.
     - 3/24/18 - Added else statement to add and subtract method. Added operator override methods for jar and added cout override method for writing jar to console.
     - 3/25/18 Added implementation of int operator.
*/

#include <exception>
#include <iostream>
#include "jar.hpp"
using namespace std;
JarType::JarType() {
    numUnits = 0;
    jarCount++;
    cout << "Rinsing jar" << endl;
    
}

JarType::JarType(int units) {
    if (units < 0) {
        throw invalid_argument( "received negative value" );
    } else {
        numUnits = units;
        jarCount++;
        cout << "Rinsing jar" << endl;
        cout << "Jar filled with " << numUnits << endl;
    }
}

JarType::JarType(char option) {
    if (option == 'p') {
        jarCount++;
        numUnits = 16;
        cout << "Jar filled with " << numUnits << endl;
    } else if ( option == 'q') {
        jarCount++;
        numUnits = 32;
        cout << "Jar filled with " << numUnits << endl;
    } else {
        cout << "Invalid prefilled data type";
    }
}

JarType::JarType( JarType &j )
{
    cout << "In Copy Constructor" << endl;
    numUnits = j.numUnits;
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
    } else {
        throw invalid_argument("Invalid value to add.");
    }
}

void JarType::substract(int n) {
    if (n >= 0) {
        numUnits -= n;
    } else {
        throw invalid_argument("Invalid value to subtract");
    }
}

JarType::~JarType() {
    jarCount--;
    cout << "Destroying jar" << endl;
}

int JarType::getJarCount() {
    return jarCount;
}

std::ostream &operator<<( std::ostream &os, const JarType &j )
{
    os << "The supplied jar contains " << j.numUnits << " units." << std::endl;
    return os;
}

JarType JarType::operator+(const JarType &j) {
    JarType tmpJar;
    
    tmpJar.add ( this->numUnits + j.numUnits );
    
    return tmpJar;
}

JarType::operator int() {
    return numUnits;
}
