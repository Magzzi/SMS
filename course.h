#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "student.h"

class Course{
	private:
		std::string courseId, courseName;
		std::vector <Student*> enrolledStudents;
		
	public:
		
		// Constructor and Destructor
		Course(const std::string& courseId, const std::string& courseName);
		~Course();
		
		// Get Methods
		
		std::string getCourseId() const;
    	std::string getCourseName() const;
    	std::vector<Student*> getEnrolledStudents() const;
    	
    	// Course management methods
		
		void setCourseName(const std::string& courseName);
		void setCourseId(const std::string& courseId);
	    void enrollStudent(Student* student);
	    void dropStudent(Student* student);
	    void listEnrolledStudents() const;
};

#endif
