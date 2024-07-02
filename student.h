#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <vector>

class Student{
	
	private:
		std::string name;
		std::string department;
		int idNum;
		std::vector<std::string> enrolledCourses;
		std::vector<int> idNUMBERS;
		std::vector<std::string> studentNames;
		
		std::vector<std::string> departments = {
        "Computer Engineering",
        "Electronics Engineering",
        "Mechanical Engineering",
        "Civil Engineering",
        "Electrical Engineering",
        "Information Technology",
        "Computer Science",
        "Software Engineering",
        "Industrial Engineering",
        "Architecture"
    };
		
	public:
		Student(const std::string& n, const std::string& d);
		~Student();
		
		// Get Functions
		std::string getName() const;
		int getID() const;
		std::string getDepartment() const;
		
		// Set Functions
		bool setName(const std::string& n);
		void setID();
		bool setDepartment(const std::string& d);
		
		// Display Functions
		void displayDetails() const;
		
		// Add Methods
		// void addCourse(const Course& course);
};

#endif
