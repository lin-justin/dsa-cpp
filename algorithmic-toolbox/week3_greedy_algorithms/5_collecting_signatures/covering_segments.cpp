// -std=c++14

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <functional>

using std::vector;

struct Segment
{
  int start, end;
};


vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;

  auto cmp = [](auto a, auto b) { return a.start < b.start; };
  std::sort(segments.begin(), segments.end(), cmp);
  std::priority_queue<Segment, vector<Segment>, std::function<bool(Segment, Segment)>> pq(cmp);

  for (auto segment : segments)
  {
    if (pq.empty() || pq.top().end < segment.start)
    {
      pq.emplace(segment);
    }
    else
    {
      auto t {pq.top()};
      pq.pop();
      Segment s;
      s.start = std::max(segment.start, t.start);
      s.end = std::min(segment.end, t.end);
      pq.emplace(s);
    }
  }

  while (!pq.empty())
  {
    points.emplace_back(pq.top().end);
    pq.pop();
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
