#include "FasterStockBook.h"
#include <iostream>

void FasterStockBook::addBid(const Bid& request) {
    requests[request.id] = request;
    std::cout << "Bid added: Id: " << request.id << ", Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
}

void FasterStockBook::editBid(int id, int cost, int amount, std::string type) {
    auto it = requests.find(id);
    if (it != requests.end()) {
        Bid& request = it->second;
        std::cout << "Bid before edited: Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
        if (cost != 0) {
            request.cost = cost;
        }
        if (amount != 0) {
            request.amount = amount;
        }
        if (!type.empty()) {
            request.type = type;
        }
        std::cout << "Bid after edited: Id: " << request.id << ", Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
    }
}

void FasterStockBook::removeBid(int id) {
    size_t removedCount = requests.erase(id);
    if (removedCount > 0) {
        std::cout << "Bid with Id " << id << " removed." << std::endl;
    } else {
        std::cout << "Bid with Id " << id << " not found." << std::endl;
    }
}

void FasterStockBook::bidTop() {
    std::map<int, Bid>::iterator it = requests.begin();
    int count = 0;
    
    while (it != requests.end() && count < 10) {
        Bid& request = it->second;
        std::cout << "Bid: Id: " << request.id << ", Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
        
        ++it;
        ++count;
    }
}
