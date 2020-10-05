# MyImageProcessLibrary
Just a hobby project to open images and apply image operations


# Building
```
git clone https://github.com/y9luiz/MyImageProcessLibrary.git
cd MyImageProcessLibrary
mkdir build
cd build
cmake ..
make
```

# Running
The main executable is the 'tarefa', you could run it passing the source image and two others filenames to be the output.
E.G.:

```
./tarefa input.pgm normalized.pgm equalized.pgm
```

This will produce two images, the first one is normalized using the maximum and minimum pixels values like parameter
and the second one is equalized using the histogram information

# Expected results
You could find samples at the samples folder and the expected outputs in the samples/expected_outputs

# Suported Image Types

### Curremente we only have suport for PGM image format.


#### Created by Luiz Felipe Maciel Correia
#### Phone 84 9 8723-5676
#### E-Mail: y9luiz@gmail.com
