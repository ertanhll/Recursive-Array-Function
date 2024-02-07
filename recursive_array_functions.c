
#include <stdio.h>
void print_array( int A[], int size ){ // assume size > 0
    printf( "%d ", A[ 0 ] );
    if( size == 1 ) { printf( "\n" ); return; }
    print_array( A + 1, size - 1 );
}
// end is NOT pointing to the last element, instead one element on the right
int is_element_of( int *start, int *end, int n ){
    int result;
    if( end - start == 1 ){  printf("virr\n"); return *start == n;
       }
    result = is_element_of( start, end - 1, n );
    printf("result11111 %d\n",result);
    if( result!=0 ){  printf("hahaha\n"); return 1;
      }
    printf("result %d\n",result);
    printf("endos\n");
    return  *(end-1) == n;
}
int count_in_array( int *start, int *end, int n ){
    int left, right, half_size;
    half_size = ( end - start ) / 2;
    //    4    5     6      x         4    5    6    7    x
    //  start: 0         end: 3   start: 0             end: 4
    // half_size: 1                       half_size: 2
    if( end - start == 1 ) return *start == n;
    //    4    x         4    5    x
    left = count_in_array( start, start + half_size, n  );
    right = count_in_array( start + half_size, end, n  );
    return left + right;
}
void array_copy( int Dest[], int Source[], int size ){
    if( size == 1 ) Dest[ 0 ] = Source[ 0 ];
    else{
        Dest[ 0 ] = Source[ 0 ];
        array_copy( Dest + 1, Source + 1, size - 1 );
    }
}
void reverse_copy( int Dest[], int Source[], int size ){
    if( size == 1 ) Dest[ 0 ] = Source[ 0 ];
    else{
        Dest[ 0 ] = Source[ size - 1 ];
        reverse_copy( Dest + 1, Source, size - 1 );
    }
}
int main(){
    int A[ 10 ] = { 5, 5, 4, 11, 5 ,4,6,4,3,55}, n = 55;
    int B[ 10 ] = { 0 };
    printf( "%d appears in A: %d\n", n, is_element_of( A, A + 10, n ) );
    printf("A+5 = %d\n", *(A+5));
    printf( "%d appears in the first half of A: %d\n", n, is_element_of( A, A + 5, n ) );
    printf( "%d appears %d times in A.\n", n, count_in_array( A, A + 10, n ) );
    array_copy( B + 5, A + 5, 5 );
    print_array( B, 10 );
    reverse_copy( B, A, 10 );
    print_array( B, 10 );
}
