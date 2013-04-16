#include <stdio.h>
#include <stdlib.h>

void print_assembly( double c_x, double c_y );
void print_reactor( void );
void print_geom_header( void );
void print_geom_footer( void );

void print_tallies_header( void );
void print_tallies( void );
void print_tallies_footer( void );

int id;

// prints 636,240 radial fuel rings
int main(void)
{
	id = 100;
	//print_geom_header();
	//print_reactor();
	//print_geom_footer();

	print_tallies_header();
	print_tallies();
	print_tallies_footer();

	return 0;
}

void print_tallies( void )
{
	FILE * fp = fopen("tallies.xml", "a");
	
	for( int i = 100; i <= 636340; i++ )
	{	
		if( i % 5 == 0 && i != 100 )
			fprintf(fp, "\n");
		fprintf(fp, "%d ", i);
	}
	
	fclose(fp);
}

void print_tallies_header( void )
{
	FILE * fp = fopen("tallies.xml", "w");
	fprintf(fp,
			"<?xml version=\"1.0\"?>\n"
			"<tallies>\n"
			"	<mesh id=\"1\">\n"
			"<type>rectangular</type>\n"
			"<lower_left>-182.07 -182.07 -183.00</lower_left>\n"
			"<upper_right>182.07  182.07  183.00</upper_right>\n"
			"<dimension>1 1 500</dimension>\n"
			"</mesh>\n\n"
			"<tally id=\"1\">\n"
			"<filter type=\"mesh\" bins=\"1\" />\n"
			"<filter type=\"cell\" bins=\"\n"
		   );
	fclose(fp);
}

void print_tallies_footer( void )
{
	FILE * fp = fopen("tallies.xml", "a");
	fprintf(fp,"\"/>\n</tallies>");
	fclose(fp);
}

void print_geom_footer( void )
{
	FILE * fp = fopen("geometry.xml", "a");
	fprintf(fp,"\n</geometry>");
	fclose(fp);
}

void print_geom_header( void )
{
	FILE * fp = fopen("geometry.xml", "w");
	fprintf(fp,
			"<?xml version=\"1.0\"?>\n"
			"<geometry>\n"
			"\n"
			"  <surface id=\"1\" type=\"z-cylinder\" coeffs=\"0. 0. 0.41\" />\n"
			"  <surface id=\"2\" type=\"z-cylinder\" coeffs=\"0. 0. 0.475\" />\n"
			"  <surface id=\"3\" type=\"z-cylinder\" coeffs=\"0. 0. 0.56\" />\n"
			"  <surface id=\"4\" type=\"z-cylinder\" coeffs=\"0. 0. 0.62\" />\n"
			"  <surface id=\"5\" type=\"z-cylinder\" coeffs=\"0. 0. 187.6\" />\n"
			"  <surface id=\"6\" type=\"z-cylinder\" coeffs=\"0. 0. 209.0\" />\n"
			"  <surface id=\"7\" type=\"z-cylinder\" coeffs=\"0. 0. 229.0\" />\n"
			"  <surface id=\"8\" type=\"z-cylinder\" coeffs=\"0. 0. 249.0\" boundary=\"vacuum\" />\n"
			"\n"
			"  <surface id=\"31\" type=\"z-plane\" coeffs=\"-229.0\" boundary=\"vacuum\" />\n"
			"  <surface id=\"32\" type=\"z-plane\" coeffs=\"-199.0\" />\n"
			"  <surface id=\"33\" type=\"z-plane\" coeffs=\"-193.0\" />\n"
			"  <surface id=\"34\" type=\"z-plane\" coeffs=\"-183.0\" />\n"
			"  <surface id=\"35\" type=\"z-plane\" coeffs=\"0.0\" />\n"
			"  <surface id=\"36\" type=\"z-plane\" coeffs=\"183.0\" />\n"
			"  <surface id=\"37\" type=\"z-plane\" coeffs=\"203.0\" />\n"
			"  <surface id=\"38\" type=\"z-plane\" coeffs=\"215.0\" />\n"
			"  <surface id=\"39\" type=\"z-plane\" coeffs=\"223.0\" boundary=\"vacuum\" />\n"
			"\n"
			"  <!-- All geometry on base universe -->\n"
			"  <cell id=\"1\"  fill=\"200\"    surfaces=\"  -6 34 -35\" /> <!-- Lower core -->\n"
			"  <cell id=\"2\"  fill=\"201\"    surfaces=\"  -6 35 -36\" /> <!-- Upper core -->\n"
			"  <cell id=\"3\"  material=\"8\"  surfaces=\"  -7 31 -32\" /> <!-- Lower core plate region -->\n"
			"  <cell id=\"4\"  material=\"9\"  surfaces=\"  -5 32 -33\" /> <!-- Bottom nozzle region -->\n"
			"  <cell id=\"5\"  material=\"12\" surfaces=\"  -5 33 -34\" /> <!-- Bottom FA region -->\n"
			"  <cell id=\"6\"  material=\"11\" surfaces=\"  -5 36 -37\" /> <!-- Top FA region -->\n"
			"  <cell id=\"7\"  material=\"10\" surfaces=\"  -5 37 -38\" /> <!-- Top nozzle region -->\n"
			"  <cell id=\"8\"  material=\"7\"  surfaces=\"  -7 38 -39\" /> <!-- Upper plate region -->\n"
			"  <cell id=\"9\"  material=\"3\"  surfaces=\"6 -7 32 -38\" /> <!-- Downcomer -->\n"
			"  <cell id=\"10\" material=\"5\"  surfaces=\"7 -8 31 -39\" /> <!-- RPV -->\n"
			"  <cell id=\"11\" material=\"6\"  surfaces=\"5 -6 32 -34\" /> <!-- Bottom of radial reflector -->\n"
			"  <cell id=\"12\" material=\"7\"  surfaces=\"5 -6 36 -38\" /> <!-- Top of radial reflector -->\n"
			"\n"
			"  <!-- Fuel pin, cladding, cold water -->\n"
			"  <cell id=\"21\" universe=\"1\" material=\"1\" surfaces=\"-1\"   />\n"
			"  <cell id=\"22\" universe=\"1\" material=\"2\" surfaces=\"1 -2\" />\n"
			"  <cell id=\"23\" universe=\"1\" material=\"3\" surfaces=\"2\"    />\n"
			"\n"
			"  <!-- Instrumentation guide tube -->\n"
			"  <cell id=\"24\" universe=\"2\" material=\"3\" surfaces=\"-3\"   />\n"
			"  <cell id=\"25\" universe=\"2\" material=\"2\" surfaces=\"3 -4\" />\n"
			"  <cell id=\"26\" universe=\"2\" material=\"3\" surfaces=\"4\"    />\n"
			"\n"
			"  <!-- Fuel pin, cladding, hot water -->\n"
			"  <cell id=\"27\" universe=\"3\" material=\"1\" surfaces=\"-1\"   />\n"
			"  <cell id=\"28\" universe=\"3\" material=\"2\" surfaces=\"1 -2\" />\n"
			"  <cell id=\"29\" universe=\"3\" material=\"4\" surfaces=\"2\"    />\n"
			"\n"
			"  <!-- Instrumentation guide tube -->\n"
			"  <cell id=\"30\" universe=\"4\" material=\"4\" surfaces=\"-3\"   />\n"
			"  <cell id=\"31\" universe=\"4\" material=\"2\" surfaces=\"3 -4\" />\n"
			"  <cell id=\"32\" universe=\"4\" material=\"4\" surfaces=\"4\"    />\n"
			"\n"
			"  <!-- cell for water assembly (cold) -->\n"
			"  <cell id=\"50\" universe=\"5\" material=\"4\" surfaces=\"34 -35\" />\n"
			"\n"
			"  <!-- containing cell for fuel assembly -->\n"
			"  <cell id=\"60\" universe=\"6\" fill=\"100\"   surfaces=\"34 -35\" />\n"
			"\n"
			"  <!-- cell for water assembly (hot) -->\n"
			"  <cell id=\"70\" universe=\"7\" material=\"3\" surfaces=\"35 -36\" />\n"
			"\n"
			"  <!-- containing cell for fuel assembly -->\n"
			"  <cell id=\"80\" universe=\"8\" fill=\"101\"   surfaces=\"35 -36\" />\n"
			"\n"
			"  <!-- Fuel Assembly (Lower Half) -->\n"
			"  <lattice id=\"100\">\n"
			"    <type>rectangular</type>\n"
			"    <dimension>17 17</dimension>\n"
			"    <lower_left>-10.71 -10.71</lower_left>\n"
			"    <width>1.26 1.26</width>\n"
			"    <universes>\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 1 1 2 1 1 2 1 1 2 1 1 1 1 1\n"
			"      1 1 1 2 1 1 1 1 1 1 1 1 1 2 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 2 1 1 1 1 1 1 1 1 1 2 1 1 1\n"
			"      1 1 1 1 1 2 1 1 2 1 1 2 1 1 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n"
			"    </universes>\n"
			"  </lattice>\n"
			"\n"
			"  <!-- Fuel Assembly (Upper Half) -->\n"
			"  <lattice id=\"101\">\n"
			"    <type>rectangular</type>\n"
			"    <dimension>17 17</dimension>\n"
			"    <lower_left>-10.71 -10.71</lower_left>\n"
			"    <width>1.26 1.26</width>\n"
			"    <universes>\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 3 3 4 3 3 4 3 3 4 3 3 3 3 3\n"
			"      3 3 3 4 3 3 3 3 3 3 3 3 3 4 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 4 3 3 4 3 3 4 3 3 4 3 3 4 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 4 3 3 4 3 3 4 3 3 4 3 3 4 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 4 3 3 4 3 3 4 3 3 4 3 3 4 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 4 3 3 3 3 3 3 3 3 3 4 3 3 3\n"
			"      3 3 3 3 3 4 3 3 4 3 3 4 3 3 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"      3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n"
			"    </universes>\n"
			"  </lattice>\n"
			"\n"
			"  <!-- Core Lattice (Lower Half) -->\n"
			"  <lattice id=\"200\">\n"
			"    <type>rectangular</type>\n"
			"    <dimension>21 21</dimension>\n"
			"    <lower_left>-224.91 -224.91</lower_left>\n"
			"    <width>21.42 21.42</width>\n"
			"    <universes>\n"
			"      5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n"
			"      5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n"
			"      5 5 5 5 5 5 5 6 6 6 6 6 6 6 5 5 5 5 5 5 5\n"
			"      5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 5 5 5 5 5\n"
			"      5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5 5\n"
			"      5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5\n"
			"      5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5\n"
			"      5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5\n"
			"      5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5\n"
			"      5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 5 5 5 5\n"
			"      5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 5 5 5 5 5\n"
			"      5 5 5 5 5 5 5 6 6 6 6 6 6 6 5 5 5 5 5 5 5\n"
			"      5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n"
			"      5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5\n"
			"    </universes>\n"
			"  </lattice>\n"
			"\n"
			"  <!-- Core Lattice (Upper Half) -->\n"
			"  <lattice id=\"201\">\n"
			"    <type>rectangular</type>\n"
			"    <dimension>21 21</dimension>\n"
			"    <lower_left>-224.91 -224.91</lower_left>\n"
			"    <width>21.42 21.42</width>\n"
			"    <universes>\n"
			"      7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7\n"
			"      7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7\n"
			"      7 7 7 7 7 7 7 8 8 8 8 8 8 8 7 7 7 7 7 7 7\n"
			"      7 7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 7 7 7 7 7\n"
			"      7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7 7\n"
			"      7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7\n"
			"      7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7\n"
			"      7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7\n"
			"      7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7\n"
			"      7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 7 7 7 7\n"
			"      7 7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 7 7 7 7 7\n"
			"      7 7 7 7 7 7 7 8 8 8 8 8 8 8 7 7 7 7 7 7 7\n"
			"      7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7\n"
			"      7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7\n"
			"    </universes>\n"
			"  </lattice>\n"
			"\n"
			);
	fclose(fp);	
}

// prints 636,240 radial fuel rings
void print_reactor( void )
{
	int ct = 0;
	double ll_x = -8 * 21.42;
	double ll_y = -8 * 21.42;

	for( int x = 0; x < 17; x++ )
	{	
		for( int y = 0; y < 17; y++ )
		{
			int ok = 0;

			if( x == 0 || x == 16 )
				if( y >= 5 && y <= 11 )
					ok = 1;

			if( x == 1 || x == 15 )
				if( y >= 3 && y <= 13 )
					ok = 1;

			if( x == 2 || x == 14 )
				if( y >= 2 && y <= 14 )
					ok = 1;

			if( x == 3 || x == 4 || x == 13 || x == 12 )
				if( y >= 1 && y <= 15 )
					ok = 1;

			if( x >= 5 && x <= 11 )
				ok = 1;

			if( ok == 1 )
			{
				ct++;
				print_assembly( ll_x + x * 21.42, ll_y + y * 21.42 );
			}
		}
	}

	printf("Printed %d Fuel Assemblies\n", ct);
	printf("Printed %d Cells\n", ct * 2640);
}

// prints 2640 cells and surfaces
void print_assembly( double c_x, double c_y )
{
	FILE * fp = fopen("geometry.xml", "a");

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
