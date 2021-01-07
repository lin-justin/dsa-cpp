#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

const long unsigned int A {34};
const long unsigned int B {2};
const long unsigned int prime_digit {10000019};
const long unsigned int table_size {100000000};

struct Query
{
    string type, name;
    int number;
};

struct Person
{
    string name;
    int number;
    Person()
        : name(""), number(-1){}
};

vector<Query> read_queries()
{
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i {0}; i < n; ++i)
    {
        cin >> queries[i].type;
        if (queries[i].type == "add")
        {
            cin >> queries[i].number >> queries[i].name;
        }
        else
        {
            cin >> queries[i].number;
        }
    }
    return queries;
}

void write_responses(const vector<string>& result)
{
    for (size_t i {0}; i < result.size(); ++i)
    {
        std::cout << result[i] << "\n";
    }
}

unsigned int Hash(int number)
{
    long unsigned int h {(A * number + B) % prime_digit};

    h %= table_size;

    return h;
}

vector<string> process_queries(const vector<Query>& queries)
{
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    size_t size {queries.size()};

    vector<Person> contacts(table_size);
    unsigned int key;
    for (size_t i {0}; i < size; ++i)
    {
        key = queries[i].number;
        if (queries[i].type == "add")
        {
            if (contacts[key].number == queries[i].number)
            {
                contacts[key].name = queries[i].name;
            }
            else
            {
                contacts[key].name = queries[i].name;
                contacts[key].number = queries[i].number;
            }
            
        }
        else if (queries[i].type == "del")
        {
            if (contacts[key].number == queries[i].number)
            {
                contacts[key].number = -1;
            }
        }
        else
        {
            string response {"not found"};
            if (contacts[key].number == queries[i].number)
            {
                response = contacts[key].name;
            }
            result.push_back(response);
        }
    }
    return result;
}

int main()
{
    write_responses(process_queries(read_queries()));
    return 0;
}
