#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

using namespace std;

class Stacker {
private:
    struct pixel {
        int r;
        int g;
        int b;
    };

    string magic_number;
    int width;
    int height;
    int max_color;

    vector<pixel> pixels;

public:
    // Constructor
    Stacker();

    // Read the first image (initializes width/height/max_color)
    bool readFirstImage(const string& filename);

    // Add another image's pixel data to the existing totals
    bool addImage(const string& filename);

    // Compute the average pixel values
    void computeAverage(int numImages);

    // Write the final averaged image to a file
    bool writeOutput(const string& outputName);
};

#endif
