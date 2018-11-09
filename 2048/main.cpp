#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "winbgim.h"

void puntaje();
void port();
int comp(int);
int igual();
void limit();
void up();
void right();
void down();
void left();
int movi();
int ramd();
void cer();
int d();
int ranum();
void ranume();
void prirec(int,int,int,int);
void relle(int,int,int);
void valor();
void prinum();
void jar();
void yar(int,int,int);

typedef struct{
	int x,y,z;
}celda;

celda matrix[4][4];

int main(){
	bool finish=false;
	srand(time(NULL));
	valor();
	celda sqrt;
	celda sqr2;
	sqrt.x=12;
	sqrt.y=12;
	sqr2.x=110;
	sqr2.y=110;
	int ancho=500,alto=600;
	initwindow(ancho,alto);
	setbkcolor(BLACK);
	clearviewport();
	port();
	prirec(sqrt.x,sqrt.y,sqr2.x,sqr2.y);
	ranume();
	ranume();
	prinum();
	getch();
	do{
		int lol=movi();
		switch(lol){
			case KEY_UP:
				delay(20);
				up();
				ranume();
				cleardevice();
				prirec(12,12,110,110);
				prinum();
				break;
			case KEY_LEFT:
				delay(20);
				left();
				ranume();
				cleardevice();
				prirec(12,12,110,110);
				prinum();
				break;
			case KEY_RIGHT:
				delay(20);
				right();
				ranume();
				cleardevice();
				prirec(12,12,110,110);
				prinum();
				break;	
			case KEY_DOWN:
				delay(5);
				down();
				ranume();
				cleardevice();
				prirec(12,12,110,110);
				prinum();
				break;	
			case KEY_ESC:
				finish = true;
				break;
		}
		puntaje();
	}while(!finish);
	closegraph();
	return 0;
}
void prirec(int sqrx,int sqry,int sq2x,int sq2y){
	setcolor(WHITE);
	rectangle(6,6,485,485);
	relle(6,6,COLOR(175,174,168));
	for(int i=0;i<4;i++){	
		for(int j=0;j<4;j++){
			rectangle(sq2x+(j*122),sq2y+(i*122),sqrx+(j*122),sqry+(i*122));
			sqrx=sqrx+(j*122);
			sqry=sqry+(i*122);
			relle(sqrx,sqry,COLOR(180,175,140));
			sqrx=12;
			sqry=12;
		}
	}	
}
void relle(int sqrx,int sqry,int color){
	setfillstyle(SOLID_FILL,color);
	floodfill(sqrx+1,sqry+1,WHITE);	
}
void ranume(){
	int num,x,y;
	do{
		num=d();
		x=d();
		y=d();
	}while(matrix[x][y].z!=0);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
	if(num<2){
		matrix[x][y].z=2;
	}
	else{
		matrix[x][y].z=4;
	}			
}

void valor(){
	for(int i=0;i<4;i++){	
		for(int j=0;j<4;j++){
			matrix[i][j].x=8+(j*122);
			matrix[i][j].y=24+(i*122);
			matrix[i][j].z=0;	
		}
	}
}
int ramd(){
	int num=rand()%4;
	return num;
}
int d(){
	int x;
	x=ramd();
	return x;
}
void prinum(){
	for(int x=0;x<4;x++){	
		for(int y=0;y<4;y++){
			if(matrix[x][y].z!=0){
				yar(x,y,matrix[x][y].z);
			}
		}
	}
}
void yar(int x,int y,int mat){
	switch(mat){
		case 2:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"2");
			break;
		case 4:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"4");
			break;
		case 8:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"8");
			break;
		case 16:
			//settextstyle(EUROPEAN_FONT,HORIZ_DIR,6);
			outtextxy(matrix[x][y].y,matrix[x][y].x,"16");
			break;
		case 32:
			//settextstyle(EUROPEAN_FONT,HORIZ_DIR,6);
			outtextxy(matrix[x][y].y,matrix[x][y].x,"32");
			break;
		case 64:
			//settextstyle(EUROPEAN_FONT,HORIZ_DIR,6);
			outtextxy(matrix[x][y].y,matrix[x][y].x,"64");
			break;
		case 128:
			//settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
			outtextxy(matrix[x][y].y,matrix[x][y].x,"128");
			break;
		case 256:
			//settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
			outtextxy(matrix[x][y].y,matrix[x][y].x,"256");
			break;
		case 512:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"512");
			break;
		case 1024:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"1024");
			break;
		case 2048:
			outtextxy(matrix[x][y].y,matrix[x][y].x,"2048");
	}
}
int movi(){
	int lol;
	lol=getch();
	switch(lol){
		case KEY_UP:
			lol=KEY_UP;
			break;
		case KEY_DOWN:
			lol=KEY_DOWN;
			break;
		case KEY_RIGHT:
			lol=KEY_RIGHT;
			break;
		case KEY_LEFT:
			lol=KEY_LEFT;
			break;
	}
	return lol;
}
void up(){
    for(int y=0;y<4;y++){
    	for(int x=0;x<4;x++){
            if(matrix[x][y].z!=0){
                if(y!=0){
                    int i=1,j;
                    while(i<4){
                    	j=i-1;
                        if(matrix[x][y-i].z!=0){
                        	/*switch(y){
                        		case 1:
                        			if(matrix[x][y-i].z==matrix[x][y-j].z){
		                            	matrix[x][y-i].z=matrix[x][y-i].z+matrix[x][y-j].z;
		                            	matrix[x][y-j].z=0;
		                        	}
									break;
								case 2:
									if(matrix[x][y-i].z==matrix[x][y-j].z){
		                            	matrix[x][y-i].z=matrix[x][y-i].z+matrix[x][y-j].z;
		                            	matrix[x][y-j].z=0;
		                            	matrix[x][y-i-1].z=matrix[x][y-i-1].z;
		                            	if(matrix[x][y-i].z==matrix[x][y-j].z){
			                            	matrix[x][y-i].z=matrix[x][y-i].z+matrix[x][y-j].z;
			                            	matrix[x][y-j].z=0;
			                        	}
		                        	}
		                            break;
		                        case 3:
		                        	if(matrix[x][y-i].z==matrix[x][y-j].z){
		                            	matrix[x][y-i].z=matrix[x][y-i].z+matrix[x][y-j].z;
		                            	matrix[x][y-j].z=0;
		                            	matrix[x][y-i-1].z=matrix[x][y-i-1].z;
		                            	
		                        	}
							}*/
							if(matrix[x][y-i].z==matrix[x][y-j].z){
                            	matrix[x][y-i].z=matrix[x][y-i].z+matrix[x][y-j].z;
                            	matrix[x][y-j].z=0;
                        	}
                        	else
                        		i=5;
                        }
                        else{
                        	matrix[x][y-i].z=matrix[x][y-j].z;
	                       	matrix[x][y-j].z=0;
						}
                        y-i==0?i=5:i=i;
                        i=i+1;
                    }
                }
            }
        }
    }
}
void left(){
    for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
            if(matrix[x][y].z!=0){
                if(x!=0){
                    int i=1,j;
                    while(i<4){
                    	j=i-1;
                        if(matrix[x-i][y].z!=0){
                        	if(matrix[x-i][y].z==matrix[x-j][y].z){
                            	matrix[x-i][y].z=matrix[x-i][y].z+matrix[x-j][y].z;
                            	matrix[x-j][y].z=0;
                        	}
                        	else
                        		i=5;
                        }
                        else{
                        	matrix[x-i][y].z=matrix[x-j][y].z;
	                       	matrix[x-j][y].z=0;
						}
                        x-i==0?i=5:i=i;
                        i=i+1;
                    }
                }
            }
        }
    }
} 
void down(){
    for(int y=3;y>=0;y--){
    	for(int x=3;x>=0;x--){
            if(matrix[x][y].z!=0){
                if(y!=3){
                    int i=1,j;
                    while(i<4){
                    	j=i-1;
                        if(matrix[x][y+i].z!=0){
                        	if(matrix[x][y+i].z==matrix[x][y+j].z){
                            	matrix[x][y+i].z=matrix[x][y+i].z+matrix[x][y+j].z;
                            	matrix[x][y+j].z=0;
                        	}
                        	else
                        		i=5;
                        }
                        else{
                        	matrix[x][y+i].z=matrix[x][y+j].z;
	                       	matrix[x][y+j].z=0;
						}
                        y+i==3?i=5:i=i;
                        i=i+1;
                    }
                }
            }
        }
    }
}
void right(){
    for(int x=3;x>=0;x--){
		for(int y=3;y>=0;y--){
            if(matrix[x][y].z!=0){
                if(x!=3){
                    int i=1,j;
                    while(i<4){
                    	j=i-1;
                        if(matrix[x+i][y].z!=0){
                        	if(matrix[x+i][y].z==matrix[x+j][y].z){
                            	matrix[x+i][y].z=matrix[x+i][y].z+matrix[x+j][y].z;
                            	matrix[x+j][y].z=0;
                        	}
                        	else
                        		i=5;
                        }
                        else{
                        	matrix[x+i][y].z=matrix[x+j][y].z;
	                       	matrix[x+j][y].z=0;
						}
                        x+i==3?i=5:i=i;
                        i=i+1;
                    }
                }
            }
        }
    }
}
int comp(int mat){
	if(mat==0)
		return 0;
	else
		return 1;
}
int igual(int ma1,int ma2){
	if(ma1==ma2){
		ma1=ma1+ma2;
		ma2=0;
		return 1;
	}
	else
		return 0;	
}
void port(){
	setcolor(COLOR(146,236,24));
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,9);
	outtextxy(30,12,"2048");
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
	outtextxy(100,340,"HECHO POR:");
	outtextxy(200,360,"MANUEL BOJACA");
	outtextxy(210,380,"LEIDER CHAVERRA");
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
	outtextxy(10,200,"presione cualquier tecla para continuar");
	getch();
}
void puntaje(){
	int puntos=0;
	char puntaje[10];
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			puntos=puntos+matrix[x][y].z;
		}
	}
	
	itoa(puntos,puntaje,10);
	setcolor(YELLOW);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
	outtextxy(10,500,"score:");
	outtextxy(130,500,puntaje);
}
