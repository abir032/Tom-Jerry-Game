#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<graphics.h>
#include <windows.h>
#include<fstream>

using namespace std;
int k=0;
int position=0;
static int data=0;
class road
{
protected:

    int i;
public:
    void roads()
    {
        setcolor(WHITE);
        line(0,390,63999,390);  ///ROAD
        line(0,391,63999,390);  ///ROAD
    }
};

class chease:virtual public road
{
protected:
    int d;
    int score=0;
public:
    void showChease(int i)
    {
        setcolor(YELLOW);
        d=105+i;
        circle(d,380,7);
        circle(105+i,380,5);
        delay(5);
        cleardevice();
    }
    int rChease1()
    {
        return d;
    }
    int rScore()
    {
        return score+=5;
    }
};
class tom:virtual public road
{
protected:
//    int position;
    int life_decrement;
    int t1;
    //int randomTom[500];
public:
    void showTom(int);
    //void set_random();
    int rTom1()
    {
        return t1;
    }

};
class jerry: public tom,public chease
{
//    int position;
    int life;
    int j;

public:
    void inputForJump();
    void setLife()
    {
        life=3;
    }
    void showJerry();
    void jump(int);

    int life_()
    {
        life--;
        return life;
    }
    int rJerry1()
    {
        return j;
    }
    void showHighScore();

    void EditHighScore(int );

    void chackHighScore( int );
};

void tom::showTom(int i)
{
    ///Tom
    setcolor(BLUE);
    arc(167+i,320,30,60,-50);  ///tail
    circle(95+i,345,30);
    circle(95+i,345,29);
    circle(95+i,345,28);
    circle(51+i,350,15);
    circle(51+i,350,14);
    circle(52+i,350,6);
    circle(52+i,350,5);
    arc(-7+i,370,30,45,50);
    t1=72+i;
    arc(t1,320,30,45,-50);
    arc(135+i,350,30,53,-50);
    arc(150+i,350,30,53,-50);

    delay(1);
    cleardevice();
}

void jerry::showJerry()
{
    ///show jerry
    setcolor(RED);
    arc(50,330,30,50,-50);
    circle(35,370,17);
    circle(35,370,16);
    circle(35,370,15);
    circle(60,375,7);
    circle(63,375,2);
    arc(-10,416,30,40,50);
    arc(0,416,30,40,50);
    arc(31,410,30,40,50);
    arc(31,404,30,40,50);

    delay(3);

}

void jerry::jump(int i)
{
    ///jerry
    setcolor(RED);
    arc(50,330-i,30,50,-50);
    circle(35,370-i,17);
    circle(35,370-i,16);
    circle(35,370-i,15);
    j=375-i;
    circle(60,j,7);
    circle(63,375-i,2);
    arc(-10,416-i,30,40,50);
    arc(0,416-i,30,40,50);
    arc(31,410-i,30,40,50);
    arc(31,404-i,30,40,50);

    delay(1);
    cleardevice();
}

void jerry::inputForJump()
{
    if(_kbhit())
    {
        if(_getch()=='w')
        {
            k=6;
            jump(k);
        }
    }
}


void jerry::showHighScore()
{

   ifstream infile;
   infile.open("hiscore.txt");

   infile >> data;

    cout<<endl<<endl<<"High Score : "<<data<<endl<<endl;

}

void jerry::EditHighScore(int f )
{
    ofstream outfile;
   outfile.open("hiscore.txt");

    outfile<<f;
}


void jerry::chackHighScore( int p)
{
   ifstream infile;
   infile.open("hiscore.txt");

   infile >> data;


    if(data<p)
    {
        cout<<"                       Your made new high score ^_^"<<endl<<endl;
        EditHighScore(p);
    }


   infile.close();

}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
    tom tom1,tom2,tom3,tom4;
    jerry j;
    chease chs1,chs2,chs3,chs4,chs5;

    int t1=600;
    int t2=600;
    int t3=600;
    int t4=600;
    int c1=500;
    int c2=500;
    int c3=500;
    int c4=500;
    int c5=500;

    int r=0;
    int mdb;
    int md=0;
    int x=0;
    int z=0;

    while(x!=1)
    {
        cout<<"------------------------------> Tom && Jerry <---------------------------------"<<endl<<endl<<endl;
        cout<<"                              1.Start Game     "<<endl;
        cout<<"                              2.Help           "<<endl;
        cout<<"                              3.Exit           "<<endl;

        cout<<"                            Select option      "<<endl;
        cout<<"                                 ";
//        PlaySoundA(TEXT("tom__jerry_8-bit"),NULL,SND_FILENAME|SND_ALIAS);
        cin>>x;

        if(x==1)
        {
            j.showHighScore();
            cout<<endl<<"Enter S to start the game: ";

            while(1)
            {

                if(_kbhit())
                {
                    if(_getch()=='s' || _getch()=='S')
                    {
                        j.setLife();
                        cout<<endl<<endl<<"Life: 3"<<endl;
                        cout<<endl<<"Score: 0"<<endl;
                        while(1)
                        {
                            //Playsound(TEXT("tom__jerry_8-bit.mp3"),NULL,SND_FILENAME | SND_ALIAS);
                            while(1)
                            {
                                j.roads();
                                if(k==0)
                                    j.inputForJump();
                                if(k==0){
                                    j.showJerry();
                                }
                                if(k>0 && k<=150)
                                {
                                    if(r==0)
                                    {
                                        k+=6;
                                        j.jump(k);
                                        if(k==150)
                                            r=1;

                                    }
                                    else if(r==1)
                                    {
                                        k-=6;
                                        j.jump(k);
                                        if(k==0)
                                            r=0;
                                    }

                                }
                                position+=1;

                                ///coming Tom
                                if(position>50 && t1>-50)// position<180 )//tom1.rTom1()>-100 )//&& md<25)
                                {
                                    t1-=7;
                                    tom1.showTom(t1);
                                }

                                if(position>110 && t2>-50 && md>=25)//&& position<240
                                {
                                    t2-=7;
                                    tom2.showTom(t2);
                                }

                                if(position>150 && t3>-50 && md>=50)//&& position<280
                                {
                                    t3-=7;
                                    tom3.showTom(t3);
                                }

                                if(position>200 && t4>-50 && md>=75)//&& position<280
                                {
                                    t4-=7;
                                    tom4.showTom(t4);
                                }

                                ///coming chease
                                if(position>0 && c1>-100)
                                {
                                    c1-=5;
                                    chs1.showChease(c1);
                                }
                                if(position>30 && c2>-100)
                                {
                                    c2-=5;
                                    chs2.showChease(c2);
                                }

                                if(position>80 && c3>-100 )
                                {
                                    c3-=5;
                                    chs3.showChease(c3);
                                }
                                if(position>120 && c4>-100 )
                                {
                                    c4-=5;
                                    chs4.showChease(c4);
                                }
                                if(position>180 && c5>-100 && md>=50)
                                {
                                    c5-=5;
                                    chs5.showChease(c5);
                                }

                                //cleardevice();


                                if(position==250 && md<25)
                                {
                                    position=0;

                                    t1=600;
                                    t2=600;
                                    t3=600;
                                    t4=600;

                                    c1=500;
                                    c2=500;
                                    c3=500;
                                    c4=500;
                                    c5=500;
                                    break;
                                }
                                else if(position==300 && md<50)
                                {
                                    position=0;

                                    t1=600;
                                    t2=600;
                                    t3=600;
                                    t4=600;

                                    c1=500;
                                    c2=500;
                                    c3=500;
                                    c4=500;
                                    c5=500;
                                    break;
                                }
                                else if(position==350 && md<75)
                                {
                                    position=0;

                                    t1=600;
                                    t2=600;
                                    t3=600;
                                    t4=600;

                                    c1=500;
                                    c2=500;
                                    c3=500;
                                    c4=500;
                                    c5=500;
                                    break;
                                }
                                else if(position==380 && md<100)
                                {
                                    position=0;

                                    t1=600;
                                    t2=600;
                                    t3=600;
                                    t4=600;

                                    c1=500;
                                    c2=500;
                                    c3=500;
                                    c4=500;
                                    c5=500;
                                    break;
                                }
                                else if(position==400 && md>=100)
                                {
                                    position=0;

                                    t1=600;
                                    t2=600;
                                    t3=600;
                                    t4=600;

                                    c1=500;
                                    c2=500;
                                    c3=500;
                                    c4=500;
                                    c5=500;
                                    break;
                                }
                                j.roads();



                                if(tom1.rTom1()== 42|| tom2.rTom1()==42 || tom3.rTom1()== 42|| tom4.rTom1()==42)
                                {
                                    if(k == 0)
                                    {
                                        mdb=j.life_();
                                        cout<<endl<<"Life: "<<mdb<<endl;
                                    }
                                    else if(j.rJerry1() >= 280 )
                                    {
                                        mdb=j.life_();
                                        cout<<endl<<"Life: "<<mdb<<endl;
                                    }
                                }

                                if((chs1.rChease1()<=63 && chs1.rChease1()>55 ) || (chs2.rChease1()<=63 && chs2.rChease1()>55 ) || (chs3.rChease1()<=63 && chs3.rChease1()>55 ) || (chs4.rChease1()<=63 && chs4.rChease1()>55 ) || (chs5.rChease1()<=63 && chs5.rChease1()>55 ) )//|| (chs2.rChease1()<=63 && chs2.rChease1()>55 ))
                                {

                                    if(k == 0)
                                    {
                                        md=j.rScore();
                                        cout<<endl<<"Score: "<<md<<endl;
                                    }
                                    else if(j.rJerry1()>=365)
                                    {
                                        md=j.rScore();
                                        cout<<endl<<"Score: "<<md<<endl;
                                    }
                                }

                                if(mdb==0)
                                {
                                    break;
                                }

                            }

                            if(mdb==0)
                            {
                    cout<<endl<<endl<<"                             Game Over"<<endl;
                                cout<<"                            Your Score: "<<md<<endl<<endl;

                                j.chackHighScore(md);
                                cout<<"                        Thank You For Playing. ^_^"<<endl<<endl<<endl<<endl<<endl<<endl;

                                break;
                            }
                        }
                    }
                    if(mdb==0)
                    {
                        break;
                    }
                }

            }
        }
        else if(x==2)
        {
            cout<<"Rules:"<<endl;
            cout<<"Enter S to start the game and press w for jump.you have 3 life."<<endl;
            cout<<"if you touch tom,you lost 1 life.if you lost 3 life,game over."<<endl;
            cout<<"If you touch chease,your score will be increase"<<endl<<endl;
        }
        else if(x==3)
        {
            break;
        }
        else
            cout<<"                             Wrong input"<<endl<<endl;
    }


    return 0;
}



