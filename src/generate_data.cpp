#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_AIRPORTS = 300;
const int NUM_ROUTES = 100000;

vector<string> generateAirportCodes(int count) {
    vector<string> codes;
    for (int i = 0; i < count; ++i) {
        string code;
        code += 'A' + rand() % 26;
        code += 'A' + rand() % 26;
        code += 'A' + rand() % 26;
        codes.push_back(code);
    }
    return codes;
}

string getRandomAirport(const vector<string>& airports, const string& exclude = "") {
    string code;
    do {
        code = airports[rand() % airports.size()];
    } while (code == exclude);
    return code;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    ofstream file("data/flights.csv");
    file << "From,To,AvgDelay,Distance\n";

    vector<string> airports = generateAirportCodes(NUM_AIRPORTS);
    unordered_set<string> used;

    int count = 0;
    while (count < NUM_ROUTES) {
        string from = getRandomAirport(airports);
        string to = getRandomAirport(airports, from);

        string route = from + "-" + to;
        if (used.find(route) != used.end()) continue;

        used.insert(route);
        int delay = 5 + rand() % 180;         // delay between 5–180 minutes
        int distance = 100 + rand() % 5000;   // distance between 100–5000 miles

        file << from << "," << to << "," << delay << "," << distance << "\n";
        ++count;
    }

    cout << "Generated " << NUM_ROUTES << " flight routes.\n";
    return 0;
}
