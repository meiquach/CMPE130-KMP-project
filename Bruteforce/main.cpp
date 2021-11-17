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
    int i = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j])
            i++;
    }
    if (i == n)
        return s;
    string remain_rev = s.substr(i, n);
    reverse(remain_rev.begin(), remain_rev.end());
    return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
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
