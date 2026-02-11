/*
Extend your understanding by creating a Student class that manages academic information with more complex interactions.

🔍 Practice
Complete the main function to:

Create at least two Student objects

Add multiple grades to each student

Display their information and averages

Test the grade validation by trying to add invalid grades
*/
#include <iostream>
#include <string>
#include <vector>

class Student{
private:
    std::string name;
    int studentId;
    std::vector<double> grades;

public:
    // Constructor
    Student(std::string studentName, int id)
    :name(studentName), studentId(id){
        std::cout << "Student " << name << " enrolled with ID: " << studentId << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    // Add a grade
    void addGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0){
            grades.push_back(grade);
            std::cout << "Grade " << grade << " added for " << name << std::endl;
        } else {
            std::cout << "Invalid grades. Must be between 0 and 100." << std::endl;
        }
    }

    // calculate average grade
    double calculateAverage() const {
        if (grades.empty()) return 0.0;

        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    // Display Student Information
    void displayStudent() const {
        std::cout << "------------------------" << std::endl;
        std::cout << "Student: " << name << " (ID: " << studentId << ")" << std::endl;
        std::cout << "Number of grades: " << grades.size() << std::endl;
        std::cout << "Average grade: " << calculateAverage() << std::endl;      
        std::cout << "------------------------" << std::endl;  
    }
};

int main(){
    Student student1("Jay", 1);
    Student student2("Martin", 2);

    student1.addGrade(78);
    student1.addGrade(75);
    student1.addGrade(98);
    student2.addGrade(88);
    student2.addGrade(75);
    student2.addGrade(88);

    std::cout << "\n=== Student Reports ===" << std::endl;
    student1.displayStudent();
    std::cout << std::endl;
    student2.displayStudent();
}

/*
✅ Success Checklist
Student objects are created with proper initialization

Grades are added with validation working correctly

Average calculation produces accurate results

All object interactions work as expected

💡 Key Points
Encapsulation: Private data members protect object integrity while public methods provide controlled access

Constructors: Ensure objects are properly initialized when created, preventing undefined states

Member Functions: Define object behavior and enable controlled interaction with object data

Const Methods: Getter methods should be marked const since they don't modify object state

❗ Common Mistakes to Avoid
Making data members public, breaking encapsulation principles

Forgetting to validate input in setter methods

Not using initializer lists in constructors for better performance

Creating getters/setters for every data member when they're not needed 

🚀 Next Steps
These object-oriented programming skills form the foundation for enterprise software development. In professional environments, you'll use these concepts to model complex business entities, create maintainable code architectures, and build systems that can scale with changing requirements. Software architects rely on these principles to design systems that separate concerns, protect data integrity, and provide clear interfaces between different components of large applications.
*/