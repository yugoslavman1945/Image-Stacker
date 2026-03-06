#ifndef STACKER_H
#define STACKER_H

#include &lt;string&gt;
#include &lt;vector&gt;

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
vector&lt;pixel&gt; pixels;

public:
// Constructor
Stacker();

// Read the first image (initializes width/height/max_color)

bool readFirstImage(const string&amp; filename);

// Add another image&#39;s pixel data to the existing totals
bool addImage(const string&amp; filename);

// Compute the average pixel values
void computeAverage(int numImages);

// Write the final averaged image to a file
bool writeOutput(const string&amp; outputName);

};

#endif
