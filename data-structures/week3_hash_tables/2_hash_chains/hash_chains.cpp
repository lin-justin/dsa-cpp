#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::cin;
using std::list;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor
{
    size_t bucket_count;
    // store all strings in one vector
    vector<list<string> > elems;
    size_t hash_func(const string& s) const
    {
        static const size_t multiplier {263};
        static const size_t prime {1000000007};
        unsigned long long hash {0};
        for (int i {static_cast<int> (s.size()) - 1}; i >= 0; --i)
        {
            hash = (hash * multiplier + s[i]) % prime;
        }
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), elems(bucket_count) {}

    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
        {
            cin >> query.s;
        }
        else
        {
            cin >> query.ind;
        }
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query)
    {
        size_t key {hash_func(query.s)};
        if (query.type == "check")
        {
            // use reverse order, because we append strings to the end
            if (query.ind <  bucket_count)
            {
                auto it {elems[query.ind].rbegin()};
                while (it != elems[query.ind].rend())
                {
                    std::cout << (*it) << " ";
                    ++it;
                }
            }
            std::cout << "\n";
        }
        else
        {
            if (query.type == "find")
            {
                bool result_find {false};
                auto result {std::find(elems[key].begin(), elems[key].end(), query.s)};
                if (result != elems[key].end())
                {
                    result_find = true;
                }
                writeSearchResult(result_find);
            }
            else if (query.type == "add")
            {
                auto result {std::find(elems[key].begin(), elems[key].end(), query.s)};
                if (result == elems[key].end())
                {
                    elems[key].push_back(query.s);
                }
            }
            else if (query.type == "del")
            {
                auto result {std::find(elems[key].begin(), elems[key].end(), query.s)};
                if (result != elems[key].end())
                {
                    elems[key].erase(result);
                }
            }
        }
    }

    void processQueries()
    {
        int n;
        cin >> n;
        for (int i {0}; i < n; ++i)
        {
            processQuery(readQuery());
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
