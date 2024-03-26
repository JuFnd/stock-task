#include "IStockBook.h"
#include <chrono>
#include <iostream>

class Session {
private:
    IStockBook& book;

public:
    void addBid(const Bid& request);
    void editBid(int id, int cost = 0, int amount = 0, std::string type = "");
    void removeBid(int id);
    void bidTop();

    Session(IStockBook& stockBook) : book(stockBook) {}
};