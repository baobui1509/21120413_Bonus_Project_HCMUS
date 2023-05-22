#include "Func.h"

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
}

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

            sy.ClassList[i].nStudent = 0;
            sy.ClassList[i].nMark = 0;
            sy.ClassList[i].StudentList = NULL;
            sy.ClassList[i].MarkBoard = NULL;
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
            classlist[sy.nClass - m + i].nStudent = 0;
            classlist[sy.nClass - m + i].nMark = 0;
            classlist[sy.nClass - m + i].StudentList = NULL;
            classlist[sy.nClass - m + i].MarkBoard = NULL;
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

void Add_Students_Class(SchoolYear &sy, string FileName, bool &tieptuc3)
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "Can not open file (" << FileName << ")" << endl;
        return;
    }

    string classname;
    int xClass;
    bool check1 = false;
    bool huhu = true;
    while (huhu)
    {
        cout << "Enter the name of class to which you want to add students: ";
        getline(cin, classname);
        for (int i = 0; i < sy.nClass; i++)
        {
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
    sy.ClassList[xClass].nStudent = nStudent;
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
            // cout << "No: " << stoi(line.substr(0, x)) << endl;
            string left = line.substr(x + 2, line.length() - x - 2);
            // Student ID
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].StudentID = left.substr(0, x);
            // cout << "StudentID: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // First name
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].FirstName = left.substr(0, x);
            // cout << "FirstName: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Last name
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].LastName = left.substr(0, x);
            // cout << "LastName: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Gender
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].Gender = left.substr(0, x);
            // cout << "Gender: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // Birthday
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].Birthday = left.substr(0, x);
            // cout << "Birthday: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
            // SocialID
            x = left.find(',');
            sy.ClassList[xClass].StudentList[index].SocialID = left.substr(0, x);
            // cout << "SocialID: " << left.substr(0, x) << endl;
            left = left.substr(x + 2, left.length() - x - 2);
        }
        index++;
    }
    finn.close();
    // sy.ClassList[xClass].Students_Added = true;
    // View_StudentList(sy.ClassList[xClass]);
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
    for (int i = 0; i < X.nStudent; i++)
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
}

void Add_Course_To_Semester(Semester &semester, Course course)
{
    // Neu semester chua co course nao
    if (semester.n == 0 && !semester.CourseList)
    {
        semester.n++;
        semester.CourseList = new Course[semester.n];
        semester.CourseList[semester.n - 1] = course;
        cout << "Add Successfully!" << endl;
    }
    // semester da co course
    else
    {
        // Kiem tra courseID co ton tai chua
        for (int i = 0; i < semester.n; i++)
        {
            if (semester.CourseList[i].CourseID == course.CourseID)
            {
                cout << "Course ID already exists!" << endl;
                return;
            }
        }
        // Neu CourseID chua ton tai thi them vao CourseList
        semester.n++;
        Course *temp = new Course[semester.n];
        for (int i = 0; i < semester.n - 1; i++)
        {
            temp[i] = semester.CourseList[i];
        }
        temp[semester.n - 1] = course;
        delete[] semester.CourseList;
        semester.CourseList = new Course[semester.n];
        for (int i = 0; i < semester.n; i++)
        {
            semester.CourseList[i] = temp[i];
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
    int index = -1;
    string line = "";
    while (getline(fin, line))
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
    fin.close();
}