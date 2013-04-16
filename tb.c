#include <stdio.h>
#include <stdlib.h>
void print_assembly( double c_x, double c_y );
void print_reactor( void );

int id;

int main(void)
{
	id = 1;
	print_reactor();
	return 0;
}

void print_reactor( void )
{
	// need to define lattice.
	// Assemblies are defined in terms of their distance from the center
	print_assembly( 0.0, 0.0 );
}

void print_assembly( double c_x, double c_y )
{
	FILE * fp = fopen("test.xml", "a");
	
	for( int x = 0; x < 17; x++ )
	{	
		for( int y = 0; y < 17; y++ )
		{
			// skip if guide tube
			if(
					(x==2&&(y==5||y==8||y==11))
					||
					(x==3&&(y==3||y==13))
					||
					(x==5&&(y==2||y==5||y==8||y==11||y==14))
					||
					(x==8&&(y==2||y==5||y==8||y==11||y==14))
					||
					(x==11&&(y==2||y==5||y==8||y==11||y==14))
					||
					(x==13&&(y==3||y==13))
					||
					(x==14&&(y==5||y==8||y==11))
			  )
				continue;

			double x_coord, y_coord;

			x_coord = c_x + ( x - 8 ) * 1.26;
			y_coord = c_y + ( y - 8 ) * 1.26;
			
			int start_id = id;
			
			// print surfaces
			for( int i = 1; i <= 10; i++ )
			{
				double radius = ( .41 / 10.0 ) * i;
				fprintf(fp, "<surface id=\"%d\" type=\"z-cylinder\" coeffs=\"%lf %lf %lf\" />\n", id++, x_coord, y_coord, radius );
			}	

			id = start_id;
			
			// print cells
			fprintf(fp, "<cell id =\"%d\" material=\"1\" surfaces=\"-%d\"/>\n", id, id );
			for( int i = 0; i < 9; i++ )
			{
				fprintf(fp, "<cell id =\"%d\" material=\"1\" surfaces=\"%d -%d\"/>\n", id+1, id, id+1 );
				id++;
			}

			id++;
		}
	}
	
	fclose(fp);
}
