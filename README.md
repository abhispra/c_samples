# c_samples

Random samples trying out different stuff
====================================================================

For building, pass the name of the soure file to cmake. For e.g.

cmake -DSOURCE=ptr_debug.cpp -DCMAKE_BUILD_TYPE=DEBUG ..

This is being invoked from a sub folder(for e.g. build) so that src
area remains clean. This would configure cmake to build a executable
of name ptr_debug from ptr_debug.cpp.
