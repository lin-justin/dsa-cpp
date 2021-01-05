#include <iostream>
#include <vector>

using std::vector;

long long num_of_inversions;

void merge(vector<int>& a, int p, int q, int r)
{
  int n1 {q - p + 1};
  int n2 {r - q};
  int *left_a {new int[n1]};
  int *right_a {new int[n2]};

  for (int i {0}; i < n1; i++)
  {
    left_a[i] = a[p + i];
  }
  for (int i {0}; i < n2; i++)
  {
    right_a[i] = a[q + i + 1];
  }

  int i{0}, j {0}, k {p};
  while (i < n1 && j < n2)
  {
    if (left_a[i] < right_a[j])
    {
      for (int g {0}; g < j && left_a[i] > right_a[g]; ++g)
      {
        num_of_inversions++;
      }
      a[k++] = left_a[i++];
    }
    else if (left_a[i] == right_a[j])
    {
      num_of_inversions += j;
      a[k++] = left_a[i++];
    }
    else
    {
      a[k++] = right_a[j++];
      num_of_inversions += j;
      while (j < n2 && (left_a[i] > right_a[j]))
      {
        num_of_inversions++;
        a[k++] = right_a[j++];
      }
      if (j < n2)
      {
        a[k++] = left_a[i++];
      }
    }
  }
  while (j < n2)
  {
    a[k++] = right_a[j++];
  }
  while (i < n1)
  {
    a[k++] = left_a[i++];
    if (i < n1)
    {
      num_of_inversions += n2;
    }
  }
}

void get_number_of_inversions(vector<int> &a, size_t left, size_t right) 
{
  if (left < right)
  {
    size_t mid {(right + left) / 2};
    get_number_of_inversions(a, left, mid);
    get_number_of_inversions(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i {0}; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  get_number_of_inversions(a, 0, n - 1);
  std::cout << num_of_inversions << "\n";
}
