#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2753838879715096147);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5478564811934511762);
void car_H_mod_fun(double *state, double *out_5157726215379466440);
void car_f_fun(double *state, double dt, double *out_6172579678110784207);
void car_F_fun(double *state, double dt, double *out_8325291601080044654);
void car_h_25(double *state, double *unused, double *out_8698314086456876076);
void car_H_25(double *state, double *unused, double *out_7730000839833474931);
void car_h_24(double *state, double *unused, double *out_2331925813818990854);
void car_H_24(double *state, double *unused, double *out_650679694548661095);
void car_h_30(double *state, double *unused, double *out_1237755322207987751);
void car_H_30(double *state, double *unused, double *out_8198410275368828058);
void car_h_26(double *state, double *unused, double *out_3763917945452857894);
void car_H_26(double *state, double *unused, double *out_3988497520959418707);
void car_h_27(double *state, double *unused, double *out_6093908765648178425);
void car_H_27(double *state, double *unused, double *out_8073570486540298647);
void car_h_29(double *state, double *unused, double *out_6197388112220713062);
void car_H_29(double *state, double *unused, double *out_7688178931054435874);
void car_h_28(double *state, double *unused, double *out_7351162040400527546);
void car_H_28(double *state, double *unused, double *out_5676166125585585168);
void car_h_31(double *state, double *unused, double *out_8855500754808005221);
void car_H_31(double *state, double *unused, double *out_3362289418726067231);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}