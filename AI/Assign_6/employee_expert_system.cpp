#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    string name, department, position;
    vector<int> ratings;

public:
    Employee(const string& n, const string& dept, const string& pos)
        : name(n), department(dept), position(pos), ratings(5, 0) {}

    void setRatings(const vector<string>& questions) {
        for (int i = 0; i < 5; ++i) {
            ratings[i] = getRating(questions[i]);
        }
    }

    string getPosition() const {
        return position;
    }

    string getName() const {
        return name;
    }

    void printSummary(const vector<string>& questions) const {
        cout << "\nPerformance Summary for: " << name << endl;
        cout << "Department: " << department << " | Position: " << position << "\n\n";

        for (int i = 0; i < 5; ++i) {
            cout << questions[i] << ": " << ratings[i] << "/10" << endl;
            giveAdvice(questions[i], ratings[i]);
        }
    }

private:
    int getRating(const string& category) {
        int rating;
        while (true) {
            cout << "Enter rating for " << category << " (1-10): ";
            if (cin >> rating && rating >= 1 && rating <= 10) {
                return rating;
            }
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    void giveAdvice(const string& category, int score) const {
        cout << "Advice for " << category << ": ";
        if (score >= 8) cout << "Excellent! Keep it up!";
        else if (score >= 6) cout << "Good. Aim higher.";
        else if (score >= 4) cout << "Needs improvement.";
        else cout << "Unsatisfactory. Urgent action needed.";
        cout << "\n\n";
    }
};

class PerformanceSystem {
    vector<Employee> employees;

public:
    void addEmployee() {
        string name, dept, pos;
        cout << "Enter employee name: ";
        getline(cin >> ws, name);
        cout << "Enter department (IT/Finance/Marketing): ";
        getline(cin, dept);
        cout << "Enter position (Manager/Developer/Customer Support): ";
        getline(cin, pos);

        vector<string> questions = getQuestions(pos);
        if (questions.empty()) {
            cout << "Invalid position.\n";
            return;
        }

        Employee emp(name, dept, pos);
        emp.setRatings(questions);
        employees.push_back(emp);
        cout << name << " added successfully!\n";
    }

    void viewAllPerformances() const {
        if (employees.empty()) {
            cout << "No employee data available.\n";
            return;
        }

        for (const auto& emp : employees) {
            vector<string> questions = getQuestions(emp.getPosition());
            emp.printSummary(questions);
            cout << "-------------------------------\n";
        }
    }

    void viewSpecificPerformance() const {
        string name;
        cout << "Enter name to search: ";
        getline(cin >> ws, name);

        for (const auto& emp : employees) {
            if (emp.getName() == name) {
                vector<string> questions = getQuestions(emp.getPosition());
                emp.printSummary(questions);
                return;
            }
        }
        cout << "Employee not found.\n";
    }

private:
    vector<string> getQuestions(const string& position) const {
        if (position == "Manager")
            return {"Leadership", "Strategy", "Team Motivation", "Decision Making", "Delegation"};
        if (position == "Developer")
            return {"Problem Solving", "Coding", "Technical Knowledge", "Code Quality", "Collaboration"};
        if (position == "Customer Support")
            return {"Communication", "Resolution", "Patience", "Product Knowledge", "Satisfaction"};
        return {};
    }
};

int main() {
    PerformanceSystem system;
    int choice;

    while (true) {
        cout << "\n=== Employee Performance System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Performances\n";
        cout << "3. View Specific Performance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore();
        switch (choice) {
            case 1: system.addEmployee(); break;
            case 2: system.viewAllPerformances(); break;
            case 3: system.viewSpecificPerformance(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
