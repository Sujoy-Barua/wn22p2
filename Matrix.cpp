// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include "Matrix.h"

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
  mat -> width = width;
  mat -> height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
  os << mat->width << " " << mat->height << "\n" ;
  const int* matBegin = mat->data;
  const int* rowBegin = mat->data;
  const int* rowEnd = mat->data + mat->width;
  const int* matEnd = mat->data + (mat->width * mat->height);
  int currentRow = 1;
  for (const int* ptr1 = matBegin; ptr1 < matEnd; ptr1+=mat->width) {
    for (const int* ptr2 = rowBegin; ptr2 < rowEnd; ++ptr2) {
      os << *ptr2 << " ";
    }
    os << "\n";
    rowBegin = mat->data + mat->width * currentRow;
    ++currentRow;
    rowEnd = mat->data + mat->width * currentRow;
  }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
  return mat -> width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
  return mat -> height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
  int dist = (ptr - (mat->data));
  if (dist < (mat->width)) {
    return 0;
  }
  else {
    return dist / (mat->width);
  }
 

}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
  int dist = (ptr - (mat->data));
  if (dist <= (mat->width)) {
    return dist;
  } 
  else {
    return dist % (mat->width);
  }
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
  return (mat->data + (row * mat->width + column));
  
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
  const int *ptr = mat->data + (row * mat->width + column);
  return ptr;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
  int *end = mat->data + ((mat->width * mat->height)); 
  for (int *ptr = mat->data ; ptr < end; ++ptr) {
    *ptr = value;
  }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
  
  int height = Matrix_height(mat);
  int width = Matrix_width(mat);

  if (mat->width > 2 && mat->height > 2) {
    int *fRowBegin = mat->data;
    int *fRowEnd = mat->data + (mat->width-1);
    int *lRowBegin = (mat->data) + (mat->width * ((mat->height) - 1));
    int *lRowEnd = (mat->data) + (((mat->width)*(mat->height))-1);
    int *fColBegin = mat->data + mat->width;
    int *fColEnd = mat->data + (mat->width*((mat->height)-2));
    int *lColBegin = mat->data + ((mat->width) - 1);
    int *lColEnd = mat->data + (mat->width*(mat->height-1)) - 1;
    

    for (int *ptr = fRowBegin; ptr <= fRowEnd; ++ptr) {
      *ptr = value;
    } 

    for (int *ptr = lRowBegin; ptr <= lRowEnd; ++ptr) {
      *ptr = value;
    }

    for (int *ptr = fColBegin; ptr <= fColEnd; ptr+=(width)) {
      *ptr = value;
    } 

    for (int *ptr = lColBegin; ptr <= lColEnd; ptr+=(width)) {
      *ptr = value;
    } 
  } else {
    for (int *ptr = mat->data; ptr <= (mat->data) + ((width*height)-1); ++ptr) {
      *ptr = value;
    }
  }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
  int height = Matrix_height(mat);
  int width = Matrix_width(mat);
  int curMax = *(mat->data);
  for (const int* ptr = mat->data; ptr <= (mat->data) + ((width*height)-1); ++ptr) {
    if (*ptr > curMax) {
      curMax = *ptr;
    }
  }
  return curMax;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int col_s, int col_e) {
  const int *curMin = (mat->data + (mat->width * row)) + col_s;
  int w = Matrix_width(mat);
  const int* begin = (mat->data + w * row) + col_s;
  const int* end = (mat->data + w * row) + col_e;
  for (const int* ptr = begin; ptr < end; ++ptr) {
    if (*ptr < *curMin) {
      curMin = ptr;
    }
  }

  return Matrix_column(mat, curMin);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int col_s, int col_e) {
  int w = Matrix_width(mat);
  int curMin = *((mat->data + w * row) + col_s);
  const int* begin = (mat->data + w * row) + col_s;
  const int* end = (mat->data + w * row) + col_e;
  for (const int* ptr = begin; ptr < end; ++ptr) {
    if (*ptr < curMin) {
      curMin = *ptr;
    }
  }
  return curMin;
}