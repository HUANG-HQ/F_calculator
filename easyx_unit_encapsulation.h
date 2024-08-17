//本头文件用于为基于easyx的本任务界面定义一些封装
//内含交互界面的系列单元体的函数
//XUANKUDE

#ifndef EASYX_UNIT_ENCAPSULATION_H
#define EASYX_UNIT_ENCAPSULATION_H
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"calculator.h"

//绘制按钮  x，y为左上角坐标  w为按钮宽度，h为按钮高度
void button(int x, int y, int w, int h, const wchar_t* text)
{
    setfillcolor(RGB(193, 191, 191));//圆角矩形填充颜色
    fillroundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形
    TCHAR arr[50];
    wcscpy_s(arr, text);
    setbkmode(TRANSPARENT);//文字背景透明
    outtextxy(x + ((w - textwidth(arr)) / 2), y + (h - textheight(arr)) / 2, arr);//居中绘制文字
}

//利用Inputbox封装一个键入参数的输入函数
double Enter_data(int x, int y, int w, int h)
{
    wchar_t s[10];// 定义字符串缓冲区，并接收用户输入
    InputBox(s, 10, L"请输入参数");
    clearroundrect(x, y, x + w, y + h, 35, 50);//清除上次输入
    solidroundrect(x, y, x + w, y + h, 35, 50);//补绘背景
    outtextxy(x + ((w - textwidth(s)) / 2), y + (h - textheight(s)) / 2, s);//居中绘制文字
    double r = _tstof(s);	// 将用户输入转换为数字
    return r;
}

//封装计算开展流程
void Start_Calculate(calculator_nt calcu_member, int calcu_WorF)
{
    //清除上次输入
    clearroundrect(40, 370, 550, 405, 35, 50);
    clearroundrect(780, 315, 835, 345, 35, 50);
    //补绘背景
    solidroundrect(40, 370, 550, 405, 35, 50);
    solidroundrect(780, 315, 835, 345, 35, 50);
    calcu_member = calculate_Cylinder_F(calcu_member);//计算所需气缸力
    if (calcu_WorF == 0)
    {
        wchar_t str[20]; swprintf_s(str, L"%lf", calcu_member.Cylinder_F);
        wchar_t str_fai[20]; swprintf_s(str_fai, L"%lf", calcu_member.fai1);
        outtextxy(780 + ((55 - textwidth(str_fai)) / 2), 315 + (30 - textheight(str_fai)) / 2, str_fai);//居中绘制计算中间值fai
        outtextxy(40 + ((510 - textwidth(str)) / 2), 370 + (35 - textheight(str)) / 2, str);//居中绘制文字,输出气缸力
    }
    else
    {
        wchar_t str[20]; swprintf_s(str, L"%lf", calcu_member.W1);
        wchar_t str_fai[20]; swprintf_s(str_fai, L"%lf", calcu_member.fai1);
        outtextxy(780 + ((55 - textwidth(str_fai)) / 2), 315 + (30 - textheight(str_fai)) / 2, str_fai);//居中绘制计算中间值fai
        outtextxy(40 + ((510 - textwidth(str)) / 2), 370 + (35 - textheight(str)) / 2, str);//居中绘制文字,输出负载
    }
}

//封装模式切换流程
int Mode_0change1(int calcu_WorF)
{

    button(580, 75, 100, 35, L"●负载计算");
    button(720, 75, 100, 35, L"气缸力计算");
    clearroundrect(550, 135, 635, 175, 35, 50);//清除W1
    solidroundrect(665, 315, 720, 345, 35, 50);//显示F1
    outtextxy(590, 322, L"Cylinder_F");
    calcu_WorF = 1;
    return calcu_WorF;
}

int Mode_1change0(int calcu_WorF)
{

    button(580, 75, 100, 35, L"负载计算");
    button(720, 75, 100, 35, L"●气缸力计算");
    clearroundrect(560, 315, 730, 360, 35, 50);//清除F1
    solidroundrect(580, 135, 635, 175, 35, 50);//显示W1
    outtextxy(554, 150, L"W1");
    calcu_WorF = 0;
    return calcu_WorF;
}

#endif
