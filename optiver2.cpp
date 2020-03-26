#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// using struct because all the fields are public by default
// holds an 'edge' object
struct edge {
    int vertex, weight;
};

// todo is for dijkstras 
struct todo {
    int vertex, distance, prev;
};

// for the priority_queue for dijkstras
bool operator<(const todo & a, const todo & b) {
    return a.distance > b.distance;
}

// helper function to quit and print a message
void quit(string message) {
  cout << message << endl;
  exit(0);
}

// helpers to check if a character is valid
int isalpha(char c) {
    return c >= 'A' && c <= 'Z';
}
int isnum(char c) {
    return c >= '0' && c <= '9';
}

// takes in a string of edges and returns an adjacency list, for dijkstras.
// if there are errors, it throws accordingly.
vector<vector<edge>> parseedges(string edges) {
    // check no leading/trailing whitespaces
    if (edges[0] != '[') quit("E1");
    if (edges[edges.length()-1] != ']') quit("E1");

    vector<vector<edge>> adjlist(26);
    vector<vector<int>> exist(26, vector<int>(26));

    // read each char one by one
    int space = 0; // prevent repeated spaces
    int inbracket = 0; // prevent ]] or [[
    int status = 0; // 0,1,2 for vertex,vertex,weight
    vector<string> cur_edge(3); // reads one edge
    for (int i = 0; i < edges.length(); i++) {
        if (edges[i] == ' ') {
            if (space != 0) quit("E1");
            space++;
        } else if (edges[i] == '[') {
            if (inbracket == 1) quit("E1");
            inbracket = 1;
        } else if (edges[i] == ']') {
            if (inbracket == 0) quit("E1"); // was never in a bracket
            if (status != 2) quit("E1"); // unfinished edge

            int a = cur_edge[0][0]-'A';
            int b = cur_edge[1][0]-'A';
            if (exist[a][b]) quit("E2"); // repeated edges

            adjlist[a].push_back({b, stoi(cur_edge[2])});
            adjlist[b].push_back({a, stoi(cur_edge[2])});

            // reset edges and values
            cur_edge.clear();
            cur_edge.resize(3);

            // updates that this edge exists
            exist[a][b] = 1;
            exist[b][a] = 1;

            inbracket = 0;
            status = 0;
            space = 0;
        } else if (edges[i] == ',') {
            status = status+1;
            if (status == 3) quit("E1");
        } else {
            // makes sure these chars are valid
            if (status <= 1 && !isalpha(edges[i])) quit("E1");
            else if (status == 2 && !isnum(edges[i])) quit("E1");
            cur_edge[status].push_back(edges[i]);
        }
    }

    return adjlist;
}

// helper function to read the query. 
// if there are errors, it throws them and halts the problem.
vector<int> parsequery(string s) {
    // not long enough - length is at least 1
    if (s.length() <= 5) quit("E1");

    if (!isalpha(s[0])) quit("E1");
    if (s.substr(1,2) != "->") quit("E1");
    if (!isalpha(s[3])) quit("E1");
    if (s[4] != ',') quit("E1");
    for (int i = 5; i < s.length(); i++) if (!isnum(s[i])) quit("E1");
    
    vector<int> answer(3);
    answer[0] = s[0] - 'A';
    answer[1] = s[3] - 'A';
    answer[2] = stoi(s.substr(5));
    return answer;
}

// dijkstras. returns the string of the unique path, halts if there any errors.
string dijkstra(int s, int t, int limit, vector<vector<edge>> & adjlist) {
    vector<int> d(26); // best distance for some vertex
    vector<int> mult(26); // mult[i] is 1 if there are multiple ways to get to i at the shortest path
    vector<int> state(26); // 0 for unvisited, 1 for visited, 2 for final
    vector<int> prev(26); // prev[i] is the best vertex to lead to i
    priority_queue<todo> pq; // priority queue to choose the best option at every iteration
    d[s] = 0;
    state[s] = 1;
    prev[s] = -1;
    pq.push({s,0,-1});
    while (pq.size()) {
        todo at = pq.top();
        pq.pop();

        // already finalised - continue
        if (state[at.vertex] == 2) continue;

        // best! update prev and state
        prev[at.vertex] = at.prev;
        state[at.vertex] = 2;

        for (edge to : adjlist[at.vertex]) {
            if (state[to.vertex] == 0) {
                // if never seen before, the dist is the best
                d[to.vertex] = d[at.vertex] + to.weight;
                pq.push({to.vertex, d[at.vertex] + to.weight, at.vertex});
                state[to.vertex] = 1;
            } else if (state[to.vertex] == 1) {
                // if seen before, only add todo to the priority queue if it is smaller
                if (d[at.vertex] + to.weight < d[to.vertex]) {
                    d[to.vertex] = d[at.vertex] + to.weight;
                    pq.push({to.vertex, d[at.vertex] + to.weight, at.vertex});
                    mult[to.vertex] = 0; 
                } else if (d[at.vertex] + to.weight == d[to.vertex]) {
                    mult[to.vertex] = 1; // multiple ways!
                }
            } else if (state[to.vertex] == 2 && d[at.vertex] + to.weight == d[to.vertex]) {
                mult[to.vertex] = 1; // multiple ways
            }
        }
    }

    // check if the graph is disconnected
    for (int i = 0; i < 26; i++) {
        if (adjlist[i].size() > 0 && state[i] != 2) quit("E2"); // disconnected
    }
    // if multiple paths
    if (mult[t]) quit("E2");
    // if shortest path is too long
    if (d[t] > limit) quit("E3");

    // go through prev and return string answer
    vector<int> reverse_path;
    int pointer = t;
    while (pointer != -1) {
        reverse_path.push_back(pointer);
        pointer = prev[pointer];
    }
    string answer;
    for (int i = reverse_path.size()-1; i >= 0; i--) {
        string s = string(1, 'A' + reverse_path[i]);
        if (i == 0) answer += s;
        else answer += s + "->";
    }
    return answer;
}

int main() {
    // read input
    string edges, query;
    getline(cin, edges);
    getline(cin, query);
    
    // parse input
    vector<vector<edge>> adjlist = parseedges(edges);
    vector<int> q = parsequery(query);

    // check start and end exists
    if (adjlist[q[0]].size() == 0) quit("E2");
    if (adjlist[q[1]].size() == 0) quit("E2");

    // print answer
    cout << dijkstra(q[0],q[1],q[2],adjlist);

    return 0;
}