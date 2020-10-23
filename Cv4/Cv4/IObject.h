#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H

#include <stdexcept>
using namespace std;

class IObject {
public:
    //ciste virtualni metoda
    virtual string toString() const = 0;
};

#endif //IOBJECT_H