#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> P(2 * N);
        long long ans = 0;
        vector<int> CachedCounts(2 * N);
        int counter = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            cin >> P[i];
            // let's try to cache count
            if (P[i] > N)
            {
                counter++;
            }
            CachedCounts[i] = counter;
        }

        for (int i = 0; i < 2 * N; i++)
        {

            long long count = 0;
            if (P[i] <= N && i > 0)
            {
                count = CachedCounts[i - 1];
            }

            ans += count;
        }

        cout << ans << endl;
    }
}