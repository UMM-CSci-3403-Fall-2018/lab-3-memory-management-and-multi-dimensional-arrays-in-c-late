#include <stdlib.h>
#include <stdbool.h>

#include "array_merge.h"
#include "mergesort.h"

int countDuplicates(int size, int* arr){
  int duplicates=0;
  for(int i=0;i<size-1;++i){
    if(arr[i]==arr[i+1]){
      ++duplicates;
    }
  }

  return duplicates;
}

int* array_merge(int num_arrays, int* sizes, int** values){
  int size, doubles, i, j;
  
  size = 0;
  for(i=0; i<num_arrays;++i){
    size = size + sizes[i];
  }

  int *destination = (int*) calloc(size, sizeof(int));
  i=0;
  j=0;
  while(i<size){
      for(int k=0;k<sizes[j];++k){
        destination[i]=values[j][k];
        ++i;
      }
      ++j;
  }

  mergesort(size, destination);

  doubles = countDuplicates(size, destination);
  int finalSize = size - doubles;

  int *finalArray = (int*) calloc(finalSize+1, sizeof(int));
  finalArray[0]=finalSize;
  
  if(finalSize != 0){
    finalArray[1] = destination[0];
  }

  j=1;
  for(i=1;i<size;++i){
    if(finalArray[j] != destination[i]){
      finalArray[j+1] = destination[i];
      ++j; 
    }
  }

  free(destination);
  return finalArray;
}
