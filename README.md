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
The concrete step that fails is located in [line 610](https://github.com/jons-pf/vtk_in_bazel/blob/main/build_log_so_far.log#L610):
`-- Detecting C maximum decimal precision for C`

The problem seems to be that the test program is built as a shared library (with the `-shared` flag)
and then executed as if it was a stand-alone program (`a.out`-style).
This fails and hence also the expected `stdout` fails to be parsed.
