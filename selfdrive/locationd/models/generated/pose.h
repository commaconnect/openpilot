#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3527959792166280959);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1197198609640831537);
void pose_H_mod_fun(double *state, double *out_6529698547862638487);
void pose_f_fun(double *state, double dt, double *out_972926144418312816);
void pose_F_fun(double *state, double dt, double *out_2749129160556482145);
void pose_h_4(double *state, double *unused, double *out_2905054802529428754);
void pose_H_4(double *state, double *unused, double *out_5331751065979740383);
void pose_h_10(double *state, double *unused, double *out_4478111556145773521);
void pose_H_10(double *state, double *unused, double *out_6449053587078220049);
void pose_h_13(double *state, double *unused, double *out_5870382568076617872);
void pose_H_13(double *state, double *unused, double *out_9165506529282264407);
void pose_h_14(double *state, double *unused, double *out_7546843480828208877);
void pose_H_14(double *state, double *unused, double *out_8414539498275112679);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}