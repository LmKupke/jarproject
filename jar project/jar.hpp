//
//  JarType.hpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 2/3/18 - Creation of the .hpp (header) file. Added class
*/

#ifndef JarType_hpp
#define JarType_hpp
#include <stdio.h>

class JarType {
public:
    JarType();
    void initToEmpty();
    void add(int n);
    int quantity() const;
    ~JarType();
    
    
private:
    int numUnits;
};



#endif /* JarType_hpp */
