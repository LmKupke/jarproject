//
//  main.cpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 2/3/18 created the main.cpp file. Added implementation in the main method.
*/
#include <iostream>
#include "jar.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    JarType jar1, jar2; // Create an object JarType jar2; // Create another object
    jar1.initToEmpty();
    jar1.add(10);
    jar2 = jar1;
    jar2.add(20);
    cout << jar2.quantity() << endl;
    return 0;
}
