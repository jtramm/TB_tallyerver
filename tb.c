#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_assembly( double c_x, double c_y );
void print_reactor( void );
void print_geom_header( void );
void print_geom_footer( void );

void print_tallies_header( void );
void print_tallies_multiline( void );
void print_tallies_single( int );
void print_tallies_footer( void );

int id;
int n_assemblies;

int main(int argc, char * argv[])
{
	int Large = 0;
	// Reads in the number of assemblies to print
	// Max is 241 (i.e., H-M model size)
	if( argc == 2 )
	{
		n_assemblies = atoi( argv[1] );
		if( n_assemblies < 1 )
			n_assemblies = 1;
		if( n_assemblies > 241 )
			n_assemblies = 241;
	}
	else if( argc == 3 )
	{
		n_assemblies = atoi( argv[1] );
		
		if( n_assemblies < 1 )
			n_assemblies = 1;
		if( n_assemblies > 241 )
			n_assemblies = 241;
		
		if( strcmp( "large", argv[2] ) == 0 || strcmp( "Large", argv[2] ) == 0 )
			Large = 1;
	}
	else
		n_assemblies = 241;

	id = 100;

	// Generates geometry.xml input file
	print_geom_header();
	print_reactor();
	print_geom_footer();

	// Generates tallies.xml input file
	print_tallies_header();
	print_tallies_single(Large);
	print_tallies_footer();

	if( Large == 0 )
		printf("H-M Small Benchmark\n");
	else
		printf("H-M Large Benchmark\n");

	return 0;
}

void print_tallies_single( int Large )
{
	FILE * fp = fopen("tallies.xml", "a");
	int tally = 1;
	
	for( int i = 100; i < 100 + 2640 * n_assemblies; i++ )
	{	
		// H-M Small model (33 fuel nuclides)
		if( Large == 0 )
			fprintf(fp,		
					"<tally id=\"%d\">\n"
					"<filter type=\"mesh\" bins=\"1\" />\n"
					"<filter type=\"cell\" bins=\"%d\"/>\n"
					"<scores>scatter nu-scatter absorption fission nu-fission kappa-fission</scores>\n"
					"<nuclides>U-234 U-235 U-236 U-238 Np-237 Pu-238 Pu-239 Pu-240 Pu-241 Pu-242 Am-241 Am-242m Am-243 Cm-242 Cm-244 Mo-95 Tc-99 Ru-101 Ru-103 Ag-109 Xe-135 Cs-133 Nd-143 Nd-145 Sm-147 Sm-149 Sm-150 Sm-151 Sm-152 Eu-153 Gd-155 O-16</nuclides>\n"
					"</tally>\n",
					tally++,i
					);
		// H-M Large Model (321 fuel nuclides)
		else
			fprintf(fp,		
					"<tally id=\"%d\">\n"
					"<filter type=\"mesh\" bins=\"1\" />\n"
					"<filter type=\"cell\" bins=\"%d\"/>\n"
					"<scores>scatter nu-scatter absorption fission nu-fission kappa-fission</scores>\n"
					"<nuclides>U-234 U-235 U-236 U-238 O-16 Th-227 Th-228 Th-229 Th-230 Th-232 Th-233 Th-234 Pa-231 Pa-232 Pa-233 U-232 U-233 U-237 U-239 U-240 U-241 Np-235 Np-236 Np-237 Np-238 Np-239 Pu-236 Pu-237 Pu-238 Pu-239 Pu-240 Pu-241 Pu-242 Pu-243 Pu-244 Pu-246 Am-241 Am-242 Am-242m Am-243 Am-244 Am-244m Cm-241 Cm-242 Cm-243 Cm-244 Cm-245 Cm-246 Cm-247 Cm-248 Cm-249 Cm-250 Bk-249 Bk-250 Cf-249 Cf-250 Cf-251 Cf-252 Cf-254 Es-254 Es-255 Fm-255 S-32 S-33 S-34 S-36 Cl-35 Cl-37 K-39 K-40 K-41 Ca-40 Ca-42 Ca-43 Ca-44 Ca-46 Ca-48 Sc-45 Ti-46 Ti-47 Ti-48 Ti-49 Ti-50 V-Nat Co-59 Zn-Nat Ga-69 Ga-71 Ge-70 Ge-72 Ge-73 Ge-74 Ge-76 As-74 As-75 Se-74 Se-76 Se-77 Se-78 Se-79 Se-80 Se-82 Br-79 Br-81 Kr-78 Kr-80 Kr-82 Kr-83 Kr-84 Kr-85 Kr-86 Rb-85 Rb-86 Rb-87 Sr-84 Sr-86 Sr-87 Sr-88 Sr-89 Sr-90 Y-89 Y-90 Y-91 Zr-93 Zr-95 Nb-93 Nb-94 Nb-95 Mo-99 Tc-99 Ru-96 Ru-98 Ru-99 Ru-100 Ru-101 Ru-102 Ru-103 Ru-104 Ru-105 Ru-106 Rh-103 Rh-105 Pd-102 Pd-104 Pd-105 Pd-106 Pd-107 Pd-108 Pd-110 Ag-107 Ag-109 Ag-110m Ag-111 Cd-106 Cd-108 Cd-110 Cd-111 Cd-112 Cd-113 Cd-114 Cd-115m Cd-116 In-113 In-115 Sn-112 Sn-113 Sn-114 Sn-115 Sn-116 Sn-117 Sn-118 Sn-119 Sn-120 Sn-122 Sn-123 Sn-124 Sn-125 Sn-126 Sb-121 Sb-123 Sb-124 Sb-125 Sb-126 Te-122 Te-123 Te-124 Te-125 Te-126 Te-127m Te-128 Te-129m Te-130 Te-132 I-127 I-129 I-130 I-131 I-135 Xe-123 Xe-124 Xe-126 Xe-128 Xe-129 Xe-130 Xe-131 Xe-132 Xe-133 Xe-134 Xe-135 Xe-136 Cs-133 Cs-134 Cs-135 Cs-136 Cs-137 Ba-130 Ba-132 Ba-133 Ba-134 Ba-135 Ba-136 Ba-137 Ba-138 Ba-140 La-138 La-139 La-140 Ce-136 Ce-138 Ce-139 Ce-140 Ce-141 Ce-142 Ce-143 Ce-144 Pr-141 Pr-142 Pr-143 Nd-142 Nd-143 Nd-144 Nd-145 Nd-146 Nd-147 Nd-148 Nd-150 Pm-147 Pm-148 Pm-148m Pm-149 Pm-151 Sm-147 Sm-148 Sm-149 Sm-150 Sm-151 Sm-152 Sm-153 Sm-154 Eu-151 Eu-152 Eu-153 Eu-154 Eu-155 Eu-156 Eu-157 Gd-152 Gd-153 Gd-154 Gd-155 Gd-156 Gd-157 Gd-158 Gd-160 Tb-159 Tb-160 Dy-156 Dy-158 Dy-160 Dy-161 Dy-162 Dy-163 Dy-164 Ho-165 Ho-166m Er-162 Er-164 Er-166 Er-167 Er-168 Er-170 Lu-175 Lu-176 Hf-174 Hf-176 Hf-177 Hf-178 Hf-179 Hf-180 Ta-181 Ta-182 W-182 W-183 W-184 W-186 Re-185 Re-187 Ir-191 Ir-193 Au-197 Hg-196 Hg-198 Hg-199 Hg-200 Hg-201 Hg-202 Hg-204 Pb-204 Pb-206 Pb-207 Pb-208</nuclides>\n"
					"</tally>\n",
					tally++,i
					);
	}
	
	fclose(fp);
	
	printf("printed %d tallies.\n", 2640 * n_assemblies);
}	

void print_tallies_header( void )
{
	FILE * fp = fopen("tallies.xml", "w+");
	fprintf(fp,
			"<?xml version=\"1.0\"?>\n"
			"<tallies>\n"
			"	<mesh id=\"1\">\n"
			"<type>rectangular</type>\n"
			"<lower_left>-182.07 -182.07 -183.00</lower_left>\n"
			"<upper_right>182.07  182.07  183.00</upper_right>\n"
			"<dimension>1 1 100</dimension>\n"
			"</mesh>\n\n"
		   );
	fclose(fp);
}

void print_tallies_footer( void )
{
	FILE * fp = fopen("tallies.xml", "a");
	fprintf(fp,"</tallies>");
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
	FILE * fp = fopen("geometry.xml", "w+");
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
	double ll_x = -8 * 21.42;
	double ll_y = -8 * 21.42;
	int assemblies_printed = 0;

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
				print_assembly( ll_x + x * 21.42, ll_y + y * 21.42 );
				assemblies_printed++;
			}
			
			if( assemblies_printed == n_assemblies )
				break;
		}
		
		if( assemblies_printed == n_assemblies )
			break;
	}

	printf("Printed %d Fuel Assemblies\n", assemblies_printed);
	printf("Printed %d Cells\n", assemblies_printed * 2640);
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

// This method was originally suggested to save space in the input file,
// but was found not to actually work with the current XML reader. The
// XML reader is only capable of reading ~50 bins in a single filter.

/*
void print_tallies_multiline( void )
{
	FILE * fp = fopen("tallies.xml", "a");
	fprintf(fp,		
			"<tally id=\"1\">\n"
			"<filter type=\"mesh\" bins=\"1\" />\n"
			"<filter type=\"cell\" bins=\"\n"
			);
	if( SHORT_TALLY == 0 )
		for( int i = 100; i < 636340; i++ )
		{	
			if( i % 5 == 0 && i != 100 )
				fprintf(fp, "\n");
			fprintf(fp, "%d ", i);
		}
	else
		for( int i = 100; i < 2740; i++ )
		{	
			if( i % 5 == 0 && i != 100 )
				fprintf(fp, "\n");
			fprintf(fp, "%d ", i);
		}
	
	fprintf(fp, "\"/>\n<scores>nu-fission</scores>\n");
	fprintf(fp,"</tally>\n");
	
	fclose(fp);
	
	if( SHORT_TALLY == 0 )
		printf("printed 636240 tallies.\n");
	else
		printf("printed 2640 tallies.\n");
	
}
*/
