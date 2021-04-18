# Description
A library of some basic CFD tools.
Current classes:
* BufferGrayscale: for drawing images in grayscale to be piped through stdout into ffmpeg to create a .mp4 video (see `video` target in the makefile).
* Eulerian2D: 2-dimensoinal smooth parcel hydrodynamics simulator.

# Usage

```
make
make video
```

# TODO
* Make boundary detection in Eulerian2D more robust.
