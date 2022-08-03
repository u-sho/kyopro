#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d, d + n);
    cout << d[n / 2] - d[n / 2 - 1] << endl;
    return 0;
}
