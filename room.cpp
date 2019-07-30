#include "room.h"

Room::Room(string description)
{
    this->description = description;

    canEnter = true;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
    if (north != nullptr)
        exits["north"] = north;

    if (east != nullptr)
        exits["east"] = east;

    if (south != nullptr)
        exits["south"] = south;

    if (west != nullptr)
        exits["west"] = west;
}

vector<string> Room::exitString()
{
    list.clear();

    map<string, Room*>::iterator index;
    for (index = exits.begin(); index != exits.end(); index++)
        list.push_back(index->first);

    return list;
}

Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction);

    if (next == exits.end())
        return nullptr;

    return next->second;
}

void Room::setCanEnter(bool canEnter)
{
    this->canEnter = canEnter;
}

bool Room::getCanEnter()
{
    return canEnter;
}

string Room::getImageFilename()
{
    return ":/game/" + getDescription() + ".jpg";
}

void Room::addItem(Item *item)
{
    this->item = item;
    items.push_back(item);
}

bool Room::ifHasGold()
{
    return hasGold;
}

bool Room::ifHasLogs()
{
    return hasLogs;
}

bool Room::ifHasMap()
{
    return hasMap;
}

bool Room::ifHasSnake()
{
    return hasSnake;
}

bool Room::ifHasStone()
{
    return hasStone;
}

bool Room::ifHasTiger()
{
    return hasTiger;
}

void Room::setGold(bool gold)
{
    if (gold)
        hasGold = true;
    else
        hasGold = false;
}

void Room::setLogs(bool logs)
{
    if (logs)
        hasLogs = true;
    else
        hasLogs = false;
}

void Room::setMap(bool map)
{
    if (map)
        hasMap = true;
    else
        hasMap = false;
}

void Room::setSnake(bool snake)
{
    if (snake)
        hasSnake = true;
    else
        hasSnake = false;
}

void Room::setStone(bool stone)
{
    if (stone)
        hasStone = true;
    else
        hasStone = false;
}

void Room::setTiger(bool tiger)
{
    if (tiger)
        hasTiger = true;
    else
        hasTiger = false;
}

void Room::setItem(bool i)
{
    if (i)
        itemPresent = true;
    else
        itemPresent = false;
}
