//
//  main.cpp
//  jar project
//
//  Created by lkupke on 2/3/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 2/3/18 created the main.cpp file. Added implementation in the main method.
    - 2/10/18 added getInput method. Added Jar1.add(-5000). Add Jar 4,5,6
    - 2/18/18 added Template to the get input function
*/
#include <iostream>
#include "jar.hpp"
using namespace std;


template <typename T>
int getInput( T & n );

int main(int argc, const char * argv[]) {
    JarType jar1, jar2; // Create an object JarType jar2; // Create another object
    
//    Removed the next line as it causes a compilation error
//    jar1.numUnits = 10000;
    
    jar1.initToEmpty();
    
    jar1.add(10);
    jar2 = jar1;
    jar2.add(20);
    
    cout << jar2.quantity() << endl;
    
    jar1.add( -5000 );
    cout << jar1.quantity() << endl;

    
    
    JarType jar3(50);
    cout << jar3.quantity() << endl;

    JarType jar4( 'p' );	// Prefill with 16 ounces
    JarType jar5( 'q' );	// Prefill with 32 ounces
//    JarType jar6( 'a' );	// Should print invalid request.
    
    JarType jar6;
    int value = 0;
    int status = getInput( value );
    if ( status == 0 )
    {
        jar6.add( value );
    }
    std::cout << "\nJar6 contains " << jar6.quantity() << endl;
    

    
    return 0;
}

// Description:  A function to ask user for a value
// Return status: 0  a valid number is entered
//                1  a valid number is not entered
template <typename T>
int getInput(T & n)
{
    T temp;
    
    std::cout << "Please enter number of units: ";
    
    std::cin >> temp;
    
    if ( temp > 0 )
    {
        n = temp;
        return 0;
    }
    return 1;
} // end of getInput()
