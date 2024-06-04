// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include "Matrix.h"
#include "Image.h"
#include "processing.h"

using namespace std;

int main(int argc, char* argv[]) {

    string inputFile = argv[1];
    string outputFile = argv[2];
    int width = atoi(argv[3]);
    int height;
    bool heightExists = false;

    if (!(argc == 4 || argc == 5)) {
         cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
         << "WIDTH and HEIGHT must be less than or equal to original" << endl;
         return 1;
    }
    
    //opening the stream to read in file
    ifstream fin;
    fin.open(inputFile);
    if (!fin.is_open()) {
        cout << "Error opening file: " << inputFile << endl;
        return 1;
    }

    //initializing image
    Image *img = new Image;
    Image_init(img, fin);

    //checking width and height conditions 
    if (!(width > 0 && width <= Image_width(img))) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
         << "WIDTH and HEIGHT must be less than or equal to original" << endl;
         return 1;
    }

    if (argc == 5) {
        height = atoi(argv[4]);
        heightExists = true;
        if (!(height > 0 && height <= Image_height(img))) {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return 1;
        }
    }

    if (heightExists) {
        seam_carve(img, width, height);
    } else {
        seam_carve(img, width, Image_height(img));
    }

    ofstream fout;
    fout.open(outputFile);
    if (!fout.is_open()) {
        cout << "Error opening file: " << outputFile << endl;
        return 1;
    }
    Image_print(img, fout);

    delete img;
    fin.close();
    fout.close();
}