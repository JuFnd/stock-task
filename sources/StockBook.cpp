#include "StockBook.h"
#include <algorithm>
#include <iostream>

void StockBook::addBid(const Bid& request) {
    requests.push_back(request);
    std::cout << "Bid added: Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
}

void StockBook::editBid(int id, int cost, int amount, std::string type) {
    if (id >= 0 && id < requests.size()) {
        Bid& request = requests[id];
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
        std::cout << "Bid after edited: Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
    }
}

void StockBook::removeBid(int id) {
    if (id >= 0 && id < requests.size()) {
        Bid removedBid = requests[id];
        requests.erase(requests.begin() + id);
        std::cout << "Bid removed: Cost: " << removedBid.cost << ", Amount: " << removedBid.amount << ", Type: " << removedBid.type << ", Prefix: " << prefix << std::endl;
    }
}

void StockBook::bidTop() {
    std::sort(requests.begin(), requests.end(), [](const Bid& a, const Bid& b) {
        return a.id > b.id;
    });

    int count = 0;
    for (const Bid& request : requests) {
        std::cout << "Cost: " << request.cost << ", Amount: " << request.amount << ", Type: " << request.type << ", Prefix: " << prefix << std::endl;
        count++;
        if (count >= 10) {
            break;
        }
    }
}
