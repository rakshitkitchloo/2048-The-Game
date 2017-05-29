#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<GL/glut.h>
int score;
#define maxxy 5
#define dxy  50
int mainarr[4][4];
int check=0;
bool window=false;
int highscore=0;
int rand2or4()
{
    if(rand()%4!=0)
        return 2;
    else
        return 4;
}
void compressarrayleft()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
    {
        if(mainarr[i][j]==0 && j!=3)
        {
            mainarr[i][j]=mainarr[i][j+1];
            mainarr[i][j+1]=0;
        }
    }
    for(j=0;j<4;j++)
    {
        if(mainarr[i][j]==0 && j!=3)
        {
            mainarr[i][j]=mainarr[i][j+1];
            mainarr[i][j+1]=0;
        }
    }
    for(j=0;j<4;j++)
    {
        if(mainarr[i][j]==0 && j!=3)
        {
            mainarr[i][j]=mainarr[i][j+1];
            mainarr[i][j+1]=0;
        }
    }
    }
}
void slidearrayleft()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=3;j>0;j--)
    {
        if(mainarr[i][j]!=0)
        {
            if(mainarr[i][j]==mainarr[i][j-1] && mainarr[i][j-1]==mainarr[i][j-2] && mainarr[i][j-2]!=mainarr[i][j-3])
            {
                mainarr[i][j-2]+=mainarr[i][j-1];
                mainarr[i][j-1]=mainarr[i][j];
                mainarr[i][j]=0;
                continue;
            }
            if(mainarr[i][j]==mainarr[i][j-1])
            {
                mainarr[i][j-1]=mainarr[i][j]*2;
                mainarr[i][j]=0;
            }
        }
    }
    compressarrayleft();
}
int randindex()
{
    int num=rand()%16;
    return num;
}
void insertnumber()
{

    int i,j,num;
    int flag=0;
    int count=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
    {
        if(mainarr[i][j]==0)
            i=5;
        else
            count++;
    }
    if(count==16)
    {
        check=1;
        printf("ARRAY IS FULL");
        return;
    }
    while(flag==0)
    {
        count++;
        num=randindex();
        i=num/4;
        j=num%4;
        if(mainarr[i][j]==0)
        {
            mainarr[i][j]=rand2or4();
            flag=1;
        }
    }
}
void compressarrayup()
{

     int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
    {
        if(mainarr[j][i]==0 && j!=3)
        {
            mainarr[j][i]=mainarr[j+1][i];
            mainarr[j+1][i]=0;
        }
    }
    for(j=0;j<4;j++)
    {
        if(mainarr[j][i]==0 && j!=3)
        {
            mainarr[j][i]=mainarr[j+1][i];
            mainarr[j+1][i]=0;
        }
    }
    for(j=0;j<4;j++)
    {
        if(mainarr[j][i]==0 && j!=3)
        {
            mainarr[j][i]=mainarr[j+1][i];
            mainarr[j+1][i]=0;
        }
    }
    }
}
void compressarrayright()
{
 int i,j;
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
    {
        if(mainarr[i][j]==0 && j!=0)
        {
            mainarr[i][j]=mainarr[i][j-1];
            mainarr[i][j-1]=0;
        }
    }
    for(j=3;j>0;j--)
    {
        if(mainarr[i][j]==0 && j!=0)
        {
            mainarr[i][j]=mainarr[i][j-1];
            mainarr[i][j-1]=0;
        }
    }
    for(j=3;j>0;j--)
    {
        if(mainarr[i][j]==0 && j!=0)
        {
            mainarr[i][j]=mainarr[i][j-1];
            mainarr[i][j-1]=0;
        }
    }
    }

}
void slidearrayright()
{
 int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<3;j++)
    {
        if(mainarr[i][j]!=0)
        {
            if(mainarr[i][j]==mainarr[i][j+1] && mainarr[i][j+1]==mainarr[i][j+2] && j<2 && mainarr[i][j+2]!=mainarr[i][j+3] )
            {
                mainarr[i][j+2]+=mainarr[i][j+1];
                mainarr[i][j+1]=mainarr[i][j];
                mainarr[i][j]=0;
                continue;
            }
            if(mainarr[i][j]==mainarr[i][j+1])
            {
                mainarr[i][j+1]=mainarr[i][j]*2;
                mainarr[i][j]=0;
            }
        }
    }
    compressarrayright();
}
void compressarraydown()
{
     int i,j;
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
    {
        if(mainarr[j][i]==0 && j!=0)
        {
            mainarr[j][i]=mainarr[j-1][i];
            mainarr[j-1][i]=0;
        }
    }
    for(j=3;j>0;j--)
    {
        if(mainarr[j][i]==0 && j!=0)
        {
            mainarr[j][i]=mainarr[j-1][i];
            mainarr[j-1][i]=0;
        }
    }
     for(j=3;j>0;j--)
    {
        if(mainarr[j][i]==0 && j!=0)
        {
            mainarr[j][i]=mainarr[j-1][i];
            mainarr[j-1][i]=0;
        }
    }
    }
}
void slidearraydown()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<3;j++)
    {
        if(mainarr[j][i]!=0)
        {
            if(mainarr[j][i]==mainarr[j+1][i] && mainarr[j+1][i]==mainarr[j+2][i] && mainarr[j+2][i]!=mainarr[j+3][i])
            {
                mainarr[j+2][i]+=mainarr[j+1][i];
                mainarr[j+1][i]=mainarr[j][i];
                mainarr[j][i]=0;
                continue;
            }
            if(mainarr[j][i]==mainarr[j+1][i])
            {
                mainarr[j+1][i]=mainarr[j][i]*2;
                mainarr[j][i]=0;
            }
        }
    }
    compressarraydown();
}
void slidearrayup()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=3;j>0;j--)
    {
        if(mainarr[j][i]!=0)
        {
            if(mainarr[j][i]==mainarr[j-1][i] && mainarr[j-1][i]==mainarr[j-2][i] && mainarr[j-2][i]!=mainarr[j-3][i])
            {
                mainarr[j-2][i]+=mainarr[j-1][i];
                mainarr[j-1][i]=mainarr[j][i];
                mainarr[j][i]=0;
                continue;
            }
            if(mainarr[j][i]==mainarr[j-1][i])
            {
                mainarr[j-1][i]=mainarr[j][i]*2;
                mainarr[j][i]=0;
            }
        }
    }
    compressarrayup();
}
void startboard()
{
    insertnumber();
    insertnumber();
}
int maxelement()
{
    int m=-10;
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
    {
        if(mainarr[i][j]>m)
            m=mainarr[i][j];
    }
    return m;
}

double x[50]={0.0},y[50]={0.0};
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5);
    //glLineWidth(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,399.0,0.0,300.0);
    glutPostRedisplay();
}
void drawStrokeText(char str[250],int x,int y,int z,float p1,float p2)
{
      int i;
	  glPushMatrix();
	  glTranslatef(x, y,z);
	  glScalef(p1,p2,z);

	  for (i=0;str[i]!='\0';i++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , str[i]);
	  }
	  glPopMatrix();
}
void makebox(int type, double x0,double y0, double x1,double y1, double x2, double y2, double x3,double y3)
{
    glLineWidth(1);
    switch(type)
        {
        case 2:
          glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("2",x3+20,y3+20,0,0.1,0.1);
            break;
        case 4:
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("4",x3+20,y3+20,0,0.1,0.1);
            break;
        case 8:
            glColor3f(0.0,0.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("8",x3+20,y3+20,0,0.1,0.1);
            break;
        case 16:
            glColor3f(0.5,0,1);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("16",x3+18,y3+20,0,0.1,0.1);
            break;
        case 32:
           glColor3f(1.0,0.5,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("32",x3+18,y3+20,0,0.1,0.1);
            break;
        case 64:
           glColor3f(0.0,1.0,0.5);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("64",x3+18,y3+20,0,0.1,0.1);
            break;
        case 128:
           glColor3f(0.8,1,0.8);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("128",x3+14,y3+20,0,0.1,0.1);
            break;
        case 256:
            glColor3f(0.5,0.5,0.5);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("256",x3+14,y3+20,0,0.1,0.1);
            break;
        case 512:
            glColor3f(0.3,0.5,0.9);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("512",x3+14,y3+20,0,0.1,0.1);
            break;
        case 1024:
           glColor3f(1.0,0.3,0.9);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("1024",x3+12,y3+20,0,0.1,0.1);
            break;
        case 2048:
            glColor3f(0.6,0.7,0.2);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawStrokeText("2048",x3+12,y3+20,0,0.1,0.1);
            break;
        case 0:
           glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(x0,y0);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();
            break;
        default: break;
       }
}
void updatehighscore()
{

        FILE *fp;
        if((fp=fopen("highscore.txt","w"))==NULL)
        {
            printf("Cannot open the file");
        }

        fprintf(fp,"%d",highscore);
        fclose(fp);
}
void calscore()
{
    score=0;
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
    {
        score+=mainarr[i][j];
    }
}
void game_window()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2d(2,2);
    glVertex2d(397,2);
    glVertex2d(397,297);
    glVertex2d(2,297);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    drawStrokeText("2048 - The Game",70,250,0,0.20,0.20);
    glColor3f(0.0,0.5,0.0);
    drawStrokeText("Score",320,200,0,0.1,0.1);
    char str[10];
    calscore();
    sprintf(str,"%d\0",score);
    drawStrokeText(str,327,180,0,0.1,0.1);
    drawStrokeText("High Score",310,150,0,0.1,0.1);
    if(score>highscore)
    {
        highscore=score;
    }
    char str1[10];
     sprintf(str1,"%d\0",highscore);
    drawStrokeText(str1,327,130,0,0.1,0.1);

    int i,j;
    int x0=45,y0=30;
    for(i=0;i<maxxy;i++)
        x[i]=x0+i*dxy;
    for(i=0;i<maxxy;i++)
        y[i]=y0+((4-i)*dxy);
    glColor3f(1.0,0.5,0.0);
    for(j=0;j<maxxy-1;j++)
        for(i=0;i<maxxy-1;i++)
            {
                glBegin(GL_LINE_LOOP);
                glVertex2d(x[i],y[j]);
                glVertex2d(x[i+1],y[j]);
                glVertex2d(x[i+1],y[j+1]);
                glVertex2d(x[i],y[j+1]);
                glEnd();
            }
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(300,40);
    glVertex2f(300,222);
    glEnd();

    i=0;
    j=0;
   char ch;
    if(maxelement()<=2048)
    {
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            printf("%d\t",mainarr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    for( j=0;j<4;j++)
        for(i=0;i<4;i++)
    {
        makebox(mainarr[j][i], x[i]+1.5,y[j]-1.5,x[i+1]-1.5,y[j]-1.5,x[i+1]-1.5,y[j+1]+1.5,x[i]+1.5,y[j+1]+1.5);
    }
    }
    glLineWidth(2);
    glColor3f(1.0,0.5,0.0);
    for(j=0;j<maxxy-1;j++)
        for(i=0;i<maxxy-1;i++)
            {
                glBegin(GL_LINE_LOOP);
                glVertex2d(x[i],y[j]);
                glVertex2d(x[i+1],y[j]);
                glVertex2d(x[i+1],y[j+1]);
                glVertex2d(x[i],y[j+1]);
                glEnd();
            }
    glutSwapBuffers();
}
void myKey(unsigned char key,int x,int y)
{
    if(key=='q'||key=='Q')
    {
        exit(1);
    }
    else if(key=='p'||key=='P')
    {
        window=true;
    }
    else if(key=='w'|| key=='W')
        {
            slidearrayup();
            insertnumber();
        }
    else if(key=='a'|| key=='A')
        {
            slidearrayleft();
            insertnumber();
        }
    else if(key=='d'||key=='D')
        {
            slidearrayright();
            insertnumber();
        }
    else if(key=='s'||key=='S')
        {
            slidearraydown();
            insertnumber();
        }
}
void initial_window()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2d(2,2);
    glVertex2d(397,2);
    glVertex2d(397,297);
    glVertex2d(2,297);
    glEnd();
    glColor3f(0.0,0.0,1.0);
    drawStrokeText("2048 - The Game",70,250,0,0.20,0.20);
    glColor3f(0.0,0.8,1.0);
    drawStrokeText("RULES:",20,200,0,0.12,0.12);
    drawStrokeText("1. Objective of the game is to get the number 2048.",20,180,0,0.08,0.08);
    drawStrokeText("2. You will have a grid of 16 tiles.",20,160,0,0.08,0.08);
    drawStrokeText("3. Move using arrow keys to join two equal numbers.",20,140,0,0.09,0.08);
    drawStrokeText("4. When two equal numbers are in touch, they will add up.",20,120,0,0.08,0.08);
    drawStrokeText("5. If there are no free tiles on our grid, the game ends.",20,100,0,0.08,0.08);
    drawStrokeText("Press P to Play.                  Press Q to Quit.",20,60,0,0.08,0.08);
    glFlush();
    glutSwapBuffers();
}
void display()
{
    if(window)
    {
        if(check==1)
        {
             drawStrokeText("You Lost it",20,100,0,0.2,0.2);
             glutSwapBuffers();
        }
        else if(maxelement()==2048)
        {

            drawStrokeText("YOU WIN",20,100,0,0.2,0.2);
             glutSwapBuffers();
        }
        else
        game_window();
    }
    else
        initial_window();
}

void idle()
{
    glutPostRedisplay();
}
int main(int argc,char **argv)
{
    int i,j;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("2048 - The Game !");
    startboard();
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutIdleFunc(idle);
    FILE *fp;
    if((fp=fopen("highscore.txt","r"))==NULL)
    {
        printf("Cannot open the file");
        //exit(1);
    }
    fscanf(fp,"%d",&highscore);
    printf("%d",highscore);
    fclose(fp);
    atexit(updatehighscore);
    glutMainLoop();
    return 0;
}
