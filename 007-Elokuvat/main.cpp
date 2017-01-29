#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct movie {
    movie(int s, int e) {
        start = s;
        end = e;
    }
    int start;
    int end;
};


bool compare (movie i, movie j) { return (i.end < j.end); }

vector<movie> movies;

int main() {
    cin.sync_with_stdio(false);
    int n, ms;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        movies.push_back(movie(start, end));
    }

    sort(movies.begin(), movies.end(), compare);

    int starttime = movies[0].start;
    for (int j = 0; j < movies.size(); ++j) {
        if (movies[j].start >= starttime) {
            ms++;
            starttime = movies[j].end;
        }
    }
    cout << ms;
    return 0;
}