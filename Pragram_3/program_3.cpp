#include <iostream>

class Balance {
private:
    int value;

public:
    explicit Balance(int givenValue) : value(givenValue) {}

    Balance operator-() const {
        return Balance(-value);
    }

    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Balance balance(25000);
    Balance negativeBalance = -balance;

    std::cout << "Original balance: ";
    balance.display();

    std::cout << "Negative balance: ";
    negativeBalance.display();

    return 0;
}
