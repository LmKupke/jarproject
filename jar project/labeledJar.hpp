//
//  labeledJar.hpp
//  jar project
//
//  Created by lkupke on 3/25/18.
//  Copyright © 2018 lkupke. All rights reserved.
/*
    EDIT HISTORY:
    - 3/25/18 Added header file. Created constructors, destructors, getLabel.
     - 3/26/18 - Added constructor for LabeledJar with string and amount as arguments. Added constructor for labeledJar with integer amount.
 */


#ifndef labeledJar_hpp
#define labeledJar_hpp

#include <string>
#include <stdio.h>
#include "jar.hpp"


class LabeledJar : public JarType {
public:
    LabeledJar();
    LabeledJar(std::string jarLabel);
    LabeledJar(int amountLabelUnits);
    LabeledJar(std::string jarLabel, int amountLabelUnits);
    ~LabeledJar();
    std::string getLabel() const;
    
private:
    std::string label;
};


#endif /* labeledJar_hpp */
