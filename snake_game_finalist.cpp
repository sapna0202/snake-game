#include<graphics.h>
#include<iostream>
using namespace std;

int endfun(int endgame){
	endgame=endgame-1;
	bar(0,0,640,480);
	system("cls");
	cout<<"YOUR SCORE: "<<endgame;
}

int bars(int x,int y){
	
	int d=0,dir=1,fx=200,fy=200,f=0;
	
	for(;;){

	    setfillstyle(1,2);
	    bar(0,0,20,640);
	    bar(0,0,640,20);
	    bar(620,0,650,640);
	    bar(0,640,640,457);
	    
	    if(x==fx && y==fy){
	    	f=f+1;
	    	setfillstyle(1,2);
	    	bar(fx,fy,fx+20,fy+20);
	    	
	    	do{
	    		fx=rand()%650;
	    		fy=rand()%450;
			}while(getpixel(fx,fy)!=0 && fx>0 && fy>0);
			fx=fx/20;
			fx=fx*20;
			fy=fy/20;
			fy=fy*20;
		}
		bar(fx,fy,fx+20,fy+20);
	    
	    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
	    else if(GetAsyncKeyState(VK_LEFT)){d=2;}
	    else if(GetAsyncKeyState(VK_UP)){d=3;}
	    else if(GetAsyncKeyState(VK_DOWN)){d=4;}
	    else{d=0;}
	    
	    switch(d){
	    	case 0:
	    		if(dir==1){x=x+20;}
	    		else if(dir==2){x=x-20;}
	    		else if(dir==3){y=y-20;}
	    		else if(dir==4){y=y+20;}
	    	break;
	    	
	    	case 1:
	    		x=x+20;
	    		dir=1;
	    		break;
	    	
	    	case 2:
	    		x=x-20;
	    		dir=2;
	    		break;
	    		
	    	case 3:
	    		dir=3;
	    		y=y-20;
	    		break;
	    		
	    	case 4:
	    		dir=4;
	    		y=y+20;
	    		break;
		}
	    
	    bar(x,y,x+20,y+20);
	    delay(100);
	    cleardevice();
	    if(x>=640||x<=0||y<=0||y>=480){
	    	endfun(f);
	    	break;
		}
	}	
}

int main(){
	int  gd=DETECT,gm ;
	initgraph(&gd,&gm,"");
	
	bars(200,200);
	getch();
		closegraph();
	return 0;
}
