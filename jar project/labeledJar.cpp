//
//  labeledJar.cpp
//  jar project
//
//  Created by lkupke on 3/25/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 3/25/18 - Created the implementation file of LabeledJar. Added constructor, destructor, method getLabel.
    - 3/26/18 - Added constructor for LabeledJar with string and amount as arguments. Added constructor for labeledJar with integer amount.
*/
#include "labeledJar.hpp"
#include <iostream>
using namespace std;

LabeledJar::LabeledJar() {
    label = "Generic";
    cout << "\nGetting labeled jar ready" << endl;
}

LabeledJar::LabeledJar(string jarLabel) {
    label = jarLabel;
}

LabeledJar::LabeledJar(int amountLabelUnits) : JarType::JarType(amountLabelUnits)
{
    label = "Generic";
    cout << "\nGetting prefilled generic labeled jar ready" << endl;
}

LabeledJar::LabeledJar(string jarLabel, int amountLabelUnits) : JarType::JarType(amountLabelUnits) {
    label = jarLabel;
    cout << "\nGetting prefilled " << label << " labeled jar ready" << endl;
}

LabeledJar::~LabeledJar(){
    cout << "\nDestroying labeled jar" << endl;
}

string LabeledJar::getLabel() const {
    return label;
}
