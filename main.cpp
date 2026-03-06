#include <iostream>
#include <string>
#include "stacker.h"

using namespace std;

int main() {
    string baseName;
    int numImages;

    cout << "Please enter the image you wish to stack: ";
    cin >> baseName;

    cout << "Please enter the number of images: ";
    cin >> numImages;

    cout << "Stacking images:" << endl;

    Stacker s;

    // Build first filename
    string firstFile = baseName + "/" + baseName + "_001.ppm";

    // Read the first image
    if (!s.readFirstImage(firstFile)) {
        cerr << "Error: Could not read first image." << endl;
        return 1;
    }

    // Read and add remaining images
    for (int i = 1; i <= numImages; i++) {

        // Format number with leading zeros
        string index = to_string(i);
        while (index.length() < 3) {
            index = "0" + index;
        }

        string filename = baseName + "/" + baseName + "_" + index + ".ppm";
        cout << " " << filename << endl;

        if (i == 1)
            continue;  // already read first image

        if (!s.addImage(filename)) {
            cerr << "Error: Could not read image " << filename << endl;
            return 1;
        }
    }

    // Compute average
    s.computeAverage(numImages);

    // Write output
    string outputName = baseName + ".ppm";
    if (!s.writeOutput(outputName)) {
        cerr << "Error: Could not write output file." << endl;
        return 1;
    }

    cout << "\nStacking succeeded." << endl;
    cout << "Output written to: " << outputName << endl;

    return 0;
}
