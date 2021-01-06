#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

std::list<int32_t> optimal_sequence(int n)
{
  std::vector<int32_t> min_steps(n + 1);
  std::vector<int32_t> predecessor(n + 1);

  for (int32_t i {2}; i <= n; i++)
  {
    min_steps[i] = min_steps[i - 1] + 1;
    predecessor[i] = i - 1;

    if (i % 3 == 0)
    {
      if (min_steps[i/3] < min_steps[i])
      {
        min_steps[i] = min_steps[i/3] + 1;
        predecessor[i] = i/3;
      }
    }

    if (i % 2 == 0)
    {
      if (min_steps[i/2] < min_steps[i])
      {
        min_steps[i] = min_steps[i/2] + 1;
        predecessor[i] = i/2;
      }
    }
  }

  std::list<int32_t> sequence;
  for (int32_t i {n}; i != 0; i = predecessor[i])
  {
    sequence.push_front(i);
  }

  std::cout << min_steps[n] << std::endl;

  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  std::list<int32_t> sequence {optimal_sequence(n)};
  
  while (!sequence.empty())
  {
    std::cout << sequence.front() << " ";
    sequence.pop_front();
  }

  std::cout << "\n";

  return 0;
}
