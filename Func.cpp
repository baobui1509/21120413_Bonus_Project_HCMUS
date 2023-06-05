#include "Func.h"

////
void TiepTuc(bool &tieptuc)
{
    bool hihi = true;
    int choice = 0;
    while (hihi)
    {
        std::cout << "    Continue?" << endl
                  << "1. Yes     2. No" << endl
                  << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            hihi = false;
            break;
        }
        case 2:
        {
            hihi = false;
            tieptuc = false;
            break;
        }
        default:
        {
            std::cout << "Illegal chocie!" << endl;
        }
        }
    }
}

// Nhap tai khoan tu file csv
void Import_Account(string Account_File, User &user)
{
    ifstream fin(Account_File);
    if (!fin.is_open())
    {
        std::cout << "Khong the mo file " << Account_File << endl;
        return;
    }
    string line = "";
    string line1 = "";
    string line2 = "";
    string line3 = "";
    string temp = "";
    Account account;
    int n1 = 0;
    int n2 = 0;

    while (getline(fin, line))
    {
        int x = line.find(',');
        line1 = line.substr(0, x);
        if (line1 == "Acadamic Staff Member")
        {
            n1++;
        }
        else if (line1 == "Student")
        {
            n2++;
        }
    }
    fin.close();

    user.Acadamic_Staff_Member = new Account[n1];
    user.Student = new Account[n2];

    n1 = 0;
    n2 = 0;
    ifstream finn(Account_File);
    while (getline(finn, line))
    {
        int x = line.find(',');
        line1 = line.substr(0, x);
        temp = line.substr(x + 2, line.length() - x - 2);
        int y = temp.find(',');
        line2 = temp.substr(0, y);
        line3 = temp.substr(y + 2, temp.length() - y - 2);
        // std::cout << "line: " << line << endl
        //           << "line1: " << line1 << endl
        //           << "temp: " << temp << endl
        //           << "line2: " << line2 << endl
        //           << "line3: " << line3 << endl;
        account.UserName = line2;
        account.Password = line3;
        if (line1 == "Acadamic Staff Member")
        {
            bool check = true;
            // Kiem tra UserName co ton tai hay chua?
            for (int i = 0; i < n1; i++)
            {
                if (user.Acadamic_Staff_Member[i].UserName == line2)
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                n1++;
                user.Acadamic_Staff_Member[n1 - 1] = account;
                // std::cout << "UserName: " << user.Acadamic_Staff_Member[n1 - 1].UserName << endl
                //           << "Password: " << user.Acadamic_Staff_Member[n1 - 1].Password << endl;
            }
        }
        else if (line1 == "Student")
        {
            bool check = true;
            // Kiem tra UserName da ton tai chua?
            for (int i = 0; i < n2; i++)
            {
                if (user.Student[i].UserName == line2)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                n2++;
                user.Student[n2 - 1] = account;
                // std::cout << "UserName: " << user.Student[n2 - 1].UserName << endl
                //           << "Password: " << user.Student[n2 - 1].Password << endl;
            }
        }
    }
    user.n1 = n1;
    user.n2 = n2;
    finn.close();
}

int Login(User user, int &index)
{
    bool hihi = true;
    int choice = 0;
    while (hihi)
    {
        cout << "Who are you?" << endl
             << "1. Acadamic Staff Member" << endl
             << "2. Student" << endl
             << "Enter your choice: ";
        cin >> choice;
        string username, password;
        bool check = false;
        switch (choice)
        {
        case 1:
        {
            bool success = true;
            while (success)
            {
                cout << "Enter UserName: ";
                cin.ignore();
                getline(cin, username);
                cout << "Enter Password: ";
                getline(cin, password);
                for (int i = 0; i < user.n1; i++)
                {
                    if (user.Acadamic_Staff_Member[i].UserName == username && user.Acadamic_Staff_Member[i].Password == password)
                    {
                        index = i;
                        check = true;
                        break;
                    }
                }
                if (check)
                {
                    cout << "Login Successfully!" << endl;
                    success = false;
                    hihi = false;
                }
                else
                {
                    cout << "Login Failed!" << endl;
                    TiepTuc(success);
                    if (!success)
                    {
                        hihi = false;
                    }
                    // else
                    // {
                    //     success = false;
                    // }
                }
            }
            break;
        }
        case 2:
        {
            bool success = true;
            while (success)
            {
                cout << "Enter UserName: ";
                cin.ignore();
                getline(cin, username);
                cout << "Enter Password: ";
                getline(cin, password);
                for (int i = 0; i < user.n1; i++)
                {
                    if (user.Student[i].UserName == username && user.Student[i].Password == password)
                    {
                        index = i;
                        check = true;
                        break;
                    }
                }
                if (check)
                {
                    cout << "Login Successfully!" << endl;
                    success = false;
                    hihi = false;
                }
                else
                {
                    cout << "Login Failed!" << endl;
                    TiepTuc(success);
                    if (!success)
                    {
                        hihi = false;
                    }
                }
            }
            break;
        }
        default:
        {
            cout << "Please enter '1' or '2': " << endl;
            break;
        }
        }
    }
    return choice;
}

// Chu y kiem tra xem co dang nhap chua
void View_Profile(User user, int role, int index)
{
    if (role == 1)
    {
        cout << "Role: Acadamic Staff Member" << endl
             << "UserName: " << user.Acadamic_Staff_Member[index].UserName << endl
             << "Password: " << user.Acadamic_Staff_Member[index].Password << endl;
    }
    else if (role == 2)
    {
        cout << "Role: Student" << endl
             << "UserName: " << user.Student[index].UserName << endl
             << "Password: " << user.Student[index].Password << endl;
    }
}

void Change_Password(User &user, int role, int index)
{
    string pw;
    cout << "Enter new Password: ";
    getline(cin, pw);
    if (role == 1)
    {
        while (pw == user.Acadamic_Staff_Member[index].Password)
        {
            cout << "The new password is the same as the old one" << endl
                 << "Enter new Password: ";
            getline(cin, pw);
        }
        user.Acadamic_Staff_Member[index].Password = pw;
    }
    else if (role == 2)
    {
        while (pw == user.Student[index].Password)
        {
            cout << "The new password is the same as the old one" << endl
                 << "Enter new Password: ";
            getline(cin, pw);
        }
        user.Student[index].Password = pw;
    }
    string temp = "";
    for (int i = 0; i < user.n1; i++)
    {
        temp += "Acadamic Staff Member, ";
        temp += user.Acadamic_Staff_Member[i].UserName;
        temp += ", ";
        temp += user.Acadamic_Staff_Member[i].Password;
        temp += '\n';
    }
    for (int i = 0; i < user.n2; i++)
    {
        temp += "Student, ";
        temp += user.Student[i].UserName;
        temp += ", ";
        temp += user.Student[i].Password;
        temp += '\n';
    }
    // cout << temp;
    ofstream fout("Account.csv");
    if (!fout.is_open())
    {
        cout << "Can't open Account file!" << endl;
        return;
    }
    fout << temp;
    fout.close();
    cout << "Change Successfully!" << endl;
}

void Create_SchoolYear(SchoolYear &schoolyear, bool &tieptuc3)
{
    cout << "Enter start year: ";
    cin >> schoolyear.StartYear;
    while (schoolyear.StartYear <= 0)
    {
        cout << "Please enter an integer number bigger than 0: ";
        cin >> schoolyear.StartYear;
    }
    schoolyear.EndYear = schoolyear.StartYear + 1;
    schoolyear.nSemester = 3;
    schoolyear.SemesterList = new Semester[schoolyear.nSemester];
    if (!schoolyear.SemesterList)
    {
        cout << "OVERFLOW!" << endl;
        tieptuc3 = false;
        return;
    }
    schoolyear.nClass = 0;
    schoolyear.ClassList = NULL;
    for (int i = 0; i < 3; i++)
    {
        schoolyear.SemesterList[i].Check = false;
    }
    cout << "School Year " << schoolyear.StartYear << "-" << schoolyear.EndYear << " has been created!" << endl;
}

// void Create_SchoolYear(SchoolYear *&schoolyear, int &nSY, bool &tieptuc3)
// {
//     nSY++;
//     SchoolYear sy;
//     cout << "Enter start year: ";
//     cin >> sy.StartYear;
//     while (sy.StartYear <= 0)
//     {
//         cout << "Please enter an integer number bigger than 0: ";
//         cin >> sy.StartYear;
//     }
//     sy.EndYear = sy.StartYear + 1;
//     sy.nSemester = 3;
//     sy.SemesterList = new Semester[sy.nSemester];
//     if (!sy.SemesterList)
//     {
//         cout << "OVERFLOW!" << endl;
//         tieptuc3 = false;
//         return;
//     }
//     sy.nClass = 0;
//     sy.ClassList = NULL;
//     for (int i = 0; i < 3; i++)
//     {
//         sy.SemesterList[i].Check = false;
//     }
//     // Neu day la nam hoc dau tien duoc tao
//     if (nSY == 1)
//     {
//         schoolyear[nSY - 1] = sy;
//     }
//     else
//     {
//         bool huhu = true;
//         while (huhu)
//         {
//             for (int i = 0; i < nSY - 1; i++)
//             {
//                 if (schoolyear[i].StartYear == sy.StartYear)
//                 {
//                     cout << "School year exists!" << endl
//                          << "Plase enter another Start Year: ";
//                     cin >> sy.StartYear;
//                     while (sy.StartYear <= 0)
//                     {
//                         cout << "Please enter an integer number bigger than 0: ";
//                         cin >> sy.StartYear;
//                     }

//                     break;
//                 }
//                 if (i == nSY - 2)
//                 {
//                     sy.EndYear = sy.StartYear + 1;
//                     sy.nSemester = 3;
//                     sy.SemesterList = new Semester[sy.nSemester];
//                     if (!sy.SemesterList)
//                     {
//                         cout << "OVERFLOW!" << endl;
//                         tieptuc3 = false;
//                         return;
//                     }
//                     sy.nClass = 0;
//                     sy.ClassList = NULL;
//                     for (int i = 0; i < 3; i++)
//                     {
//                         sy.SemesterList[i].Check = false;
//                     }
//                     huhu = false;
//                 }
//             }
//         }
//         SchoolYear *temp = new SchoolYear[nSY];
//         if (!temp)
//         {
//             cout << "OVERFLOW" << endl;
//             tieptuc3 = false;
//             return;
//         }
//         for (int i = 0; i < nSY - 1; i++)
//         {
//             temp[i] = schoolyear[i];
//         }
//         temp[nSY - 1] = sy;

//         // delete[] schoolyear;
//         schoolyear = new SchoolYear[nSY];
//         for (int i = 0; i < nSY; i++)
//         {
//             schoolyear[i] = temp[i];
//         }
//         delete[] temp;
//     }
//     cout << "School Year " << schoolyear[nSY - 1].StartYear << "-" << schoolyear[nSY - 1].EndYear << " has been created!" << endl;
// }

// Chu y
void Create_Classes(SchoolYear &sy)
{
    int m;
    cout << "Enter the number of class: ";
    cin >> m;
    while (m <= 0)
    {
        cout << "Please enter an integer number bigger than 0: ";
        cin >> m;
    }
    sy.nClass += m;
    // Neu truoc do chua co lop nao duoc tao
    if (sy.nClass == m)
    {
        sy.ClassList = new Class[sy.nClass];
        cin.ignore();
        for (int i = 0; i < sy.nClass; i++)
        {
            cout << "Enter the name of class " << i + 1 << ": ";
            // Nhap ten khong duoc trung
            getline(cin, sy.ClassList[i].ClassName);
            bool huhu = true;
            while (huhu)
            {
                int j = 0;
                while (j < i)
                {
                    if (sy.ClassList[i].ClassName == sy.ClassList[j].ClassName)
                    {
                        cout << "Class Name already exists!" << endl
                             << "Enter another name: ";
                        getline(cin, sy.ClassList[i].ClassName);
                        break;
                    }
                    j++;
                }
                if (j == i)
                {
                    huhu = false;
                }
            }

            sy.ClassList[i].n = 0;
            sy.ClassList[i].StudentList = NULL;
            sy.ClassList[i].MarkBoard.Marks = NULL;
        }
    }
    else
    {
        string name = "";
        Class *classlist = new Class[sy.nClass];
        for (int i = 0; i < sy.nClass - m; i++)
        {
            classlist[i] = sy.ClassList[i];
        }
        cin.ignore();
        for (int i = 0; i < m; i++)
        {
            cout << "Enter the name of class " << i + 1 << ": ";
            getline(cin, classlist[sy.nClass - m + i].ClassName);
            bool huhu = true;
            while (huhu)
            {
                int j = 0;
                while (j < sy.nClass - m + i)
                {
                    if (classlist[sy.nClass - m + i].ClassName == classlist[j].ClassName)
                    {
                        cout << "Class Name already exists!" << endl
                             << "Enter another name: ";
                        getline(cin, classlist[sy.nClass - m + i].ClassName);
                        break;
                    }
                    j++;
                }
                if (j == sy.nClass - m + i)
                {
                    huhu = false;
                }
            }

            classlist[sy.nClass - m + i].n = 0;
            classlist[sy.nClass - m + i].StudentList = NULL;
            classlist[sy.nClass - m + i].MarkBoard.Marks = NULL;
        }
        delete[] sy.ClassList;
        sy.ClassList = new Class[sy.nClass];
        for (int i = 0; i < sy.nClass; i++)
        {
            sy.ClassList[i] = classlist[i];
        }
        delete[] classlist;
    }
}

void Add_Students_Class(SchoolYear &sy, int nClass, string FileName, bool &tieptuc3)
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "Can not open file (" << FileName << ")" << endl;
        return;
    }
    sy.nClass = nClass;
    string classname;
    int xClass;
    bool check1 = false;
    bool huhu = true;
    // Kiem tra ten Class co ton tai hay khong
    while (huhu)
    {
        cout << "Enter the name of class to which you want to add students: ";
        getline(cin, classname);
        for (int i = 0; i < sy.nClass; i++)
        {
            // cout << "i: " << i << endl;
            if (sy.ClassList[i].ClassName == classname)
            {
                check1 = true;
                xClass = i;
                break;
            }
        }
        if (!check1)
        {
            cout << "The Class Name does not exist!" << endl;
            TiepTuc(huhu);
            if (!huhu)
            {
                tieptuc3 = false;
                return;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            huhu = false;
        }
    }

    int nStudent = 0;
    string line = "";
    int index = -1;
    while (getline(fin, line))
    {
        nStudent++;
    }
    nStudent--;
    sy.ClassList[xClass].n = nStudent;
    fin.close();
    sy.ClassList[xClass].StudentList = new Student[nStudent];
    ifstream finn(FileName);
    // No, Student ID, First name, Last name, Gender, Date of Birth, Social ID
    // 1, 00000001, Bui, Bao, Nam, Male, 10/1/2003, S1

    while (getline(finn, line))
    {
        cout << line << endl;
        if (index != -1)
        {
            // No
            int x = line.find(',');
            sy.ClassList[xClass].StudentList[index].No = stoi(line.substr(0, x));
            string left = line.substr(x + 2, line.length() - x - 2);
            // Student ID
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].StudentID = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // First name
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].FirstName = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // Last name
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].LastName = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // Gender
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].Gender = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // Birthday
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].Birthday = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // SocialID
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].SocialID = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
        }
        index++;
    }
    finn.close();
    cout << "Add Successfully!" << endl;
}

void View_StudentList(Class X)
{
    // No, Student ID, First name, Last name, Gender, Date of Birth, Social ID
    cout << "No"
         << "\t"
         << "\t"
         << "Student ID"
         << "\t"
         << "\t"
         << " First name "
         << "\t"
         << "\t"
         << " Last Name "
         << "\t"
         << "\t"
         << "Gender"
         << "\t "
         << "\t "
         << "Date of Birth "
         << "\t"
         << "\t"
         << "Social ID" << endl;
    for (int i = 0; i < X.n; i++)
    {
        cout << X.StudentList[i].No << "\t"
             << "\t" << X.StudentList[i].StudentID << "\t"
             << "\t" << X.StudentList[i].FirstName << "\t"
             << "\t" << X.StudentList[i].LastName << "\t"
             << "\t" << X.StudentList[i].Gender << "\t"
             << "\t" << X.StudentList[i].Birthday << "\t"
             << "\t" << X.StudentList[i].SocialID << endl;
    }
}

void Enter_And_Check_ClassName(SchoolYear &schoolyear, int &xClass, bool &tieptuc3)
{
    string name;
    bool huhu = true;
    bool check1 = false;
    cin.ignore();
    while (huhu)
    {
        cout << "Enter the name of class: ";
        getline(cin, name);
        for (int i = 0; i < schoolyear.nClass; i++)
        {
            if (schoolyear.ClassList[i].ClassName == name)
            {
                check1 = true;
                xClass = i;
                break;
            }
        }
        if (!check1)
        {
            cout << "Class name does not exist!" << endl;
            TiepTuc(huhu);
            if (!huhu)
            {
                tieptuc3 = false;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            huhu = false;
        }
    }
}

void Create_Semester(SchoolYear *&sy, int nSY, int &iSY, int &iSemester)
{
    int x, y;
    bool huhu = true;
    cout << "Which Semester do you want to create?" << endl
         << "1. Semester 1          2. Semester 2             3. Semester 3" << endl
         << "Enter your choice: ";
    cin >> x;
    while (x < 1 || x > 3)
    {
        cout << "Enter a number in [1, 3]: ";
        cin >> x;
    }
    while (huhu)
    {
        cout << "Which School Year do you want to add this Semester in: " << endl;
        for (int i = 0; i < nSY; i++)
        {
            cout << i + 1 << ". School Year " << sy[i].StartYear << "-" << sy[i].EndYear << "\t";
        }
        cout << endl
             << "Enter your choice: ";
        cin >> y;
        while (y < 1 || y > nSY)
        {
            cout << "Enter a number in [1, " << nSY << "]: ";
            cin >> y;
        }
        // Neu nam hoc nay da co hoc ky can tao
        if (sy[y - 1].SemesterList[x - 1].Check)
        {
            bool k = true;
            int replace;
            while (k)
            {
                cout << "This School Year has been having the Semester " << y << endl
                     << "Do you want to replace?" << endl
                     << "1. Yes        2. No" << endl;
                cin >> replace;
                switch (replace)
                {
                case 1:
                {
                    iSY = y - 1;
                    iSemester = x - 1;
                    k = false;
                    huhu = false;
                    break;
                }
                case 2:
                {
                    bool kk = true;
                    int p;
                    while (kk)
                    {
                        cout << "Do you want to choose another School Year?" << endl
                             << "1. Yes                2. No" << endl
                             << "Enter your choice: ";
                        cin >> p;
                        switch (p)
                        {
                        case 1:
                        {
                            kk = false;
                            k = false;
                            cout << "Create Successfully!" << endl;
                            break;
                        }
                        case 2:
                        {
                            k = kk = huhu = false;
                            break;
                        }
                        default:
                        {
                            cout << "Illegal choice!" << endl;
                            break;
                        }
                        }
                    }
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
        else
        {
            huhu = false;
            sy[y - 1].SemesterList[x - 1].Check = true;
            sy[y - 1].SemesterList[x - 1].CourseList = NULL;
            sy[y - 1].SemesterList[x - 1].n = 0;
            iSY = y - 1;
            iSemester = x - 1;
            cout << "Create Successfully!" << endl;
        }
    }
}

void Course_Input(Course &course)
{
    // string CourseID, CourseName, ClassName, TeacherName, DayOfWeek, Session;
    // int NumberOfCredits, MaxNumberStudent;
    cout << "Enter course ID: ";
    getline(cin, course.CourseID);
    cout << "Enter Course name: ";
    getline(cin, course.CourseName);
    cout << "Enter class name: ";
    getline(cin, course.ClassName);
    cout << "Enter teacher name: ";
    getline(cin, course.TeacherName);
    cout << "Enter day of the week: ";
    getline(cin, course.DayOfWeek);
    cout << "Enter the session: ";
    cin >> course.Session;
    cout << "Enter number of credits: ";
    cin >> course.NumberOfCredits;
    cout << "Enter the maximum number of students: ";
    cin >> course.MaxNumberStudent;
    course.n = 0;
    course.StudentList = NULL;
    course.MarkBoard = NULL;
    course.Export = false;
    course.Publish = false;
}

void Add_Course_To_Semester(SchoolYear *&schoolyear, int nSY, int iSemester, int n, Course course)
{
    if (n == 0)
    {
        schoolyear[nSY - 1].SemesterList[iSemester].CourseList = NULL;
    }
    schoolyear[nSY - 1].SemesterList[iSemester].n = n;

    // Neu semester chua co course nao
    if (schoolyear[nSY - 1].SemesterList[iSemester].n == 0 && !schoolyear[nSY - 1].SemesterList[iSemester].CourseList)
    {
        schoolyear[nSY - 1].SemesterList[iSemester].n++;
        schoolyear[nSY - 1].SemesterList[iSemester].CourseList = new Course[schoolyear[nSY - 1].SemesterList[iSemester].n];
        schoolyear[nSY - 1].SemesterList[iSemester].CourseList[schoolyear[nSY - 1].SemesterList[iSemester].n - 1] = course;
        cout << "Add Successfully!" << endl;
    }
    // schoolyear[nSY-1].SemesterList[iSemester] da co course
    else
    {
        // Kiem tra courseID co ton tai chua
        for (int i = 0; i < schoolyear[nSY - 1].SemesterList[iSemester].n; i++)
        {
            if (schoolyear[nSY - 1].SemesterList[iSemester].CourseList[i].CourseID == course.CourseID)
            {
                cout << "Course ID already exists!" << endl;
                return;
            }
        }
        // Neu CourseID chua ton tai thi them vao CourseList
        schoolyear[nSY - 1].SemesterList[iSemester].n++;
        Course *temp = new Course[schoolyear[nSY - 1].SemesterList[iSemester].n];
        for (int i = 0; i < schoolyear[nSY - 1].SemesterList[iSemester].n - 1; i++)
        {
            temp[i] = schoolyear[nSY - 1].SemesterList[iSemester].CourseList[i];
        }
        temp[schoolyear[nSY - 1].SemesterList[iSemester].n - 1] = course;
        delete[] schoolyear[nSY - 1].SemesterList[iSemester].CourseList;
        schoolyear[nSY - 1].SemesterList[iSemester].CourseList = new Course[schoolyear[nSY - 1].SemesterList[iSemester].n];
        for (int i = 0; i < schoolyear[nSY - 1].SemesterList[iSemester].n; i++)
        {
            schoolyear[nSY - 1].SemesterList[iSemester].CourseList[i] = temp[i];
        }
        cout << "Add Successfully!" << endl;
    }
}

void Add_Students_To_Course(Semester &s, string FileName, bool &tieptuc3)
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "Can not open file " << FileName << endl;
        return;
    }
    string courseID;
    int xCourse;
    bool check1 = false;
    bool huhu = true;
    while (huhu)
    {
        cout << "Enter the course ID to which you want to add students: ";
        getline(cin, courseID);
        for (int i = 0; i < s.n; i++)
        {
            if (s.CourseList[i].CourseID == courseID)
            {
                check1 = true;
                xCourse = i;
                break;
            }
        }
        if (!check1)
        {
            cout << "The CourseID does not exist!" << endl;
            TiepTuc(huhu);
            if (!huhu)
            {
                tieptuc3 = false;
                return;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            huhu = false;
        }
    }

    // Dem so luong hoc sinh co trong file CSV
    string line = "";
    int n = 0;
    if (!fin.is_open())
    {
        cout << "Can not open file " << FileName << endl;
        return;
    }
    while (getline(fin, line))
    {
        n++;
    }
    fin.close();
    n--;
    s.CourseList[xCourse].n = n;
    s.CourseList[xCourse].StudentList = new Student[n];
    if (!s.CourseList[xCourse].StudentList)
    {
        cout << "OVERFLOW!" << endl;
        return;
    }

    // Doc va luu thong tin sinh vien vao CourseList
    ifstream finn(FileName);
    int index = -1;
    while (getline(finn, line))
    {
        cout << line << endl;
        if (index != -1)
        {
            // No
            int x = line.find(',');
            s.CourseList[xCourse].StudentList[index].No = stoi(line.substr(0, x));
            // cout << "No: " << stoi(line.substr(0, x)) << endl;
            string left = line.substr(x + 2, line.length() - x - 2);
            // Student ID
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].StudentID = left.substr(0, x);
            // cout << "StudentID: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // First name
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].FirstName = left.substr(0, x);
            // cout << "FirstName: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Last name
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].LastName = left.substr(0, x);
            // cout << "LastName: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Gender
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].Gender = left.substr(0, x);
            // cout << "Gender: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Birthday
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].Birthday = left.substr(0, x);
            // cout << "Birthday: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // SocialID
            x = left.find(',');
            s.CourseList[xCourse].StudentList[index].SocialID = left.substr(0, x);
            // cout << "SocialID: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
        }
        index++;
    }
    finn.close();
}

void View_ClassList(SchoolYear *sy, int nSY)
{
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    for (int i = 0; i < sy[choice - 1].nClass; i++)
    {
        cout << i + 1 << ". " << sy[choice - 1].ClassList[i].ClassName << endl;
    }
}

void View_StudentList_Course(SchoolYear *sy, int nSY)
{
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    // iSemester--;
    int h = 0;
    cout << "Which CourseID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].n; i++)
    {
        h++;
        cout << i + 1 << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[i].CourseID << endl;
    }
    int iCourse;
    cout << "Choose CourseID: ";
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > h)
    {
        cout << "Please enter a number in [1, " << h << "]: ";
        cin >> iCourse;
    }
    iCourse--;
    if (sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n == 0)
    {
        cout << "THERE ARE NOT ANY STUDENTS IN THIS COURSE" << endl;
        return;
    }
    cout << "No"
         << "\t"
         << "\t"
         << "Student ID"
         << "\t"
         << "\t"
         << " First name "
         << "\t"
         << "\t"
         << " Last Name "
         << "\t"
         << "\t"
         << "Gender"
         << "\t "
         << "\t "
         << "Date of Birth "
         << "\t"
         << "\t"
         << "Social ID" << endl;
    // cout << "n:" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n; i++)
    {
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].No << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].StudentID << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].FirstName << "\t"
             << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].LastName << "\t"
             << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].Gender
             << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].Birthday << "\t"
             << "\t" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].SocialID << endl;
    }
}

void View_CourseList(Semester s)
{
    // string CourseID, CourseName, ClassName, TeacherName, DayOfWeek;
    // int NumberOfCredits, MaxNumberStudent, Session;
    // COURSE01
    // Mang may tinh
    // MMT
    // Hoang Dung
    // Sunday
    // 1
    // 4
    // 50

    cout << "CourseID"
         << "\t"
         << "Course Name"
         << "\t"
         << "Class Name"
         << "\t"
         << "Teacher Name"
         << "\t"
         << "Day Of The Week"
         << "      "
         << "Number Of Credits"
         << "      "
         << "Maximum number of Students"
         << "      "
         << "Session" << endl;
    for (int i = 0; i < s.n; i++)
    {
        cout << s.CourseList[i].CourseID << "\t" << s.CourseList[i].CourseName << "\t" << s.CourseList[i].ClassName << "\t"
             << "\t" << s.CourseList[i].TeacherName << "\t" << s.CourseList[i].DayOfWeek << "\t"
             << "\t"
             << "\t" << s.CourseList[i].NumberOfCredits << "\t"
             << "\t"
             << "\t" << s.CourseList[i].MaxNumberStudent << "\t"
             << "\t"
             << "\t"
             << "\t" << s.CourseList[i].Session << endl;
    }
}

void Update_Course_In4(Semester &s)
{
    cout << "Which Course ID?" << endl;
    for (int i = 0; i < s.n; i++)
    {
        cout << i + 1 << ". " << s.CourseList[i].CourseID << endl;
    }
    cout << "Choose course ID: ";
    int iCourse;
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > s.n)
    {
        cout << "Please enter a number in [1, " << s.n << "]: ";
        cin >> iCourse;
    }
    cin.ignore();
    cout << "Enter new information: " << endl;
    cout << "Course ID: ";
    getline(cin, s.CourseList[iCourse].CourseID);
    cout << "Course Name: ";
    getline(cin, s.CourseList[iCourse].CourseName);
    cout << "Class Name: ";
    getline(cin, s.CourseList[iCourse].ClassName);
    cout << "Teacher Name: ";
    getline(cin, s.CourseList[iCourse].TeacherName);
    cout << "Day of the week: ";
    getline(cin, s.CourseList[iCourse].DayOfWeek);
    cout << "Number of credits: ";
    cin >> s.CourseList[iCourse].NumberOfCredits;
    cout << "Maximun number of students: ";
    cin >> s.CourseList[iCourse].MaxNumberStudent;
    cout << "Session: ";
    cin >> s.CourseList[iCourse].Session;
    cout << "Update Successfully!" << endl;
}

void Add_A_Student_To_Course(Semester &s)
{
    // Chon khoa hoc de them sinh vien
    cout << "Which course?" << endl;
    for (int i = 0; i < s.n; i++)
    {
        cout << i + 1 << ". " << s.CourseList[i].CourseID << endl;
    }
    cout << "Choose course ID: ";
    int iCourse;
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > s.n)
    {
        cout << "Please enter a number in [1, " << s.n << "]: ";
        cin >> iCourse;
    }
    iCourse--;
    // Nhap thong tin sinh vien can them
    // int No;
    // string StudentID;
    // string FirstName;
    // string LastName;
    // string Gender;
    // string Birthday;
    // string SocialID;
    Student student;
    cin.ignore();
    cout << "Enter information of student: " << endl;
    student.No = s.CourseList[iCourse].n + 1;
    cout << "Student ID: ";
    getline(cin, student.StudentID);
    cout << "First Name: ";
    getline(cin, student.FirstName);
    cout << "Last Name: ";
    getline(cin, student.LastName);
    cout << "Gender: ";
    getline(cin, student.Gender);
    cout << "Birthday: ";
    getline(cin, student.Birthday);
    cout << "Social ID: ";
    getline(cin, student.SocialID);

    s.CourseList[iCourse].n++;
    Student *StudentList = new Student[s.CourseList[iCourse].n];
    StudentList[s.CourseList[iCourse].n - 1] = student;
    for (int i = 0; i < s.CourseList[iCourse].n - 1; i++)
    {
        StudentList[i] = s.CourseList[iCourse].StudentList[i];
    }

    s.CourseList[iCourse].StudentList = new Student[s.CourseList[iCourse].n];
    for (int i = 0; i < s.CourseList[iCourse].n; i++)
    {
        s.CourseList[iCourse].StudentList[i] = StudentList[i];
    }
    delete[] StudentList;
    cout << "Add Successfully!" << endl;
}

void Remove_A_Student_From_Course(Semester &s)
{
    cout << "Which course?" << endl;
    for (int i = 0; i < s.n; i++)
    {
        cout << i + 1 << ". " << s.CourseList[i].CourseID << endl;
    }
    cout << "Choose course ID: ";
    int iCourse;
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > s.n)
    {
        cout << "Please enter a number in [1, " << s.n << "]: ";
        cin >> iCourse;
    }
    iCourse--;

    cout << "Enter Student ID: ";
    string studentID;
    cin.ignore();
    getline(cin, studentID);
    int iStudent;
    for (int i = 0; i < s.CourseList[iCourse].n; i++)
    {
        if (s.CourseList[iCourse].StudentList[i].StudentID == studentID)
        {
            iStudent = i;
            break;
        }
        if (i == s.CourseList[iCourse].n - 1)
        {
            cout << "StudentID does not exist!" << endl;
            return;
        }
    }
    for (int i = iStudent; i < s.CourseList[iCourse].n - 1; i++)
    {
        s.CourseList[iCourse].StudentList[i] = s.CourseList[iCourse].StudentList[i + 1];
    }
    s.CourseList[iCourse].n--;
    cout << "Remove Successfully!" << endl;
}

void Delete_A_Course(Semester &s)
{
    cout << "Which course?" << endl;
    for (int i = 0; i < s.n; i++)
    {
        cout << i + 1 << ". " << s.CourseList[i].CourseID << endl;
    }
    cout << "Choose course ID: ";
    int iCourse;
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > s.n)
    {
        cout << "Please enter a number in [1, " << s.n << "]: ";
        cin >> iCourse;
    }
    iCourse--;
    for (int i = iCourse; i < s.n - 1; i++)
    {
        s.CourseList[i] = s.CourseList[i + 1];
    }
    s.n--;
    cout << "Delete SUccessfully!" << endl;
}

void Export_StudentList_Course(SchoolYear *sy, int nSY, string &FileName)
{
    // Nhap course muon export
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    int h = 0;
    cout << "Which CourseID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].n; i++)
    {
        h++;
        cout << i + 1 << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[i].CourseID << endl;
    }
    int iCourse;
    cout << "Choose CourseID: ";
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > h)
    {
        cout << "Please enter a number in [1, " << h << "]: ";
        cin >> iCourse;
    }
    iCourse--;
    if (sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n == 0)
    {
        cout << "THERE ARE NOT ANY STUDENTS IN THIS COURSE" << endl;
        return;
    }

    // Export
    cout << "Enter name of file to which you want to export: ";
    cin.ignore();
    getline(cin, FileName);
    ofstream fout(FileName);
    if (!fout.is_open())
    {
        cout << "Can not open file " << FileName << "!" << endl;
        return;
    }

    fout << "No, Student ID, First Name, Last Name, Gender, Date of Birth, Social ID"
         << "\n";
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n; i++)
    {
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].No << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].StudentID << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].FirstName << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].LastName << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].Gender << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].Birthday << ", ";
        fout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].StudentList[i].SocialID;
        if (i != sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n - 1)
        {
            fout << "\n";
        }
    }
    fout.close();
    sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].Export = true;
    cout << "Export Successfully!" << endl;
}

void Import_CourseMark(SchoolYear *&sy, int nSY, string &FileName)
{
    // Nhap course muon import diem
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    int h = 0;
    cout << "Which CourseID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].n; i++)
    {
        h++;
        cout << i + 1 << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[i].CourseID << endl;
    }
    int iCourse;
    cout << "Choose CourseID: ";
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > h)
    {
        cout << "Please enter a number in [1, " << h << "]: ";
        cin >> iCourse;
    }
    iCourse--;

    // Ney ASM chua export StudentList
    if (sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].Export != true)
    {
        cout << "Please export a list of students in a course to a CSV file FIRST!" << endl;
        return;
    }

    cout << "Enter name of file from which you want to import: ";
    cin.ignore();
    getline(cin, FileName);
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "Can not open file " << FileName << "!" << endl;
        return;
    }
    string line = "";
    string left = "";
    int i = -1;
    sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard = new CourseMark[sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n];
    while (getline(fin, line))
    {
        cout << line << endl;
        if (i != -1)
        {
            // No, StudentID, StudentFullName, MidtermMark, FinalMark, TotalMark, OtherMark
            //  1, 00000001, Bao Bui, 10, 10, 20, 10
            // No
            int x = line.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].No = stoi(line.substr(0, x));
            left = line.substr(x + 2, line.length() - x - 2);
            // StudentID
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentID = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // StudentFullName
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentFullName = left.substr(0, x);
            left = left.substr(x + 2, left.length() - x - 2);
            // MidtermMark
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].MidtermMark = stoi(left.substr(0, x));
            left = left.substr(x + 2, left.length() - x - 2);
            // FinalMark
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].FinalMark = stoi(left.substr(0, x));
            left = left.substr(x + 2, left.length() - x - 2);
            // TotalMark
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].TotalMark = stoi(left.substr(0, x));
            left = left.substr(x + 2, left.length() - x - 2);
            // OtherMark
            x = left.find(',');
            sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].OtherMark = stoi(left.substr(0, x));
            left = left.substr(x + 2, left.length() - x - 2);
        }
        i++;
    }
    sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].Publish = true;
    fin.close();
    cout << "Import Seccessfully!" << endl;
}

void View_ScoreBoard_Course(SchoolYear *sy, int nSY)
{
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    int h = 0;
    cout << "Which CourseID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].n; i++)
    {
        h++;
        cout << i + 1 << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[i].CourseID << endl;
    }
    int iCourse;
    cout << "Choose CourseID: ";
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > h)
    {
        cout << "Please enter a number in [1, " << h << "]: ";
        cin >> iCourse;
    }
    iCourse--;

    // Neu course nay chua co bang diem
    if (!sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard)
    {
        cout << "This course has not imported scoreboard yet!" << endl;
        return;
    }

    // int No;
    // string StudentID, StudentFullName;
    // float MidtermMark, FinalMark, TotalMark, OtherMark;

    cout << "No"
         << "\t"
         << "Student ID"
         << "\t"
         << "Student Full Name"
         << "\t"
         << "Midterm Mark"
         << "\t"
         << "Final Mark"
         << "\t"
         << "Total Mark"
         << "\t"
         << "Other Mark" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n; i++)
    {
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].No << "\t";
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentID << "\t";
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentFullName << "\t"
             << "\t";
        if (i == 0)
        {
            cout << "\t";
        }
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].MidtermMark << "\t"
             << "\t";
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].FinalMark << "\t"
             << "\t";
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].TotalMark << "\t"
             << "\t";
        cout << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].OtherMark << endl;
    }
}

void Update_Student_Result(SchoolYear *sy, int nSY)
{
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    int h = 0;
    cout << "Which CourseID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].n; i++)
    {
        h++;
        cout << i + 1 << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[i].CourseID << endl;
    }
    int iCourse;
    cout << "Choose CourseID: ";
    cin >> iCourse;
    while (iCourse <= 0 || iCourse > h)
    {
        cout << "Please enter a number in [1, " << h << "]: ";
        cin >> iCourse;
    }
    iCourse--;

    // Neu course nay chua co bang diem
    if (!sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard)
    {
        cout << "This course has not imported scoreboard yet!" << endl;
        return;
    }

    cout << "Which Student ID?" << endl;
    for (int i = 0; i < sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n; i++)
    {
        cout << i + 1
             << ". " << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentID << " (" << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[i].StudentFullName << ")" << endl;
    }
    cout << "Choose Student ID: ";
    int u;
    cin >> u;
    while (u <= 0 || u > sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n)
    {
        cout << "Please enter a number in [1, " << sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].n << "]: ";
        cin >> u;
    }
    u--;
    cout << "Enter new result:" << endl
         << "Midterm Mark: ";
    cin >> sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[u].MidtermMark;
    cout << "Final Mark: ";
    cin >> sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[u].FinalMark;
    cout << "Total Mark: ";
    cin >> sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[u].TotalMark;
    cout << "Other Mark: ";
    cin >> sy[choice - 1].SemesterList[iSemester].CourseList[iCourse].MarkBoard[u].OtherMark;
    cout << "Update Successfully!" << endl;
}

void Get_ClassMark(Semester semester, Class &_class)
{
    // Dem so luong Course ma moi Student tham gia de cap phat cho mang FinalMark
    float *temp;
    _class.MarkBoard.Marks = new Mark[_class.n];
    int nCourse;
    _class.MarkBoard.OverallGPA = 0;
    for (int i = 0; i < _class.n; i++) // Moi hoc sinh trong lop hoc
    {
        nCourse = 0;
        for (int j = 0; j < semester.n; j++) // Moi Course trong Semester
        {
            for (int k = 0; k < semester.CourseList[j].n; k++) // Moi Student trong Course
            {
                if (_class.StudentList[i].StudentID == semester.CourseList[j].StudentList[k].StudentID)
                {
                    nCourse++;
                    // Luu FinalMark vao mang temp
                    if (nCourse == 1)
                    {
                        temp = new float[1];
                        temp[0] = semester.CourseList[j].MarkBoard[k].FinalMark;
                    }
                    else
                    {
                        float *tempp = new float[nCourse];
                        for (int q = 0; q < nCourse - 1; q++)
                        {
                            tempp[q] = temp[q];
                        }
                        tempp[nCourse - 1] = semester.CourseList[j].MarkBoard[k].FinalMark;
                        temp = new float[nCourse];
                        for (int q = 0; q < nCourse; q++)
                        {
                            temp[q] = tempp[q];
                        }
                        delete[] tempp;
                    }
                    break;
                }
            }
        }
        _class.MarkBoard.Marks[i].GPA = 0;
        _class.MarkBoard.Marks[i].nFinalMark = nCourse;
        // FinalMark
        _class.MarkBoard.Marks[i]
            .FinalMark = new float[nCourse];
        for (int q = 0; q < nCourse; q++)
        {
            _class.MarkBoard.Marks[i].FinalMark[q] = temp[q];
            _class.MarkBoard.Marks[i].GPA += temp[q];
        }
        // GPA
        _class.MarkBoard.Marks[i].GPA /= nCourse;
        _class.MarkBoard.OverallGPA += _class.MarkBoard.Marks[i].GPA;
        // Information
        _class.MarkBoard.Marks[i]
            .No = i + 1;
        _class.MarkBoard.Marks[i].StudentID = _class.StudentList[i].StudentID;
        _class.MarkBoard.Marks[i].StudentFullName = _class.StudentList[i].LastName + ' ' + _class.StudentList[i].FirstName;
    }
    // cout << "Overall: " << _class.MarkBoard.OverallGPA << endl
    //      << "_class.n: " << _class.n << endl;
    _class.MarkBoard.OverallGPA /= _class.n;
    delete[] temp;
}

void View_ClassMark(SchoolYear *sy, int nSY)
{
    // Chon Semester
    cout << "Which school year?" << endl;
    for (int i = 0; i < nSY; i++)
    {
        cout << i + 1 << ". " << sy[i].StartYear << "-" << sy[i].EndYear << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice <= 0 || choice > nSY)
    {
        cout << "Please enter a number in [1, " << nSY << "]: ";
    }
    cout << "Which Semester?" << endl;
    int k = 1;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            cout << k << ". Semester " << i + 1 << endl;
            k++;
        }
    }
    cout << "Choose semester: ";
    int iSemester;
    cin >> iSemester;
    while (iSemester <= 0 || iSemester > k)
    {
        cout << "Please enter a number in [1, " << k << "]: ";
        cin >> iSemester;
    }
    k = 0;
    for (int i = 0; i < sy[choice - 1].nSemester; i++)
    {
        if (sy[choice - 1].SemesterList[i].Check)
        {
            k++;
            if (k == iSemester)
            {
                iSemester = i;
                break;
            }
        }
    }
    // Chon Class
    cout << "Which Class?" << endl;
    for (int i = 0; i < sy[choice - 1].nClass; i++)
    {
        cout << i + 1 << ". " << sy[choice - 1].ClassList[i].ClassName << endl;
    }
    cout << "Choose Class: ";
    int iClass;
    cin >> iClass;
    while (iClass <= 0 || iClass > sy[choice - 1].nClass)
    {
        cout << "Please enter a number in [1, " << sy[choice - 1].nClass << "]: ";
        cin >> iClass;
    }
    iClass--;
    if (!sy[choice - 1].ClassList[iClass].MarkBoard.Marks) // Neu diem cua Class chua duoc cap nhat thi cap nhat cho no, neu da cap nhat roi thi thoi (tiet kiem bo nho)
    {
        Get_ClassMark(sy[choice - 1].SemesterList[iSemester], sy[choice - 1].ClassList[iClass]);
    }
    // In ra bang diem
    cout << "No"
         << "\t"
         << "Student ID"
         << "\t"
         << "Full Name"
         << "\t"
         << "Final Marks"
         << "\t"
         << "GPA" << endl;
    for (int i = 0; i < sy[choice - 1].ClassList[iClass].n; i++)
    {
        cout << sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].No << "\t";
        cout << sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].StudentID << "\t";
        cout << sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].StudentFullName << "\t";
        if (i == 0)
        {
            cout << "\t";
        }
        for (int j = 0; j < sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].nFinalMark; j++)
        {
            cout << sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].FinalMark[j];
            if (j != sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].nFinalMark - 1)
            {
                cout << ", ";
            }
        }
        cout << "\t"
             << "\t";
        cout << sy[choice - 1].ClassList[iClass].MarkBoard.Marks[i].GPA << endl;
    }
    cout << "Overall GPA: " << sy[choice - 1].ClassList[iClass].MarkBoard.OverallGPA << endl;
}

void View_Student_CourseList(SchoolYear *sy, int nSY, int iSemester)
{
    if (!sy || nSY == 0)
    {
        cout << "THERE ARE NOT ANY SCHOOL YEARS CREATED!" << endl;
        return;
    }
    if (!sy[nSY - 1].SemesterList)
    {
        cout << "THERE ARE NOT ANY SEMESTERS CREATED!" << endl;
        return;
    }
    if (!sy[nSY - 1].SemesterList[iSemester].CourseList)
    {
        cout << "THERE ARE NOT ANY COURSES CREATED!" << endl;
        return;
    }
    cout << "Enter your Student ID: ";
    string studentID = "";
    getline(cin, studentID);
    bool check = false;
    // string CourseID, CourseName, ClassName, TeacherName, DayOfWeek;
    // int NumberOfCredits, MaxNumberStudent, Session;
    for (int i = 0; i < sy[nSY - 1].SemesterList[iSemester].n; i++) // Moi Course
    {
        for (int j = 0; j < sy[nSY - 1].SemesterList[iSemester].CourseList[i].n; j++) // Moi Student
        {
            if (studentID == sy[nSY - 1].SemesterList[iSemester].CourseList[i].StudentList[j].StudentID)
            {
                check = true;
                if (i == 0)
                {
                    cout << "CourseID"
                         << "\t"
                         << "Course Name"
                         << "\t"
                         << "Class Name"
                         << "\t"
                         << "Teacher Name"
                         << "\t"
                         << "Day Of The Week"
                         << "      "
                         << "Number Of Credits"
                         << "      "
                         << "Maximum number of Students"
                         << "      "
                         << "Session" << endl;
                }
                cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].CourseID << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].CourseName << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].ClassName << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].TeacherName << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].DayOfWeek << "\t"
                     << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].NumberOfCredits << "\t"
                     << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].MaxNumberStudent << "\t"
                     << "\t"
                     << "\t"
                     << "\t" << sy[nSY - 1].SemesterList[iSemester].CourseList[i].Session << endl;
                break;
            }
        }
    }
    if (!check)
    {
        cout << "YOU HAVE NOT ENROLLED ANY COURSES YET!" << endl;
    }
}

void View_StudentMark(SchoolYear *sy, int nSY, int iSemester)
{
    if (!sy || nSY == 0)
    {
        cout << "THERE ARE NOT ANY SCHOOL YEARS CREATED!" << endl;
        return;
    }
    if (!sy[nSY - 1].SemesterList)
    {
        cout << "THERE ARE NOT ANY SEMESTERS CREATED!" << endl;
        return;
    }
    if (!sy[nSY - 1].SemesterList[iSemester].CourseList)
    {
        cout << "THERE ARE NOT ANY COURSES CREATED!" << endl;
        return;
    }

    cout << "Enter your Student ID: ";
    string studentID = "";
    getline(cin, studentID);

    bool check1 = false, check2 = false;

    for (int i = 0; i < sy[nSY - 1].SemesterList[iSemester].n; i++) // Moi Course
    {
        if (sy[nSY - 1].SemesterList[iSemester].CourseList[i].Publish)
        {
            check1 = true;
            for (int j = 0; j < sy[nSY - 1].SemesterList[iSemester].CourseList[i].n; j++) // Diem cua moi Student
            {
                if (studentID == sy[nSY - 1].SemesterList[iSemester].CourseList[i].MarkBoard[j].StudentID)
                {
                    if (i == 0)
                    {
                        check2 = true;
                        cout << "Course ID"
                             << "\t"
                             << "Course Name"
                             << "\t"
                             << "Midterm Mark"
                             << "\t"
                             << "Final Mark"
                             << "\t"
                             << "Total Mark"
                             << "\t"
                             << "Other Mark" << endl;
                    }
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].CourseID << "\t"
                         << "\t";
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].CourseName << "\t"
                         << "\t";
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].MarkBoard[j].MidtermMark << "\t"
                         << "\t";
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].MarkBoard[j].FinalMark << "\t"
                         << "\t";
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].MarkBoard[j].TotalMark << "\t"
                         << "\t";
                    cout << sy[nSY - 1].SemesterList[iSemester].CourseList[i].MarkBoard[j].OtherMark << endl;
                    break;
                }
            }
        }
    }
    if (!check1)
    {
        cout << "THERE ARE NOT ANY COURSE SCOREBOARDS PUBLISHED YET!" << endl;
    }
    else
    {
        if (!check2)
        {
            cout << "YOU HAVE NOT ENROLLED ANY COURSES YET!" << endl;
        }
    }
}