#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    int l, r;
    vector<pair<int, int>> line;
    cin >> l >> r;
    while (l != 0 || r != 0) {
        line.push_back(make_pair(l, r));
        cin >> l >> r;
    }
    sort(line.begin(), line.end());
    vector<pair<int, int>> ans;
    l = 0;
    r = m;
    int id = -1;
    int i = 0;
    while (i < line.size())
    {
        if (line[i].first > l)
        {
            if (id == -1)
            {
                cout << "No solution";
                return 0;
            }
            ans.push_back(line[id]);
            l = line[id].second + 1;
            id = -1;
        }
        else {
            if (id == -1)
            {
                id = i;
            }
            if (line[id].second < line[i].second)
            {
                id = i;
            }
            ++i;
        }
    }
    if (id != -1)
    {
        ans.push_back(line[id]);
    }
    cout << ans.size() << '\n';
    for (auto& it : ans)
    {
        cout << it.first << ' ' << it.second << '\n';
    }

    return 0;
}
