#include <iostream>
#include <string>
#include <vector>

#define P 1000007
#define X 263

using std::string;
typedef unsigned long long ull;

struct Data
{
    string pattern, text;
};

Data read_input()
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output)
{
    for (size_t i {0}; i < output.size(); ++i)
    {
        std::cout << output[i] << " ";
    }
    std::cout << "\n";
}

size_t PolyHash(const string& s)
{
    size_t hash {0};
    for (int i {static_cast<int>(s.size()) - 1}; i >= 0; --i)
    {
        hash = (hash * X + s[i]) % P;
    }
    if (hash < 0)
    {
        return hash += P;
    }
    return hash;
}

std::vector<size_t> preComputeHash(const string& text, int plength)
{
    size_t tlength {text.size()};

    int y {1};
    std::vector<size_t> hashes(tlength - plength + 1);

    string substring {text.substr(tlength - plength, plength)};
    hashes[hashes.size() - 1] = PolyHash(substring);

    for (int i {0}; i < plength; ++i)
    {
        y = (y * X) % P;
    }

    for (size_t i {hashes.size() - 2}; i >= 0; --i)
    {
        hashes[i] = (X * hashes[i + 1] - y * text[i + plength] + text[i]) % P;
        hashes[i] < 0 ? hashes[i] += P : true;
    }
    return hashes;
}

bool areEqual(const string& str1, const string& str2, int start, int end)
{
    for (int i {start}, j {0}; i < end; i++, j++)
    {
        if (str1[i++] != str2[j++])
        {
            return false;
        }
    }
    return true;
}

std::vector<int> get_occurrences(const Data& input)
{
    const string& s {input.pattern}, t {input.text};
    std::vector<int> ans;
    size_t hash_pattern {PolyHash(s)};
    std::vector<size_t> Hashes {preComputeHash(t, s.size())};

    for (size_t i {0}; i < Hashes.size(); ++i)
    {
        if ((Hashes[i == hash_pattern] && areEqual(t, s, i, i + s.size())))
        {
            ans.push_back(i);
        }
    }
    return ans;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
