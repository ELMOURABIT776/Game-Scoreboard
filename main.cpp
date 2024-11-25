#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

    vector<vector<int>> scores = {
        {15, 20, 18, 22},
        {10, 14, 12, 16},
        {20, 18, 22, 25},
        {12, 14, 17, 15},
        {18, 19, 20, 21}
    };

    int num_players = scores.size();
    int num_rounds = scores[0].size();


    for (int i = 0; i < num_players; i++) {
        int total_score = 0;
        for (int j = 0; j < num_rounds; j++) {
            total_score += scores[i][j];
        }
        double avg_score = total_score / double(num_rounds);
        cout << "Player " << i + 1 << ": Total = " << total_score << ", Avg = " << fixed << setprecision(2) << avg_score << endl;
    }


    for (int j = 0; j < num_rounds; j++) {
        int round_highest = *max_element(scores.begin(), scores.end(), [j](const vector<int>& a, const vector<int>& b) {
            return a[j] < b[j];
        })[j];
        int round_lowest = *min_element(scores.begin(), scores.end(), [j](const vector<int>& a, const vector<int>& b) {
            return a[j] < b[j];
        })[j];

        cout << "Round " << j + 1 << ": Highest = " << round_highest << ", Lowest = " << round_lowest << endl;
    }

    return 0;
}
