#include "course.h"
#include <iostream>
#include "student.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// Constructor
Course::Course(const std::string& courseId, const std::string& courseName)
    : courseId(courseId), courseName(courseName) {
}

// Destructor
Course::~Course() {
    enrolledStudents.clear();
}

// Get Functions
std::string Course::getCourseId() const {
    return courseId;
}

std::string Course::getCourseName() const {
    return courseName;
}

std::vector<Student*> Course::getEnrolledStudents() const {
    return enrolledStudents;
}

// Setter methods (if needed)
void Course::setCourseId(const std::string& courseId) {
    this->courseId = courseId;
}

void Course::setCourseName(const std::string& courseName) {
    this->courseName = courseName;
}

// Course management methods
void Course::enrollStudent(Student* student) {
    enrolledStudents.push_back(student);
}

void Course::dropStudent(Student* student) {
    // Find and remove the student from enrolledStudents (if found)
    auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), student);
    if (it != enrolledStudents.end()) {
        enrolledStudents.erase(it);
    }
}

void Course::listEnrolledStudents() const {
    std::cout << "Enrolled students in " << courseName << " (" << courseId << "):\n";
    for (auto student : enrolledStudents) {
        std::cout << "- " << student->getName() << " (" << student->getID() << ")\n";
    }
}

