#include "vtkPolyData.h"

TEST(TestBuildVtk, CheckHasVtk) {
  vtkNew<vtkPolyData> poly_data;
  CHECK_NE(poly_data, nullptr);
}  // CheckHasVtk
