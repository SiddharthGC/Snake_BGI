//SNAKE GAME - using C and graphics.h

//Created by Siddharth G.C - 15Z348

//Last modified : 12:40 A.M.,Wednesday,03/08/2016.

                                                            //Header files
#include <stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
                                                            //Global variables
int xpos,ypos,GameOver = 0,MainWindow;

void intro_screen()                                         //Intro screen function
    {
        int i;
        int width1 = textwidth("SIDDHARTH G.C PRESENTS");
        int height1 = textheight("SIDDHARTH G.C PRESENTS");
        int maxx = getmaxx();
        int maxy = getmaxy();
        for(i=0;i<15;i++)
        {
            setfillstyle(SOLID_FILL,i);
            bar(0+i*12,0+i*12,maxx-i*12,maxy-i*12);
            delay(500);
        }
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,0);
            bar(0+i*12,0+i*12,maxx-i*12,maxy-i*12);
        outtextxy(maxx/2 - width1/2,maxy/2 - height1/2 - 60,"SIDDHARTH G.C PRESENTS");
        delay(2000);
        setcolor(WHITE);
        settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
        int width2 = textwidth("SNAKE");
        int height2 = textheight("SNAKE");
        outtextxy(maxx/2 - width2/2,maxy/2 - height2/2 +15,"SNAKE");
        delay(2000);
        settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
        int width3 = textwidth("Press any key to begin");
        int height3 = textheight("Press any key to begin");
        outtextxy(maxx/2 - width3/2,maxy/2 - height3/2 + 100,"Press any key to begin");
        getch();
    }

int menu_screen()                                           //Main menu and navigation
{
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL,GREEN);
    int maxx = getmaxx();
    int maxy = getmaxy();
    setcolor(GREEN);
    rectangle(9,9,maxx-9,maxy-9);
    setfillstyle(10,BLUE);
    bar(10,10,maxx-10,maxy-10);
    setfillstyle(SOLID_FILL,GREEN);
    bar(230,269,780,355);
    bar(230,420,780,506);
    bar(230,571,780,657);
    setcolor(WHITE);
    settextstyle(3,HORIZ_DIR,6);
    outtextxy(maxx/2 - 130,160,"Main Menu");
    setbkcolor(GREEN);
    settextstyle(3,HORIZ_DIR,5);
    setcolor(BLACK);
    outtextxy(maxx/2 -121,293,"Start Game");
    outtextxy(maxx/2 -121,443,"How to play");
    outtextxy(maxx/2 -35,595,"Exit");
    while(1)
    {
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,xpos,ypos);
    if((xpos>230)&&(xpos<780)&&(ypos>269)&&(ypos<355))
    {
        return 1;
    }
    else  if((xpos>230)&&(xpos<780)&&(ypos>420)&&(ypos<506))
    {
        return 2;
    }
    else  if((xpos>230)&&(xpos<780)&&(ypos>571)&&(ypos<657))
    {
        return 3;
    }
    else
    {
     continue;
    }
}
}

void game_screen()                                          //The most important function - handles all the gameplay and visuals.
{
    srand(time(0));
    int GameWindow = initwindow(1024,768,"Snake",0,0,false,false);
    int sflag=0,score = 0,length = 7,temp,i,k=0,collide=0,temp2;
    int page=0;
    char scores[10],ch,direction = 'r';
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL,GREEN);
    int maxx = getmaxx();
    int maxy = getmaxy();
    int bound_l = maxx/2 - 401, bound_r =maxx/2 +401,bound_t = maxy/2 - 161,bound_b=maxy/2 +301;
    int startposx = (bound_r+bound_l)/2, startposy =(bound_b+bound_t)/2;
    int headposx[300],headposy[300];
    headposx[0] = startposx;headposy[0] = startposy;
    for(i=10;i<(length+1)*10;i+=10)
    {
        headposx[k] = startposx-i;
        headposy[k] = startposy;
        k++;
    }
    k=0;
    i=0;
    int frposx,frposy,setter = 0;
    while(1)
    {
       setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        setcolor(GREEN);
        rectangle(9,9,maxx-9,maxy-9);
     setfillstyle(10,BLUE);
    bar(10,10,maxx-10,maxy-10);
    setfillstyle(SOLID_FILL,BLACK);
    bar(maxx/2-400,maxy/2 -160 ,maxx/2 +400,maxy/2 +300);
    setcolor(GREEN);
    rectangle(bound_l,bound_t,bound_r,bound_b);
    rectangle(bound_l-1,bound_t-1,bound_r+1,bound_b+1);
    rectangle(bound_l-3,bound_t-3,bound_r+3,bound_b+3);
    rectangle(bound_l-4,bound_t-4,bound_r+4,bound_b+4);
    if(setter==0)
    {
        frposx = (bound_l+5) + (rand() % ( (bound_r-5) - (bound_l+5) + 1 ) );
        frposy = (bound_t+5) + (rand() % ( (bound_b-5) - (bound_t+5) + 1 ) );
        setter = 1;
    }
    setfillstyle(SOLID_FILL,RED);
    setcolor(GREEN);
        rectangle(frposx-5,frposy-5,frposx+5,frposy+5);
        floodfill(frposx,frposy,GREEN);
        if((frposx-5<=headposx[0])&&(frposy-5<=headposy[0])&&(frposx+5>=headposx[0])&&(frposy+5>=headposy[0]))
        {
            score+=200;
            length++;
            setter = 0;
        }
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(3,HORIZ_DIR,5);
    sprintf(scores,"%d",score);
    outtextxy(maxx/2-95,maxy/2 - 250,"Score : ");
    outtextxy(maxx/2 + 65,maxy/2-250,scores);
    setcolor(GREEN);
     if( kbhit() )
     {
         sflag++;
     ch=getch(); if(ch==0) ch=getch();
     if(ch==72&& direction!=2) direction=1;
     if(ch==80&& direction!=1) direction=2;
     if(ch==75&& direction!=4) direction=3;
     if(ch==77&& direction!=3) direction=4;
      }
    if(i<7){
		   headposx[i]=startposx;
		   headposy[i]=startposy;
		   i++;
	       }

    if(i>=7)
    {
    for(k=length;k>=0;k--)
      {
       headposx[1+k]=headposx[k];
       headposy[1+k]=headposy[k];
      }
    headposx[0]=startposx;
    headposy[0]=startposy;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,CYAN);
    circle(headposx[0],headposy[0],5);
    floodfill(headposx[0],headposy[0],WHITE);
    setcolor(WHITE);
     for(k=1;k<length;k++)
    {
        setfillstyle(SOLID_FILL,GREEN);
        circle(headposx[k],headposy[k],5);
        floodfill(headposx[k],headposy[k],WHITE);
    }
    }
    if(direction==1)  startposy =  startposy-10;
    if(direction==2)  startposy =  startposy+10;
    if(direction==3)  startposx =  startposx-10;
    if(direction==4)  startposx =  startposx+10;
    if(direction==0){  startposy = startposy+10 ;  startposx=startposx+10; }
    if((sflag >= 1)&&(sflag<=16))
    {
        sflag++;
    }
    if(sflag>=16)
    {
    for(temp2=1;temp2<length;temp2++)
    {
    if(headposx[0]==headposx[temp2] && headposy[0]==headposy[temp2])
        {collide = 1;}
    }
    }
      page = 1-page;
      delay(50);
      if((startposy>=bound_b)||(startposx>=bound_r)||(startposx<=bound_l)||(startposy<=bound_t)||(collide==1))
      {
          setactivepage(0);
          setvisualpage(0);
          cleardevice();
          setcolor(WHITE);
          setbkcolor(BLACK);
          outtextxy(maxx/2-150,maxy/2 - 300,"GAME OVER");
          delay(3000);
          sprintf(scores,"SCORE : %d",score);
          outtextxy(maxx/2-145,maxy/2,scores);
          delay(5000);
          break;
      }
}
closegraph(GameWindow);
setcurrentwindow(MainWindow);
}

void howtoplay()                                            //The tutorial screen
{
setbkcolor(BLACK);
    setfillstyle(SOLID_FILL,GREEN);
    int maxx = getmaxx();
    int maxy = getmaxy();
    setcolor(GREEN);
    rectangle(9,9,maxx-9,maxy-9);
    setfillstyle(10,BLUE);
    bar(10,10,maxx-10,maxy-10);
    int mid_x = textwidth("INSTRUCTIONS");
    int mid_y = textheight("INSTRUCTIONS");
    outtextxy(maxx/2 - mid_x/2, maxy/2 - mid_y/2 - 250, "INSTRUCTIONS");
    line(maxx/2 - mid_x/2 - 20, maxy/2 - mid_y/2 - 200, maxx/2 - mid_x/2 + 370,maxy/2 - mid_y/2 - 200);
    line(maxx/2 - mid_x/2 - 20, maxy/2 - mid_y/2 - 201, maxx/2 - mid_x/2 + 370,maxy/2 - mid_y/2 - 201);
    line(maxx/2 - mid_x/2 - 20, maxy/2 - mid_y/2 - 199, maxx/2 - mid_x/2 + 370,maxy/2 - mid_y/2 - 199);
    setfillstyle(SOLID_FILL,GREEN);
    bar(20,20,120,60);
    setbkcolor(GREEN);
    setcolor(BLACK);
    settextstyle(3,HORIZ_DIR,3);
    outtextxy(41,28,"BACK");
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(3,HORIZ_DIR,WHITE);
    outtextxy(140,220,"1. Use the up, down, left and right arrow keys");
    outtextxy(180,255,"to move the snake.");
    outtextxy(140,320,"2. Eat the fruits to increase your score and size.");
    outtextxy(140,385,"3. Each fruit increases your score by 200 points.");
    outtextxy(140,450,"4. Avoid collision with the walls and yourself,");
    outtextxy(177,485,"as either one of these will end the game.");
    outtextxy(maxx/2 - 120,590,"GOOD LUCK !");
    while(1)
    {
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
      delay(0);
    }
    getmouseclick(WM_LBUTTONDOWN,xpos,ypos);
    if((xpos>20)&&(xpos<120)&&(ypos>20)&&(ypos<60))
        break;
         else
    continue;
}
}

void credits_screen()                                       //End credits screen
{
                    initwindow(800,600,"CREDITS",0,0,false,true);
                    int maxx = getmaxx();
                    int maxy = getmaxy();
                    settextstyle(2,HORIZ_DIR,10);
                    setcolor(GREEN);
                    rectangle(9,9,maxx-9,maxy-9);
                    setfillstyle(10,BLUE);
                    bar(10,10,maxx-10,maxy-10);
                    int mid_x = textwidth("CREDITS");
                    int mid_y = textheight("CREDITS");
                    outtextxy(maxx/2 - mid_x/2, maxy/2 - mid_y/2 - 250, "CREDITS");
                    line(maxx/2 - mid_x/2 - 20, maxy/2 - mid_y/2 - 200, maxx/2 - mid_x/2 + 230,maxy/2 - mid_y/2 - 200);
                    setcolor(WHITE);
                    settextstyle(2,HORIZ_DIR,8);
                    outtextxy(100,130,"CREATED BY :");
                   outtextxy(100,200,"SIDDHARTH G.C ....................................................15Z348");
                   settextstyle(2,HORIZ_DIR,9);
                    setcolor(GREEN);
                   mid_x = textwidth("DISCLAIMER");
                    mid_y = textheight("DISCLAIMER");
                   outtextxy(maxx/2 - mid_x/2 + 6, maxy/2 - mid_y/2 + 40, "DISCLAIMER");
                   setcolor(WHITE);
                    settextstyle(2,HORIZ_DIR,8);
                   outtextxy(80,360,"This is merely a student project. I do not claim to own ");
                    outtextxy(57,390,"the rights to the SNAKE game, and I'm pretty sure no one ");
                    outtextxy(340,420,"really does.");
                    outtextxy(290,490,"Thanks for playing");
                    getch();
                    closegraph();
}

int main()                                                  //Main function
{
    MainWindow = initwindow(1024,768,"Snake",0,0,false,false);
    intro_screen();
    while(GameOver!=1)
    {
    int Choice = menu_screen();
    switch(Choice)
    {
    case 1:
        game_screen();
        break;
    case 2:
        howtoplay();
        break;
    case 3:
        GameOver=1;
        closegraph(MainWindow);
        credits_screen();
        break;
    }
    }
   printf("Siddharth G.C - 15Z348");
   return 0;
}
