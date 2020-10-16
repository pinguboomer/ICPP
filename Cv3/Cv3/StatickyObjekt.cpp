#include "StatickyObjekt.h"


StatickyObjekt::StatickyObjekt(int id, TypPrekazky typPrekazky):Objekt(id)
{
    this->id = id;
    this->typPrekazky = typPrekazky;
}

TypPrekazky StatickyObjekt::GetTypPrekazky()
{
    return typPrekazky;
}
