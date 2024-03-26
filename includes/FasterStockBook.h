#pragma once

#include "IStockBook.h"
#include <map>

class FasterStockBook : public IStockBook {
private:
    std::string prefix = "Faster";
    std::map<int, Bid, std::greater<int>> requests;

public:
    void addBid(const Bid& request) override;
    void editBid(int id, int cost = 0, int amount = 0, std::string type = "") override;
    void removeBid(int id) override;
    void bidTop() override;
};
