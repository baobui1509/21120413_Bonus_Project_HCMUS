#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 0;
    while (i < 10)
    {
        if (i == 5)
        {
            continue;
        }
        cout << i << endl;
        i++;
    }
    return 0;
}

// 1
// 1
// xyz
// 321
// 1
// 1
// 2023
// 1
// 2
// 3
// 1
// 2
// 3
// 1
// 3
// Students.csv
// 1
// 1
// 14
// 1
