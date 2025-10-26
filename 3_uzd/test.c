#include <stdio.h>

int charcount( FILE *const fin )
{
    int c, count;
	
    count = 0;
    for( ;; )
    {
        c = fgetc( fin );
        if( c == EOF || c == '\n' )
            break;
        ++count;
    }

    return count;
}



int main( int argc, char **argv )
{
    FILE *fin;

    fin = fopen( "test.txt", "r" );
    if( fin == NULL )
        return 1;

    printf( "Character count: %d.\n", charcount( fin ) );

    fclose( fin );
    return 0;
}