#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    struct path
    {
        int a, b, c, d;
        path(int q, int w, int e, int r) : a{q}, b{w}, c{e}, d{r} {};
        bool out()
        {
            return (a < 0 || a > c - 1 || b < 0 || b > d - 1);
        }
    };
    vector<path> one;
    int findPaths(int m, int n, int N, int i, int j)
    {
        int find = 0;
        path one_path{i, j, m, n};
        one.push_back(one_path);
        for (int k = 0; k < N; k++)
        {
            int k1 = 0;
            int lenth = one.size();
            for (; k1 < lenth; k1++)
            {
                int dir = 4;    //四个方向
                while (dir)
                {
                    switch (dir)
                    {
                    case 1:
                        one_path = one[k1];
                        one_path.a++;
                        break;
                    case 2:
                        one_path = one[k1];
                        one_path.a--;
                        break;
                    case 3:
                        one_path = one[k1];
                        one_path.b++;
                        break;
                    case 4:
                        one_path = one[k1];
                        one_path.b--;
                        break;
                    }
                    if (one_path.out())   //判断出界
                        find++;
                    else
                        one.push_back(one_path);  //存入数组
                    dir--;
                }
                vector<path>::iterator it = one.begin();
                one.erase(it);
            }
        }
        return find;
    }
};
int main()
{
    Solution q;
    cout << q.findPaths(3, 3, 4, 1, 1);
}