#include "Session.h"
#include <chrono>
#include <iostream>

void Session::addBid(const Bid& request) {
    auto start = std::chrono::steady_clock::now();
    book.addBid(request);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время выполнения операции addBid: " << duration.count() << " секунд" << std::endl;
}

void Session::editBid(int id, int cost, int amount, std::string type) {
    auto start = std::chrono::steady_clock::now();
    book.editBid(id, cost, amount, type);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время выполнения операции editBid: " << duration.count() << " секунд" << std::endl;
}

void Session::removeBid(int id) {
    auto start = std::chrono::steady_clock::now();
    book.removeBid(id);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время выполнения операции removeBid: " << duration.count() << " секунд" << std::endl;
}

void Session::bidTop() {
    auto start = std::chrono::steady_clock::now();
    book.bidTop();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Время выполнения операции bidTop: " << duration.count() << " секунд" << std::endl;
}
