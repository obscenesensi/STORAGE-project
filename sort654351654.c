#include <stdio.h>

int main() {
    FILE *fin = fopen( "elevator.in", "r" );
    FILE *fout = fopen( "elevator.out", "w" );

    int n, i, j, tmp, trans, max = 0, candidate;
    int weight[ 100000 ];

    fscanf( fin, "%d\n", &n );
    
    for ( i = 0; i < n; ++i ) {
        fscanf( fin, "%d\n", &weight[ i ] );
    }

    for ( i = 0; i < n; ++i ) { //buble sort
        for (j = 0; j < n; ++j) {
            if ( weight[ j + 1 ] > weight[ j ] ) {
                tmp = weight[ j ];
                weight[ j ] = weight[ j + 1 ];
                weight[ j + 1 ] = tmp;
            }
        }
    }


    if ( n % 2 == 0 ) {
        for ( i = 0; i < n; ++i ) {
            candidate = weight[ i ] + weight[ n - i ]; 
            if ( candidate > max ) {
                max = candidate;
            }
        }
        trans = n /2;
    } 
    else {
        max = weight[ n ];
        for ( i = 0; i < n - 1; ++i ) {
            candidate = weight[ i ] + weight[ n - i ]; 
            if ( candidate > max ) {
                max = candidate;
            }
        }
        trans = n / 2 + 1;
    }
    
    fprintf( fout, "%d %d", trans, max );

    fclose( fin );
    fclose( fout );
    return 0;
}
