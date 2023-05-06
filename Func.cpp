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
            std::cout << "Fail chocie!" << endl;
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
                    else
                    {
                        success = false;
                    }
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
        for (int i = 0; i < user.n1; i++)
        {
            if (i == index)
            {
                cout << "Role: Acadamic Staff Member" << endl
                     << "UserName: " << user.Acadamic_Staff_Member[i].UserName << endl
                     << "Password: " << user.Acadamic_Staff_Member[i].Password << endl;
                break;
            }
        }
    }
    else if (role == 2)
    {
        for (int i = 0; i < user.n2; i++)
        {
            if (i == index)
            {
                cout << "Role: Student" << endl
                     << "UserName: " << user.Student[i].UserName << endl
                     << "Password: " << user.Student[i].Password << endl;
                break;
            }
        }
    }
}