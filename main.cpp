#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int maxColors = 8;
    int red[maxColors], green[maxColors], blue[maxColors];
    double brightness[maxColors];
    int count;
    bool allSafe = true;

    do {
        cout << "How many colors are in your palette (2-8): ";
        cin >> count;
        if (count < 2 || count > maxColors) {
            cout << "Try again.\n";
        }
    } while (count < 2 || count > maxColors);

    for (int i = 0; i < count; i++) {
        cout << "Color " << i + 1 << " - enter R G B: ";
        cin >> red[i] >> green[i] >> blue[i];
        brightness[i] = 0.299 * red[i] + 0.587 * green[i] + 0.114 * blue[i];
    }

    int i = 0;
    while (i < count) {
        int j = i + 1;
        while (j < count) {
            double gap = std::abs(brightness[i] - brightness[j]); 
            
            if (gap < 30) {
                cout << "Color " << (i + 1) << " and " << (j + 1) << ": Hard to tell apart." << endl;
                allSafe = false;
            } else if (gap < 70) {
                cout << "Color " << (i + 1) << " and " << (j + 1) << "... OKAY" << endl;
            } else {
                cout << "Color " << (i + 1) << " and " << (j + 1) << "... EASY" << endl;
            }
            j++;
        }
        i++;
    }

    if (allSafe) {
        cout << "\nYour palette looks good!\n" 
             << "Every pair of colors has enough brightness difference to be told apart." << endl;
    } else {
        cout << "\nWarning: Some colors in your palette are too similar.\n" 
             << "People with color blindness may not be able to tell them apart." << endl;
    }

    return 0;
}
