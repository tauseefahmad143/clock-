#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.1415

int main()
{
    initwindow(500,500,"ANALOG CLOCK");
    
    int page=0;
    while(1)
    {
         setactivepage(page);
         setvisualpage(1-page);
         cleardevice();
         setcolor(11);
         circle(250,260,220);
         circle(250,260,175);
         circle(250,250,5);
         setcolor(10);
         circle(250,250,10);
         setcolor(WHITE);
         outtextxy(250+200*sin(1*PI/6)-5 , 250-200*cos(1*PI/6) , "1");
         outtextxy(250+200*sin(2*PI/6)-5 , 250-200*cos(2*PI/6) , "2");
         outtextxy(250+200*sin(3*PI/6)-5 , 250-200*cos(3*PI/6) , "3");
         outtextxy(250+200*sin(4*PI/6)-5 , 250-200*cos(4*PI/6) , "4");
         outtextxy(250+200*sin(5*PI/6)-5 , 250-200*cos(5*PI/6) , "5");
         outtextxy(250+200*sin(6*PI/6)-5 , 250-200*cos(6*PI/6) , "6");
         outtextxy(250+200*sin(7*PI/6)-5 , 250-200*cos(7*PI/6) , "7");
         outtextxy(250+200*sin(8*PI/6)-5 , 250-200*cos(8*PI/6) , "8");
         outtextxy(250+200*sin(9*PI/6)-10 , 250-200*cos(9*PI/6) , "9");
         outtextxy(250+200*sin(10*PI/6)-10 , 250-200*cos(10*PI/6) , "10");
         outtextxy(250+200*sin(11*PI/6)-10 , 250-200*cos(11*PI/6) , "11");
         outtextxy(250+200*sin(12*PI/6)-5 , 250-200*cos(12*PI/6) , "12");
         
         setcolor(12);
         settextstyle(4,0,2);
         outtextxy(170,180,__DATE__);
         
		 time_t now = time(0);
         tm *ltm = localtime(&now);
         system("cls");
         printf("%d,%d",ltm->tm_hour,ltm->tm_min);
         
    // Hour Hand
         setcolor(RED);
         line(250,250,250+150*sin(ltm->tm_hour * PI/6),250-150*cos(ltm->tm_hour * PI/6));
    // Minute Hand
         setcolor(GREEN);
         line(250,250,250+170*sin(ltm->tm_min * PI/30),250-190*cos(ltm->tm_min * PI/30));
    // Secod Hand
         setcolor(WHITE);
         line(250,250,250+150*sin(ltm->tm_sec * PI/30),250-150*cos(ltm->tm_sec * PI/30));
         
         if(GetAsyncKeyState(VK_RETURN))
              break;
         delay(10);
         
         page = 1-page;
    }
    
    getch();
	closegraph();
	return 0;
}

