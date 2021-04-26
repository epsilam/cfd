# Description
A library of some basic CFD tools.
Current classes:
* BufferGrayscale: for drawing PPM images to be piped into ffmpeg to create a video (see `video` target in the makefile).
* Eulerian2D: 2-dimensional smooth parcel hydrodynamics simulator. Example:
![sample2](https://user-images.githubusercontent.com/38050380/116092193-dfd49e00-a6a5-11eb-9a60-309b65ffd6c1.gif)

# Dependencies
* ffmpeg

# Usage

```
make
make video
```

# TODO
* Make boundary detection in Eulerian2D more robust.
* Allow usage of custom boundaries from images.
