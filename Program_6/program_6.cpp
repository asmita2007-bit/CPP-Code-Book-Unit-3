#include <iostream>

class Distance {
private:
    int meters;

public:
    explicit Distance(int value) : meters(value) {}

    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    bool operator==(const Distance& other) const {
        return meters == other.meters;
    }

    void display() const {
        std::cout << meters << " meters\n";
    }
};

int main() {
    Distance first(120);
    Distance second(90);
    Distance third(120);

    std::cout << "First distance: ";
    first.display();

    std::cout << "Second distance: ";
    second.display();

    if (first > second) {
        std::cout << "First distance is greater\n";
    } else {
        std::cout << "Second distance is greater or equal\n";
    }

    if (first == third) {
        std::cout << "First and third distances are equal\n";
    } else {
        std::cout << "First and third distances are not equal\n";
    }

    return 0;
}
