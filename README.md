# netpbm-image-processing
Image processing project in C for converting Netpbm images between color, grayscale, and black-and-white formats.

## Overview
This repository contains an academic project for the course Introduction to Programming from the first semester.
The project focuses on processing images in the Netpbm format using the C programming language.
The program reads image data from standard input, processes the image pixel by pixel, and writes the converted image to standard output.

It supports:
- Color images
- Grayscale images
- Black-and-white images
- ASCII Netpbm formats
- Binary Netpbm formats

## Project
The program performs the following image conversions:
- P3 → P2
- P2 → P1
- P6 → P5
- P5 → P4

The implementation also supports conversions between ASCII and binary encodings.

The program:
- Parses Netpbm image headers
- Reads image dimensions and maximum pixel values
- Handles image comments
- Converts RGB pixels to grayscale
- Converts grayscale pixels to black and white
- Processes binary and ASCII image data
- Validates input data and detects invalid formats

## Tools and Technologies
- C
- GCC
- Netpbm
- Standard Input / Output
- ASCII Data Processing
- Binary Data Processing
- Bit Manipulation
  
## How to Compile and Run

### Compile
Compile the program using GCC:
- gcc -Wall -Wextra -o figproc src/figproc.c

### Run
To convert a color image to grayscale:
- ./figproc < input.ppm > output.pgm

To convert a grayscale image to black and white:
./figproc < input.pgm > output.pbm

### Example
gcc -Wall -Wextra -o figproc src/figproc.c
./figproc < color-1.ppm > grayscale-1.pgm
./figproc < grayscale-1.pgm > black-white-1.pbm

## What I Practiced
- Programming in C
- Processing structured input data
- Parsing image file formats
- Working with RGB and grayscale pixel values
- Converting color images to grayscale
- Converting grayscale images to black and white
- Working with ASCII and binary data representations
- Processing data byte by byte
- Working with bits and binary values
- Using standard input and output
- Handling invalid input and errors
- Implementing image processing without storing the entire image in memory

## Project Structure
- ├── README.md
- ├── src/
- ├── └── figproc.c
- ├── examples/
- ├── ├── color-1.ppm
- ├── ├── grayscale-1.pgm
- ├── └── black-white-1.pbm
- ├── ├── color-2.ppm
- ├── ├── grayscale-2.pgm
- ├── └── black-white-2.pbm
