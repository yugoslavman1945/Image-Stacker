#include "stacker.h"
#include <fstream>
#include <iostream>

using namespace std;

Stacker::Stacker() {
    magic_number = "P3";
    width = 0;
    height = 0;
    max_color = 255;
}

bool Stacker::readFirstImage(const string& filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        return false;
    }

    // Read header
    in >> magic_number >> width >> height >> max_color;

    // Resize pixel vector
    pixels.resize(width * height);

    // Read pixel data
    for (int i = 0; i < width * height; i++) {
        in >> pixels[i].r >> pixels[i].g >> pixels[i].b;
    }

    in.close();
    return true;
}

bool Stacker::addImage(const string& filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        return false;
    }

    string magic;
    int w, h, maxc;

    // Read header
    in >> magic >> w >> h >> maxc;

    // Dimension check
    if (w != width || h != height) {
        cerr << "Error: Image dimensions do not match." << endl;
        return false;
    }

    // Add pixel values
    for (int i = 0; i < width * height; i++) {
        int r, g, b;
        in >> r >> g >> b;

        pixels[i].r += r;
        pixels[i].g += g;
        pixels[i].b += b;
    }

    in.close();
    return true;
}

void Stacker::computeAverage(int numImages) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].r /= numImages;
        pixels[i].g /= numImages;
        pixels[i].b /= numImages;
    }
}

bool Stacker::writeOutput(const string& outputName) {
    ofstream out(outputName);

    if (!out.is_open()) {
        cerr << "Error: Could not write output file." << endl;
        return false;
    }

    out << magic_number << "\n";
    out << width << " " << height << "\n";
    out << max_color << "\n";

    for (int i = 0; i < width * height; i++) {
        out << pixels[i].r << " "
            << pixels[i].g << " "
            << pixels[i].b << "\n";
    }

    out.close();
    return true;
}
