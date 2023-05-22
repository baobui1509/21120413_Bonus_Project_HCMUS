#include "Func.h"

int main()
{
    User user;
    bool tieptuc1 = true;
    int choice1 = 0;
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
                        SchoolYear *schoolyear;
                        int iSY, iSemester;
                        int nSY = 0;
                        bool tieptuc3 = true;
                        bool haha1 = false, haha2 = false, haha4 = false, haha5 = false;
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
                                 << "10. Add a student to the course" << endl
                                 << "11. Remove a student from the course" << endl
                                 << "12. Delete a course" << endl
                                 << "13. View a list of classes" << endl
                                 << "14. View a list of students in a class" << endl
                                 << "15. View a list of students in a course" << endl
                                 << "16. Export a list of students in a course to a CSV file" << endl
                                 << "17. Import the scoreboard of a course"
                                 << "18. View the scoreboard of a course"
                                 << "19. Update a student's result" << endl
                                 << "20. View the scoreboard of a class, including final marks of all courses in the semester, GPA in this semester, and the overall GPA" << endl
                                 << "21. Turn back" << endl
                                 << "22. Exit" << endl
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
                                cout << "School Year " << schoolyear[nSY - 1].StartYear << "-" << schoolyear[nSY - 1].EndYear << " has been created!" << endl;
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

                                haha2 = true;
                                Create_Classes(schoolyear[nSY - 1]);
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
                                Add_Students_Class(schoolyear[nSY - 1], NameFile, tieptuc3);
                                if (!tieptuc3)
                                {
                                    tieptuc2 = false;
                                    tieptuc1 = false;
                                    break;
                                }
                                cout << "Add Successfully!" << endl;
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
                                Add_Course_To_Semester(schoolyear[nSY - 1].SemesterList[iSemester], course);
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
                                if (!haha5)
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
                            case 14:
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
                            case 21:
                            {
                                tieptuc3 = false;
                                break;
                            }
                            case 22:
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