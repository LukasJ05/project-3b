#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data/flights.csv");
    if (!file.is_open()) {
        cerr << "Failed to open flights.csv\n";
        return 1;
    }

    string line;
    int rowCount = 0;

    // Skip header
    if (getline(file, line)) {
        // Count lines after header
        while (getline(file, line)) {
            ++rowCount;
        }
    }

    file.close();

    cout << "Total number of data rows (excluding header): " << rowCount << "\n";

    if (rowCount >= 100000) {
        cout << "Requirement met: 100,000+ rows present.\n";
    } else {
        cout << "Requirement NOT met: Need at least 100,000 rows.\n";
    }

    return 0;
}
