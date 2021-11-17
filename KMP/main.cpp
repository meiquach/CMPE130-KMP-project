//KMP method for shortest Palindrome

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
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}

int main()
{
    ifstream f("test_KMP.txt");
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
