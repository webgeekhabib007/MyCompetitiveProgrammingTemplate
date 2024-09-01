#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n_tests;
    cin >> n_tests;

    while (n_tests--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n % 2 == 0) {
            unordered_map<char, int> even_counter, odd_counter;

            for (int i = 0; i < s.length(); i++) {
                if (i % 2 == 0) {
                    even_counter[s[i]]++;
                } else {
                    odd_counter[s[i]]++;
                }
            }

            char even_max_char = '\0';
            int even_max_count = 0;
            for (const auto& pair : even_counter) {
                if (pair.second > even_max_count) {
                    even_max_count = pair.second;
                    even_max_char = pair.first;
                }
            }

            char odd_max_char = '\0';
            int odd_max_count = 0;
            for (const auto& pair : odd_counter) {
                if (pair.second > odd_max_count) {
                    odd_max_count = pair.second;
                    odd_max_char = pair.first;
                }
            }

            int result = (n / 2 - even_max_count) + (n / 2 - odd_max_count);
            cout << result << endl;
        } else {
            if (n == 1) {
                cout << 1 << endl;
                continue;
            }

            int best = numeric_limits<int>::max();
            unordered_map<char, int> even_counter, odd_counter;

            for (int i = 0; i < n - 1; i++) {
                if (i % 2 == 0) {
                    even_counter[s[i]]++;
                } else {
                    odd_counter[s[i]]++;
                }
            }

            unordered_map<char, int> even_counter_after, odd_counter_after;

            int even_max_count = 0;
            for (const auto& pair : even_counter) {
                even_max_count = max(even_max_count, pair.second);
            }

            int odd_max_count = 0;
            for (const auto& pair : odd_counter) {
                odd_max_count = max(odd_max_count, pair.second);
            }

            best = min(best, (n / 2 - even_max_count) + (n / 2 - odd_max_count));

            for (int i = n - 2; i >= 0; i--) {
                if (i % 2 == 0) {
                    even_counter[s[i]]--;
                    even_counter_after[s[i + 1]]++;
                } else {
                    odd_counter[s[i]]--;
                    odd_counter_after[s[i + 1]]++;
                }
            }

            unordered_map<char, int> even_counter_merged = even_counter;
            for (const auto& pair : even_counter_after) {
                even_counter_merged[pair.first] += pair.second;
            }

            unordered_map<char, int> odd_counter_merged = odd_counter;
            for (const auto& pair : odd_counter_after) {
                odd_counter_merged[pair.first] += pair.second;
            }

            even_max_count = 0;
            for (const auto& pair : even_counter_merged) {
                even_max_count = max(even_max_count, pair.second);
            }

            odd_max_count = 0;
            for (const auto& pair : odd_counter_merged) {
                odd_max_count = max(odd_max_count, pair.second);
            }

            best = min(best, (n / 2 - even_max_count) + (n / 2 - odd_max_count));

            if (n < 2) {
                cout << best + 2 << endl;
            } else {
                cout << best + 1 << endl;
            }
        }
    }

    return 0;
}
