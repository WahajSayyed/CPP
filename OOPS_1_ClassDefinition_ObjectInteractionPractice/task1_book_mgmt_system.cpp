/*
You're building a digital library system that needs to track book information. Create a Book class that stores essential book data and provides controlled access to that information.

🔍 Practice
Run the code and observe how objects are created and manipulated. Think about:

How does the constructor ensure proper object initialization?

What happens when you try to access private data members directly?

Modify the code to experiment with:

Adding validation to the setPages method (reject negative values)

Creating additional book objects with different data

Test your changes and observe the encapsulation in action.
*/
#include <iostream>
#include <string>

class Book{
private:
    std::string title;
    std::string author;
    int pages;
    bool isAvailable;
public:
    // Parameterized constructor
    Book(std::string bookTitle, std::string bookAuthor, int pageCount)
        :title(bookTitle), author(bookAuthor), pages(pageCount), isAvailable(true){
        }
    // Getter methods
    std::string getTitle() const {return title;}
    std::string getAuthor() const {return author;}
    int getPages() const {return pages;}
    bool getAvailability() const {return isAvailable;}
    // Setter methods
    void setPages(int newPages){
        if (newPages > 0){
            pages = newPages;
        }
    }
    void setAvailability(bool status){
        isAvailable = status;
    }
    // Display book information
    void displayInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Pages: " << pages << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;
    }        
};

int main(){
    // Create book objects
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", 1376);
    Book book2("Clean Code", "Robert C. Martin", 464);
    // Display book information
    book1.displayInfo();
    book2.displayInfo();
    // Demonstrate object interaction
    std::cout << "Checking out: " << book1.getTitle() <<std::endl;
    book1.setAvailability(false);
    book1.displayInfo();
    return 0;
}
/*
✅ Success Checklist
Objects are created successfully using the parameterized constructor

Private data members are properly encapsulated and accessed through getters/setters

The displayInfo method shows all book details correctly  
*/