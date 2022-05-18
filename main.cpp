#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void separateNumbers(string s)
{
    for(size_t i = 1; i <= (s.length() / 2) + 1 && i < 17; i++)
    {
        size_t number = stoll(s.substr(0, i));
        size_t start = i;

        while(true)
        {
            number++;

            int count = 0;
            size_t newNumber = number;

            while(number != 0)
            {
                number /= 10;
                count++;
            }

            if(start + count <= s.length())
            {
                number = stoll(s.substr(start, count));

                if(number != newNumber)
                    break;

                start += count;
            }
            else
                break;

            if(start == s.length())
            {
                cout << "YES " + s.substr(0, i) << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
        );

    return s;
}
