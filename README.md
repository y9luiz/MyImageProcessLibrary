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
## Input example
	![Alt text](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.tudogostoso.com.br%2Freceita%2F29124-bolo-simples.html&psig=AOvVaw2lx1YLTFCe-wHA5BanJhjF&ust=1601945674589000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCPC22emenOwCFQAAAAAdAAAAABAD "Optional Title")


# Suported Image Types

### Curremente we only have suport for PGM image format.


#### Created by Luiz Felipe Maciel Correia
#### Phone 84 9 8723-5676
#### E-Mail: y9luiz@gmail.com
