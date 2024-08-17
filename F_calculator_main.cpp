//用于计算气缸式重力补偿机构相应参数下所需气缸力与负载
//XUANKUDE

#include <graphics.h>
#include <conio.h>
#include <string>
#include <sstream>
#include"calculator.h"
#include"easyx_unit_encapsulation.h"

int main() {
    // 初始化图形窗口，颜色为米黄色
    initgraph(840, 480);
    setbkcolor(RGB(235, 231, 228));
    //气缸参数
    setbkmode(TRANSPARENT);//文字显示去背景
    solidroundrect(205, 315, 260, 345, 35, 50); outtextxy(130, 322, L"Cylinder_d");
    solidroundrect(435, 315, 490, 345, 35, 50); outtextxy(360, 322, L"Cylinder_p");
    solidroundrect(665, 315, 720, 345, 35, 50); outtextxy(590, 322, L"Cylinder_F");
    //臂单元结构参数
    solidroundrect(580, 135, 635, 175, 35, 50); outtextxy(554, 150, L"W1");
    solidroundrect(580, 190, 635, 225, 35, 50); outtextxy(554, 205, L"S1");
    solidroundrect(580, 245, 635, 280, 35, 50); outtextxy(554, 260, L"Lg1");
    solidroundrect(680, 135, 735, 175, 35, 50); outtextxy(654, 150, L"L1");
    solidroundrect(680, 190, 735, 225, 35, 50); outtextxy(654, 205, L"l1");
    solidroundrect(680, 245, 735, 280, 35, 50); outtextxy(654, 260, L"θ");
    solidroundrect(780, 135, 835, 175, 35, 50); outtextxy(754, 150, L"b1");
    solidroundrect(780, 190, 835, 225, 35, 50); outtextxy(754, 205, L"ψ");
    solidroundrect(780, 245, 835, 280, 35, 50); outtextxy(754, 260, L"Wa1");
    solidroundrect(780, 315, 835, 345, 35, 50); outtextxy(754, 322, L"Φ");

    //初始化参数
    calculator_nt calcu_member;//定义一个计算结构体变量
    IMAGE data_intro;//定义图片信息结构体变量
    ExMessage msg;//定义鼠标信息结构体变量
    int calcu_WorF = 0;//计算模式标识，0表示气缸力计算，1表示负载计算

    //清屏
    cleardevice();

    //界面名
    settextcolor(0);
    outtextxy(50, 30, L"F_calculator");

    //示意图
    loadimage(&data_intro, L"data_intro.png", 490, 220);
    putimage(40, 70, &data_intro);

    //按键
    button(580, 75, 100, 35, L"负载计算");
    button(720, 75, 100, 35, L"●气缸力计算");
    button(600, 370, 100, 35, L"计算");

    //继续绘制圆角矩形框图
    solidroundrect(40, 370, 550, 405, 35, 50);//输出框

    //气缸参数
    solidroundrect(205, 315, 260, 345, 35, 50); outtextxy(130, 322, L"Cylinder_d");
    solidroundrect(435, 315, 490, 345, 35, 50); outtextxy(360, 322, L"Cylinder_p");

    //臂单元结构参数
    solidroundrect(580, 135, 635, 175, 35, 50); outtextxy(554, 150, L"W1");
    solidroundrect(580, 190, 635, 225, 35, 50); outtextxy(554, 205, L"S1");
    solidroundrect(580, 245, 635, 280, 35, 50); outtextxy(554, 260, L"Lg1");
    solidroundrect(680, 135, 735, 175, 35, 50); outtextxy(654, 150, L"L1");
    solidroundrect(680, 190, 735, 225, 35, 50); outtextxy(654, 205, L"l1");
    solidroundrect(680, 245, 735, 280, 35, 50); outtextxy(654, 260, L"θ");
    solidroundrect(780, 135, 835, 175, 35, 50); outtextxy(754, 150, L"b1");
    solidroundrect(780, 190, 835, 225, 35, 50); outtextxy(754, 205, L"ψ");
    solidroundrect(780, 245, 835, 280, 35, 50); outtextxy(754, 260, L"Wa1");
    solidroundrect(780, 315, 835, 345, 35, 50); outtextxy(754, 322, L"Φ");

    while (true) {

        //获取鼠标信息
        if (peekmessage(&msg, EX_MOUSE))
        {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                //判断鼠标点击是否在按钮内
                if (msg.x >= 580 && msg.x <= 680 && msg.y >= 75 && msg.y <= 110)//点击了负载计算
                {
                    if (calcu_WorF == 1) break;
                    calcu_WorF = Mode_0change1(calcu_WorF);
                }
                if (msg.x >= 720 && msg.x <= 820 && msg.y >= 75 && msg.y <= 110)//点击了气缸力计算
                {
                    if (calcu_WorF == 0) break;
                    calcu_WorF = Mode_1change0(calcu_WorF);
                }
                if (msg.x >= 600 && msg.x <= 700 && msg.y >= 370 && msg.y <= 405)
                    Start_Calculate(calcu_member, calcu_WorF);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 135 && msg.y <= 175 && calcu_WorF == 0)//算气缸力时允许键入W1
                    calcu_member.W1 = Enter_data(580, 135, 55, 40);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 190 && msg.y <= 225)//键入S1
                    calcu_member.S1 = Enter_data(580, 190, 55, 40);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 245 && msg.y <= 280)//键入Lg1
                    calcu_member.Lg1 = Enter_data(580, 245, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 135 && msg.y <= 175)//键入L1
                    calcu_member.L1 = Enter_data(680, 135, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 190 && msg.y <= 225)//键入l1
                    calcu_member.l1 = Enter_data(680, 190, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 245 && msg.y <= 280)//键入xita
                    calcu_member.theta = Enter_data(680, 245, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 135 && msg.y <= 175)//键入b1
                    calcu_member.b1 = Enter_data(780, 135, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 190 && msg.y <= 225)//键入psi
                    calcu_member.psi = Enter_data(780, 190, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 245 && msg.y <= 280)//键入Wa1
                    calcu_member.Wa1 = Enter_data(780, 245, 55, 40);
                if (msg.x >= 205 && msg.x <= 260 && msg.y >= 315 && msg.y <= 345)//键入Cylinder_d
                    calcu_member.Cylinder_d = Enter_data(205, 315, 55, 40);
                if (msg.x >= 435 && msg.x <= 490 && msg.y >= 315 && msg.y <= 345)//键入Cylinder_p
                    calcu_member.Cylinder_p = Enter_data(435, 315, 55, 40);
                if (msg.x >= 665 && msg.x <= 720 && msg.y >= 315 && msg.y <= 345 && calcu_WorF == 1)//算负载时允许键入Cylinder_F
                    calcu_member.Cylinder_F = Enter_data(665, 315, 55, 40);
                break;
            case WM_RBUTTONDOWN:
                printf("点击了右键");//暂时没用
                break;
            }
        }

    }
    return 0;
}
