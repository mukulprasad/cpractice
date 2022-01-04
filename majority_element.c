/**
 * Given an array of size n1, find the majority element. 
 * Majority element are those which appear more thatn 'floor' times.
 * floor is defined as count / 2
 *
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 **/
int majorityElement(const int* A, int n1) {
  int i, j;
  float floor;
  int count = 1;
  floor = n1/2;
  
  for (i = 0; i < n1; i++) {
    count = 1;
    for (j = i+1; j < n1; j++){
      if (A[i] == A[j]){
        count += 1;
      }
    }
    if (count > floor){
      return (A[i]);
    }
  }
}
