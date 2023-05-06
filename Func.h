#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Account
{
    string UserName;
    string Password;
};

struct User
{
    int n1, n2;
    Account *Acadamic_Staff_Member;
    Account *Student;
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

struct Course
{
    Student *StudentList;
    string CourseID, CourseName, ClassName, TeacherName, DayOfWeek;
    int NumberOfCredits, MaxNumberStudent, Session;
};

struct Semester
{
    Course *CourseList;
};

struct Class
{
    Student *StudentList;
    string ClassName;
};

void TiepTuc(bool &tieptuc);
void Import_Account(string Account_File, User &user);
int Login(User user, int &index);
void View_Profile(User user, int role, int index);
void Change_Password(User &user, int role, int index);