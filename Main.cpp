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
                     << "5. Exit " << endl
                     << "Enter your choice: ";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    cout << "____________________________________Funtions________________________________________" << endl;
                    if (role == 1)
                    {
                        SchoolYear *schoolyear;
                        int nSY = 0;
                        bool tieptuc3 = true;
                        bool haha = false;
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
                                Create_SchoolYear(schoolyear[nSY - 1]);
                                haha = true;
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
                                cout << "______Create several classes for 1st-year students______" << endl;
                                if (!haha)
                                {
                                    cout << "There has been no School Year created yet!" << endl;
                                    break;
                                }
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
                            }
                        }
                    }
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
                    cout << "______Exit______" << endl;
                    tieptuc1 = false;
                    tieptuc2 = false;
                    break;
                }
                default:
                {
                    cout << "Fail Choice" << endl;
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