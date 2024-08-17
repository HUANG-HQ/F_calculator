//��ͷ�ļ�����Ϊ����easyx�ı�������涨��һЩ��װ
//�ں����������ϵ�е�Ԫ��ĺ���
//XUANKUDE

#ifndef EASYX_UNIT_ENCAPSULATION_H
#define EASYX_UNIT_ENCAPSULATION_H
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"calculator.h"

//���ư�ť  x��yΪ���Ͻ�����  wΪ��ť��ȣ�hΪ��ť�߶�
void button(int x, int y, int w, int h, const wchar_t* text)
{
    setfillcolor(RGB(193, 191, 191));//Բ�Ǿ��������ɫ
    fillroundrect(x, y, x + w, y + h, 10, 10);//����Բ�Ǿ���
    TCHAR arr[50];
    wcscpy_s(arr, text);
    setbkmode(TRANSPARENT);//���ֱ���͸��
    outtextxy(x + ((w - textwidth(arr)) / 2), y + (h - textheight(arr)) / 2, arr);//���л�������
}

//����Inputbox��װһ��������������뺯��
double Enter_data(int x, int y, int w, int h)
{
    wchar_t s[10];// �����ַ������������������û�����
    InputBox(s, 10, L"���������");
    clearroundrect(x, y, x + w, y + h, 35, 50);//����ϴ�����
    solidroundrect(x, y, x + w, y + h, 35, 50);//���汳��
    outtextxy(x + ((w - textwidth(s)) / 2), y + (h - textheight(s)) / 2, s);//���л�������
    double r = _tstof(s);	// ���û�����ת��Ϊ����
    return r;
}

//��װ���㿪չ����
void Start_Calculate(calculator_nt calcu_member, int calcu_WorF)
{
    //����ϴ�����
    clearroundrect(40, 370, 550, 405, 35, 50);
    clearroundrect(780, 315, 835, 345, 35, 50);
    //���汳��
    solidroundrect(40, 370, 550, 405, 35, 50);
    solidroundrect(780, 315, 835, 345, 35, 50);
    calcu_member = calculate_Cylinder_F(calcu_member);//��������������
    if (calcu_WorF == 0)
    {
        wchar_t str[20]; swprintf_s(str, L"%lf", calcu_member.Cylinder_F);
        wchar_t str_fai[20]; swprintf_s(str_fai, L"%lf", calcu_member.fai1);
        outtextxy(780 + ((55 - textwidth(str_fai)) / 2), 315 + (30 - textheight(str_fai)) / 2, str_fai);//���л��Ƽ����м�ֵfai
        outtextxy(40 + ((510 - textwidth(str)) / 2), 370 + (35 - textheight(str)) / 2, str);//���л�������,���������
    }
    else
    {
        wchar_t str[20]; swprintf_s(str, L"%lf", calcu_member.W1);
        wchar_t str_fai[20]; swprintf_s(str_fai, L"%lf", calcu_member.fai1);
        outtextxy(780 + ((55 - textwidth(str_fai)) / 2), 315 + (30 - textheight(str_fai)) / 2, str_fai);//���л��Ƽ����м�ֵfai
        outtextxy(40 + ((510 - textwidth(str)) / 2), 370 + (35 - textheight(str)) / 2, str);//���л�������,�������
    }
}

//��װģʽ�л�����
int Mode_0change1(int calcu_WorF)
{

    button(580, 75, 100, 35, L"���ؼ���");
    button(720, 75, 100, 35, L"����������");
    clearroundrect(550, 135, 635, 175, 35, 50);//���W1
    solidroundrect(665, 315, 720, 345, 35, 50);//��ʾF1
    outtextxy(590, 322, L"Cylinder_F");
    calcu_WorF = 1;
    return calcu_WorF;
}

int Mode_1change0(int calcu_WorF)
{

    button(580, 75, 100, 35, L"���ؼ���");
    button(720, 75, 100, 35, L"������������");
    clearroundrect(560, 315, 730, 360, 35, 50);//���F1
    solidroundrect(580, 135, 635, 175, 35, 50);//��ʾW1
    outtextxy(554, 150, L"W1");
    calcu_WorF = 0;
    return calcu_WorF;
}

#endif
