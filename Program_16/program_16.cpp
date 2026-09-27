#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra
    )
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}

    double calculateSalary() const override {
        return basicSalary + allowance;
    }

    double calculateTax() const {
        return calculateSalary() * 0.10;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours
    )
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

class FreelanceEmployee : public Employee {
private:
    double projectAmount;

public:
    FreelanceEmployee(
        int id,
        std::string employeeName,
        double amount
    )
        : Employee(id, std::move(employeeName)),
          projectAmount(amount) {}

    double calculateSalary() const override {
        return projectAmount;
    }
};

void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();

    std::cout << "Salary: Rs. "
              << employee.calculateSalary()
              << "\n\n";
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;

    employees.push_back(
        std::make_unique<PermanentEmployee>(
            101, "Asha", 40000.0, 8000.0
        )
    );

    employees.push_back(
        std::make_unique<ContractEmployee>(
            102, "Vikas", 500.0, 80
        )
    );

    employees.push_back(
        std::make_unique<FreelanceEmployee>(
            103, "Neha", 30000.0
        )
    );

    for (const auto& employee : employees) {
        printPaySlip(*employee);
    }

    const auto* permanentEmployee =
        dynamic_cast<const PermanentEmployee*>(
            employees[0].get()
        );

    if (permanentEmployee != nullptr) {
        std::cout << "Tax for permanent employee: Rs. "
                  << permanentEmployee->calculateTax()
                  << "\n\n";
    }

    double totalPayroll = 0.0;

    for (const auto& employee : employees) {
        totalPayroll += employee->calculateSalary();
    }

    std::cout << "Total Payroll Amount: Rs. "
              << totalPayroll << '\n';

    return 0;
}
