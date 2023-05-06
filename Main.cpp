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
                    cout << "______Funtions______" << endl;
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