#include "glibw32.h"
#include <math.h>
#include <windows.h>
#define PI 3.14159265358979


int main()
{
    ginit(640, 400);

    GRAPH g;
    g.window(-320, -200, 319, 199);
    g.setlinestyle(0,3);  // 線幅を３ピクセルに

    double dt = 360.0;

    g.arc(0.0, 0.0, dt, dt, 150.0, 7);// 円弧を描く

/////////////////////////////////////////////////////////
	FILE *file;
	int i,c,k,b;
	k=0;
	int a[1000];
	file = fopen("data.txt","r");
	fscanf(file,"%d",&i);
//	printf("%d",i);
	while( (a[k] = fgetc( file )) != EOF ){
//	printf( "%c", a[k] );
	k=k+1;
	}
	fclose(file);
//	for(c=0;c<i;c++){
//		a[c]=a[c+2];
//	}
//	for(c=0;c<k;c++){
//		printf("a[%d]=%c\n",c,a[c]);
//	}
//ファイル操作//
///////////////////////////////////////////////////////
	double deg,rad,len;
	double x[1000],y[1000];
	c=0;
	k=1;
	deg=360/i;
	len=150;
	rad=deg*PI/180.0;
//	printf("rad = %f\n",rad);
	for(c=0;c<i;c++){
		x[c] =len*cos(k * rad );
		y[c] =len*sin(k * rad );
		k=k+1;
//		printf("x=%f",x[c]);
//		printf("y=%f\n",y[c]);
	}
//	printf("%f\n%f\n",x,y);

//座標求めるやつ
///////////////////////////////////////////////////////
	int m,w;
	c=2;
	for(w=0;w<i;w++){
	for(m=0;m<i;m++){
		if(a[c]==49){
			g.line(x[w],y[w],x[m],y[m]);
			}
//			printf("a[%d]=%d\n",c,a[c]);
		c=c+1;
	}
	c=c+2;
	}
	

///////////////////////////////////////////////////////

//	int endfl;
//	scanf("%d",endfl);
//	exit(0);


    gend();

    return 0;
}
