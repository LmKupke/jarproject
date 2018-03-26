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
    - 3/18/18  - Added copy constructor for jar, added static method getJarCount(), added static private attribute jarCount
    - 3/24/18 - Added friend for cout operator. Added operator overload method for adding jars
    - 3/25/18 - Added operator int to header file.
*/

#ifndef JarType_hpp
#define JarType_hpp
#include <stdio.h>
#include <exception>
class JarType {
public:
    JarType();
    JarType(int n);
    JarType(char option);
    JarType( JarType &j );
    void initToEmpty();
    void add(int n);
    int quantity() const;
    void substract(int n);
    static int getJarCount();
    ~JarType();
    friend int reveal( JarType j );
    friend std::ostream &operator<<(std::ostream &os, const JarType &j);
    JarType operator+(const JarType &j);
    operator int();
private:
    int numUnits;
    static int jarCount;
};



#endif /* JarType_hpp */
