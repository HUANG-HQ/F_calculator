//���ڼ�������ʽ��������������Ӧ�����������������븺��
//XUANKUDE

#include <graphics.h>
#include <conio.h>
#include <string>
#include <sstream>
#include"calculator.h"
#include"easyx_unit_encapsulation.h"

int main() {
    // ��ʼ��ͼ�δ��ڣ���ɫΪ�׻�ɫ
    initgraph(840, 480);
    setbkcolor(RGB(235, 231, 228));
    //���ײ���
    setbkmode(TRANSPARENT);//������ʾȥ����
    solidroundrect(205, 315, 260, 345, 35, 50); outtextxy(130, 322, L"Cylinder_d");
    solidroundrect(435, 315, 490, 345, 35, 50); outtextxy(360, 322, L"Cylinder_p");
    solidroundrect(665, 315, 720, 345, 35, 50); outtextxy(590, 322, L"Cylinder_F");
    //�۵�Ԫ�ṹ����
    solidroundrect(580, 135, 635, 175, 35, 50); outtextxy(554, 150, L"W1");
    solidroundrect(580, 190, 635, 225, 35, 50); outtextxy(554, 205, L"S1");
    solidroundrect(580, 245, 635, 280, 35, 50); outtextxy(554, 260, L"Lg1");
    solidroundrect(680, 135, 735, 175, 35, 50); outtextxy(654, 150, L"L1");
    solidroundrect(680, 190, 735, 225, 35, 50); outtextxy(654, 205, L"l1");
    solidroundrect(680, 245, 735, 280, 35, 50); outtextxy(654, 260, L"��");
    solidroundrect(780, 135, 835, 175, 35, 50); outtextxy(754, 150, L"b1");
    solidroundrect(780, 190, 835, 225, 35, 50); outtextxy(754, 205, L"��");
    solidroundrect(780, 245, 835, 280, 35, 50); outtextxy(754, 260, L"Wa1");
    solidroundrect(780, 315, 835, 345, 35, 50); outtextxy(754, 322, L"��");

    //��ʼ������
    calculator_nt calcu_member;//����һ������ṹ�����
    IMAGE data_intro;//����ͼƬ��Ϣ�ṹ�����
    ExMessage msg;//���������Ϣ�ṹ�����
    int calcu_WorF = 0;//����ģʽ��ʶ��0��ʾ���������㣬1��ʾ���ؼ���

    //����
    cleardevice();

    //������
    settextcolor(0);
    outtextxy(50, 30, L"F_calculator");

    //ʾ��ͼ
    loadimage(&data_intro, L"data_intro.png", 490, 220);
    putimage(40, 70, &data_intro);

    //����
    button(580, 75, 100, 35, L"���ؼ���");
    button(720, 75, 100, 35, L"������������");
    button(600, 370, 100, 35, L"����");

    //��������Բ�Ǿ��ο�ͼ
    solidroundrect(40, 370, 550, 405, 35, 50);//�����

    //���ײ���
    solidroundrect(205, 315, 260, 345, 35, 50); outtextxy(130, 322, L"Cylinder_d");
    solidroundrect(435, 315, 490, 345, 35, 50); outtextxy(360, 322, L"Cylinder_p");

    //�۵�Ԫ�ṹ����
    solidroundrect(580, 135, 635, 175, 35, 50); outtextxy(554, 150, L"W1");
    solidroundrect(580, 190, 635, 225, 35, 50); outtextxy(554, 205, L"S1");
    solidroundrect(580, 245, 635, 280, 35, 50); outtextxy(554, 260, L"Lg1");
    solidroundrect(680, 135, 735, 175, 35, 50); outtextxy(654, 150, L"L1");
    solidroundrect(680, 190, 735, 225, 35, 50); outtextxy(654, 205, L"l1");
    solidroundrect(680, 245, 735, 280, 35, 50); outtextxy(654, 260, L"��");
    solidroundrect(780, 135, 835, 175, 35, 50); outtextxy(754, 150, L"b1");
    solidroundrect(780, 190, 835, 225, 35, 50); outtextxy(754, 205, L"��");
    solidroundrect(780, 245, 835, 280, 35, 50); outtextxy(754, 260, L"Wa1");
    solidroundrect(780, 315, 835, 345, 35, 50); outtextxy(754, 322, L"��");

    while (true) {

        //��ȡ�����Ϣ
        if (peekmessage(&msg, EX_MOUSE))
        {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                //�ж�������Ƿ��ڰ�ť��
                if (msg.x >= 580 && msg.x <= 680 && msg.y >= 75 && msg.y <= 110)//����˸��ؼ���
                {
                    if (calcu_WorF == 1) break;
                    calcu_WorF = Mode_0change1(calcu_WorF);
                }
                if (msg.x >= 720 && msg.x <= 820 && msg.y >= 75 && msg.y <= 110)//���������������
                {
                    if (calcu_WorF == 0) break;
                    calcu_WorF = Mode_1change0(calcu_WorF);
                }
                if (msg.x >= 600 && msg.x <= 700 && msg.y >= 370 && msg.y <= 405)
                    Start_Calculate(calcu_member, calcu_WorF);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 135 && msg.y <= 175 && calcu_WorF == 0)//��������ʱ�������W1
                    calcu_member.W1 = Enter_data(580, 135, 55, 40);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 190 && msg.y <= 225)//����S1
                    calcu_member.S1 = Enter_data(580, 190, 55, 40);
                if (msg.x >= 580 && msg.x <= 635 && msg.y >= 245 && msg.y <= 280)//����Lg1
                    calcu_member.Lg1 = Enter_data(580, 245, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 135 && msg.y <= 175)//����L1
                    calcu_member.L1 = Enter_data(680, 135, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 190 && msg.y <= 225)//����l1
                    calcu_member.l1 = Enter_data(680, 190, 55, 40);
                if (msg.x >= 680 && msg.x <= 735 && msg.y >= 245 && msg.y <= 280)//����xita
                    calcu_member.theta = Enter_data(680, 245, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 135 && msg.y <= 175)//����b1
                    calcu_member.b1 = Enter_data(780, 135, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 190 && msg.y <= 225)//����psi
                    calcu_member.psi = Enter_data(780, 190, 55, 40);
                if (msg.x >= 780 && msg.x <= 835 && msg.y >= 245 && msg.y <= 280)//����Wa1
                    calcu_member.Wa1 = Enter_data(780, 245, 55, 40);
                if (msg.x >= 205 && msg.x <= 260 && msg.y >= 315 && msg.y <= 345)//����Cylinder_d
                    calcu_member.Cylinder_d = Enter_data(205, 315, 55, 40);
                if (msg.x >= 435 && msg.x <= 490 && msg.y >= 315 && msg.y <= 345)//����Cylinder_p
                    calcu_member.Cylinder_p = Enter_data(435, 315, 55, 40);
                if (msg.x >= 665 && msg.x <= 720 && msg.y >= 315 && msg.y <= 345 && calcu_WorF == 1)//�㸺��ʱ�������Cylinder_F
                    calcu_member.Cylinder_F = Enter_data(665, 315, 55, 40);
                break;
            case WM_RBUTTONDOWN:
                printf("������Ҽ�");//��ʱû��
                break;
            }
        }

    }
    return 0;
}
