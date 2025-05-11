#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
    public:
        int id;
        string name, dept, position;
        vector<int>ratings;

        Employee(int id, string name,string dept, string position, vector<int>ratings)
        {
            this->id = id;
            this->name = name;
            this->dept = dept;
            this->position = position;
            this->ratings = ratings;
        }

};

class EmployeeSystem
{
    vector<Employee>employees;
    public:
        void printSummary(Employee emp)
        {
            cout<<"\n\nID : "<<emp.id<<endl;
            cout<<"\n------------- PROFILE EVALUATION ------------\n"<<endl;
            cout<<"\nName: "<<emp.name<<endl;
            cout<<"Department: "<<emp.dept<<endl;
            cout<<"Position: "<<emp.position<<endl;
            vector<string>questions = getQuestions(emp.position);
            cout<<"\n\nSkill\t\t\t\tRatings\t\t\t\t\tAdvice\n\n"<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<questions[i]<<"\t\t\t\t"<<emp.ratings[i]<<"\t\t\t\t\t"<<getAdvice(emp.ratings[i])<<"\n"<<endl;
            }
        }

        vector<int> getRatings(vector<string>ques)
        {
            vector<int>ratings;
            cout<<"\nGive rating for each quality(1 to 10): \n"<<endl;
            for(int i=0;i<ques.size();i++)
            {
                int rating;
                cout<<"Rating for "<<ques[i]<<": ";
                cin>>rating;
                if(rating < 1 || rating > 10)
                {
                    "Please give rating only in the range of 1 to 10";
                    i--;
                    continue;
                }
                ratings.push_back(rating);
            }
            return ratings;
        }    

        vector<string> getQuestions(string pos)
        {
            if(pos == "Developer")
            {
                return {"Code Quality","Technical Skills","Collaboration","Problem Solving","Coding skills"};
            }
            else if(pos == "Manager")
            {
                return {"Leadership","Communication Skills","Decision Making","Knowledge"};
            }
            else if(pos == "Customer Support")
            {
                return {"Product Quality","Communication","Customer Satisfaction","Patience","Resolution"};
            }
            cout<<"Please enter valid position name"<<endl;
            return {" "};
        }

        string getAdvice(int score)
        {
            if(score >= 8)
            {
                return "Excellent! Keep it up!";
            }
            else if(score >= 6)
            {
                return "Good! Aim Higher";
            }
            else if(score >= 4)
            {
                return "Needs improvement";
            }
            else
            {
                return "Unsatisfactory, Urgent action needed";
            }
        }

        void addEmployee()
        {
            int id;
            string name,dept,position;
            vector<int>ratings;
            cout<<"\nEnter employee details"<<endl;
            cout<<"\nId: ";
            cin>>id;
            cin.ignore();

            cout<<"\nName: ";
            getline(cin,name);
            cout<<"\nDepartment(IT/Finance/Marketing): ";
            getline(cin,dept);
            cout<<"\nPosition(Developer/Manager/Customer Support): ";
            getline(cin,position);

            vector<string>questions;
            questions = getQuestions(position);

            ratings = getRatings(questions);

            Employee emp(id,name,dept,position,ratings);
            employees.push_back(emp);
        }

        void viewIndivisualPerformance()
        {
            string nm;
            cout<<"\nEnter employee name: ";
            cin.ignore();
            getline(cin,nm);
            int flag = 1;

            for(auto emp : employees)
            {
                if(emp.name == nm)
                {
                    flag = 0;
                    printSummary(emp);
                    break;
                }
            }
            if(flag == 1)
            {
                cout<<"\nNo any employee exist with name "<<nm<<endl;
            }
        }

        void viewAllPerformances()
        {
            for(auto emp : employees)
            {
                printSummary(emp);
            }
        }

       
};

int main()
{
    EmployeeSystem emSys;

    int choice;
    while (true) {
        cout << "\n=== Employee Performance System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. All Employees Performances\n";
        cout << "3. Single Employee Performance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin>>choice;

        switch (choice) {
            case 1: emSys.addEmployee(); break;
            case 2: emSys.viewAllPerformances(); break;
            case 3: emSys.viewIndivisualPerformance(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;

}