#pragma once

#include <string>

struct Bid {
    int id;
    int cost;
    int amount;
    std::string type;

    Bid(){};
    Bid(int _id, int _cost, int _amount, std::string _type) : id(_id + _cost), cost(_cost), amount(_amount), type(_type) {};
};
