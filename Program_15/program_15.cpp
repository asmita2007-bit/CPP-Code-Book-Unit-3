#include <iostream>
#include <string>

class Payment {
public:
    virtual void pay(double amount) const = 0;

    virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using card\n";
    }
};

class UpiPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

class NetBankingPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount
                  << " using net banking\n";
    }
};

class WalletPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount
                  << " using wallet\n";
    }
};

void processPayment(const Payment& payment, double amount) {
    payment.pay(amount);
}

int main() {
    CardPayment card;
    UpiPayment upi;
    NetBankingPayment netBanking;
    WalletPayment wallet;

    processPayment(card, 1250.0);
    processPayment(upi, 750.0);
    processPayment(netBanking, 500.0);
    processPayment(wallet, 900.0);

    return 0;
}
