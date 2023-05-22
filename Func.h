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
    bool Check;
    Course *CourseList;
};

struct Class
{
    // bool Students_Added;
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
void Create_SchoolYear(SchoolYear &schoolyear, bool &tieptuc3);
void Create_Classes(SchoolYear &sy);
void Add_Students_Class(SchoolYear &sy, string FileName, bool &tieptuc3);
void View_StudentList(Class X);
void Enter_And_Check_ClassName(SchoolYear &schoolyear, int &xClass, bool &tieptuc3);
void Create_Semester(SchoolYear *&sy, int nSY, int &iSY, int &iSemester);
void Course_Input(Course &course);
void Add_Course_To_Semester(Semester &semester, Course course);
void Add_Students_To_Course(Semester &s, string FileName, bool &tieptuc3);