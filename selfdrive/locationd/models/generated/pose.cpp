#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3527959792166280959) {
   out_3527959792166280959[0] = delta_x[0] + nom_x[0];
   out_3527959792166280959[1] = delta_x[1] + nom_x[1];
   out_3527959792166280959[2] = delta_x[2] + nom_x[2];
   out_3527959792166280959[3] = delta_x[3] + nom_x[3];
   out_3527959792166280959[4] = delta_x[4] + nom_x[4];
   out_3527959792166280959[5] = delta_x[5] + nom_x[5];
   out_3527959792166280959[6] = delta_x[6] + nom_x[6];
   out_3527959792166280959[7] = delta_x[7] + nom_x[7];
   out_3527959792166280959[8] = delta_x[8] + nom_x[8];
   out_3527959792166280959[9] = delta_x[9] + nom_x[9];
   out_3527959792166280959[10] = delta_x[10] + nom_x[10];
   out_3527959792166280959[11] = delta_x[11] + nom_x[11];
   out_3527959792166280959[12] = delta_x[12] + nom_x[12];
   out_3527959792166280959[13] = delta_x[13] + nom_x[13];
   out_3527959792166280959[14] = delta_x[14] + nom_x[14];
   out_3527959792166280959[15] = delta_x[15] + nom_x[15];
   out_3527959792166280959[16] = delta_x[16] + nom_x[16];
   out_3527959792166280959[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1197198609640831537) {
   out_1197198609640831537[0] = -nom_x[0] + true_x[0];
   out_1197198609640831537[1] = -nom_x[1] + true_x[1];
   out_1197198609640831537[2] = -nom_x[2] + true_x[2];
   out_1197198609640831537[3] = -nom_x[3] + true_x[3];
   out_1197198609640831537[4] = -nom_x[4] + true_x[4];
   out_1197198609640831537[5] = -nom_x[5] + true_x[5];
   out_1197198609640831537[6] = -nom_x[6] + true_x[6];
   out_1197198609640831537[7] = -nom_x[7] + true_x[7];
   out_1197198609640831537[8] = -nom_x[8] + true_x[8];
   out_1197198609640831537[9] = -nom_x[9] + true_x[9];
   out_1197198609640831537[10] = -nom_x[10] + true_x[10];
   out_1197198609640831537[11] = -nom_x[11] + true_x[11];
   out_1197198609640831537[12] = -nom_x[12] + true_x[12];
   out_1197198609640831537[13] = -nom_x[13] + true_x[13];
   out_1197198609640831537[14] = -nom_x[14] + true_x[14];
   out_1197198609640831537[15] = -nom_x[15] + true_x[15];
   out_1197198609640831537[16] = -nom_x[16] + true_x[16];
   out_1197198609640831537[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6529698547862638487) {
   out_6529698547862638487[0] = 1.0;
   out_6529698547862638487[1] = 0.0;
   out_6529698547862638487[2] = 0.0;
   out_6529698547862638487[3] = 0.0;
   out_6529698547862638487[4] = 0.0;
   out_6529698547862638487[5] = 0.0;
   out_6529698547862638487[6] = 0.0;
   out_6529698547862638487[7] = 0.0;
   out_6529698547862638487[8] = 0.0;
   out_6529698547862638487[9] = 0.0;
   out_6529698547862638487[10] = 0.0;
   out_6529698547862638487[11] = 0.0;
   out_6529698547862638487[12] = 0.0;
   out_6529698547862638487[13] = 0.0;
   out_6529698547862638487[14] = 0.0;
   out_6529698547862638487[15] = 0.0;
   out_6529698547862638487[16] = 0.0;
   out_6529698547862638487[17] = 0.0;
   out_6529698547862638487[18] = 0.0;
   out_6529698547862638487[19] = 1.0;
   out_6529698547862638487[20] = 0.0;
   out_6529698547862638487[21] = 0.0;
   out_6529698547862638487[22] = 0.0;
   out_6529698547862638487[23] = 0.0;
   out_6529698547862638487[24] = 0.0;
   out_6529698547862638487[25] = 0.0;
   out_6529698547862638487[26] = 0.0;
   out_6529698547862638487[27] = 0.0;
   out_6529698547862638487[28] = 0.0;
   out_6529698547862638487[29] = 0.0;
   out_6529698547862638487[30] = 0.0;
   out_6529698547862638487[31] = 0.0;
   out_6529698547862638487[32] = 0.0;
   out_6529698547862638487[33] = 0.0;
   out_6529698547862638487[34] = 0.0;
   out_6529698547862638487[35] = 0.0;
   out_6529698547862638487[36] = 0.0;
   out_6529698547862638487[37] = 0.0;
   out_6529698547862638487[38] = 1.0;
   out_6529698547862638487[39] = 0.0;
   out_6529698547862638487[40] = 0.0;
   out_6529698547862638487[41] = 0.0;
   out_6529698547862638487[42] = 0.0;
   out_6529698547862638487[43] = 0.0;
   out_6529698547862638487[44] = 0.0;
   out_6529698547862638487[45] = 0.0;
   out_6529698547862638487[46] = 0.0;
   out_6529698547862638487[47] = 0.0;
   out_6529698547862638487[48] = 0.0;
   out_6529698547862638487[49] = 0.0;
   out_6529698547862638487[50] = 0.0;
   out_6529698547862638487[51] = 0.0;
   out_6529698547862638487[52] = 0.0;
   out_6529698547862638487[53] = 0.0;
   out_6529698547862638487[54] = 0.0;
   out_6529698547862638487[55] = 0.0;
   out_6529698547862638487[56] = 0.0;
   out_6529698547862638487[57] = 1.0;
   out_6529698547862638487[58] = 0.0;
   out_6529698547862638487[59] = 0.0;
   out_6529698547862638487[60] = 0.0;
   out_6529698547862638487[61] = 0.0;
   out_6529698547862638487[62] = 0.0;
   out_6529698547862638487[63] = 0.0;
   out_6529698547862638487[64] = 0.0;
   out_6529698547862638487[65] = 0.0;
   out_6529698547862638487[66] = 0.0;
   out_6529698547862638487[67] = 0.0;
   out_6529698547862638487[68] = 0.0;
   out_6529698547862638487[69] = 0.0;
   out_6529698547862638487[70] = 0.0;
   out_6529698547862638487[71] = 0.0;
   out_6529698547862638487[72] = 0.0;
   out_6529698547862638487[73] = 0.0;
   out_6529698547862638487[74] = 0.0;
   out_6529698547862638487[75] = 0.0;
   out_6529698547862638487[76] = 1.0;
   out_6529698547862638487[77] = 0.0;
   out_6529698547862638487[78] = 0.0;
   out_6529698547862638487[79] = 0.0;
   out_6529698547862638487[80] = 0.0;
   out_6529698547862638487[81] = 0.0;
   out_6529698547862638487[82] = 0.0;
   out_6529698547862638487[83] = 0.0;
   out_6529698547862638487[84] = 0.0;
   out_6529698547862638487[85] = 0.0;
   out_6529698547862638487[86] = 0.0;
   out_6529698547862638487[87] = 0.0;
   out_6529698547862638487[88] = 0.0;
   out_6529698547862638487[89] = 0.0;
   out_6529698547862638487[90] = 0.0;
   out_6529698547862638487[91] = 0.0;
   out_6529698547862638487[92] = 0.0;
   out_6529698547862638487[93] = 0.0;
   out_6529698547862638487[94] = 0.0;
   out_6529698547862638487[95] = 1.0;
   out_6529698547862638487[96] = 0.0;
   out_6529698547862638487[97] = 0.0;
   out_6529698547862638487[98] = 0.0;
   out_6529698547862638487[99] = 0.0;
   out_6529698547862638487[100] = 0.0;
   out_6529698547862638487[101] = 0.0;
   out_6529698547862638487[102] = 0.0;
   out_6529698547862638487[103] = 0.0;
   out_6529698547862638487[104] = 0.0;
   out_6529698547862638487[105] = 0.0;
   out_6529698547862638487[106] = 0.0;
   out_6529698547862638487[107] = 0.0;
   out_6529698547862638487[108] = 0.0;
   out_6529698547862638487[109] = 0.0;
   out_6529698547862638487[110] = 0.0;
   out_6529698547862638487[111] = 0.0;
   out_6529698547862638487[112] = 0.0;
   out_6529698547862638487[113] = 0.0;
   out_6529698547862638487[114] = 1.0;
   out_6529698547862638487[115] = 0.0;
   out_6529698547862638487[116] = 0.0;
   out_6529698547862638487[117] = 0.0;
   out_6529698547862638487[118] = 0.0;
   out_6529698547862638487[119] = 0.0;
   out_6529698547862638487[120] = 0.0;
   out_6529698547862638487[121] = 0.0;
   out_6529698547862638487[122] = 0.0;
   out_6529698547862638487[123] = 0.0;
   out_6529698547862638487[124] = 0.0;
   out_6529698547862638487[125] = 0.0;
   out_6529698547862638487[126] = 0.0;
   out_6529698547862638487[127] = 0.0;
   out_6529698547862638487[128] = 0.0;
   out_6529698547862638487[129] = 0.0;
   out_6529698547862638487[130] = 0.0;
   out_6529698547862638487[131] = 0.0;
   out_6529698547862638487[132] = 0.0;
   out_6529698547862638487[133] = 1.0;
   out_6529698547862638487[134] = 0.0;
   out_6529698547862638487[135] = 0.0;
   out_6529698547862638487[136] = 0.0;
   out_6529698547862638487[137] = 0.0;
   out_6529698547862638487[138] = 0.0;
   out_6529698547862638487[139] = 0.0;
   out_6529698547862638487[140] = 0.0;
   out_6529698547862638487[141] = 0.0;
   out_6529698547862638487[142] = 0.0;
   out_6529698547862638487[143] = 0.0;
   out_6529698547862638487[144] = 0.0;
   out_6529698547862638487[145] = 0.0;
   out_6529698547862638487[146] = 0.0;
   out_6529698547862638487[147] = 0.0;
   out_6529698547862638487[148] = 0.0;
   out_6529698547862638487[149] = 0.0;
   out_6529698547862638487[150] = 0.0;
   out_6529698547862638487[151] = 0.0;
   out_6529698547862638487[152] = 1.0;
   out_6529698547862638487[153] = 0.0;
   out_6529698547862638487[154] = 0.0;
   out_6529698547862638487[155] = 0.0;
   out_6529698547862638487[156] = 0.0;
   out_6529698547862638487[157] = 0.0;
   out_6529698547862638487[158] = 0.0;
   out_6529698547862638487[159] = 0.0;
   out_6529698547862638487[160] = 0.0;
   out_6529698547862638487[161] = 0.0;
   out_6529698547862638487[162] = 0.0;
   out_6529698547862638487[163] = 0.0;
   out_6529698547862638487[164] = 0.0;
   out_6529698547862638487[165] = 0.0;
   out_6529698547862638487[166] = 0.0;
   out_6529698547862638487[167] = 0.0;
   out_6529698547862638487[168] = 0.0;
   out_6529698547862638487[169] = 0.0;
   out_6529698547862638487[170] = 0.0;
   out_6529698547862638487[171] = 1.0;
   out_6529698547862638487[172] = 0.0;
   out_6529698547862638487[173] = 0.0;
   out_6529698547862638487[174] = 0.0;
   out_6529698547862638487[175] = 0.0;
   out_6529698547862638487[176] = 0.0;
   out_6529698547862638487[177] = 0.0;
   out_6529698547862638487[178] = 0.0;
   out_6529698547862638487[179] = 0.0;
   out_6529698547862638487[180] = 0.0;
   out_6529698547862638487[181] = 0.0;
   out_6529698547862638487[182] = 0.0;
   out_6529698547862638487[183] = 0.0;
   out_6529698547862638487[184] = 0.0;
   out_6529698547862638487[185] = 0.0;
   out_6529698547862638487[186] = 0.0;
   out_6529698547862638487[187] = 0.0;
   out_6529698547862638487[188] = 0.0;
   out_6529698547862638487[189] = 0.0;
   out_6529698547862638487[190] = 1.0;
   out_6529698547862638487[191] = 0.0;
   out_6529698547862638487[192] = 0.0;
   out_6529698547862638487[193] = 0.0;
   out_6529698547862638487[194] = 0.0;
   out_6529698547862638487[195] = 0.0;
   out_6529698547862638487[196] = 0.0;
   out_6529698547862638487[197] = 0.0;
   out_6529698547862638487[198] = 0.0;
   out_6529698547862638487[199] = 0.0;
   out_6529698547862638487[200] = 0.0;
   out_6529698547862638487[201] = 0.0;
   out_6529698547862638487[202] = 0.0;
   out_6529698547862638487[203] = 0.0;
   out_6529698547862638487[204] = 0.0;
   out_6529698547862638487[205] = 0.0;
   out_6529698547862638487[206] = 0.0;
   out_6529698547862638487[207] = 0.0;
   out_6529698547862638487[208] = 0.0;
   out_6529698547862638487[209] = 1.0;
   out_6529698547862638487[210] = 0.0;
   out_6529698547862638487[211] = 0.0;
   out_6529698547862638487[212] = 0.0;
   out_6529698547862638487[213] = 0.0;
   out_6529698547862638487[214] = 0.0;
   out_6529698547862638487[215] = 0.0;
   out_6529698547862638487[216] = 0.0;
   out_6529698547862638487[217] = 0.0;
   out_6529698547862638487[218] = 0.0;
   out_6529698547862638487[219] = 0.0;
   out_6529698547862638487[220] = 0.0;
   out_6529698547862638487[221] = 0.0;
   out_6529698547862638487[222] = 0.0;
   out_6529698547862638487[223] = 0.0;
   out_6529698547862638487[224] = 0.0;
   out_6529698547862638487[225] = 0.0;
   out_6529698547862638487[226] = 0.0;
   out_6529698547862638487[227] = 0.0;
   out_6529698547862638487[228] = 1.0;
   out_6529698547862638487[229] = 0.0;
   out_6529698547862638487[230] = 0.0;
   out_6529698547862638487[231] = 0.0;
   out_6529698547862638487[232] = 0.0;
   out_6529698547862638487[233] = 0.0;
   out_6529698547862638487[234] = 0.0;
   out_6529698547862638487[235] = 0.0;
   out_6529698547862638487[236] = 0.0;
   out_6529698547862638487[237] = 0.0;
   out_6529698547862638487[238] = 0.0;
   out_6529698547862638487[239] = 0.0;
   out_6529698547862638487[240] = 0.0;
   out_6529698547862638487[241] = 0.0;
   out_6529698547862638487[242] = 0.0;
   out_6529698547862638487[243] = 0.0;
   out_6529698547862638487[244] = 0.0;
   out_6529698547862638487[245] = 0.0;
   out_6529698547862638487[246] = 0.0;
   out_6529698547862638487[247] = 1.0;
   out_6529698547862638487[248] = 0.0;
   out_6529698547862638487[249] = 0.0;
   out_6529698547862638487[250] = 0.0;
   out_6529698547862638487[251] = 0.0;
   out_6529698547862638487[252] = 0.0;
   out_6529698547862638487[253] = 0.0;
   out_6529698547862638487[254] = 0.0;
   out_6529698547862638487[255] = 0.0;
   out_6529698547862638487[256] = 0.0;
   out_6529698547862638487[257] = 0.0;
   out_6529698547862638487[258] = 0.0;
   out_6529698547862638487[259] = 0.0;
   out_6529698547862638487[260] = 0.0;
   out_6529698547862638487[261] = 0.0;
   out_6529698547862638487[262] = 0.0;
   out_6529698547862638487[263] = 0.0;
   out_6529698547862638487[264] = 0.0;
   out_6529698547862638487[265] = 0.0;
   out_6529698547862638487[266] = 1.0;
   out_6529698547862638487[267] = 0.0;
   out_6529698547862638487[268] = 0.0;
   out_6529698547862638487[269] = 0.0;
   out_6529698547862638487[270] = 0.0;
   out_6529698547862638487[271] = 0.0;
   out_6529698547862638487[272] = 0.0;
   out_6529698547862638487[273] = 0.0;
   out_6529698547862638487[274] = 0.0;
   out_6529698547862638487[275] = 0.0;
   out_6529698547862638487[276] = 0.0;
   out_6529698547862638487[277] = 0.0;
   out_6529698547862638487[278] = 0.0;
   out_6529698547862638487[279] = 0.0;
   out_6529698547862638487[280] = 0.0;
   out_6529698547862638487[281] = 0.0;
   out_6529698547862638487[282] = 0.0;
   out_6529698547862638487[283] = 0.0;
   out_6529698547862638487[284] = 0.0;
   out_6529698547862638487[285] = 1.0;
   out_6529698547862638487[286] = 0.0;
   out_6529698547862638487[287] = 0.0;
   out_6529698547862638487[288] = 0.0;
   out_6529698547862638487[289] = 0.0;
   out_6529698547862638487[290] = 0.0;
   out_6529698547862638487[291] = 0.0;
   out_6529698547862638487[292] = 0.0;
   out_6529698547862638487[293] = 0.0;
   out_6529698547862638487[294] = 0.0;
   out_6529698547862638487[295] = 0.0;
   out_6529698547862638487[296] = 0.0;
   out_6529698547862638487[297] = 0.0;
   out_6529698547862638487[298] = 0.0;
   out_6529698547862638487[299] = 0.0;
   out_6529698547862638487[300] = 0.0;
   out_6529698547862638487[301] = 0.0;
   out_6529698547862638487[302] = 0.0;
   out_6529698547862638487[303] = 0.0;
   out_6529698547862638487[304] = 1.0;
   out_6529698547862638487[305] = 0.0;
   out_6529698547862638487[306] = 0.0;
   out_6529698547862638487[307] = 0.0;
   out_6529698547862638487[308] = 0.0;
   out_6529698547862638487[309] = 0.0;
   out_6529698547862638487[310] = 0.0;
   out_6529698547862638487[311] = 0.0;
   out_6529698547862638487[312] = 0.0;
   out_6529698547862638487[313] = 0.0;
   out_6529698547862638487[314] = 0.0;
   out_6529698547862638487[315] = 0.0;
   out_6529698547862638487[316] = 0.0;
   out_6529698547862638487[317] = 0.0;
   out_6529698547862638487[318] = 0.0;
   out_6529698547862638487[319] = 0.0;
   out_6529698547862638487[320] = 0.0;
   out_6529698547862638487[321] = 0.0;
   out_6529698547862638487[322] = 0.0;
   out_6529698547862638487[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_972926144418312816) {
   out_972926144418312816[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_972926144418312816[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_972926144418312816[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_972926144418312816[3] = dt*state[12] + state[3];
   out_972926144418312816[4] = dt*state[13] + state[4];
   out_972926144418312816[5] = dt*state[14] + state[5];
   out_972926144418312816[6] = state[6];
   out_972926144418312816[7] = state[7];
   out_972926144418312816[8] = state[8];
   out_972926144418312816[9] = state[9];
   out_972926144418312816[10] = state[10];
   out_972926144418312816[11] = state[11];
   out_972926144418312816[12] = state[12];
   out_972926144418312816[13] = state[13];
   out_972926144418312816[14] = state[14];
   out_972926144418312816[15] = state[15];
   out_972926144418312816[16] = state[16];
   out_972926144418312816[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2749129160556482145) {
   out_2749129160556482145[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2749129160556482145[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2749129160556482145[2] = 0;
   out_2749129160556482145[3] = 0;
   out_2749129160556482145[4] = 0;
   out_2749129160556482145[5] = 0;
   out_2749129160556482145[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2749129160556482145[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2749129160556482145[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2749129160556482145[9] = 0;
   out_2749129160556482145[10] = 0;
   out_2749129160556482145[11] = 0;
   out_2749129160556482145[12] = 0;
   out_2749129160556482145[13] = 0;
   out_2749129160556482145[14] = 0;
   out_2749129160556482145[15] = 0;
   out_2749129160556482145[16] = 0;
   out_2749129160556482145[17] = 0;
   out_2749129160556482145[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2749129160556482145[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2749129160556482145[20] = 0;
   out_2749129160556482145[21] = 0;
   out_2749129160556482145[22] = 0;
   out_2749129160556482145[23] = 0;
   out_2749129160556482145[24] = 0;
   out_2749129160556482145[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2749129160556482145[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2749129160556482145[27] = 0;
   out_2749129160556482145[28] = 0;
   out_2749129160556482145[29] = 0;
   out_2749129160556482145[30] = 0;
   out_2749129160556482145[31] = 0;
   out_2749129160556482145[32] = 0;
   out_2749129160556482145[33] = 0;
   out_2749129160556482145[34] = 0;
   out_2749129160556482145[35] = 0;
   out_2749129160556482145[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2749129160556482145[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2749129160556482145[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2749129160556482145[39] = 0;
   out_2749129160556482145[40] = 0;
   out_2749129160556482145[41] = 0;
   out_2749129160556482145[42] = 0;
   out_2749129160556482145[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2749129160556482145[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2749129160556482145[45] = 0;
   out_2749129160556482145[46] = 0;
   out_2749129160556482145[47] = 0;
   out_2749129160556482145[48] = 0;
   out_2749129160556482145[49] = 0;
   out_2749129160556482145[50] = 0;
   out_2749129160556482145[51] = 0;
   out_2749129160556482145[52] = 0;
   out_2749129160556482145[53] = 0;
   out_2749129160556482145[54] = 0;
   out_2749129160556482145[55] = 0;
   out_2749129160556482145[56] = 0;
   out_2749129160556482145[57] = 1;
   out_2749129160556482145[58] = 0;
   out_2749129160556482145[59] = 0;
   out_2749129160556482145[60] = 0;
   out_2749129160556482145[61] = 0;
   out_2749129160556482145[62] = 0;
   out_2749129160556482145[63] = 0;
   out_2749129160556482145[64] = 0;
   out_2749129160556482145[65] = 0;
   out_2749129160556482145[66] = dt;
   out_2749129160556482145[67] = 0;
   out_2749129160556482145[68] = 0;
   out_2749129160556482145[69] = 0;
   out_2749129160556482145[70] = 0;
   out_2749129160556482145[71] = 0;
   out_2749129160556482145[72] = 0;
   out_2749129160556482145[73] = 0;
   out_2749129160556482145[74] = 0;
   out_2749129160556482145[75] = 0;
   out_2749129160556482145[76] = 1;
   out_2749129160556482145[77] = 0;
   out_2749129160556482145[78] = 0;
   out_2749129160556482145[79] = 0;
   out_2749129160556482145[80] = 0;
   out_2749129160556482145[81] = 0;
   out_2749129160556482145[82] = 0;
   out_2749129160556482145[83] = 0;
   out_2749129160556482145[84] = 0;
   out_2749129160556482145[85] = dt;
   out_2749129160556482145[86] = 0;
   out_2749129160556482145[87] = 0;
   out_2749129160556482145[88] = 0;
   out_2749129160556482145[89] = 0;
   out_2749129160556482145[90] = 0;
   out_2749129160556482145[91] = 0;
   out_2749129160556482145[92] = 0;
   out_2749129160556482145[93] = 0;
   out_2749129160556482145[94] = 0;
   out_2749129160556482145[95] = 1;
   out_2749129160556482145[96] = 0;
   out_2749129160556482145[97] = 0;
   out_2749129160556482145[98] = 0;
   out_2749129160556482145[99] = 0;
   out_2749129160556482145[100] = 0;
   out_2749129160556482145[101] = 0;
   out_2749129160556482145[102] = 0;
   out_2749129160556482145[103] = 0;
   out_2749129160556482145[104] = dt;
   out_2749129160556482145[105] = 0;
   out_2749129160556482145[106] = 0;
   out_2749129160556482145[107] = 0;
   out_2749129160556482145[108] = 0;
   out_2749129160556482145[109] = 0;
   out_2749129160556482145[110] = 0;
   out_2749129160556482145[111] = 0;
   out_2749129160556482145[112] = 0;
   out_2749129160556482145[113] = 0;
   out_2749129160556482145[114] = 1;
   out_2749129160556482145[115] = 0;
   out_2749129160556482145[116] = 0;
   out_2749129160556482145[117] = 0;
   out_2749129160556482145[118] = 0;
   out_2749129160556482145[119] = 0;
   out_2749129160556482145[120] = 0;
   out_2749129160556482145[121] = 0;
   out_2749129160556482145[122] = 0;
   out_2749129160556482145[123] = 0;
   out_2749129160556482145[124] = 0;
   out_2749129160556482145[125] = 0;
   out_2749129160556482145[126] = 0;
   out_2749129160556482145[127] = 0;
   out_2749129160556482145[128] = 0;
   out_2749129160556482145[129] = 0;
   out_2749129160556482145[130] = 0;
   out_2749129160556482145[131] = 0;
   out_2749129160556482145[132] = 0;
   out_2749129160556482145[133] = 1;
   out_2749129160556482145[134] = 0;
   out_2749129160556482145[135] = 0;
   out_2749129160556482145[136] = 0;
   out_2749129160556482145[137] = 0;
   out_2749129160556482145[138] = 0;
   out_2749129160556482145[139] = 0;
   out_2749129160556482145[140] = 0;
   out_2749129160556482145[141] = 0;
   out_2749129160556482145[142] = 0;
   out_2749129160556482145[143] = 0;
   out_2749129160556482145[144] = 0;
   out_2749129160556482145[145] = 0;
   out_2749129160556482145[146] = 0;
   out_2749129160556482145[147] = 0;
   out_2749129160556482145[148] = 0;
   out_2749129160556482145[149] = 0;
   out_2749129160556482145[150] = 0;
   out_2749129160556482145[151] = 0;
   out_2749129160556482145[152] = 1;
   out_2749129160556482145[153] = 0;
   out_2749129160556482145[154] = 0;
   out_2749129160556482145[155] = 0;
   out_2749129160556482145[156] = 0;
   out_2749129160556482145[157] = 0;
   out_2749129160556482145[158] = 0;
   out_2749129160556482145[159] = 0;
   out_2749129160556482145[160] = 0;
   out_2749129160556482145[161] = 0;
   out_2749129160556482145[162] = 0;
   out_2749129160556482145[163] = 0;
   out_2749129160556482145[164] = 0;
   out_2749129160556482145[165] = 0;
   out_2749129160556482145[166] = 0;
   out_2749129160556482145[167] = 0;
   out_2749129160556482145[168] = 0;
   out_2749129160556482145[169] = 0;
   out_2749129160556482145[170] = 0;
   out_2749129160556482145[171] = 1;
   out_2749129160556482145[172] = 0;
   out_2749129160556482145[173] = 0;
   out_2749129160556482145[174] = 0;
   out_2749129160556482145[175] = 0;
   out_2749129160556482145[176] = 0;
   out_2749129160556482145[177] = 0;
   out_2749129160556482145[178] = 0;
   out_2749129160556482145[179] = 0;
   out_2749129160556482145[180] = 0;
   out_2749129160556482145[181] = 0;
   out_2749129160556482145[182] = 0;
   out_2749129160556482145[183] = 0;
   out_2749129160556482145[184] = 0;
   out_2749129160556482145[185] = 0;
   out_2749129160556482145[186] = 0;
   out_2749129160556482145[187] = 0;
   out_2749129160556482145[188] = 0;
   out_2749129160556482145[189] = 0;
   out_2749129160556482145[190] = 1;
   out_2749129160556482145[191] = 0;
   out_2749129160556482145[192] = 0;
   out_2749129160556482145[193] = 0;
   out_2749129160556482145[194] = 0;
   out_2749129160556482145[195] = 0;
   out_2749129160556482145[196] = 0;
   out_2749129160556482145[197] = 0;
   out_2749129160556482145[198] = 0;
   out_2749129160556482145[199] = 0;
   out_2749129160556482145[200] = 0;
   out_2749129160556482145[201] = 0;
   out_2749129160556482145[202] = 0;
   out_2749129160556482145[203] = 0;
   out_2749129160556482145[204] = 0;
   out_2749129160556482145[205] = 0;
   out_2749129160556482145[206] = 0;
   out_2749129160556482145[207] = 0;
   out_2749129160556482145[208] = 0;
   out_2749129160556482145[209] = 1;
   out_2749129160556482145[210] = 0;
   out_2749129160556482145[211] = 0;
   out_2749129160556482145[212] = 0;
   out_2749129160556482145[213] = 0;
   out_2749129160556482145[214] = 0;
   out_2749129160556482145[215] = 0;
   out_2749129160556482145[216] = 0;
   out_2749129160556482145[217] = 0;
   out_2749129160556482145[218] = 0;
   out_2749129160556482145[219] = 0;
   out_2749129160556482145[220] = 0;
   out_2749129160556482145[221] = 0;
   out_2749129160556482145[222] = 0;
   out_2749129160556482145[223] = 0;
   out_2749129160556482145[224] = 0;
   out_2749129160556482145[225] = 0;
   out_2749129160556482145[226] = 0;
   out_2749129160556482145[227] = 0;
   out_2749129160556482145[228] = 1;
   out_2749129160556482145[229] = 0;
   out_2749129160556482145[230] = 0;
   out_2749129160556482145[231] = 0;
   out_2749129160556482145[232] = 0;
   out_2749129160556482145[233] = 0;
   out_2749129160556482145[234] = 0;
   out_2749129160556482145[235] = 0;
   out_2749129160556482145[236] = 0;
   out_2749129160556482145[237] = 0;
   out_2749129160556482145[238] = 0;
   out_2749129160556482145[239] = 0;
   out_2749129160556482145[240] = 0;
   out_2749129160556482145[241] = 0;
   out_2749129160556482145[242] = 0;
   out_2749129160556482145[243] = 0;
   out_2749129160556482145[244] = 0;
   out_2749129160556482145[245] = 0;
   out_2749129160556482145[246] = 0;
   out_2749129160556482145[247] = 1;
   out_2749129160556482145[248] = 0;
   out_2749129160556482145[249] = 0;
   out_2749129160556482145[250] = 0;
   out_2749129160556482145[251] = 0;
   out_2749129160556482145[252] = 0;
   out_2749129160556482145[253] = 0;
   out_2749129160556482145[254] = 0;
   out_2749129160556482145[255] = 0;
   out_2749129160556482145[256] = 0;
   out_2749129160556482145[257] = 0;
   out_2749129160556482145[258] = 0;
   out_2749129160556482145[259] = 0;
   out_2749129160556482145[260] = 0;
   out_2749129160556482145[261] = 0;
   out_2749129160556482145[262] = 0;
   out_2749129160556482145[263] = 0;
   out_2749129160556482145[264] = 0;
   out_2749129160556482145[265] = 0;
   out_2749129160556482145[266] = 1;
   out_2749129160556482145[267] = 0;
   out_2749129160556482145[268] = 0;
   out_2749129160556482145[269] = 0;
   out_2749129160556482145[270] = 0;
   out_2749129160556482145[271] = 0;
   out_2749129160556482145[272] = 0;
   out_2749129160556482145[273] = 0;
   out_2749129160556482145[274] = 0;
   out_2749129160556482145[275] = 0;
   out_2749129160556482145[276] = 0;
   out_2749129160556482145[277] = 0;
   out_2749129160556482145[278] = 0;
   out_2749129160556482145[279] = 0;
   out_2749129160556482145[280] = 0;
   out_2749129160556482145[281] = 0;
   out_2749129160556482145[282] = 0;
   out_2749129160556482145[283] = 0;
   out_2749129160556482145[284] = 0;
   out_2749129160556482145[285] = 1;
   out_2749129160556482145[286] = 0;
   out_2749129160556482145[287] = 0;
   out_2749129160556482145[288] = 0;
   out_2749129160556482145[289] = 0;
   out_2749129160556482145[290] = 0;
   out_2749129160556482145[291] = 0;
   out_2749129160556482145[292] = 0;
   out_2749129160556482145[293] = 0;
   out_2749129160556482145[294] = 0;
   out_2749129160556482145[295] = 0;
   out_2749129160556482145[296] = 0;
   out_2749129160556482145[297] = 0;
   out_2749129160556482145[298] = 0;
   out_2749129160556482145[299] = 0;
   out_2749129160556482145[300] = 0;
   out_2749129160556482145[301] = 0;
   out_2749129160556482145[302] = 0;
   out_2749129160556482145[303] = 0;
   out_2749129160556482145[304] = 1;
   out_2749129160556482145[305] = 0;
   out_2749129160556482145[306] = 0;
   out_2749129160556482145[307] = 0;
   out_2749129160556482145[308] = 0;
   out_2749129160556482145[309] = 0;
   out_2749129160556482145[310] = 0;
   out_2749129160556482145[311] = 0;
   out_2749129160556482145[312] = 0;
   out_2749129160556482145[313] = 0;
   out_2749129160556482145[314] = 0;
   out_2749129160556482145[315] = 0;
   out_2749129160556482145[316] = 0;
   out_2749129160556482145[317] = 0;
   out_2749129160556482145[318] = 0;
   out_2749129160556482145[319] = 0;
   out_2749129160556482145[320] = 0;
   out_2749129160556482145[321] = 0;
   out_2749129160556482145[322] = 0;
   out_2749129160556482145[323] = 1;
}
void h_4(double *state, double *unused, double *out_2905054802529428754) {
   out_2905054802529428754[0] = state[6] + state[9];
   out_2905054802529428754[1] = state[7] + state[10];
   out_2905054802529428754[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5331751065979740383) {
   out_5331751065979740383[0] = 0;
   out_5331751065979740383[1] = 0;
   out_5331751065979740383[2] = 0;
   out_5331751065979740383[3] = 0;
   out_5331751065979740383[4] = 0;
   out_5331751065979740383[5] = 0;
   out_5331751065979740383[6] = 1;
   out_5331751065979740383[7] = 0;
   out_5331751065979740383[8] = 0;
   out_5331751065979740383[9] = 1;
   out_5331751065979740383[10] = 0;
   out_5331751065979740383[11] = 0;
   out_5331751065979740383[12] = 0;
   out_5331751065979740383[13] = 0;
   out_5331751065979740383[14] = 0;
   out_5331751065979740383[15] = 0;
   out_5331751065979740383[16] = 0;
   out_5331751065979740383[17] = 0;
   out_5331751065979740383[18] = 0;
   out_5331751065979740383[19] = 0;
   out_5331751065979740383[20] = 0;
   out_5331751065979740383[21] = 0;
   out_5331751065979740383[22] = 0;
   out_5331751065979740383[23] = 0;
   out_5331751065979740383[24] = 0;
   out_5331751065979740383[25] = 1;
   out_5331751065979740383[26] = 0;
   out_5331751065979740383[27] = 0;
   out_5331751065979740383[28] = 1;
   out_5331751065979740383[29] = 0;
   out_5331751065979740383[30] = 0;
   out_5331751065979740383[31] = 0;
   out_5331751065979740383[32] = 0;
   out_5331751065979740383[33] = 0;
   out_5331751065979740383[34] = 0;
   out_5331751065979740383[35] = 0;
   out_5331751065979740383[36] = 0;
   out_5331751065979740383[37] = 0;
   out_5331751065979740383[38] = 0;
   out_5331751065979740383[39] = 0;
   out_5331751065979740383[40] = 0;
   out_5331751065979740383[41] = 0;
   out_5331751065979740383[42] = 0;
   out_5331751065979740383[43] = 0;
   out_5331751065979740383[44] = 1;
   out_5331751065979740383[45] = 0;
   out_5331751065979740383[46] = 0;
   out_5331751065979740383[47] = 1;
   out_5331751065979740383[48] = 0;
   out_5331751065979740383[49] = 0;
   out_5331751065979740383[50] = 0;
   out_5331751065979740383[51] = 0;
   out_5331751065979740383[52] = 0;
   out_5331751065979740383[53] = 0;
}
void h_10(double *state, double *unused, double *out_4478111556145773521) {
   out_4478111556145773521[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4478111556145773521[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4478111556145773521[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6449053587078220049) {
   out_6449053587078220049[0] = 0;
   out_6449053587078220049[1] = 9.8100000000000005*cos(state[1]);
   out_6449053587078220049[2] = 0;
   out_6449053587078220049[3] = 0;
   out_6449053587078220049[4] = -state[8];
   out_6449053587078220049[5] = state[7];
   out_6449053587078220049[6] = 0;
   out_6449053587078220049[7] = state[5];
   out_6449053587078220049[8] = -state[4];
   out_6449053587078220049[9] = 0;
   out_6449053587078220049[10] = 0;
   out_6449053587078220049[11] = 0;
   out_6449053587078220049[12] = 1;
   out_6449053587078220049[13] = 0;
   out_6449053587078220049[14] = 0;
   out_6449053587078220049[15] = 1;
   out_6449053587078220049[16] = 0;
   out_6449053587078220049[17] = 0;
   out_6449053587078220049[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6449053587078220049[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6449053587078220049[20] = 0;
   out_6449053587078220049[21] = state[8];
   out_6449053587078220049[22] = 0;
   out_6449053587078220049[23] = -state[6];
   out_6449053587078220049[24] = -state[5];
   out_6449053587078220049[25] = 0;
   out_6449053587078220049[26] = state[3];
   out_6449053587078220049[27] = 0;
   out_6449053587078220049[28] = 0;
   out_6449053587078220049[29] = 0;
   out_6449053587078220049[30] = 0;
   out_6449053587078220049[31] = 1;
   out_6449053587078220049[32] = 0;
   out_6449053587078220049[33] = 0;
   out_6449053587078220049[34] = 1;
   out_6449053587078220049[35] = 0;
   out_6449053587078220049[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6449053587078220049[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6449053587078220049[38] = 0;
   out_6449053587078220049[39] = -state[7];
   out_6449053587078220049[40] = state[6];
   out_6449053587078220049[41] = 0;
   out_6449053587078220049[42] = state[4];
   out_6449053587078220049[43] = -state[3];
   out_6449053587078220049[44] = 0;
   out_6449053587078220049[45] = 0;
   out_6449053587078220049[46] = 0;
   out_6449053587078220049[47] = 0;
   out_6449053587078220049[48] = 0;
   out_6449053587078220049[49] = 0;
   out_6449053587078220049[50] = 1;
   out_6449053587078220049[51] = 0;
   out_6449053587078220049[52] = 0;
   out_6449053587078220049[53] = 1;
}
void h_13(double *state, double *unused, double *out_5870382568076617872) {
   out_5870382568076617872[0] = state[3];
   out_5870382568076617872[1] = state[4];
   out_5870382568076617872[2] = state[5];
}
void H_13(double *state, double *unused, double *out_9165506529282264407) {
   out_9165506529282264407[0] = 0;
   out_9165506529282264407[1] = 0;
   out_9165506529282264407[2] = 0;
   out_9165506529282264407[3] = 1;
   out_9165506529282264407[4] = 0;
   out_9165506529282264407[5] = 0;
   out_9165506529282264407[6] = 0;
   out_9165506529282264407[7] = 0;
   out_9165506529282264407[8] = 0;
   out_9165506529282264407[9] = 0;
   out_9165506529282264407[10] = 0;
   out_9165506529282264407[11] = 0;
   out_9165506529282264407[12] = 0;
   out_9165506529282264407[13] = 0;
   out_9165506529282264407[14] = 0;
   out_9165506529282264407[15] = 0;
   out_9165506529282264407[16] = 0;
   out_9165506529282264407[17] = 0;
   out_9165506529282264407[18] = 0;
   out_9165506529282264407[19] = 0;
   out_9165506529282264407[20] = 0;
   out_9165506529282264407[21] = 0;
   out_9165506529282264407[22] = 1;
   out_9165506529282264407[23] = 0;
   out_9165506529282264407[24] = 0;
   out_9165506529282264407[25] = 0;
   out_9165506529282264407[26] = 0;
   out_9165506529282264407[27] = 0;
   out_9165506529282264407[28] = 0;
   out_9165506529282264407[29] = 0;
   out_9165506529282264407[30] = 0;
   out_9165506529282264407[31] = 0;
   out_9165506529282264407[32] = 0;
   out_9165506529282264407[33] = 0;
   out_9165506529282264407[34] = 0;
   out_9165506529282264407[35] = 0;
   out_9165506529282264407[36] = 0;
   out_9165506529282264407[37] = 0;
   out_9165506529282264407[38] = 0;
   out_9165506529282264407[39] = 0;
   out_9165506529282264407[40] = 0;
   out_9165506529282264407[41] = 1;
   out_9165506529282264407[42] = 0;
   out_9165506529282264407[43] = 0;
   out_9165506529282264407[44] = 0;
   out_9165506529282264407[45] = 0;
   out_9165506529282264407[46] = 0;
   out_9165506529282264407[47] = 0;
   out_9165506529282264407[48] = 0;
   out_9165506529282264407[49] = 0;
   out_9165506529282264407[50] = 0;
   out_9165506529282264407[51] = 0;
   out_9165506529282264407[52] = 0;
   out_9165506529282264407[53] = 0;
}
void h_14(double *state, double *unused, double *out_7546843480828208877) {
   out_7546843480828208877[0] = state[6];
   out_7546843480828208877[1] = state[7];
   out_7546843480828208877[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8414539498275112679) {
   out_8414539498275112679[0] = 0;
   out_8414539498275112679[1] = 0;
   out_8414539498275112679[2] = 0;
   out_8414539498275112679[3] = 0;
   out_8414539498275112679[4] = 0;
   out_8414539498275112679[5] = 0;
   out_8414539498275112679[6] = 1;
   out_8414539498275112679[7] = 0;
   out_8414539498275112679[8] = 0;
   out_8414539498275112679[9] = 0;
   out_8414539498275112679[10] = 0;
   out_8414539498275112679[11] = 0;
   out_8414539498275112679[12] = 0;
   out_8414539498275112679[13] = 0;
   out_8414539498275112679[14] = 0;
   out_8414539498275112679[15] = 0;
   out_8414539498275112679[16] = 0;
   out_8414539498275112679[17] = 0;
   out_8414539498275112679[18] = 0;
   out_8414539498275112679[19] = 0;
   out_8414539498275112679[20] = 0;
   out_8414539498275112679[21] = 0;
   out_8414539498275112679[22] = 0;
   out_8414539498275112679[23] = 0;
   out_8414539498275112679[24] = 0;
   out_8414539498275112679[25] = 1;
   out_8414539498275112679[26] = 0;
   out_8414539498275112679[27] = 0;
   out_8414539498275112679[28] = 0;
   out_8414539498275112679[29] = 0;
   out_8414539498275112679[30] = 0;
   out_8414539498275112679[31] = 0;
   out_8414539498275112679[32] = 0;
   out_8414539498275112679[33] = 0;
   out_8414539498275112679[34] = 0;
   out_8414539498275112679[35] = 0;
   out_8414539498275112679[36] = 0;
   out_8414539498275112679[37] = 0;
   out_8414539498275112679[38] = 0;
   out_8414539498275112679[39] = 0;
   out_8414539498275112679[40] = 0;
   out_8414539498275112679[41] = 0;
   out_8414539498275112679[42] = 0;
   out_8414539498275112679[43] = 0;
   out_8414539498275112679[44] = 1;
   out_8414539498275112679[45] = 0;
   out_8414539498275112679[46] = 0;
   out_8414539498275112679[47] = 0;
   out_8414539498275112679[48] = 0;
   out_8414539498275112679[49] = 0;
   out_8414539498275112679[50] = 0;
   out_8414539498275112679[51] = 0;
   out_8414539498275112679[52] = 0;
   out_8414539498275112679[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3527959792166280959) {
  err_fun(nom_x, delta_x, out_3527959792166280959);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1197198609640831537) {
  inv_err_fun(nom_x, true_x, out_1197198609640831537);
}
void pose_H_mod_fun(double *state, double *out_6529698547862638487) {
  H_mod_fun(state, out_6529698547862638487);
}
void pose_f_fun(double *state, double dt, double *out_972926144418312816) {
  f_fun(state,  dt, out_972926144418312816);
}
void pose_F_fun(double *state, double dt, double *out_2749129160556482145) {
  F_fun(state,  dt, out_2749129160556482145);
}
void pose_h_4(double *state, double *unused, double *out_2905054802529428754) {
  h_4(state, unused, out_2905054802529428754);
}
void pose_H_4(double *state, double *unused, double *out_5331751065979740383) {
  H_4(state, unused, out_5331751065979740383);
}
void pose_h_10(double *state, double *unused, double *out_4478111556145773521) {
  h_10(state, unused, out_4478111556145773521);
}
void pose_H_10(double *state, double *unused, double *out_6449053587078220049) {
  H_10(state, unused, out_6449053587078220049);
}
void pose_h_13(double *state, double *unused, double *out_5870382568076617872) {
  h_13(state, unused, out_5870382568076617872);
}
void pose_H_13(double *state, double *unused, double *out_9165506529282264407) {
  H_13(state, unused, out_9165506529282264407);
}
void pose_h_14(double *state, double *unused, double *out_7546843480828208877) {
  h_14(state, unused, out_7546843480828208877);
}
void pose_H_14(double *state, double *unused, double *out_8414539498275112679) {
  H_14(state, unused, out_8414539498275112679);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
