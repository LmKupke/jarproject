//
//  JarType.hpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 2/3/18 - Creation of the .hpp (header) file. Added class
    - 2/10/18 - Added two different type of constructors. Added subtract method.
*/

#ifndef JarType_hpp
#define JarType_hpp
#include <stdio.h>

class JarType {
public:
    JarType();
    JarType(int n);
    JarType(char option);
    void initToEmpty();
    void add(int n);
    int quantity() const;
    void substract(int n);
    ~JarType();
    
    
private:
    int numUnits;
};



#endif /* JarType_hpp */
