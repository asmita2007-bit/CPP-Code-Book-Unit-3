#include <iostream>
#include <string>

int add(int first, int second) {
    return first + second;
}

double add(double first, double second) {
    return first + second;
}

int add(int first, int second, int third) {
    return first + second + third;
}

std::string add(const std::string& first, const std::string& second) {
    return first + second;
}

int main() {
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';
    std::cout << "Joined strings: "
              << add(std::string("Hello "), std::string("World")) << '\n';

    return 0;
}
