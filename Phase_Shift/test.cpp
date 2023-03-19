#include <iostream>
#include<map>
using namespace std;

void foo(char a[]) {
    a[2] = '2';
}

int main()
{
    char p[3];
    // foo(p);
    char a = 'b';;
    a++;
    cout << a << endl;

    return 0;
}