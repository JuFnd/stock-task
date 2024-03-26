#include "StockBook.h"
#include "FasterStockBook.h"
#include "Session.h"

int main() {
    StockBook stockBook;
    Session session(stockBook);

    FasterStockBook fasterStockBook;
    Session fasterSession(fasterStockBook);

    for (int i = 0; i < 100; i++) {
        std::string type = (i % 2 == 0) ? "buy" : "sell";
        Bid bid(100 + i ,100 + i, 10 + i, type);
        session.addBid(bid);
    }

    session.bidTop();

    for (int i = 0; i < 10; i++) {
        int id = i * 10;
        if (id < 100) {
            std::string newType = (id % 2 == 0) ? "sell" : "buy";
            session.editBid(id+100, 0, 0, newType);
        }
    }

    session.bidTop();

    session.removeBid(102);

    for (int i = 0; i < 100; i++) {
        std::string type = (i % 2 == 0) ? "buy" : "sell";
        Bid bid(100 + i, 100 + i, 10 + i, type);
        fasterSession.addBid(bid);
    }

    fasterSession.bidTop();

    for (int i = 0; i < 10; i++) {
        int id = i * 10;
        if (id < 100) {
            std::string newType = (id % 2 == 0) ? "sell" : "buy";
            fasterSession.editBid(id+100, 0, 0, newType);
        }
    }

    fasterSession.bidTop();

    fasterSession.removeBid(202);

    return 0;
}
