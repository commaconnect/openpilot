#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2753838879715096147) {
   out_2753838879715096147[0] = delta_x[0] + nom_x[0];
   out_2753838879715096147[1] = delta_x[1] + nom_x[1];
   out_2753838879715096147[2] = delta_x[2] + nom_x[2];
   out_2753838879715096147[3] = delta_x[3] + nom_x[3];
   out_2753838879715096147[4] = delta_x[4] + nom_x[4];
   out_2753838879715096147[5] = delta_x[5] + nom_x[5];
   out_2753838879715096147[6] = delta_x[6] + nom_x[6];
   out_2753838879715096147[7] = delta_x[7] + nom_x[7];
   out_2753838879715096147[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5478564811934511762) {
   out_5478564811934511762[0] = -nom_x[0] + true_x[0];
   out_5478564811934511762[1] = -nom_x[1] + true_x[1];
   out_5478564811934511762[2] = -nom_x[2] + true_x[2];
   out_5478564811934511762[3] = -nom_x[3] + true_x[3];
   out_5478564811934511762[4] = -nom_x[4] + true_x[4];
   out_5478564811934511762[5] = -nom_x[5] + true_x[5];
   out_5478564811934511762[6] = -nom_x[6] + true_x[6];
   out_5478564811934511762[7] = -nom_x[7] + true_x[7];
   out_5478564811934511762[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5157726215379466440) {
   out_5157726215379466440[0] = 1.0;
   out_5157726215379466440[1] = 0.0;
   out_5157726215379466440[2] = 0.0;
   out_5157726215379466440[3] = 0.0;
   out_5157726215379466440[4] = 0.0;
   out_5157726215379466440[5] = 0.0;
   out_5157726215379466440[6] = 0.0;
   out_5157726215379466440[7] = 0.0;
   out_5157726215379466440[8] = 0.0;
   out_5157726215379466440[9] = 0.0;
   out_5157726215379466440[10] = 1.0;
   out_5157726215379466440[11] = 0.0;
   out_5157726215379466440[12] = 0.0;
   out_5157726215379466440[13] = 0.0;
   out_5157726215379466440[14] = 0.0;
   out_5157726215379466440[15] = 0.0;
   out_5157726215379466440[16] = 0.0;
   out_5157726215379466440[17] = 0.0;
   out_5157726215379466440[18] = 0.0;
   out_5157726215379466440[19] = 0.0;
   out_5157726215379466440[20] = 1.0;
   out_5157726215379466440[21] = 0.0;
   out_5157726215379466440[22] = 0.0;
   out_5157726215379466440[23] = 0.0;
   out_5157726215379466440[24] = 0.0;
   out_5157726215379466440[25] = 0.0;
   out_5157726215379466440[26] = 0.0;
   out_5157726215379466440[27] = 0.0;
   out_5157726215379466440[28] = 0.0;
   out_5157726215379466440[29] = 0.0;
   out_5157726215379466440[30] = 1.0;
   out_5157726215379466440[31] = 0.0;
   out_5157726215379466440[32] = 0.0;
   out_5157726215379466440[33] = 0.0;
   out_5157726215379466440[34] = 0.0;
   out_5157726215379466440[35] = 0.0;
   out_5157726215379466440[36] = 0.0;
   out_5157726215379466440[37] = 0.0;
   out_5157726215379466440[38] = 0.0;
   out_5157726215379466440[39] = 0.0;
   out_5157726215379466440[40] = 1.0;
   out_5157726215379466440[41] = 0.0;
   out_5157726215379466440[42] = 0.0;
   out_5157726215379466440[43] = 0.0;
   out_5157726215379466440[44] = 0.0;
   out_5157726215379466440[45] = 0.0;
   out_5157726215379466440[46] = 0.0;
   out_5157726215379466440[47] = 0.0;
   out_5157726215379466440[48] = 0.0;
   out_5157726215379466440[49] = 0.0;
   out_5157726215379466440[50] = 1.0;
   out_5157726215379466440[51] = 0.0;
   out_5157726215379466440[52] = 0.0;
   out_5157726215379466440[53] = 0.0;
   out_5157726215379466440[54] = 0.0;
   out_5157726215379466440[55] = 0.0;
   out_5157726215379466440[56] = 0.0;
   out_5157726215379466440[57] = 0.0;
   out_5157726215379466440[58] = 0.0;
   out_5157726215379466440[59] = 0.0;
   out_5157726215379466440[60] = 1.0;
   out_5157726215379466440[61] = 0.0;
   out_5157726215379466440[62] = 0.0;
   out_5157726215379466440[63] = 0.0;
   out_5157726215379466440[64] = 0.0;
   out_5157726215379466440[65] = 0.0;
   out_5157726215379466440[66] = 0.0;
   out_5157726215379466440[67] = 0.0;
   out_5157726215379466440[68] = 0.0;
   out_5157726215379466440[69] = 0.0;
   out_5157726215379466440[70] = 1.0;
   out_5157726215379466440[71] = 0.0;
   out_5157726215379466440[72] = 0.0;
   out_5157726215379466440[73] = 0.0;
   out_5157726215379466440[74] = 0.0;
   out_5157726215379466440[75] = 0.0;
   out_5157726215379466440[76] = 0.0;
   out_5157726215379466440[77] = 0.0;
   out_5157726215379466440[78] = 0.0;
   out_5157726215379466440[79] = 0.0;
   out_5157726215379466440[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6172579678110784207) {
   out_6172579678110784207[0] = state[0];
   out_6172579678110784207[1] = state[1];
   out_6172579678110784207[2] = state[2];
   out_6172579678110784207[3] = state[3];
   out_6172579678110784207[4] = state[4];
   out_6172579678110784207[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6172579678110784207[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6172579678110784207[7] = state[7];
   out_6172579678110784207[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8325291601080044654) {
   out_8325291601080044654[0] = 1;
   out_8325291601080044654[1] = 0;
   out_8325291601080044654[2] = 0;
   out_8325291601080044654[3] = 0;
   out_8325291601080044654[4] = 0;
   out_8325291601080044654[5] = 0;
   out_8325291601080044654[6] = 0;
   out_8325291601080044654[7] = 0;
   out_8325291601080044654[8] = 0;
   out_8325291601080044654[9] = 0;
   out_8325291601080044654[10] = 1;
   out_8325291601080044654[11] = 0;
   out_8325291601080044654[12] = 0;
   out_8325291601080044654[13] = 0;
   out_8325291601080044654[14] = 0;
   out_8325291601080044654[15] = 0;
   out_8325291601080044654[16] = 0;
   out_8325291601080044654[17] = 0;
   out_8325291601080044654[18] = 0;
   out_8325291601080044654[19] = 0;
   out_8325291601080044654[20] = 1;
   out_8325291601080044654[21] = 0;
   out_8325291601080044654[22] = 0;
   out_8325291601080044654[23] = 0;
   out_8325291601080044654[24] = 0;
   out_8325291601080044654[25] = 0;
   out_8325291601080044654[26] = 0;
   out_8325291601080044654[27] = 0;
   out_8325291601080044654[28] = 0;
   out_8325291601080044654[29] = 0;
   out_8325291601080044654[30] = 1;
   out_8325291601080044654[31] = 0;
   out_8325291601080044654[32] = 0;
   out_8325291601080044654[33] = 0;
   out_8325291601080044654[34] = 0;
   out_8325291601080044654[35] = 0;
   out_8325291601080044654[36] = 0;
   out_8325291601080044654[37] = 0;
   out_8325291601080044654[38] = 0;
   out_8325291601080044654[39] = 0;
   out_8325291601080044654[40] = 1;
   out_8325291601080044654[41] = 0;
   out_8325291601080044654[42] = 0;
   out_8325291601080044654[43] = 0;
   out_8325291601080044654[44] = 0;
   out_8325291601080044654[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8325291601080044654[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8325291601080044654[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8325291601080044654[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8325291601080044654[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8325291601080044654[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8325291601080044654[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8325291601080044654[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8325291601080044654[53] = -9.8100000000000005*dt;
   out_8325291601080044654[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8325291601080044654[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8325291601080044654[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8325291601080044654[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8325291601080044654[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8325291601080044654[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8325291601080044654[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8325291601080044654[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8325291601080044654[62] = 0;
   out_8325291601080044654[63] = 0;
   out_8325291601080044654[64] = 0;
   out_8325291601080044654[65] = 0;
   out_8325291601080044654[66] = 0;
   out_8325291601080044654[67] = 0;
   out_8325291601080044654[68] = 0;
   out_8325291601080044654[69] = 0;
   out_8325291601080044654[70] = 1;
   out_8325291601080044654[71] = 0;
   out_8325291601080044654[72] = 0;
   out_8325291601080044654[73] = 0;
   out_8325291601080044654[74] = 0;
   out_8325291601080044654[75] = 0;
   out_8325291601080044654[76] = 0;
   out_8325291601080044654[77] = 0;
   out_8325291601080044654[78] = 0;
   out_8325291601080044654[79] = 0;
   out_8325291601080044654[80] = 1;
}
void h_25(double *state, double *unused, double *out_8698314086456876076) {
   out_8698314086456876076[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7730000839833474931) {
   out_7730000839833474931[0] = 0;
   out_7730000839833474931[1] = 0;
   out_7730000839833474931[2] = 0;
   out_7730000839833474931[3] = 0;
   out_7730000839833474931[4] = 0;
   out_7730000839833474931[5] = 0;
   out_7730000839833474931[6] = 1;
   out_7730000839833474931[7] = 0;
   out_7730000839833474931[8] = 0;
}
void h_24(double *state, double *unused, double *out_2331925813818990854) {
   out_2331925813818990854[0] = state[4];
   out_2331925813818990854[1] = state[5];
}
void H_24(double *state, double *unused, double *out_650679694548661095) {
   out_650679694548661095[0] = 0;
   out_650679694548661095[1] = 0;
   out_650679694548661095[2] = 0;
   out_650679694548661095[3] = 0;
   out_650679694548661095[4] = 1;
   out_650679694548661095[5] = 0;
   out_650679694548661095[6] = 0;
   out_650679694548661095[7] = 0;
   out_650679694548661095[8] = 0;
   out_650679694548661095[9] = 0;
   out_650679694548661095[10] = 0;
   out_650679694548661095[11] = 0;
   out_650679694548661095[12] = 0;
   out_650679694548661095[13] = 0;
   out_650679694548661095[14] = 1;
   out_650679694548661095[15] = 0;
   out_650679694548661095[16] = 0;
   out_650679694548661095[17] = 0;
}
void h_30(double *state, double *unused, double *out_1237755322207987751) {
   out_1237755322207987751[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8198410275368828058) {
   out_8198410275368828058[0] = 0;
   out_8198410275368828058[1] = 0;
   out_8198410275368828058[2] = 0;
   out_8198410275368828058[3] = 0;
   out_8198410275368828058[4] = 1;
   out_8198410275368828058[5] = 0;
   out_8198410275368828058[6] = 0;
   out_8198410275368828058[7] = 0;
   out_8198410275368828058[8] = 0;
}
void h_26(double *state, double *unused, double *out_3763917945452857894) {
   out_3763917945452857894[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3988497520959418707) {
   out_3988497520959418707[0] = 0;
   out_3988497520959418707[1] = 0;
   out_3988497520959418707[2] = 0;
   out_3988497520959418707[3] = 0;
   out_3988497520959418707[4] = 0;
   out_3988497520959418707[5] = 0;
   out_3988497520959418707[6] = 0;
   out_3988497520959418707[7] = 1;
   out_3988497520959418707[8] = 0;
}
void h_27(double *state, double *unused, double *out_6093908765648178425) {
   out_6093908765648178425[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8073570486540298647) {
   out_8073570486540298647[0] = 0;
   out_8073570486540298647[1] = 0;
   out_8073570486540298647[2] = 0;
   out_8073570486540298647[3] = 1;
   out_8073570486540298647[4] = 0;
   out_8073570486540298647[5] = 0;
   out_8073570486540298647[6] = 0;
   out_8073570486540298647[7] = 0;
   out_8073570486540298647[8] = 0;
}
void h_29(double *state, double *unused, double *out_6197388112220713062) {
   out_6197388112220713062[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7688178931054435874) {
   out_7688178931054435874[0] = 0;
   out_7688178931054435874[1] = 1;
   out_7688178931054435874[2] = 0;
   out_7688178931054435874[3] = 0;
   out_7688178931054435874[4] = 0;
   out_7688178931054435874[5] = 0;
   out_7688178931054435874[6] = 0;
   out_7688178931054435874[7] = 0;
   out_7688178931054435874[8] = 0;
}
void h_28(double *state, double *unused, double *out_7351162040400527546) {
   out_7351162040400527546[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5676166125585585168) {
   out_5676166125585585168[0] = 1;
   out_5676166125585585168[1] = 0;
   out_5676166125585585168[2] = 0;
   out_5676166125585585168[3] = 0;
   out_5676166125585585168[4] = 0;
   out_5676166125585585168[5] = 0;
   out_5676166125585585168[6] = 0;
   out_5676166125585585168[7] = 0;
   out_5676166125585585168[8] = 0;
}
void h_31(double *state, double *unused, double *out_8855500754808005221) {
   out_8855500754808005221[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3362289418726067231) {
   out_3362289418726067231[0] = 0;
   out_3362289418726067231[1] = 0;
   out_3362289418726067231[2] = 0;
   out_3362289418726067231[3] = 0;
   out_3362289418726067231[4] = 0;
   out_3362289418726067231[5] = 0;
   out_3362289418726067231[6] = 0;
   out_3362289418726067231[7] = 0;
   out_3362289418726067231[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2753838879715096147) {
  err_fun(nom_x, delta_x, out_2753838879715096147);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5478564811934511762) {
  inv_err_fun(nom_x, true_x, out_5478564811934511762);
}
void car_H_mod_fun(double *state, double *out_5157726215379466440) {
  H_mod_fun(state, out_5157726215379466440);
}
void car_f_fun(double *state, double dt, double *out_6172579678110784207) {
  f_fun(state,  dt, out_6172579678110784207);
}
void car_F_fun(double *state, double dt, double *out_8325291601080044654) {
  F_fun(state,  dt, out_8325291601080044654);
}
void car_h_25(double *state, double *unused, double *out_8698314086456876076) {
  h_25(state, unused, out_8698314086456876076);
}
void car_H_25(double *state, double *unused, double *out_7730000839833474931) {
  H_25(state, unused, out_7730000839833474931);
}
void car_h_24(double *state, double *unused, double *out_2331925813818990854) {
  h_24(state, unused, out_2331925813818990854);
}
void car_H_24(double *state, double *unused, double *out_650679694548661095) {
  H_24(state, unused, out_650679694548661095);
}
void car_h_30(double *state, double *unused, double *out_1237755322207987751) {
  h_30(state, unused, out_1237755322207987751);
}
void car_H_30(double *state, double *unused, double *out_8198410275368828058) {
  H_30(state, unused, out_8198410275368828058);
}
void car_h_26(double *state, double *unused, double *out_3763917945452857894) {
  h_26(state, unused, out_3763917945452857894);
}
void car_H_26(double *state, double *unused, double *out_3988497520959418707) {
  H_26(state, unused, out_3988497520959418707);
}
void car_h_27(double *state, double *unused, double *out_6093908765648178425) {
  h_27(state, unused, out_6093908765648178425);
}
void car_H_27(double *state, double *unused, double *out_8073570486540298647) {
  H_27(state, unused, out_8073570486540298647);
}
void car_h_29(double *state, double *unused, double *out_6197388112220713062) {
  h_29(state, unused, out_6197388112220713062);
}
void car_H_29(double *state, double *unused, double *out_7688178931054435874) {
  H_29(state, unused, out_7688178931054435874);
}
void car_h_28(double *state, double *unused, double *out_7351162040400527546) {
  h_28(state, unused, out_7351162040400527546);
}
void car_H_28(double *state, double *unused, double *out_5676166125585585168) {
  H_28(state, unused, out_5676166125585585168);
}
void car_h_31(double *state, double *unused, double *out_8855500754808005221) {
  h_31(state, unused, out_8855500754808005221);
}
void car_H_31(double *state, double *unused, double *out_3362289418726067231) {
  H_31(state, unused, out_3362289418726067231);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
