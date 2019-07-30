#include "item.h"

#include <QDebug>

Item::Item()
{

}

Item::Item(const string description)
{
    this->description = description;
}
