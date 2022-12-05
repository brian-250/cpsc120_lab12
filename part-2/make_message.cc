// Brian Milian
// CPSC 120-12
// 2022-12-01
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 12-02
// Partners: @engenies
//
// Creates a GIF image with different colors at each pixel of the image. The user can also interact with the program and add any phrase of text desired on the image. The text will be of color yellow.
//

#include <Magick++.h>

#include <iostream>
#include <string>
#include <vector>

#include "make_message_functions.h"

/// Main function - Entry point for our ray tracer
/// The program takes two arguments which is the output file name and a
/// a brief message. The image generated by the main function is written
/// out as a GIF file.
int main(int argc, char const* argv[]) {
  // Initialize the GraphicsMagick library. It must be the first thing
  // that happens in the main function.
  // Do not change or remove the line below.
  Magick::InitializeMagick(*argv);
  // std::vector of std::strings.
  std::vector<std::string> args = std::vector<std::string>{argv, argv + argc};
  // too few, print an error message and exit.
  if (args.size() < 3) {
    std::cout << "Please provide a path to a file and a brief message.\n";
    return 1;
  }
  std::string output_file_name;
  output_file_name = args.at(1);
  // initialize it to ".gif"
  std::string image_format{".gif"};
  // output_file_name has the extension defined as image_format. If
  // output_file_name does not, then print an error message and return 1.
  if (!HasMatchingFileExtension(output_file_name, image_format)) {
    std::cout << output_file_name << " is missing the required file extension .gif.\n";
    return 1;
  }

  // the args.at(2)
  std::string message{args.at(2)};

  const double aspect_ratio = 16.0 / 9.0;
  // Set the image width to 1024 pixels
  const int image_width = 1024;
  // Calculate the height of the image using the width and aspect ratio.
  // Remember to round the number to the closest integer.
  const int image_height = int(lround(image_width / aspect_ratio));
  Magick::ColorRGB yellow(1, 1, 0);

  // THE image Image needs to be created in the for-loop below because we are creating five unique images
  // Magick::Image image(Magick::Geometry(image_width, image_height), yellow);

  // Print out some information about the image to help us debug what's
  // going on.

  // WRONG to use image.columns(). You have to use image_width
  // WRONG to use image.rows(). You have to use image_height
  // std::cout << "Your image has " << image.columns()
  //           << " columns (x direction) and " << image.rows()
  //           << " rows (y direction).\n";

  std::cout << "Your image has " << image_width
            << " columns (x direction) and " << image_height
            << " rows (y direction).\n";

  const int number_of_images = 5;
  std::vector<Magick::Image> images;

  for (int image_count = 0; image_count < number_of_images; image_count++) {
    std::cerr << "Image " << image_count + 1 << "...";
    Magick::Image image(Magick::Geometry(image_width, image_height), yellow);

    // For example:
    // for (int row = 0; row < image.rows(); row++) {
    //   for (int column = 0; column < image.columns(); column++) {
      for (int row = 0; row < image.rows(); row++) {
        for (int column = 0; column < image.columns(); column++){
          // it RandomDouble01()
          double random_color_intensity = RandomDouble01();
          double red = 0.0;
          double green = 0.0;
          double blue = 0.0;
          if (CoinFlip() == true) {
            red = random_color_intensity;
          }
          if (CoinFlip() == true) {
            green = random_color_intensity;
          }
          if (CoinFlip() == true) {
            blue = random_color_intensity;
          }
          // it with the values from the red, green, blue variables.
          Magick::ColorRGB color(red, green, blue);
          // For example:
          // image.pixelColor(row, column, color); INCORRECT WAY
          // image.pixelColor(column, row, color); CORRECT WAY
          image.pixelColor(column, row, color);
          // it with the values from the red, green, blue variables.
          // TODO: Set the current pixel color in the image to the new color.
          // For example:
          // image.pixelColor(column, row, color);
          //   }
          // }
        }
      }
      // uncomment the lines below to add your message to the center of the
      // image.
      // image.font("Helvetica");
    // image.fontPointsize(image.rows() / 3.0);
    // image.fillColor(Magick::Color("yellow"));
    // image.annotate(message, Magick::CenterGravity);
    image.font("Helvetica");
    image.fontPointsize(image.rows() / 3.0);
    image.fillColor(Magick::Color("yellow"));
    image.annotate(message, Magick::CenterGravity);

    images.push_back(image);
    std::cerr << "completed.\n";
  }

  // For example:
  // Magick::writeImages(images.begin(), images.end(), output_file_name);
  Magick::writeImages(images.begin(), images.end(), output_file_name);
  return 0;
}