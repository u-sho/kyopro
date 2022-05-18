#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p[20];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (
            (min(p[i - 1], p[i + 1]) < p[i]) && (p[i] < max(p[i - 1], p[i + 1])))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}