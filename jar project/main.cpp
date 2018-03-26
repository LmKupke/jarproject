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
    - 2/18/18 added Template to the get input function.
    - 3/18/18 added instance of jar using copy constructor to file, added static JarCount to 0, added friend declaration and implementation,
    - 3/25/18 - Added Try Catch block for add method. Added a rack from the free pool and deleted it. Created a unique pointer for jar warehouse and wrote to the command line.
    - 3/25/18 - Assignment 8 - Added int xyz = jar. Added the labelled jars to to main.cpp file. 
    - 3/26/18 - Added LabeledJar instances (pills,pickles,candy,abc) with different constructors.
*/
#include <iostream>
#include "jar.hpp"
#include <exception>
#include <memory>
#include "labeledJar.hpp"
using namespace std;


template <typename T>
T getInput(string output);

int JarType::jarCount = 0;

int reveal( JarType j );

int main(int argc, const char * argv[]) {
    
    std::cout << "Count of jars is: " << JarType::getJarCount() << std::endl;
    JarType jar1, jar2; // Create an object JarType jar2; // Create another object
    
    std::cout << "After jar1 and jar2, count of jars is: " << JarType::getJarCount() << std::endl;

//    Removed the next line as it causes a compilation error
//    jar1.numUnits = 10000;
    
    jar1.initToEmpty();
    
    jar1.add(10);
    jar2 = jar1;
    jar2.add(20);
    
    cout << jar2.quantity() << endl;
    
    //jar1.add( -5000 );
    cout << jar1.quantity() << endl;

    
    
    JarType jar3(50);
    cout << jar3.quantity() << endl;

    JarType jar4( 'p' );	// Prefill with 16 ounces
    JarType jar5( 'q' );	// Prefill with 32 ounces
//    JarType jar6( 'a' );	// Should print invalid request.
    
    JarType jar6;

    int value = getInput<int>("Please enter number of units: ");
    jar6.add( value );

    std::cout << "\nJar6 contains " << jar6.quantity() << endl;
    
    
    JarType jar7, jar8, jar9;
    JarType shelf[3];
    
    shelf[0] = jar7;
    shelf[1] = jar8;
    shelf[2] = jar9;
    
    for (int i = 0; i < 3; i++) {
        int jarAmount = getInput<int>("Please enter the number of units: ");
        shelf[i].add(jarAmount);
    }
    
    for (int i = 0; i < 3; i++) {
        cout << shelf[i].quantity() << endl;
    }
    
    
    JarType * jarPtr = nullptr;	// Define the pointer variable
    jarPtr = &jar1;	// Get address of jar1 -- a good statement (pointer to == address of)
    cout << "Showing quantities in jar1 via a pointer variable: " << jarPtr->quantity() << endl;

    // Made copy of jar from another Jar
    JarType jar31 = jar1;
    jar31.quantity();
    cout << " The reveal friend method shows Jar two has " << reveal(jar2) << " number of units" << endl;
    
    try {
        jar31.add(-3);
    } catch (const exception& e) {
        cout << e.what() << endl;
        
    }
    JarType * rack = new JarType[5];
    
    for (int i = 0; i < 4; i++) {
        rack[i].add(2);
        cout << rack[i].quantity() << endl;
    }
    delete [] rack;
    
    const int arraySize = 10;
    unique_ptr<JarType[]> wareHouse( new JarType[arraySize] );
    
    for ( int i = 0; i < arraySize; i++ ) {
        wareHouse[i].add((3 * i));
        cout << "  Item " << i << " has: " << wareHouse[i].quantity() << endl;
    }
    
    cout << jar1;
    
    JarType jar30;
    jar30 = jar1 + jar2;
    cout << jar30;
    
    
    
    int xyz = jar1;
    jar2 = xyz;
    
    LabeledJar pills;
    pills.add(23);
    cout << "\nLabeled jar contains: " << pills.quantity() << " units." << endl;
    cout << "\nLabeled jar's label: " << pills.getLabel() << endl;
    LabeledJar pickles(25);  // Prefill
    pickles.quantity();
    LabeledJar candy("Kit Kat"); // Create jar with label Kit Kat
    LabeledJar abc("Kit Kat", 25);
    
    return 0;
}

// Description:  A function to ask user for a value
// Return status: 0  a valid number is entered
//                1  a valid number is not entered
template <typename T>
T getInput(string output)
{
    T temp;
    
    std::cout << output;
    
    std::cin >> temp;
    
    return temp;
} // end of getInput()


int reveal( JarType j )
{
    // Has direct access to all properties of JarType
    return j.numUnits;
}
