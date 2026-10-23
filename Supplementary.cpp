#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int TOTAL_VOTES = 100;
const int NUM_CANDIDATES = 5;

const std::string CANDIDATES[NUM_CANDIDATES] = {
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustin",
    "Deja Jayla Banaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};

void insertionSort(int arr[], int n) {
    int K = 0, J, temp;
    while (K < n) {
        temp = arr[K];
        J = K - 1;
        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

int main() {
    int votes[TOTAL_VOTES];
    int voteCounts[NUM_CANDIDATES] = {0};

    srand(time(0));

    for (int i = 0; i < TOTAL_VOTES; i++) {
        votes[i] = (rand() % NUM_CANDIDATES) + 1;
    }

    std::cout << "UNSORTED VOTE ARRAY" << std::endl;
    for (int i = 0; i < TOTAL_VOTES; i++) {
        std::cout << votes[i] << " ";
    }
    std::cout << "\n\n";

    insertionSort(votes, TOTAL_VOTES);

    std::cout << "SORTED VOTE ARRAY" << std::endl;
    for (int i = 0; i < TOTAL_VOTES; i++) {
        std::cout << votes[i] << " ";
    }
    std::cout << "\n\n";

    for (int i = 0; i < TOTAL_VOTES; i++) {
        voteCounts[votes[i] - 1]++;
    }

    int maxVotes = -1;
    int winningIndex = -1;

    std::cout << "VOTE COUNT RESULTS" << std::endl;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        std::cout << "Candidate " << (i + 1) << " (" << CANDIDATES[i] << "): " 
                  << voteCounts[i] << " votes" << std::endl;

        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winningIndex = i;
        }
    }

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "WINNING CANDIDATE: Candidate " << (winningIndex + 1) 
              << " - " << CANDIDATES[winningIndex] 
              << " with " << maxVotes << " votes!" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}