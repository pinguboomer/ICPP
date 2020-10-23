#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

#include <iostream>
#include "IObject.h"


class IComparable : public IObject {
public:
    //ciste virtualni metoda
    virtual int compareTo(IComparable* obj) const = 0;
};

#endif //ICOMPARABLE_H