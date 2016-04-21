#ifndef PARSEAVIRIS_H
#define PARSEAVIRIS_H

#include <QString>
#include "HyperCube.h"
class ParseAviris
{
public:
    ParseAviris();
    virtual ~ParseAviris();

    bool Parse(QString fileName, HyperCube& cube);
};

#endif // PARSEAVIRIS_H
