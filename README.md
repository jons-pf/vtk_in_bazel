# vtk_in_bazel

This is a Bazel project used to try to build VTK in Bazel.

## Building

1. First launch the VTK build process (CMake, launched through Bazel):

    ```bash
    bazel build //vtk
    ```

2. Now launch the build process of the test program:

    ```bash
    bazel build //vtk:test_vtk_setup
    ```

## Current Status

Step 1 currently fails. The build log is provided in `build_log_so_far.log`.
So far, I tracked down the error to the nested build process of HDF5.
The concrete step that fails is located in line 610: `-- Detecting C maximum decimal precision for C`
