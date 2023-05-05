#include <iostream>

using namespace std;

struct User
{

    string UserName;
    string Password;
};

struct Student
{
    int No;
    string StudentID;
    string FirstName;
    string LastName;
    string Gender;
    string Birthday;
    string SocialID;
};

struct Semester
{
    Course *CourseList;
};

struct Course
{
    Student *StudentList;
    string CourseID, CourseName, ClassName, TeacherName, DayOfWeek;
    int NumberOfCredits, MaxNumberStudent, Session;
};

struct Class
{
    Student *StudentList;
    string ClassName;
};

// hehe