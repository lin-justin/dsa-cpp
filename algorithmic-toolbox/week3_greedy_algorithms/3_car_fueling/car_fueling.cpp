#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops)
{
    int num_refills {0};
    int tank_val {tank};

    stops.at(0) = 0;
    stops.at(stops.size() - 1) = dist;

    for (size_t i {0}; i < stops.size(); ++i)
    {
        if (i == 0 && stops.at(1) - tank > 0)
        {
            return -1;
        }
        else if (i > 0 && stops.at(i) - stops.at(i - 1) > tank && stops.at(i) - stops.at(i - 1) <= tank_val)
        {
            ++num_refills;
            tank = tank_val;
        }
        else if (i > 0 && tank_val < stops.at(i) - stops.at(i - 1))
        {
            return -1;
        }

        if (i > 0)
        {
            tank -= stops.at(i) - stops.at(i - 1);
        }
        dist -= stops.at(i);
    }
    return num_refills;
}


int main()
{
    int d {0};
    cin >> d;
    int m {0};
    cin >> m;
    size_t n {0};
    cin >> n;

    vector<int> stops(n);
    for (size_t i {0}; i < n; ++i)
    {
        cin >> stops.at(i);
    }
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
