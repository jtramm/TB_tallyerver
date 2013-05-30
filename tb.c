#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_assembly( double c_x, double c_y );
void print_reactor( void );
void print_geom_header( void );
void print_geom_footer( void );

void print_tallies_header( void );
void print_tallies_multiline( void );
void print_tallies_single( int, char ** );
void print_tallies_footer( void );

int id;
int n_assemblies;

int main(int argc, char * argv[])
{
	char * str[320];
	str[0] = "U-234";
	str[1] = "U-235";
	str[2] = "U-236";
	str[3] = "U-238";
	str[4] = "O-16";
	str[5] = "Th-227";
	str[6] = "Th-228";
	str[7] = "Th-229";
	str[8] = "Th-230";
	str[9] = "Th-232";
	str[10] = "Th-233";
	str[11] = "Th-234";
	str[12] = "Pa-231";
	str[13] = "Pa-232";
	str[14] = "Pa-233";
	str[15] = "U-232";
	str[16] = "U-233";
	str[17] = "U-237";
	str[18] = "U-239";
	str[19] = "U-240";
	str[20] = "U-241";
	str[21] = "Np-235";
	str[22] = "Np-236";
	str[23] = "Np-237";
	str[24] = "Np-238";
	str[25] = "Np-239";
	str[26] = "Pu-236";
	str[27] = "Pu-237";
	str[28] = "Pu-238";
	str[29] = "Pu-239";
	str[30] = "Pu-240";
	str[31] = "Pu-241";
	str[32] = "Pu-242";
	str[33] = "Pu-243";
	str[34] = "Pu-244";
	str[35] = "Pu-246";
	str[36] = "Am-241";
	str[37] = "Am-242";
	str[38] = "Am-242m";
	str[39] = "Am-243";
	str[40] = "Am-244";
	str[41] = "Am-244m";
	str[42] = "Cm-241";
	str[43] = "Cm-242";
	str[44] = "Cm-243";
	str[45] = "Cm-244";
	str[46] = "Cm-245";
	str[47] = "Cm-246";
	str[48] = "Cm-247";
	str[49] = "Cm-248";
	str[50] = "Cm-249";
	str[51] = "Cm-250";
	str[52] = "Bk-249";
	str[53] = "Bk-250";
	str[54] = "Cf-249";
	str[55] = "Cf-250";
	str[56] = "Cf-251";
	str[57] = "Cf-252";
	str[58] = "Cf-254";
	str[59] = "Es-254";
	str[60] = "Es-255";
	str[61] = "Fm-255";
	str[62] = "S-32";
	str[63] = "S-33";
	str[64] = "S-34";
	str[65] = "S-36";
	str[66] = "Cl-35";
	str[67] = "Cl-37";
	str[68] = "K-39";
	str[69] = "K-40";
	str[70] = "K-41";
	str[71] = "Ca-40";
	str[72] = "Ca-42";
	str[73] = "Ca-43";
	str[74] = "Ca-44";
	str[75] = "Ca-46";
	str[76] = "Ca-48";
	str[77] = "Sc-45";
	str[78] = "Ti-46";
	str[79] = "Ti-47";
	str[80] = "Ti-48";
	str[81] = "Ti-49";
	str[82] = "Ti-50";
	str[83] = "V-Nat";
	str[84] = "Co-59";
	str[85] = "Zn-Nat";
	str[86] = "Ga-69";
	str[87] = "Ga-71";
	str[88] = "Ge-70";
	str[89] = "Ge-72";
	str[90] = "Ge-73";
	str[91] = "Ge-74";
	str[92] = "Ge-76";
	str[93] = "As-74";
	str[94] = "As-75";
	str[95] = "Se-74";
	str[96] = "Se-76";
	str[97] = "Se-77";
	str[98] = "Se-78";
	str[99] = "Se-79";
	str[100] = "Se-80";
	str[101] = "Se-82";
	str[102] = "Br-79";
	str[103] = "Br-81";
	str[104] = "Kr-78";
	str[105] = "Kr-80";
	str[106] = "Kr-82";
	str[107] = "Kr-83";
	str[108] = "Kr-84";
	str[109] = "Kr-85";
	str[110] = "Kr-86";
	str[111] = "Rb-85";
	str[112] = "Rb-86";
	str[113] = "Rb-87";
	str[114] = "Sr-84";
	str[115] = "Sr-86";
	str[116] = "Sr-87";
	str[117] = "Sr-88";
	str[118] = "Sr-89";
	str[119] = "Sr-90";
	str[120] = "Y-89";
	str[121] = "Y-90";
	str[122] = "Y-91";
	str[123] = "Zr-93";
	str[124] = "Zr-95";
	str[125] = "Nb-93";
	str[126] = "Nb-94";
	str[127] = "Nb-95";
	str[128] = "Mo-99";
	str[129] = "Tc-99";
	str[130] = "Ru-96";
	str[131] = "Ru-98";
	str[132] = "Ru-99";
	str[133] = "Ru-100";
	str[134] = "Ru-101";
	str[135] = "Ru-102";
	str[136] = "Ru-103";
	str[137] = "Ru-104";
	str[138] = "Ru-105";
	str[139] = "Ru-106";
	str[140] = "Rh-103";
	str[141] = "Rh-105";
	str[142] = "Pd-102";
	str[143] = "Pd-104";
	str[144] = "Pd-105";
	str[145] = "Pd-106";
	str[146] = "Pd-107";
	str[147] = "Pd-108";
	str[148] = "Pd-110";
	str[149] = "Ag-107";
	str[150] = "Ag-109";
	str[151] = "Ag-110m";
	str[152] = "Ag-111";
	str[153] = "Cd-106";
	str[154] = "Cd-108";
	str[155] = "Cd-110";
	str[156] = "Cd-111";
	str[157] = "Cd-112";
	str[158] = "Cd-113";
	str[159] = "Cd-114";
	str[160] = "Cd-115m";
	str[161] = "Cd-116";
	str[162] = "In-113";
	str[163] = "In-115";
	str[164] = "Sn-112";
	str[165] = "Sn-113";
	str[166] = "Sn-114";
	str[167] = "Sn-115";
	str[168] = "Sn-116";
	str[169] = "Sn-117";
	str[170] = "Sn-118";
	str[171] = "Sn-119";
	str[172] = "Sn-120";
	str[173] = "Sn-122";
	str[174] = "Sn-123";
	str[175] = "Sn-124";
	str[176] = "Sn-125";
	str[177] = "Sn-126";
	str[178] = "Sb-121";
	str[179] = "Sb-123";
	str[180] = "Sb-124";
	str[181] = "Sb-125";
	str[182] = "Sb-126";
	str[183] = "Te-122";
	str[184] = "Te-123";
	str[185] = "Te-124";
	str[186] = "Te-125";
	str[187] = "Te-126";
	str[188] = "Te-127m";
	str[189] = "Te-128";
	str[190] = "Te-129m";
	str[191] = "Te-130";
	str[192] = "Te-132";
	str[193] = "I-127";
	str[194] = "I-129";
	str[195] = "I-130";
	str[196] = "I-131";
	str[197] = "I-135";
	str[198] = "Xe-123";
	str[199] = "Xe-124";
	str[200] = "Xe-126";
	str[201] = "Xe-128";
	str[202] = "Xe-129";
	str[203] = "Xe-130";
	str[204] = "Xe-131";
	str[205] = "Xe-132";
	str[206] = "Xe-133";
	str[207] = "Xe-134";
	str[208] = "Xe-135";
	str[209] = "Xe-136";
	str[210] = "Cs-133";
	str[211] = "Cs-134";
	str[212] = "Cs-135";
	str[213] = "Cs-136";
	str[214] = "Cs-137";
	str[215] = "Ba-130";
	str[216] = "Ba-132";
	str[217] = "Ba-133";
	str[218] = "Ba-134";
	str[219] = "Ba-135";
	str[220] = "Ba-136";
	str[221] = "Ba-137";
	str[222] = "Ba-138";
	str[223] = "Ba-140";
	str[224] = "La-138";
	str[225] = "La-139";
	str[226] = "La-140";
	str[227] = "Ce-136";
	str[228] = "Ce-138";
	str[229] = "Ce-139";
	str[230] = "Ce-140";
	str[231] = "Ce-141";
	str[232] = "Ce-142";
	str[233] = "Ce-143";
	str[234] = "Ce-144";
	str[235] = "Pr-141";
	str[236] = "Pr-142";
	str[237] = "Pr-143";
	str[238] = "Nd-142";
	str[239] = "Nd-143";
	str[240] = "Nd-144";
	str[241] = "Nd-145";
	str[242] = "Nd-146";
	str[243] = "Nd-147";
	str[244] = "Nd-148";
	str[245] = "Nd-150";
	str[246] = "Pm-147";
	str[247] = "Pm-148";
	str[248] = "Pm-148m";
	str[249] = "Pm-149";
	str[250] = "Pm-151";
	str[251] = "Sm-147";
	str[252] = "Sm-148";
	str[253] = "Sm-149";
	str[254] = "Sm-150";
	str[255] = "Sm-151";
	str[256] = "Sm-152";
	str[257] = "Sm-153";
	str[258] = "Sm-154";
	str[259] = "Eu-151";
	str[260] = "Eu-152";
	str[261] = "Eu-153";
	str[262] = "Eu-154";
	str[263] = "Eu-155";
	str[264] = "Eu-156";
	str[265] = "Eu-157";
	str[266] = "Gd-152";
	str[267] = "Gd-153";
	str[268] = "Gd-154";
	str[269] = "Gd-155";
	str[270] = "Gd-156";
	str[271] = "Gd-157";
	str[272] = "Gd-158";
	str[273] = "Gd-160";
	str[274] = "Tb-159";
	str[275] = "Tb-160";
	str[276] = "Dy-156";
	str[277] = "Dy-158";
	str[278] = "Dy-160";
	str[279] = "Dy-161";
	str[280] = "Dy-162";
	str[281] = "Dy-163";
	str[282] = "Dy-164";
	str[283] = "Ho-165";
	str[284] = "Ho-166m";
	str[285] = "Er-162";
	str[286] = "Er-164";
	str[287] = "Er-166";
	str[288] = "Er-167";
	str[289] = "Er-168";
	str[290] = "Er-170";
	str[291] = "Lu-175";
	str[292] = "Lu-176";
	str[293] = "Hf-174";
	str[294] = "Hf-176";
	str[295] = "Hf-177";
	str[296] = "Hf-178";
	str[297] = "Hf-179";
	str[298] = "Hf-180";
	str[299] = "Ta-181";
	str[300] = "Ta-182";
	str[301] = "W-182";
	str[302] = "W-183";
	str[303] = "W-184";
	str[304] = "W-186";
	str[305] = "Re-185";
	str[306] = "Re-187";
	str[307] = "Ir-191";
	str[308] = "Ir-193";
	str[309] = "Au-197";
	str[310] = "Hg-196";
	str[311] = "Hg-198";
	str[312] = "Hg-199";
	str[313] = "Hg-200";
	str[314] = "Hg-201";
	str[315] = "Hg-202";
	str[316] = "Hg-204";
	str[317] = "Pb-204";
	str[318] = "Pb-206";
	str[319] = "Pb-207";
	str[320] = "Pb-208";
	
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
	print_tallies_single(Large, str);
	print_tallies_footer();

	if( Large == 0 )
		printf("H-M Small Benchmark\n");
	else
		printf("H-M Large Benchmark\n");

	return 0;
}

void print_tallies_single( int Large, char * str[] )
{
	FILE * fp = fopen("tallies.xml", "a");
	int tally = 1;
	int n_per_t = 33;

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
		{
			int printed = 0;
			// outer loop prints variable number of tallies, based on nuclides per tally
			for( int j = 0; j < 320 / n_per_t; j++ )
			{
				fprintf(fp,		
						"<tally id=\"%d\">\n"
						"<filter type=\"mesh\" bins=\"1\" />\n"
						"<filter type=\"cell\" bins=\"%d\"/>\n"
						"<scores>scatter nu-scatter absorption fission nu-fission kappa-fission</scores>\n"
						"<nuclides>",
						tally++,i
					   );
				// inner loop prints nuclides, based on nuclides per tally
				for( int k = 0; k < n_per_t; k++ )
					if( printed < 320 )
						fprintf(fp,"%s ", str[printed++]);
				fprintf(fp,		
						"</nuclides>"
						"</tally>\n"
					   );
			}
		}
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
