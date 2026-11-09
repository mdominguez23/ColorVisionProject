
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


bool hexToRGB(string hex, int &r, int &g, int &b);
double getBrightness(int r, int g, int b);
int hexDigitValue(char ch);
void simulateColor(int visionType, int &r, int &g, int &b);

int main() {
    const int MAX_COLORS = 10;
    string hexCodes[MAX_COLORS];
    double brightness[MAX_COLORS];
    int count;
    bool allSafe = true;

    // ---------- 1. How many colors ----------
    do {
        cout << "How many colors are in your palette (2-10): ";
        cin >> count;
        if (count < 2 || count > MAX_COLORS) {
            cout << "Try again.\n";
        }
    } while (count < 2 || count > MAX_COLORS);

    // ---------- 2. Choose a vision type ----------
    int visionType;
    do {
        cout << "Choose a vision type:\n"
             << "1. Protanopia (red-blind)\n"
             << "2. Deuteranopia (green-blind)\n"
             << "3. Tritanopia (blue-blind)\n"
             << "4. Normal vision\n"
             << "Choice: ";
        cin >> visionType;
        
    } while (visionType < 1 || visionType > 4);

    // ---------- 3. Read each hex color ----------
    for (int i = 0; i < count; i++) {
        string hexInput;
        int red, green, blue;
        bool valid = false;

        while (!valid) {
            cout << "Color " << i + 1 << " - enter hex code (like #FF8000): ";
            cin >> hexInput;
            valid = hexToRGB(hexInput, red, green, blue);
           
        }

        hexCodes[i] = hexInput;
        simulateColor(visionType, red, green, blue);
        brightness[i] = getBrightness(red, green, blue);
    }

    // ---------- 4. Open the report file ----------
    ofstream report("palette_report.txt");
    

    // ---------- 5. Compare every pair ----------
    int i = 0;
    while (i < count) {
        int j = i + 1;
        while (j < count) {
            double gap = abs(brightness[i] - brightness[j]);

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

    // ---------- 6. Final verdict ----------
    if (allSafe) {
        cout << "\nYour palette looks good!\n"
             << "Every pair of colors has enough brightness difference to be told apart." << endl;
        
    } else {
        cout << "\nWarning: Some colors in your palette are too similar.\n"
             << "People with color blindness may not be able to tell them apart." << endl;
        
    }

    report.close();
    return 0;
}

// ---------- DEFINITIONS ----------

// Converts a hex code like #FF8000 into R, G, B.
// Returns false if the code is not valid.
bool hexToRGB(string hex, int &r, int &g, int &b) {
    // must be 7 characters and start with #
    if (hex.length() != 7 || hex[0] != '#') {
        return false;
    }

    // characters 1-6 must be 0-9, A-F, or a-f
    for (int i = 1; i <= 6; i++) {
        char ch = hex[i];
        if (!((ch >= '0' && ch <= '9') ||
              (ch >= 'A' && ch <= 'F') ||
              (ch >= 'a' && ch <= 'f'))) {
            return false;
        }
    }

    // convert each pair from base 16: first digit x 16 + second digit
    r = hexDigitValue(hex[1]) * 16 + hexDigitValue(hex[2]);
    g = hexDigitValue(hex[3]) * 16 + hexDigitValue(hex[4]);
    b = hexDigitValue(hex[5]) * 16 + hexDigitValue(hex[6]);

    return true;
}

// Returns how bright a color looks to the human eye (0-255).
double getBrightness(int r, int g, int b) {
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

// Converts one hex character (0-9, A-F, a-f) into its value (0-15).
int hexDigitValue(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    } else {
        return ch - 'a' + 10;
    }
}


void simulateColor(int visionType, int &r, int &g, int &b) {
    double newR = r;
    double newG = g;
    double newB = b;

    switch (visionType) {
        case 1:   // protanopia
            newR =  0.152286 * r + 1.052583 * g - 0.204868 * b;
            newG =  0.114503 * r + 0.786281 * g + 0.099216 * b;
            newB = -0.003882 * r - 0.048116 * g + 1.051998 * b;
            break;
        case 2:
            newR =  0.367322·r + 0.860646·g − 0.227968·b
            newG =  0.280085·r + 0.672501·g + 0.047413·b
            newB = −0.011820·r + 0.042940·g + 0.968881·b   // deuteranopia
            break;
        case 3:
            newR =  1.255528·r − 0.076749·g − 0.178779·b
            newG = −0.078411·r + 0.930809·g + 0.147602·b
            newB =  0.004733·r + 0.691367·g + 0.303900·b  // tritanopia
            break;
        default:  // normal vision: no change
            return;
    }

    // keep each value in the 0-255 range
    if (newR < 0) {
        newR = 0;
    } else if (newR > 255) {
        newR = 255;
    }
    

    r = newR;
    g = newG;
    b = newB;
}