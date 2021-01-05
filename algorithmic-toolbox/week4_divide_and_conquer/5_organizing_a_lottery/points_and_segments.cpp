#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

using std::vector;

struct Point
{
  int value, type;
};

void mergeSort(vector<Point>& all_points, int p, int q, int r)
{
  int n1 {q - p + 1};
  int n2 {r - q};
  int max_int {std::numeric_limits<int>::max()};

  vector<Point> left_vec(n1 + 1);
  vector<Point> right_vec(n2 + 1);

  int i {0}, j {0};

  for (int i{ 0}; i < n1; i++)
  {
    left_vec[i] = all_points[p + i];
  }

  for (int i {0}; i < n2; i++)
  {
    right_vec[i] = all_points[q + i + 1];
  }

  left_vec[n1].value = right_vec[n2].value = max_int;

  for (int k {p}; k <= r; k++)
  {
    if (left_vec[i].value < right_vec[j].value)
    {
      all_points[k] = left_vec[i++];
    }
    else if (left_vec[i].value > right_vec[j].value)
    {
      all_points[k] = right_vec[j++];
    }
    else
    {
      if (left_vec[i].type == -1)
      {
        all_points[k] = left_vec[i++];
      }
      else if (right_vec[i].type == -1)
      {
        all_points[k] = right_vec[j++];
      }
      else if (left_vec[i].type != 0)
      {
        all_points[k] = left_vec[i++];
      }
      else
      {
        all_points[k] = right_vec[j++];
      }
    }
  }
}

void merge_sort(vector<Point>& all_points, int p, int r)
{
  if (p < r)
  {
    int q {(p + r) / 2};
    merge_sort(all_points, p, q);
    merge_sort(all_points, q + 1, r);
    mergeSort(all_points, p, q, r);
  }
}

vector<int> fast_count_segments(vector<Point> all_points, int m, int n)
{
  vector<int> cnt(m);
  merge_sort(all_points, 0, (m + 2 * n - 1));

  int count {0};
  for (int i {0}; i < (2 * n + m); i++)
  {
    if (all_points[i].type == -1)
    {
      count++;
    }
    else if (all_points[i].type == 0)
    {
      count--;
    }
    else
    {
      cnt[all_points[i].type - 2 * n] = count;
    }
  }
  return cnt;
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  vector<Point>all_points(m + 2 * n);
  vector<int> points(m);
  //get segments
  for (int i {0}; i < 2*n; i++)
  {
    std::cin >> all_points[i].value;
    all_points[i].type = -1;
    std::cin >> all_points[++i].value;
    all_points[i].type = 0;
  }
  //get points
  for (int i {2 * n}; i < (2 * n + m); i++)
  {
    std::cin >> all_points[i].value;
    all_points[i].type = i;
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(all_points, m, n);
  for (size_t i {0}; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
  std::cout << "\n";
}