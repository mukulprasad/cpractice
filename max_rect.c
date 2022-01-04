#include <stdio.h>

void main()
{
  int A[4][4] = {0,0,1,1,
                 0,1,1,0,
                 1,1,1,0,
                 1,0,0,1};
  
  int B[4][4] = {0,0,0,0,
                 0,0,0,0,
                 0,0,0,0,
                 0,0,0,0};

  int row = 4; 
  int col = 4;

  int rect_size      = 0; 
  int ones_in_row    = 0;
  int max_rect_size  = 0;
  int number_of_rows = 0;
  
  int min_consec_ones_in_row = 0;

  int i, j, x, y;
  
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      if (A[i][j] == 0){
        continue;
      }
      rect_size = 0; 
      ones_in_row = 0;
      max_rect_size = 0;
      number_of_rows = 0;
      
      x = i;
      y = j;
      while(x < row) {
        y = j;
        if (A[x][y] == 0) {
          break;
        }
        ones_in_row = 0;
        min_consec_ones_in_row = 9;
        number_of_rows ++;
        // find number of consecutive ones in a row
        while(y < col) {
          if (A[x][y]) {
            ones_in_row ++;
            y += 1;
          }else{
            break;
          }
        }
        if (ones_in_row < min_consec_ones_in_row) {
          min_consec_ones_in_row = ones_in_row;
        }
        rect_size = number_of_rows * min_consec_ones_in_row;
        if (max_rect_size < rect_size) {
          max_rect_size = rect_size;
        }
        x += 1;
      }
      B[i][j] = max_rect_size;
    }
  }
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("%d ",B[i][j]);
    }
    printf("\n");
  }
}



  
