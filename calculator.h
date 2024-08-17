//本头文件用于为一个臂结构单元定义一个计算结构体
//内含该单元结构的系列参数和相应计算函数
//XUANKUDE

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stdio.h>
#include <math.h>

//定义计算参数计算结构体
typedef struct
{
    //定义参数W1为负载，L1为杆长，Lg1为重心到根部距离，b1为基杆上半段的距离，
    //S1为气缸与上杆的距离，Wa1为杆重量，l1为转动杆的长度,Cylinder_F为所需气缸力,
    //Cylinder_d为气缸直径,Cylinder_p为气缸最大压强,Cylinder_F_MAX为所选气缸力极限
    double W1, L1, Lg1, b1, S1, Wa1, l1, Cylinder_F, Cylinder_d, Cylinder_p, Cylinder_F_MAX;
    double theta, psi, fai1;//定义角度theta,psi,dai1；
} calculator_nt;

//定义重力平衡所需气缸力与该气缸参数气缸最大推力计算函数
calculator_nt calculate_Cylinder_F(calculator_nt cal_variable)
{
    cal_variable.fai1 = asin((cal_variable.b1 * cos(cal_variable.theta) - cal_variable.S1) / cal_variable.l1);
    double Fa = (cal_variable.W1 * cal_variable.L1 + cal_variable.Wa1 * cal_variable.Lg1);
    double Fb = (cos(cal_variable.theta) * cos(cal_variable.fai1)) / (cal_variable.b1 * cos(cal_variable.psi));
    cal_variable.Cylinder_F = Fa * Fb;
    cal_variable.Cylinder_F_MAX = 3.1415926 * cal_variable.Cylinder_p * pow(cal_variable.Cylinder_d / 2, 2);
    return cal_variable;
};

//定义该参数能受负载的计算函数
calculator_nt calculate_W1(calculator_nt cal_variable)
{
    cal_variable.fai1 = asin((cal_variable.b1 * cos(cal_variable.theta) - cal_variable.S1) / cal_variable.l1);
    double Fa = (cal_variable.b1 * cos(cal_variable.psi)) / (cos(cal_variable.theta) * cos(cal_variable.fai1));
    double Fb = cal_variable.Cylinder_F / cal_variable.L1;
    double Fc = cal_variable.Wa1 * cal_variable.Lg1 / cal_variable.L1;
    cal_variable.W1 = Fa * Fb - Fc;
    return cal_variable;
}

#endif