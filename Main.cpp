#include "Func.h"
// hihi
int main()
{
    User user;
    bool tieptuc1 = true;
    int choice1 = 0;
    SchoolYear *schoolyear;
    bool haha1 = false, haha2 = false, haha3 = false, haha4 = false, haha5 = false, haha15 = false, haha16 = false;
    int iSY, iSemester;
    int nSY = 0;
    while (tieptuc1)
    {
        cout << "______________________MENU_______________________" << endl
             << "1. Login" << endl
             << "2. Exit" << endl
             << "Enter your choice: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            cout << "______Login______" << endl;
            Import_Account("Account.csv", user);
            int index = -1;
            int role = 0;
            role = Login(user, index);
            if (index == -1)
            {
                tieptuc1 = false;
                break;
            }
            bool tieptuc2 = true;
            int choice2 = 0;
            while (tieptuc2)
            {
                cout << "______________________MENU_______________________" << endl
                     << "1. Functions" << endl
                     << "2. View your profile" << endl
                     << "3. Change password" << endl
                     << "4. Log out" << endl
                     << "5. Turn back" << endl
                     << "6. Exit " << endl
                     << "Enter your choice: ";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    cout << "____________________________________Funtions________________________________________" << endl;
                    // Acadamic Staff Member
                    if (role == 1)
                    {
                        bool tieptuc3 = true;
                        int choice3 = 0;
                        while (tieptuc3)
                        {
                            cout << "1. Create a school year" << endl
                                 << "2. Create several classes for 1st-year students" << endl
                                 << "3. Add new 1st year students to 1st-year classes" << endl
                                 << "4. Create a semester" << endl
                                 << "5. Add a course to this semester (A course will be taught in only one session in a week)" << endl
                                 << "6. Upload a CSV file, containing a list of students enrolled in the course" << endl
                                 << "7. View the list of courses" << endl
                                 << "8. Update course information" << endl
                                 << "9. Add a student to the course" << endl
                                 << "10. Remove a student from the course" << endl
                                 << "11. Delete a course" << endl
                                 << "12. View a list of classes" << endl
                                 << "13. View a list of students in a class" << endl
                                 << "14. View a list of students in a course" << endl
                                 << "15. Export a list of students in a course to a CSV file" << endl
                                 << "16. Import the scoreboard of a course" << endl
                                 << "17. View the scoreboard of a course" << endl
                                 << "18. Update a student's result" << endl
                                 << "19. View the scoreboard of a class" << endl
                                 << "20. Turn back" << endl
                                 << "21. Exit" << endl
                                 << "Enter your choice: ";
                            cin >> choice3;
                            switch (choice3)
                            {
                            case 1:
                            {
                                cout << "______Create a school year______" << endl;
                                nSY++;
                                schoolyear = new SchoolYear[nSY];
                                // Nho kiem tra nam hoc moi co trung lap khong?
                                Create_SchoolYear(schoolyear[nSY - 1], tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc1 = false;
                                    tieptuc2 = false;
                                    break;
                                }
                                haha1 = true;
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc1 = false;
                                    tieptuc2 = false;
                                }
                                break;
                            }
                            case 2:
                            {
                                if (!haha1)
                                {
                                    cout << "THERE HAS BEEN NO SCHOOL YEAR CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Create several classes for 1st-year students______" << endl;
                                Create_Classes(schoolyear[nSY - 1]);
                                haha2 = true;
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc1 = false;
                                    tieptuc2 = false;
                                }
                                cout << "Create Successfully!" << endl;
                                break;
                            }
                            case 3:
                            {
                                cout << "______Add new 1st year students to 1st-year classes______" << endl;
                                if (!haha2)
                                {
                                    cout << "THERE HAS NO CLASS CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                string NameFile;
                                cout << "Enter input file name: ";
                                cin.ignore();
                                getline(cin, NameFile);
                                int nClass = schoolyear[nSY - 1].nClass;
                                Add_Students_Class(schoolyear[nSY - 1], nClass, NameFile, tieptuc3);
                                haha3 = true;
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                    break;
                                }
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 4:
                            {
                                if (!haha1)
                                {
                                    cout << "THERE HAS BEEN NO SCHOOL YEAR CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Create a semester______" << endl;
                                // Tao hoc ky
                                // iSY: index cua nam hoc muon them hoc ky
                                // iSemester: index cua hoc ky
                                Create_Semester(schoolyear, nSY, iSY, iSemester);
                                haha4 = true;
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 5:
                            {
                                if (!haha4)
                                {
                                    cout << "YOU HAVE TO CREATE A SEMESTER FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Add a course to this semester (A course will be taught in only one session in a week)______" << endl;
                                cin.ignore();
                                Course course;
                                Course_Input(course);
                                haha5 = true;
                                int n = schoolyear[nSY - 1].SemesterList[iSemester].n;
                                Add_Course_To_Semester(schoolyear, nSY, iSemester, n, course);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 6:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "YOU HAVE TO CREATE A COURSE FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Upload a CSV file, containing a list of students enrolled in the course______" << endl;
                                string FileName;
                                cout << "Enter the name of CSV file: ";
                                cin.ignore();
                                getline(cin, FileName);
                                Add_Students_To_Course(schoolyear[nSY - 1].SemesterList[iSemester], FileName, tieptuc3);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 7:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______View the list of courses______" << endl;
                                View_CourseList(schoolyear[nSY - 1].SemesterList[iSemester]);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 8:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Update course information______" << endl;
                                Update_Course_In4(schoolyear[nSY - 1].SemesterList[iSemester]);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 9:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Add a student to the course______" << endl;
                                Add_A_Student_To_Course(schoolyear[nSY - 1].SemesterList[iSemester]);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 10:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Remove a student from the course______" << endl;
                                Remove_A_Student_From_Course(schoolyear[nSY - 1].SemesterList[iSemester]);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 11:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Delete a course______" << endl;
                                Delete_A_Course(schoolyear[nSY - 1].SemesterList[iSemester]);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 12:
                            {
                                if (!haha2)
                                {
                                    cout << "THERE HAS NO CLASS CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______View a list of classes______" << endl;
                                View_ClassList(schoolyear, nSY);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 13:
                            {
                                if (!haha2)
                                {
                                    cout << "THERE HAS BEEN NO CLASS CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______View a list of students in a class______" << endl;
                                int xClass;
                                // Nhap va kiem tra class name co ton tai khong
                                Enter_And_Check_ClassName(schoolyear[nSY - 1], xClass, tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                    break;
                                }
                                // Neu lop do chua duoc them sinh vien vao
                                if (schoolyear[nSY - 1].ClassList[xClass].StudentList == NULL)
                                {
                                    cout << "THIS CLASS HAS NO STUDENT!" << endl;
                                }
                                else
                                {
                                    View_StudentList(schoolyear[nSY - 1].ClassList[xClass]);
                                }
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 14:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS BEEN NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "_____View a list of students in a course_____" << endl;
                                View_StudentList_Course(schoolyear, nSY);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 15:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS BEEN NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Export a list of students in a course to a CSV file______" << endl;
                                string FileName;
                                Export_StudentList_Course(schoolyear, nSY, FileName);
                                haha15 = true;
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 16:
                            {
                                if (!haha5 || schoolyear[nSY - 1].SemesterList[iSemester].n == 0)
                                {
                                    cout << "THERE HAS BEEN NO COURSE CREATED YET!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                if (!haha15)
                                {
                                    cout << "PLEASE EXPORT A LIST OF STUDENTS IN A COURSE TO A CSV FILE FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Import the scoreboard of a course______" << endl;
                                string FileName;
                                Import_CourseMark(schoolyear, nSY, FileName);
                                haha16 = true;
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 17:
                            {
                                if (!haha16)
                                {
                                    cout << "PLEASE IMPORT THE SCOREBOARD FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______View the scoreboard of a course______" << endl;
                                View_ScoreBoard_Course(schoolyear, nSY);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 18:
                            {
                                if (!haha16)
                                {
                                    cout << "PLEASE IMPORT THE SCOREBOARD FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______Update a student's result______" << endl;
                                Update_Student_Result(schoolyear, nSY);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 19:
                            {
                                if (!haha2)
                                {
                                    cout << "PLEASE CREATE CLASSES FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                if (!haha3)
                                {
                                    cout << "PLEASE ADD STUDENTS TO CLASSES FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                if (!haha16)
                                {
                                    cout << "PLEASE IMPORT THE SCOREBOARD FIRST!" << endl;
                                    TiepTuc(tieptuc3);
                                    if (!tieptuc3)
                                    {
                                        tieptuc2 = false;
                                        tieptuc1 = false;
                                    }
                                    break;
                                }
                                cout << "______View the scoreboard of a class______" << endl;
                                View_ClassMark(schoolyear, nSY);
                                TiepTuc(tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                }
                                break;
                            }
                            case 20:
                            {
                                tieptuc3 = false;
                                break;
                            }
                            case 21:
                            {
                                cout << "______Exist______" << endl;
                                tieptuc1 = tieptuc2 = tieptuc3 = false;
                                break;
                            }
                            default:
                            {
                                cout << "Illegal choice!" << endl;
                                break;
                            }
                            }
                        }
                    }
                    // Student
                    else if (role == 2)
                    {
                    }
                    break;
                }
                case 2:
                {
                    cout << "______View your profile______" << endl;
                    View_Profile(user, role, index);
                    TiepTuc(tieptuc2);
                    if (!tieptuc2)
                    {
                        tieptuc1 = false;
                    }
                    break;
                }
                case 3:
                {
                    cout << "______Change password______" << endl;
                    cin.ignore();
                    Change_Password(user, role, index);
                    TiepTuc(tieptuc2);
                    if (!tieptuc2)
                    {
                        tieptuc1 = false;
                    }
                    break;
                }
                case 4:
                {
                    cout << "______Log out______" << endl;
                    tieptuc2 = false;
                    break;
                }
                case 5:
                {
                    cout << "______Turn back______" << endl;
                    tieptuc2 = false;
                    break;
                }
                case 6:
                {
                    cout << "______Exit______" << endl;
                    tieptuc1 = false;
                    tieptuc2 = false;
                    break;
                }
                default:
                {
                    cout << "Illegal Choice" << endl;
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            cout << "______Exit______" << endl;
            tieptuc1 = false;
            break;
        }
        default:
        {
            cout << "Please enter '1' or '2': " << endl;
            break;
        }
        }
    }
    return 0;
}

// 1
// 1
// xyz
// 321
// 1
// 1
// 2022
// 1
// 4
// 1
// 1
// 1
// 5
// COURSE01
// Mang may tinh
// MMT
// Hoang Dung
// Sunday
// 1
// 4
// 50
// 1
