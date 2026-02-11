/*
Create a secure user profile class for a social media platform that needs to protect personal information while allowing controlled access for different user roles.

🔍 Practice
Complete the implementation by adding:

Privacy control methods (setPrivacyStatus, togglePrivacy)

Friend management methods (addFriend, removeFriend, with validation)

A friend class PlatformModerator that can access private information for moderation

A friend function technicalSupport for customer service access

Test all validation and access control features.
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
class UserProfile {
private:
    std::string username;
    std::string email;
    std::string passwordHash;
    std::string fullName;
    int age;
    std::vector<std::string> friends;
    bool isPrivateProfile;
    bool isVerified;
    std::string phoneNumber;
    // Private validation helpers
    bool isValidEmail(const std::string& email) const {
        std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        return std::regex_match(email, emailPattern);
    }    
    bool isValidUsername(const std::string& username) const {
        return username.length() >= 3 && username.length() <= 20;
    }
public:
    // Constructor with comprehensive validation
    UserProfile(const std::string& user, const std::string& mail, const std::string& name) 
        : isPrivateProfile(true), isVerified(false), age(0) {        
        if (!setUsername(user)) {
            throw std::invalid_argument("Invalid username");
        }
        if (!setEmail(mail)) {
            throw std::invalid_argument("Invalid email address");
        }
        if (!setFullName(name)) {
            throw std::invalid_argument("Invalid full name");
        }
    }    
    // Getters for public information
    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }
    std::string getDisplayName() const { 
        return isPrivateProfile ? username : fullName; 
    }
    bool isProfilePrivate() const { return isPrivateProfile; }
    bool isUserVerified() const { return isVerified; }
    int getFriendCount() const { return friends.size(); }    
    // Secured setters with validation
    bool setUsername(const std::string& newUsername) {
        if (isValidUsername(newUsername)) {
            username = newUsername;
            return true;
        }
        std::cout << "Error: Username must be 3-20 characters long" << std::endl;
        return false;
    }    
    bool setEmail(const std::string& newEmail) {
        if (isValidEmail(newEmail)) {
            email = newEmail;
            return true;
        }
        std::cout << "Error: Invalid email format" << std::endl;
        return false;
    }    
    bool setFullName(const std::string& name) {
        if (!name.empty() && name.length() <= 100) {
            fullName = name;
            return true;
        }
        std::cout << "Error: Full name cannot be empty or exceed 100 characters" << std::endl;
        return false;
    }    
    bool setAge(int newAge) {
        if (newAge >= 13 && newAge <= 120) {
            age = newAge;
            return true;
        }
        std::cout << "Error: Age must be between 13 and 120" << std::endl;
        return false;
    }    
    // Your implementation here: Add methods for privacy settings, friend management, etc.    
    // Friend declarations for platform administration
    friend class PlatformModerator;
    friend void technicalSupport(UserProfile& user, const std::string& issue);
    void setPrivacyStatus(bool isPrivate) {
        isPrivateProfile = isPrivate;
        std::cout << "Profile set to " << (isPrivate ? "private" : "public") << std::endl;
    }    
    bool addFriend(const std::string& friendUsername) {
        if (friendUsername == username) {
            std::cout << "Error: Cannot add yourself as friend" << std::endl;
            return false;
        }        
        for (const auto& existing : friends) {
            if (existing == friendUsername) {
                std::cout << "Error: Already friends with " << friendUsername << std::endl;
                return false;
            }
        }        
        friends.push_back(friendUsername);
        std::cout << "Added " << friendUsername << " as friend" << std::endl;
        return true;
    }    
    void displayPublicProfile() const {
        std::cout << "=== Public Profile ===" << std::endl;
        std::cout << "Username: " << username << std::endl;
        std::cout << "Display Name: " << getDisplayName() << std::endl;
        std::cout << "Verified: " << (isVerified ? "Yes" : "No") << std::endl;
        std::cout << "Friends: " << getFriendCount() << std::endl;
    }
};



class PlatformModerator {
public:
    static void performModeration(const UserProfile& user) {
        std::cout << "\n=== MODERATION REVIEW ===" << std::endl;
        std::cout << "Full access to: " << user.username << std::endl;
        std::cout << "Real name: " << user.fullName << std::endl;
        std::cout << "Email: " << user.email << std::endl;
        std::cout << "Age: " << user.age << std::endl;
        std::cout << "Friend count: " << user.friends.size() << std::endl;
    }
};
void technicalSupport(UserProfile& user, const std::string& issue) {
    std::cout << "Technical Support accessing account: " << user.username << std::endl;
    std::cout << "Issue: " << issue << std::endl;
    std::cout << "Contact email: " << user.email << std::endl;
}
int main() {
    std::cout << "=== User Profile Management System ===" << std::endl;    
    try {
        UserProfile user1("alice123", "alice@email.com", "Alice Johnson");
        user1.setAge(25);
        user1.displayPublicProfile();        
        // Test friend management
        user1.addFriend("bob456");
        user1.addFriend("charlie789");
        user1.addFriend("alice123"); // Should fail        
        // Test privacy controls
        user1.setPrivacyStatus(false);
        user1.displayPublicProfile();        
        // Test friend access
        PlatformModerator::performModeration(user1);
        technicalSupport(user1, "Password reset request");        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }    
    return 0;
}
/*
✅ Success Checklist
All personal data is properly encapsulated and protected

Email and username validation works correctly

Privacy settings control information visibility appropriately

Friend relationships provide necessary access for platform operations

💡 Key Points
Data Protection: Private members prevent unauthorized access and maintain data integrity

Validation Logic: Setters should enforce business rules and prevent invalid data states

Controlled Access: Getters can implement different access levels based on user permissions

Friend Relationships: Should be used sparingly and only for legitimate business requirements

❗ Common Mistakes to Avoid
Making data members public just for convenience, breaking encapsulation

Creating getters and setters for every private member without considering if they're needed

Not implementing validation in setter methods, allowing invalid data

Overusing friend relationships, which can weaken encapsulation benefits

🚀 Next Steps
These encapsulation skills are fundamental to enterprise software architecture. 
In professional development, you'll use these patterns to design secure APIs, protect sensitive business data, implement role-based access controls, and create maintainable codebases.
Mastery of encapsulation enables you to build systems that scale securely, meet compliance requirements, and provide robust foundations for complex enterprise applications.
*/