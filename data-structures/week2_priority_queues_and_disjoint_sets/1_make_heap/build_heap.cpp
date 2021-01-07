#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder
{
  private:
    int sz;
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const
    {
      cout << swaps_.size() << "\n";
      for (size_t i {0}; i < swaps_.size(); ++i)
      {
        cout << swaps_[i].first << " " << swaps_[i].second << "\n";
      }
    }

    void ReadData()
    {
      int n;
      cin >> n;
      sz = n;
      data_.resize(n);
      for(int i {0}; i < n; ++i)
      {
        cin >> data_[i];
      }
    }

    void SiftDown(int i)
    {
      int minIndex {i};
      int left_child {(i * 2) + 1};
      int right_child {left_child + 1};

      if (left_child < sz && data_[left_child] < data_[minIndex])
      {
        minIndex = left_child;
      }

      if (right_child < sz && data_[right_child] < data_[minIndex])
      {
        minIndex = right_child;
      }

      if (minIndex != i)
      {
        swap(data_[i], data_[minIndex]);
        swaps_.push_back(make_pair(i, minIndex));
        SiftDown(minIndex);
      }
    }

    void GenerateSwaps()
    {
      swaps_.clear();
      // The following naive implementation just sorts 
      // the given sequence using selection sort algorithm
      // and saves the resulting sequence of swaps.
      // This turns the given array into a heap, 
      // but in the worst case gives a quadratic number of swaps.
      //
      // TODO: replace by a more efficient implementation
      // for (int i {0}; i < data_.size(); ++i)
      // {
      //   for (int j {i + 1}; j < data_.size(); ++j)
      //   {
      //     if (data_[i] > data_[j])
      //     {
      //       swap(data_[i], data_[j]);
      //       swaps_.push_back(make_pair(i, j));
      //     }
      //   }
      // }

      for (int i {sz/2}; i > -1; --i)
      {
        SiftDown(i);
      }
    }

  public:
    void Solve()
    {
      ReadData();
      GenerateSwaps();
      WriteResponse();
    }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
