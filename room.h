#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Item;
class Room
{
public:
    Room(string description);

    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getImageFilename();
    void addItem(Item *item);

    vector<string> exitString();
    Room *nextRoom(string direction);

    string getDescription() const { return description; }

    void setCanEnter(bool canEnter);
    bool getCanEnter();

    bool ifHasGold();
    bool ifHasLogs();
    bool ifHasMap();
    bool ifHasSnake();
    bool ifHasStone();
    bool ifHasTiger();

    void setGold(bool);
    void setLogs(bool);
    void setMap(bool);
    void setSnake(bool);
    void setStone(bool);
    void setTiger(bool);
    void setItem(bool);

    vector<Item*> items;
    Item *item;

private:
    string description;
    map<string, Room*> exits;
    bool canEnter;
    vector<string> list;
    bool hasGold = false;
    bool hasLogs = false;
    bool hasMap = false;
    bool hasSnake = false;
    bool hasStone = false;
    bool hasTiger = false;
    bool itemPresent = false;
};

#endif // ROOM_H
