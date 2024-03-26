#pragma once

#include "Bid.h"

class IStockBook {
public:
	virtual void addBid(const Bid& request) = 0;
	virtual void editBid(int id, int cost = 0, int amount = 0, std::string type = "") = 0;
	virtual void removeBid(int id) = 0;
	virtual void bidTop() = 0;
};