#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s2;
    string s3 = {'a', 'n'};
    getline(cin, s2);
    string s1 = "anshu yadav";
    string s;
    cin >> s;
    cout << s << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s.size() << endl;
    cout << s1.size() << endl;
    cout << s2.size() << endl;
    cout << s3.size << endl;
    cout << " something ";
    char arr[3];
    cin >> arr;
    cout << arr << endl;
    char arr2[] = {"hello"};
    cout << arr2;
    cout << arr2[0];
    //  cout << arr.size(); incorrect
    //  cout << arr2.size(); incorrect
    cout << sizeof(arr) << endl;
    cout << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << sizeof(arr2) / sizeof(arr2[0]) << endl;
    cout << strlen(arr) << endl;
    cout << strlen(arr2) << endl;

    //   cout << arr2.length(); incorrect  only use for string not for char array

    return 0;
}