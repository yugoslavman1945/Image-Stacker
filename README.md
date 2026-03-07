# Image Stacker Project

## 1. Project Overview
This program implements an image stacking algorithm using ASCII PPM (P3) image
files. By averaging multiple noisy images of the same object, the program produces a
cleaner, higher‑quality output image.

The project includes:
- A 'Stacker' class for reading, storing, and processing PPM images
- A 'main.cpp' driver for user interaction
- A 'Makefile' for building the project
- Documentation in this README

---

## 2. How to Compile

```bash
make
```
To clean the build:
```bash
make clean
```
## 3. How to Run

```bash
./image_stacker
```
The program will prompt:
```
Please enter the image you wish to stack:
Please enter the number of images:
```
Example:
```
orion
10
```
The program will read:
```
orion/orion_001.ppm
...
orion/orion_010.ppm
```
and produce:
```
orion.ppm
```
## 4. Program Design
### 4.1 Stacker Class
Responsibilities:
  - Read PPM headers
  - Store pixel data in vector
  - Sum RGB values across images
  - Compute averages
  - Write final output
Private members:
  - string magic_number
  - int width, height, max_color
  - struct pixel { int r, g, b; }
  - vector pixels
### 4.2 Main Driver
Handles:
  - User prompts
  - Printing filenames
  - Calling Stacker methods
  - Error handling
  - Success messages
### 4.3 Error Handling
The program checks for:
  - Missing files
  - Incorrect PPM formatting
  - Dimension mismatches
  - Invalid user input
## 5. Challenges Encountered
  - Parsing ASCII PPM whitespace
  - Ensuring dimension accuracy
  - Avoiding overflow when working with RGB values
  - Designing clean class/driver integration
  - Managing vectors
## 6. Work Distribution
Partner A — BackEnd / Core Logic
  - Designed Stacker class
  - Implemented stacker.cpp
  - Wrote PPM parsing, stacking, averaging, and output logic
  - Unittested class methods
Partner B — FrontEnd / Integration & DevOps
  - Wrote main.cpp
  - Created Makefile
  - Organized GitHub repo
  - Wrote README
  - Performed fullpipeline testing
Shared Work
  - Agreed on class design
  - Debugged integration
  - Verified final output
  - Checked rubric compliance
## 7. Files

```
project/
│── main.cpp
│── stacker.cpp
│── stacker.h
│── Makefile
│── README.md
└── (sample images not included)
```
## 8. References
- PPM (Portable Pixmap) Format Specification
- Course materials provided by instructor
