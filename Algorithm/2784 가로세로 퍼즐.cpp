#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

typedef pair<int, int> pii;
map<vector<string>, int> m;
vector<int> visited(6);
vector<string> v;
vector<string> str;
vector<string> ans;
string input;
int N, M, check;
void Print()
{
    if (v.size() == 3 && m.count(v) == 0)
    {
        int flag = 0;
        vector<int> tmpVisited;
        tmpVisited = visited;
        for (int i = 0; i < v.size(); i++)
        {
            string tmp = "";
            for (int j = 0; j < v.size(); j++)
            {
                tmp += v[j][i];
            }
            for (int i = 0; i < str.size(); i++)
            {
                if (!tmpVisited[i])
                {
                    if (tmp == str[i])
                    {
                        flag++;
                        tmpVisited[i] = 1;
                        break;
                    }                    
                }
            }           
        }
        if(flag == 3)
            ans.push_back(v[0] + v[1] + v[2]);        
        m.insert({ v, 0 });
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back(str[i]);
            Print();
            visited[i] = 0;
            v.pop_back();
        }
    }
}
int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> input;
        str.push_back(input);
    }
    sort(str.begin(), str.end());
    Print();
    if (ans.empty())
    {
        cout << 0;
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << ans[0][i * 3 + j];
            }
            cout << "\n";
        }
    }   
    return 0;
}