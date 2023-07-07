#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma warning(disable : 4996)

struct Account
{
    string UserName;
    string Password;
    string Name;
};

struct User
{
    int n1, n2;
    Account *Acadamic_Staff_Member;
    Account *Student;
};

struct CourseMark
{
    int No;
    string StudentID, StudentFullName;
    float MidtermMark, FinalMark, TotalMark, OtherMark;
};

struct Mark // Chua diem cua 1 Class
{
    int No;
    string StudentID, StudentFullName;
    int nFinalMark;
    float *FinalMark;
    float GPA;
};

struct ClassMark
{
    Mark *Marks;
    float OverallGPA;
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
    int n;
    Student *StudentList;
    CourseMark *MarkBoard;
    bool Publish;
    bool Export;
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
    int n;
    Student *StudentList;
    ClassMark MarkBoard;
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

void Add_Students_Class(SchoolYear &sy, int nClass, string FileName, bool &tieptuc3);

void View_StudentList(Class X);

void Enter_And_Check_ClassName(SchoolYear &schoolyear, int &xClass, bool &tieptuc3);

void Create_Semester(SchoolYear *&sy, int nSY, int &iSY, int &iSemester);

void Course_Input(Course &course);

void Add_Course_To_Semester(SchoolYear *&schoolyear, int nSY, int iSemester, int n, Course course);

void Add_Students_To_Course(Semester &s, string FileName, bool &tieptuc3);

void View_ClassList(SchoolYear *sy, int nSY);

void View_StudentList_Course(SchoolYear *sy, int nSY);

void View_CourseList(Semester s);

void Update_Course_In4(Semester &s);

void Add_A_Student_To_Course(Semester &s);

void Remove_A_Student_From_Course(Semester &s);

void Delete_A_Course(Semester &s);

void Export_StudentList_Course(SchoolYear *sy, int nSY, string &FileName);

void Import_CourseMark(SchoolYear *&sy, int nSY, string &FileName);

void View_ScoreBoard_Course(SchoolYear *sy, int nSY);

void Update_Student_Result(SchoolYear *sy, int nSY);

void Get_ClassMark(Semester semester, Class &_class);

void View_ClassMark(SchoolYear *sy, int nSY);

void View_Student_CourseList(SchoolYear *sy, int nSY, int iSemester);

void View_StudentMark(SchoolYear *sy, int nSY, int iSemester);