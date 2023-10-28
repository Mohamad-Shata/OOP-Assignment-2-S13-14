#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};

bool compareScores(const Player& p1, const Player& p2) {
    return p1.score > p2.score;
}

int main() {
    vector<Player> playerList;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a new player and score\n";
        cout << "2. Print the top 10 players' names and scores\n";
        cout << "3. Search for a player's highest score\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int score;

            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter player score: ";
            cin >> score;

            playerList.push_back({name, score});
        } else if (choice == 2) {
            sort(playerList.begin(), playerList.end(), compareScores);

            cout << "Top 10 players:\n";
            int count = 0;
            for (const auto& player : playerList) {
                cout << player.name << " " << player.score << endl;
                count++;
                if (count == 10) {
                    break;
                }
            }
        } else if (choice == 3) {
            string searchName;
            cout << "Enter player name to search: ";
            cin >> searchName;

            int highestScore = 0;
            bool found = false;

            for (const auto& player : playerList) {
                if (player.name == searchName) {
                    highestScore = max(highestScore, player.score);
                    found = true;
                }
            }

            if (found) {
                cout << "Highest score for player " << searchName << ": " << highestScore << endl;
            } else {
                cout << "Player " << searchName << " not found or not in the top 10.\n";
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}
