//��ͷ�ļ�����Ϊһ���۽ṹ��Ԫ����һ������ṹ��
//�ں��õ�Ԫ�ṹ��ϵ�в�������Ӧ���㺯��
//XUANKUDE

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stdio.h>
#include <math.h>

//��������������ṹ��
typedef struct
{
    //�������W1Ϊ���أ�L1Ϊ�˳���Lg1Ϊ���ĵ��������룬b1Ϊ�����ϰ�εľ��룬
    //S1Ϊ�������ϸ˵ľ��룬Wa1Ϊ��������l1Ϊת���˵ĳ���,Cylinder_FΪ����������,
    //Cylinder_dΪ����ֱ��,Cylinder_pΪ�������ѹǿ,Cylinder_F_MAXΪ��ѡ����������
    double W1, L1, Lg1, b1, S1, Wa1, l1, Cylinder_F, Cylinder_d, Cylinder_p, Cylinder_F_MAX;
    double theta, psi, fai1;//����Ƕ�theta,psi,dai1��
} calculator_nt;

//��������ƽ������������������ײ�����������������㺯��
calculator_nt calculate_Cylinder_F(calculator_nt cal_variable)
{
    cal_variable.fai1 = asin((cal_variable.b1 * cos(cal_variable.theta) - cal_variable.S1) / cal_variable.l1);
    double Fa = (cal_variable.W1 * cal_variable.L1 + cal_variable.Wa1 * cal_variable.Lg1);
    double Fb = (cos(cal_variable.theta) * cos(cal_variable.fai1)) / (cal_variable.b1 * cos(cal_variable.psi));
    cal_variable.Cylinder_F = Fa * Fb;
    cal_variable.Cylinder_F_MAX = 3.1415926 * cal_variable.Cylinder_p * pow(cal_variable.Cylinder_d / 2, 2);
    return cal_variable;
};

//����ò������ܸ��صļ��㺯��
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