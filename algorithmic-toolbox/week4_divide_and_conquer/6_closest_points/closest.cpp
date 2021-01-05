#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct Point
{
  int x, y;
};

// Quick sort
void partition(vector<Point>& a, int l, int r, int& m1, int& m2, char coordinate)
{
  int k {l + std::rand() % (r - l + 1)};
  std::swap(a[r], a[k]);

  Point pivot {a[r]};

  int index {1}, i {l}, j{l};

  if (coordinate == 'x')
  {
    while (i < (r - index + 1))
    {
      if (a[i].x < pivot.x)
      {
        std::swap(a[i], a[j++]);
      }
      else if (a[i].x == pivot.x)
      {
        std::swap(a[i--], a[r - index]);
        index++;
      }
      i++;
    }
  }
  else
  {
    while (i < (r - index + 1))
    {
      if (a[i].y < pivot.y)
      {
        std::swap(a[i], a[j++]);
      }
      else if (a[i].y == pivot.y)
      {
        std::swap(a[i--], a[r - index]);
        index++;
      }
      i++;
    }
  }
  m1 = j;
  for (int k {0}; k < index; k++)
  {
    std::swap(a[j++], a[r - k]);
  }
  m2 = j - 1;
}

void randomized_quick_sort(vector<Point>& a, int l, int r, char coordinate)
{
  if (l >= r)
  {
    return;
  }
  int m1, m2;
  partition(a, l, r, m1, m2, coordinate);
  randomized_quick_sort(a, l, m1 - 1, coordinate);
  randomized_quick_sort(a, m2 + 1, r, coordinate);
}

double distance(Point p1, Point p2)
{
  return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

double minimal_distance(vector<Point>& points, int l, int r)
{
  if (l < r)
  {
    int q {(l + r) / 2};
    double min_left {minimal_distance(points, l, q)};
    double min_right {minimal_distance(points, q + 1, r)};

    double closest_dist {min(min_left, min_right)};
    double gamma {closest_dist};

    vector<Point> sort_by;
    Point p;

    for (int i {q}; i >= l && ((points[q].x - points[i].x) <= gamma); i--)
    {
      p.x = points[i].x;
      p.y = points[i].y;
      sort_by.push_back(p);
    }

    for (int j {q + 1}; j <= r && ((points[j].x - points[q + 1].x) <= gamma); j++)
    {
      p.x = points[j].x;
      p.y = points[j].y;
      sort_by.push_back(p);
    }

    randomized_quick_sort(sort_by, 0, sort_by.size() - 1, 'y');

    for (size_t i {0}; i < sort_by.size() - 1; i++)
    {
      for (size_t j {i + 1}; j < sort_by.size(); j++)
      {
        if ((sort_by[j].y - sort_by[i].y) <= gamma)
        {
          double dist {distance(sort_by[i], sort_by[j])};
          closest_dist = min(dist, closest_dist);
        }
        else
        {
          break;
        }
      }
    }
    return closest_dist;
  }
  else
  {
    return std::numeric_limits<double>::max();
  }
}

double get_minimal_distance(vector<Point>& points, int l, int r)
{
  randomized_quick_sort(points, l, r, 'x');
  return minimal_distance(points, l, r);
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<Point> points(n);
  for (size_t i {0}; i < n; i++)
  {
    std::cin >> points[i].x >> points[i].y;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << get_minimal_distance(points, 0, n - 1) << "\n";
}
