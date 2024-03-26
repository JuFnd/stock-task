#pragma once

#include <vector>

#include "IStockBook.h"

class StockBook : public IStockBook {
private:
	std::string prefix = "Default";
	std::vector<Bid> requests;

public:
	void addBid(const Bid& request) override;
	void editBid(int id, int cost = 0, int amount = 0, std::string type = "") override;
	void removeBid(int id) override;
	void bidTop() override;
};