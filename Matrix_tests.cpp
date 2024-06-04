// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()

// Tests if the Matrix_fill function can successfully fill
// the matrix when the matrix is bigger than basic
TEST(test_Matrix_fill_comp) {

  Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 3, 5);

  *Matrix_at(mat1, 0, 0) = 10;
  *Matrix_at(mat1, 0, 1) = 6;
  *Matrix_at(mat1, 0, 2) = 30;
  *Matrix_at(mat1, 1, 0) = 40;
  *Matrix_at(mat1, 1, 1) = 5;
  *Matrix_at(mat1, 1, 2) = 6;
  *Matrix_at(mat1, 2, 0) = 72;
  *Matrix_at(mat1, 2, 1) = 8;
  *Matrix_at(mat1, 2, 2) = 99;
  *Matrix_at(mat1, 3, 0) = 5;
  *Matrix_at(mat1, 3, 1) = 10;
  *Matrix_at(mat1, 3, 2) = 5;
  *Matrix_at(mat1, 4, 0) = 13;
  *Matrix_at(mat1, 4, 1) = 14;
  *Matrix_at(mat1, 4, 2) = 15;

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 3, 5);

  *Matrix_at(mat2, 0, 0) = 5;
  *Matrix_at(mat2, 0, 1) = 5;
  *Matrix_at(mat2, 0, 2) = 5;
  *Matrix_at(mat2, 1, 0) = 5;
  *Matrix_at(mat2, 1, 1) = 5;
  *Matrix_at(mat2, 1, 2) = 5;
  *Matrix_at(mat2, 2, 0) = 5;
  *Matrix_at(mat2, 2, 1) = 5;
  *Matrix_at(mat2, 2, 2) = 5;
  *Matrix_at(mat2, 3, 0) = 5;
  *Matrix_at(mat2, 3, 1) = 5;
  *Matrix_at(mat2, 3, 2) = 5;
  *Matrix_at(mat2, 4, 0) = 5;
  *Matrix_at(mat2, 4, 1) = 5;
  *Matrix_at(mat2, 4, 2) = 5;

  Matrix_fill(mat1, 5);
  ASSERT_TRUE(Matrix_equal(mat1, mat2));

  delete mat1;
  delete mat2;
}


// Tests to see if the Matrix_max function can find the maximum number in a 3x5 matrix
TEST(test_matrix_max) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 1;
  *Matrix_at(mat, 0, 1) = 2;
  *Matrix_at(mat, 0, 2) = 3;
  *Matrix_at(mat, 1, 0) = 4;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 10;
  *Matrix_at(mat, 3, 1) = 11;
  *Matrix_at(mat, 3, 2) = 12;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int expectedMax = 99; 
  int actualMax = Matrix_max(mat);
  ASSERT_EQUAL(expectedMax, actualMax);

  delete mat;

}

// Tests to see of the Matrix_min_value_in_row function can find the min in 
// a desired row
TEST(test_matrix_min_value_in_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 10;
  *Matrix_at(mat, 3, 1) = 12;
  *Matrix_at(mat, 3, 2) = 5;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int actualMin = Matrix_min_value_in_row(mat, 3, 0, 3);
  ASSERT_EQUAL(5, actualMin);

  delete mat;
}

// Tests to see of the Matrix_column_of_min_value_in_row function 
// can find the (one) column of min in 
// a desired row within the bounds of column starting and ending
TEST(test_Matrix_column_of_min_value_in_row_OneMin) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 10;
  *Matrix_at(mat, 3, 1) = 5;
  *Matrix_at(mat, 3, 2) = 12;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int actualCol = Matrix_column_of_min_value_in_row(mat, 3, 0, 3);
  ASSERT_EQUAL(1, actualCol);

  delete mat;
}

// Tests to see of the Matrix_column_of_min_value_in_row function can find
// the leftmost column of min in a desired row within the bounds of column 
// starting and ending when there is actually more than one MIN in the same row
TEST(test_Matrix_column_of_min_value_in_row_multiMin) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 5;
  *Matrix_at(mat, 3, 1) = 10;
  *Matrix_at(mat, 3, 2) = 5;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int actualCol = Matrix_column_of_min_value_in_row(mat, 3, 0, 3);
  ASSERT_EQUAL(0, actualCol);

  delete mat;
}

// Tests if the matrix_fill_border function can fill the matrix's border
// with desired value

TEST(test_Matrix_fill_border) {
  Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 3, 5);

  *Matrix_at(mat1, 0, 0) = 10;
  *Matrix_at(mat1, 0, 1) = 6;
  *Matrix_at(mat1, 0, 2) = 30;
  *Matrix_at(mat1, 1, 0) = 40;
  *Matrix_at(mat1, 1, 1) = 5;
  *Matrix_at(mat1, 1, 2) = 6;
  *Matrix_at(mat1, 2, 0) = 72;
  *Matrix_at(mat1, 2, 1) = 8;
  *Matrix_at(mat1, 2, 2) = 99;
  *Matrix_at(mat1, 3, 0) = 5;
  *Matrix_at(mat1, 3, 1) = 10;
  *Matrix_at(mat1, 3, 2) = 5;
  *Matrix_at(mat1, 4, 0) = 13;
  *Matrix_at(mat1, 4, 1) = 14;
  *Matrix_at(mat1, 4, 2) = 15;

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 3, 5);

  *Matrix_at(mat2, 0, 0) = 50;
  *Matrix_at(mat2, 0, 1) = 50;
  *Matrix_at(mat2, 0, 2) = 50;
  *Matrix_at(mat2, 1, 0) = 50;
  *Matrix_at(mat2, 1, 1) = 5;
  *Matrix_at(mat2, 1, 2) = 50;
  *Matrix_at(mat2, 2, 0) = 50;
  *Matrix_at(mat2, 2, 1) = 8;
  *Matrix_at(mat2, 2, 2) = 50;
  *Matrix_at(mat2, 3, 0) = 50;
  *Matrix_at(mat2, 3, 1) = 10;
  *Matrix_at(mat2, 3, 2) = 50;
  *Matrix_at(mat2, 4, 0) = 50;
  *Matrix_at(mat2, 4, 1) = 50;
  *Matrix_at(mat2, 4, 2) = 50;

  Matrix_fill_border(mat1, 50);
  ASSERT_TRUE(Matrix_equal(mat1, mat2));

  delete mat1;
  delete mat2;
}

// Tests if the Matrix_fill function can successfully fill
// the matrix's border when the matrix is 2x2.
TEST(test_Matrix_fill_border_edge) {

  Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 2, 2);

  *Matrix_at(mat1, 0, 0) = 10;
  *Matrix_at(mat1, 0, 1) = 6;
  *Matrix_at(mat1, 1, 0) = 40;
  *Matrix_at(mat1, 1, 1) = 5;

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 2, 2);

  *Matrix_at(mat2, 0, 0) = 7;
  *Matrix_at(mat2, 0, 1) = 7;
  *Matrix_at(mat2, 1, 0) = 7;
  *Matrix_at(mat2, 1, 1) = 7;

  Matrix_fill_border(mat1, 7);
  ASSERT_TRUE(Matrix_equal(mat1, mat2));

  delete mat1;
  delete mat2;
}

// Tests if the matrix_column can output the correct
// column a pointer is pointing at inside a matrix
TEST(test_Matrix_column) {

  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 5;
  *Matrix_at(mat, 3, 1) = 10;
  *Matrix_at(mat, 3, 2) = 5;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int* ptr1 = Matrix_at(mat, 1, 2);
  int actualCol = Matrix_column(mat, ptr1);
  int expectedCol = 2;
  ASSERT_EQUAL(expectedCol, actualCol);

  delete mat;
}

// Tests if the matrix_row can output the correct
// row a pointer is pointing at inside a matrix

TEST(test_Matrix_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;
  *Matrix_at(mat, 3, 0) = 5;
  *Matrix_at(mat, 3, 1) = 10;
  *Matrix_at(mat, 3, 2) = 5;
  *Matrix_at(mat, 4, 0) = 13;
  *Matrix_at(mat, 4, 1) = 14;
  *Matrix_at(mat, 4, 2) = 15;

  int* ptr1 = Matrix_at(mat, 2, 2);
  int actualRow = Matrix_row(mat, ptr1);
  int expectedRow = 2;
  ASSERT_EQUAL(expectedRow, actualRow);

  delete mat;
}

// Tests if the matrix_height function can output the
// correct height of a matrix
TEST(test_Matrix_height) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;

  int actualHgt = Matrix_height(mat);
  int expectedHgt = 3;
  ASSERT_EQUAL(expectedHgt, actualHgt);

  delete mat;
}

// Tests if the matrix_width function can output the
// correct width of a matrix
TEST(test_Matrix_width) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);

  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 1) = 6;
  *Matrix_at(mat, 0, 2) = 30;
  *Matrix_at(mat, 1, 0) = 40;
  *Matrix_at(mat, 1, 1) = 5;
  *Matrix_at(mat, 1, 2) = 6;
  *Matrix_at(mat, 2, 0) = 72;
  *Matrix_at(mat, 2, 1) = 8;
  *Matrix_at(mat, 2, 2) = 99;

  int actualWdth = Matrix_width(mat);
  int expectedWdth = 3;
  ASSERT_EQUAL(expectedWdth, actualWdth);

  delete mat;
}

// Tests if the matrix_print function prints a matrix correctly
TEST(test_Matrix_print) {

  Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 2, 2);

  *Matrix_at(mat1, 0, 0) = 10;
  *Matrix_at(mat1, 0, 1) = 6;
  *Matrix_at(mat1, 1, 0) = 40;
  *Matrix_at(mat1, 1, 1) = 5;

  ostringstream output;
  Matrix_print(mat1, output);

  ostringstream correct;
  correct << "2 2\n";
  correct << "10 6 \n";
  correct << "40 5 \n";
  ASSERT_EQUAL(output.str(), correct.str());

  delete mat1;
}

TEST_MAIN() // Do NOT put a semicolon here