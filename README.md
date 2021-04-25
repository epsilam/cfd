# Description
A library of some basic CFD tools.
Current classes:
* BufferGrayscale: for drawing PPM images to be piped into ffmpeg to create a video (see `video` target in the makefile).
* Eulerian2D: 2-dimensional smooth parcel hydrodynamics simulator. Example:
![output](https://user-images.githubusercontent.com/38050380/116011719-af99ea80-a626-11eb-85fe-690df19508e5.gif)

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
