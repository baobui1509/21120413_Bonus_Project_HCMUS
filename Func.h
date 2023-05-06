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

struct Mark
{
    int No;
    string StudentID, StudentFullName;
    float TotalMark, FinalMark, MidtermMark, OtherMark;
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
    Mark MarkBoard;
};

struct Course
{
    int n;
    Student *StudentList;
    Mark *MarkBoard;
    string CourseID, CourseName, ClassName, TeacherName, DayOfWeek;
    int NumberOfCredits, MaxNumberStudent, Session;
};

struct Semester
{
    int n;
    Course *CourseList;
};

struct Class
{
    int nStudent, nMark;
    Student *StudentList;
    Mark *MarkBoard;
    string ClassName;
};

struct SchoolYear
{
    int nSemester, nClass;
    Semester *SemesterList;
    Class *ClassList;
    int StartYear, EndYear;
};

void TiepTuc(bool &tieptuc);
void Import_Account(string Account_File, User &user);
int Login(User user, int &index);
void View_Profile(User user, int role, int index);
void Change_Password(User &user, int role, int index);
void Create_SchoolYear(SchoolYear &schoolyear);
void Create_Classes(SchoolYear &sy);