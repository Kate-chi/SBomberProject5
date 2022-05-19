
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "DestroyableGroundObject.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(const Visitor& v)
{
    v.log(*this);
}


DestroyableGroundObject* Bomb::CheckDestoyableObjects()
{
    for (DestroyableGroundObject* observer : observerVec)
    {
        const double x1 = x - width / 2.0;
        const double x2 = x1 + width;

        if (observer->isInside(x1, x2)) 
            return observer;
    }

    return nullptr;
}

void Bomb::addObserver(DestroyableGroundObject* obj)
{
    observerVec.push_back(obj);
}

