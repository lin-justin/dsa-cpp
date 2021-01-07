#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

class JobQueue
{
  private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;
    vector<std::pair<int, long long> > task;

    void WriteResponse() const
    {
      for (size_t i {0}; i < jobs_.size(); ++i)
      {
        cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
      }
    }

    void ReadData()
    {
      int m;
      cin >> num_workers_ >> m;
      jobs_.resize(m);
      for(int i {0}; i < m; ++i)
      {
        cin >> jobs_[i];
      }
    }

    int parent(int i)
    {
      return i / 2;
    }

    int left_child(int i)
    {
      return (2 * i) + 1;
    }

    int right_child(int i)
    {
      return left_child(i) + 1;
    }

    int minIndex(int idx1, int idx2)
    {
      if (task[idx1].second == task[idx2].second)
      {
        if (task[idx1].first  < task[idx2].first)
        {
          return idx1;
        }
        else
        {
          return idx2;
        }
      }
      else if (task[idx1].second < task[idx2].second)
      {
        return idx1;
      }
      else
      {
        return idx2;
      }
    }

    void SiftDown(int i)
    {
      int min_index;
      int left {left_child(i)};
      int right {right_child(i)};

      int min_left {i}, min_right {i};

      if (left < num_workers_)
      {
        min_left = minIndex(left, i);
      }
      if (right < num_workers_)
      {
        min_right = minIndex(right, i);
      }

      if (min_left != i && min_right != i)
      {
        min_index = minIndex(min_left, min_right);
        std::swap(task[min_index], task[i]);
        SiftDown(min_index);
      }
      else if (i != min_left)
      {
        min_index = min_left;
        std::swap(task[min_index], task[i]);
        SiftDown(min_index);
      }
      else if (i !=  min_right)
      {
        min_index = min_right;
        std::swap(task[min_index], task[i]);
        SiftDown(min_index);
      }
    }

    void AssignJobs()
    {
      // TODO: replace this code with a faster algorithm.
      // assigned_workers_.resize(jobs_.size());
      // start_times_.resize(jobs_.size());
      // vector<long long> next_free_time(num_workers_, 0);
      // for (int i {0}; i < jobs_.size(); ++i)
      // {
      //   int duration {jobs_[i]};
      //   int next_worker = 0;
      //   for (int j {0}; j < num_workers_; ++j)
      //   {
      //     if (next_free_time[j] < next_free_time[next_worker])
      //     {
      //       next_worker = j;
      //     }
      //   }
      //   assigned_workers_[i] = next_worker;
      //   start_times_[i] = next_free_time[next_worker];
      //   next_free_time[next_worker] += duration;
      // }

      assigned_workers_.resize(jobs_.size());
      start_times_.resize(jobs_.size());
      task.resize(num_workers_);

      for (int i {0}; i < num_workers_; ++i)
      {
        task[i].first = i;
        task[i].second = 0;
      }

      for (size_t i {0}; i < jobs_.size(); ++i)
      {
        assigned_workers_[i] = task[0].first;
        start_times_[i] = task[0].second;
        task[0].second += jobs_[i];
        SiftDown(0);
      }
    }

  public:
    void Solve()
    {
      ReadData();
      AssignJobs();
      WriteResponse();
    }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
