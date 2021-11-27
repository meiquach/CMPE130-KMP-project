//Brute Force for Shortest Palindrome

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(0, n - i) == rev.substr(i))
            return rev.substr(0, i) + s;
    }
    return "";
}

int main()
{
    ifstream f("test_BruteForce.txt");
    vector<string> vec;
    string str;
    
    while (getline(f, str)) {
        if (str.size() > 0)
            vec.push_back(str);
    }
    
    
    for (int i=0; i < vec.size(); i++) {
        cout << "case " << i + 1 << endl;
        cout << " String: " << vec[i] << endl;
        cout << " Answer: " << shortestPalindrome(vec[i]) << endl << endl;
    }

    return 0;
}
