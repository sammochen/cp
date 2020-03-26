#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the implementation of the IntervalLimiter class.
 */
class IntervalLimiter
{
public:


    unsigned long limit, interval;
    vector<long long> times; // times of each event
    vector<long long> added; // how much was added at each event
    vector<long long> prefix_sum; // prefix_sum of added

    // returns the index of smallest time that is >= time
    int binary_search(int time, int L, int R) {
        while (L<R) {
            int M = (L+R)/2;
            if (times[M] >= time) R = M;
            else L = M+1;
        }
        return L;
    }

    IntervalLimiter(unsigned long a, unsigned long b)
    {

        limit = a;
        interval = b;
        prefix_sum = {0}; // supports prefix_sum of nothing
    }

    /* Return the limited value. */
    long apply(long value, unsigned long monotonic_time)
    {
        long sign = value >= 0 ? 1 : -1; // remember the sign
        value = abs(value); // sign doesn't matter
        // if its the first one, add as much as you can.
        if (times.size() == 0) {
            value = min(value, (long)limit);
            times.push_back(monotonic_time);
            added.push_back(value);
            prefix_sum.push_back(value);
            return sign*value;
        }

        // this is the earliest time that we have to worry about  
        // the binary search finds the earliest occurence of time-interval+1
        int earliest_time = binary_search(monotonic_time - interval + 1, 0, times.size() - 1);
        // prefix_sum supports O(1) time to add the sums
        int sum = prefix_sum[prefix_sum.size()-1] - prefix_sum[earliest_time];

        // limited by the 'cap'
        value = min(value, (long)limit-sum);

        // update the lists
        times.push_back(monotonic_time);
        added.push_back(value);
        prefix_sum.push_back(prefix_sum[prefix_sum.size()-1] + value);

        return sign*value;
    }
};