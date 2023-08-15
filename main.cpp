#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>


# define PI           3.14159265358979323846

bool isDay = true; // You can change this to switch between day and night mode
int _angle1 = 0;
int _boatMove = 0;
static int _boatMoveLeft = 0;
static int _boatMoveRight = 0;
float animationTime = 0.0f;
GLfloat carPositionX = -0.5f; // Initial x-axis position of the car
GLfloat carPositionY = -1.2f; // Initial y-axis position of the car
GLfloat carSpeed = 0.01f;     // Speed of the car movement



void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    _angle1 += 2;
    if (_angle1 > 1000)
        _angle1 -= 1000;

    //_boatMove += 1;
    //if (_boatMove > 500)
        //_boatMove -= 500;
        _boatMove += 2;  // Increase this value to control the speed of the boat

    if (_boatMove > glutGet(GLUT_WINDOW_WIDTH)) {
        _boatMove = 0;  // Reset the boat position to the left
    }
     _angle1 += 0.01; // Increment the angle for slow movement
    if (_angle1 > 800) // Reset the angle to loop the animation
    {
        _angle1 = 0.0;
    }

      carPositionX += carSpeed;

    // Check if the car has reached the destination
    if (carPositionX > 0.5f) {
        carPositionX = -0.5f; // Reset car position to the initial value
    }

    glutPostRedisplay();

    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}


void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
GLfloat i = 0.0f;

void circle(float a, float b, float r){

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x=a; GLfloat y=b; GLfloat radius =r;
       glBegin(GL_TRIANGLE_FAN);
       glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}   glEnd();
}


class Port
{
public:



    // ... (rest of the functions)




    void outliner()
    {
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(0, 350);
        glVertex2f(80, 450);
        glVertex2f(80, 450);
        glVertex2f(140, 380);
        glVertex2f(140, 380);
        glVertex2f(170, 300);
        glVertex2f(90, 435);
        glVertex2f(100, 455);
        glVertex2f(100, 455);
        glVertex2f(200, 300);
        glVertex2f(260, 480);
        glVertex2f(330, 360);
        glVertex2f(330, 360);
        glVertex2f(380, 300);
        glVertex2f(330, 360);
        glVertex2f(420, 450);
        glVertex2f(420, 450);
        glVertex2f(500, 370);

        glEnd();
    }


    void circle(int xx, int yy, float r)
    {

        glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin

        for (int i = 0; i < 200; i++)
        {
            // glColor3ub(255, 215, 0);
            float pi = 3.1416;
            float A = (i * 2 * pi) / 200;
            // float r = 4.0f;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x + xx, y + yy);
        }
        glEnd();
    }
    void sun()
    {
        if (isDay)
        {
            glColor3ub(252, 186, 3);    //midday sun effect
        }
        else
        {
            glColor3ub(228, 228, 228);//moon
        }

        circle(175, 440, 20);

    }
    void star() //L064
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(255, 251, 251);//white-star
        glVertex2f(-0.075, 0);
        glVertex2f(0.075, 0);

        glVertex2f(-0.05, -0.075);
        glVertex2f(0.05, 0.075);

        glVertex2f(0.05, -0.075);
        glVertex2f(-0.05, 0.075);

        glVertex2f(0, -0.1);
        glVertex2f(0, 0.1);

        glEnd();
    }
    void scaledstar()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(05, 490, 0);
        glScalef(15, 15, 0);
        star();
        glPopMatrix();
    }
    void scaledstarLoop()
    {
        scaledstar();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(5, 0, 0);

        for (int i = 0; i < 3; i++)
        {
            glTranslatef(0, -20, 0);
            scaledstar();
            for (int i = 0; i < 40; i++)
            {
                if (i % 2 == 0)
                {
                    glTranslatef(15, -35, 0);
                    scaledstar();
                }
                else
                {
                    glTranslatef(18, 35, 0);
                    scaledstar();
                }

            }
            glTranslatef(-660, -35, 0);

        }
        glPopMatrix();
    }
    void sky()

    {



        //cloud();
        if (isDay)
        {
            glBegin(GL_QUADS);
            glColor3ub(51, 190, 255);
            glVertex2f(0, 300);
            glColor3ub(107, 207, 255);
            glVertex2f(500, 300);
            glColor3ub(0, 173, 255);
            glVertex2f(500, 500);
            glColor3ub(255, 250, 241);
            glVertex2f(0, 500);

            glEnd();
        }
        else
        {

            glBegin(GL_QUADS);
            glColor3ub(7, 11, 52);
            glVertex2f(0, 300);
            glColor3ub(0, 0, 255);
            glVertex2f(500, 300);
            glColor3ub(43, 47, 119);
            glVertex2f(500, 500);
            glColor3ub(20, 24, 82);
            glVertex2f(0, 500);
            glEnd();
            scaledstarLoop();

        }

    }
    void river()
{
    glBegin(GL_QUADS);     // upper
    glColor3ub(135, 206, 235);   // Sky blue color
    glVertex2f(0, 400);
    glVertex2f(500, 400);
    glVertex2f(500, 180);
    glVertex2f(0, 180);
    glEnd();

    glBegin(GL_QUADS);     // down river
    glColor3ub(135, 206, 235);  // Dark blue color
    glVertex2f(50, 0);
    glVertex2f(500, 0);
    glVertex2f(500, 80);
    glVertex2f(0, 80);
    glEnd();

    glBegin(GL_QUADS);     // river bank
    glColor3ub(72, 67, 76);
    glVertex2f(0, 80);
    glVertex2f(500, 80);
    glVertex2f(500, 112);
    glVertex2f(0, 112);
    glEnd();


}



    void Badh()
    {

        // glColor3b(204, 102, 0); //Badh color
        glBegin(GL_POLYGON);
        glColor3ub(118, 157, 168);
        glVertex2f(0, 122);
        glColor3ub(40, 96, 120);
        glVertex2f(20, 122);
        glColor3ub(63, 51, 48);
        glVertex2f(20, 110);
        glColor3ub(172, 172, 41);
        glVertex2f(0, 110);
        glColor3ub(185, 172, 172);
        glEnd();

        //create border
        glColor3b(0, 0, 0); //border color

        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 122);
        glVertex2f(20, 122);
        glVertex2f(20, 110);
        glVertex2f(0, 110);
        glEnd();
    }



    void circle()
    {
        // glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
        // glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
        glLineWidth(7.5);
        glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
        for (int i = 0; i < 200; i++)
        {
            glColor3ub(203, 203, 203);
            float pi = 3.1416;
            float A = (i * 2 * pi) / 200;
            float r = 30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }

        //glVertex2f(0.3f,0.4f);
        //glVertex2f(0.1f,0.4f);

        glEnd();
    }

    void cloud()
    {
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glTranslatef(20, 95.5, 0);
        circle();

        glTranslatef(15, 2.5, 0);
        circle();

        glTranslatef(20, 5, 0);
        circle();

        glTranslatef(30, 2.5, 0);
        circle();

        glTranslatef(0, -2.5, 0);
        circle();

        glTranslatef(0, -5, 0);
        circle();

        glTranslatef(0, -7.5, 0);
        circle();

        glPopMatrix();

        // glutSwapBuffers();
    }

    void movingcloud()
    {
        glPushMatrix();//stationary-cloud
        glTranslatef(10, 405, 0);
        glScalef(0.5, 0.5, 0);
        cloud();
        glTranslatef(500, 0, 0);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(500, 400, 0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.5, 0.5, 1);
        glTranslatef(-(_angle1 / 2 % 1000), 0, 0);
        glPushMatrix();
        glTranslatef(-100, 0, 0);
        cloud();
        glTranslatef(200, 35, 0);
        cloud();
        glPopMatrix();
        glPopMatrix();

        glPopMatrix();
        // glutSwapBuffers();
    }

    void circle1(int xx, int yy, float r)
    {

        glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
        for (int i = 0; i < 200; i++)
        {
            // glColor3ub(255, 215, 0);
            float pi = 3.1416;
            float A = (i * 2 * pi) / 200;
            // float r = 4.0f;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x + xx, y + yy);
        }
        glEnd();
    }
    void Roadbody()
    {


        glBegin(GL_POLYGON);
        glColor3ub(204, 122, 0);
        glVertex2f(500, 180);
        glColor3ub(0, 61, 0);
        glVertex2f(500, 145);
        glColor3ub(255, 170, 0);
        glVertex2f(0, 145);
        glColor3ub(179, 89, 0);
        glVertex2f(0, 180);


        glEnd();


    }

    void road()
    {
        /* glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glTranslatef(0, 100, 0);*/
        Roadbody();
        /*glTranslatef(0, -100, 0);
        glPopMatrix();*/
    }

    void BoatBodyStick()//boitha
    {
        glBegin(GL_LINES);
        glColor3ub(165, 42, 42);//brown-stick
        glVertex2f(210, 75);
        glVertex2f(220, 10);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0, 0, 0);//brown-stick
        glVertex2f(218, 20);
        glVertex2f(220, 10);
        glVertex2f(230, 10);
        glEnd();

    }
    void BoatBodyShell()//L067//L068//L069
    {
        glBegin(GL_POLYGON);
        glColor3ub(165, 42, 42);//brown-shell
        glVertex2f(120, 30);
        glVertex2f(200, 30);
        glVertex2f(195, 55);
        glVertex2f(125, 55);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(255, 255, 0);//yellow-shell-stripe-pattern
        glVertex2f(120, 30);
        glVertex2f(200, 30);

        glVertex2f(121, 35);
        glVertex2f(199, 35);

        glVertex2f(122, 40);
        glVertex2f(198, 40);

        glVertex2f(123, 45);
        glVertex2f(197, 45);

        glVertex2f(124, 50);
        glVertex2f(196, 50);

        glVertex2f(125, 55);
        glVertex2f(195, 55);


        glEnd();


    }
    void BoatBody()
    {
        glLineWidth(1);
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);//black-base
        glVertex2f(120, 10);
        glVertex2f(200, 10);
        glVertex2f(200, 30);
        glVertex2f(120, 30);
        glEnd();
        glBegin(GL_TRIANGLES);//black-nose-front
        glVertex2f(120, 10);
        glVertex2f(120, 30);
        glVertex2f(80, 40);
        glEnd();
        glBegin(GL_TRIANGLES);//black-nose-back
        glVertex2f(200, 10);
        glVertex2f(200, 30);
        glVertex2f(240, 40);
        glEnd();

        glBegin(GL_POLYGON);//yellow-inside-shape
        glColor3ub(255, 255, 0);
        glVertex2f(240, 40);
        glVertex2f(80, 40);
        glVertex2f(120, 30);
        glVertex2f(200, 30);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(0, 0, 0);//black_stripe
        glVertex2f(205, 30);
        glVertex2f(200, 40);

        glVertex2f(210, 30);
        glVertex2f(205, 40);

        glVertex2f(215, 30);
        glVertex2f(210, 40);

        glVertex2f(220, 30);
        glVertex2f(215, 40);

        glVertex2f(225, 30);
        glVertex2f(220, 40);

        //
        glVertex2f(115, 30);
        glVertex2f(120, 40);

        glVertex2f(110, 30);
        glVertex2f(115, 40);

        glVertex2f(105, 30);
        glVertex2f(110, 40);

        glVertex2f(100, 30);
        glVertex2f(105, 40);

        glVertex2f(95, 30);
        glVertex2f(100, 40);

        glEnd();
        BoatBodyShell();

    }
    void Boatsticks()
    {
        // BoatBodyStick();
        glBegin(GL_LINES);
        glLineWidth(3);
        glColor3ub(32, 12, 2);
        glVertex2f(62, 5);
        glVertex2f(67, 55);
        glEnd();
    }
    void Boats()
    {
        if (isDay)
        {
            glPushMatrix();
            glTranslatef(310, 70, 0);
            glTranslatef(10, 310, 0);
            glTranslatef((-_boatMove / 6) % 500, 0, 0);
            glTranslatef(110, 00, 0);

            glScalef(0.3, 0.3, 0);
            BoatBody();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-40, 60, 0);
            glTranslatef(0, 310, 0);
            glTranslatef(((_boatMove / 4) % 500), 0, 0);
            glScalef(0.3, 0.3, 0);
            BoatBody();
            glTranslatef(-500, 0, 0);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(10, 310, 0);
            glTranslatef(510, 30, 0);
            glTranslatef(-(_boatMove / 6) % 520, 0, 0);
            glScalef(0.6, 0.6, 0);
            BoatBody();
            glPopMatrix();

            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glTranslatef(-100, 310, 0);
            glTranslatef((_boatMove / 3) % 500, 0, 0);
            glScalef(0.7, 0.7, 0);
            BoatBody();
            glPopMatrix();
        }
        else
        {
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glTranslatef(20, 175, 0);
            Boatsticks();

            glScalef(0.7, 0.7, 0);
            BoatBody();
            glTranslatef(105, -2, 0);
            //glScalef(0.7,0.7,0);
            BoatBody();
            glLineWidth(8);
            glTranslatef(40, 0, 0);
            Boatsticks();
            glPopMatrix();
        }
    }
    // void boatUpdate(int value)
    // {

    //    _boatMove += 1;
    //    glutPostRedisplay(); //Notify GLUT that the display has changed

    //    glutTimerFunc(20, boatUpdate, 0);

    // }

    void Container(float x, float y) //L070
    {
        glBegin(GL_POLYGON);
        glVertex2f(x, 125 + y);
        glVertex2f(x, 150 + y);
        glVertex2f(10 + x, 150 + y);
        glVertex2f(10 + x, 125 + y);
        glEnd();
    }

    void Window(float x, float y)  //L070
    {
        glBegin(GL_POLYGON);
        glVertex2f(x, 175 + y);
        glVertex2f(x, 170 + y);
        glVertex2f(5 + x, 170 + y);
        glVertex2f(5 + x, 175 + y);
        glEnd();
    }

    void Railing(float x, float y)  //L070
    {
        glLineWidth(5);
        glColor3ub(36, 36, 74);
        glBegin(GL_LINES);
        glVertex2f(x, 125 + y);
        glVertex2f(x, 135 + y);
        glEnd();
    }void Ship() //L070
    {     float scalingFactor = 0.001; // Scaling factor from pixels to centimeters

         //float scalingFactor = 0.03; // Scaling factor from pixels to centimeters

    glBegin(GL_QUADS);  // chimney
    glColor3ub(0, 0, 100);
    glVertex2f(70 * scalingFactor, 50 * scalingFactor);
    glVertex2f(65 * scalingFactor, 50 * scalingFactor);
    glVertex2f(66 * scalingFactor, 70 * scalingFactor);
    glVertex2f(69 * scalingFactor, 70 * scalingFactor);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(65 * scalingFactor, 65 * scalingFactor);
    glVertex2f(70 * scalingFactor, 65 * scalingFactor);
    glEnd();

    glBegin(GL_QUADS);  // chimney
    glColor3ub(0, 0, 100);
    glVertex2f(70 * scalingFactor, 50 * scalingFactor);
    glVertex2f(65 * scalingFactor, 50 * scalingFactor);
    glVertex2f(66 * scalingFactor, 70 * scalingFactor);
    glVertex2f(69 * scalingFactor, 70 * scalingFactor);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(65 * scalingFactor, 65 * scalingFactor);
    glVertex2f(70 * scalingFactor, 65 * scalingFactor);
    glEnd();


        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(197, 193);
        glVertex2f(208, 193);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 0, 0);
        glVertex2f(199, 210);
        glVertex2f(206, 210);
        glEnd();

        glBegin(GL_POLYGON); //cabin
        glColor3ub(116, 202, 141);
        glVertex2f(180, 125);
        glVertex2f(180, 180);
        glVertex2f(200, 180);
        glVertex2f(200, 170);
        glVertex2f(220, 170);
        glVertex2f(220, 125);
        glEnd();
        glBegin(GL_POLYGON);
        for (int i = 0; i < 200; i++)
        {
            glColor3ub(255, 0, 0);
            float pi = 3.1416;
            float A = (i * pi) / 200;
            float r = 8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x + 190, y + 185);
        }

        glEnd();
        glBegin(GL_POLYGON);
        for (int i = 0; i < 200; i++)
        {
            glColor3ub(116, 202, 141);
            float pi = 3.1416;
            float A = (i * pi) / 200;
            float r = 10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x + 190, y + 179);
        }

        glEnd();

        glBegin(GL_POLYGON);  //ship body
        glColor3ub(178, 87, 223);
        glVertex2f(90, 150);
        glVertex2f(120, 150);
        glVertex2f(130, 125);
        glVertex2f(130, 100);
        glVertex2f(100, 100);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(178, 87, 223);
        glVertex2f(130, 125);
        glVertex2f(130, 100);
        glVertex2f(200, 100);
        glVertex2f(200, 125);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(178, 87, 223);
        glVertex2f(200, 150);
        glVertex2f(225, 150);
        glVertex2f(230, 125);
        glVertex2f(220, 100);
        glVertex2f(200, 100);
        glVertex2f(200, 125);
        glVertex2f(205, 150);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(111, 3, 165);
        glVertex2f(100, 100);
        glVertex2f(220, 100);
        glVertex2f(220, 95);
        glVertex2f(100, 95);
        glEnd();

        glColor3ub(255, 0, 0);  //Container
        for (int i = 130; i < 171; i++)
        {
            if (i % 20 == 0)
            {
                Container(i, 0);
            }

        }
        glColor3ub(0, 128, 255);
        for (int i = 130; i < 181; i++)
        {
            if (i % 20 == 0)
            {
                Container(i - 10, 0);
            }

        }
        glColor3ub(255, 222, 0);
        for (int i = 130; i < 171; i++)
        {
            if (i % 20 == 0)
            {
                Container(i + 5, 25);
            }

        }
        glColor3ub(9, 255, 0);
        for (int i = 130; i < 171; i++)
        {
            if (i % 20 == 0)
            {
                Container(i - 5, 25);
            }

        }
        glColor3ub(255, 128, 0);
        for (int i = 130; i < 151; i++)
        {
            if (i % 20 == 0)
            {
                Container(i + 10, 50);
            }

        }
        glColor3ub(255, 128, 255);
        for (int i = 130; i < 171; i++)
        {
            if (i % 20 == 0)
            {
                Container(i, 50);
            }

        }

        glColor3ub(0, 0, 0);  //windows
        for (int i = 180; i < 200; i++)
        {
            if (i % 10 == 0)
            {
                Window(i + 2, 0);
            }

        }
        for (int i = 180; i < 220; i++)
        {
            if (i % 10 == 0)
            {
                Window(i + 2, -8);
            }

        }
        for (int i = 180; i < 220; i++)
        {
            if (i % 10 == 0)
            {
                Window(i + 2, -16);
            }

        }
        for (int i = 180; i < 200; i++)
        {
            if (i % 10 == 0)
            {
                Window(i + 2, -24);
            }

        }
        for (int i = 180; i < 200; i++)
        {
            if (i % 10 == 0)
            {
                Window(i + 2, -32);
            }

        }
        glBegin(GL_POLYGON); //cabin
        glColor3ub(0, 0, 0);
        glVertex2f(183, 178);
        glVertex2f(197, 178);
        glVertex2f(197, 183);
        glVertex2f(183, 183);
        glEnd();

        glLineWidth(5);  //railing
        glColor3ub(36, 36, 74);
        glBegin(GL_LINES);
        glVertex2f(125, 135);
        glVertex2f(200, 135);
        glEnd();
        for (int i = 130; i < 200; i++)
        {
            if (i % 10 == 0)
            {
                Railing(i, 0);
            }

        }

    }
    void fullBath()
    {
        glColor3ub(204, 102, 0);
        //transform Badh to using push matrix and pop matrix
        for (size_t i = 0; i < 25; i++)
        {
            glPushMatrix();
            glTranslatef(0 + (20 * i), 0, 0);
            glColor3ub(204, 90 + (5 * i), 0);
            Badh();
            glPopMatrix();
        }
    }

    void fullBadh3layer()
    {
        for (size_t i = 0; i < 3; i++)
        {
            glPushMatrix();
            glTranslatef(0, 0 + (i * 12), 0);

            fullBath();
            glPopMatrix();
        }
    }

    void scalledship()  //L070
    {
        glPushMatrix();
        glTranslatef(100, 260, 0);
        glScalef(1.4, 1.2, 0);
        //glTranslatef(250, 100, 0);
        glTranslatef((-_boatMove / 4) % 500, 0, 0);
        Ship();
        glPopMatrix();
    }


    //add method//Launch//L071
    void Boat2Windows()
    {
        if (isDay)
        {
            glColor3ub(22, 22, 0);//yellow-window
        }
        else
        {
            glColor3ub(202, 202, 0);//yellow-window
        }
        glBegin(GL_QUADS);
        glVertex2f(135, 35);
        glVertex2f(150, 35);
        glVertex2f(150, 50);
        glVertex2f(135, 50);
        glEnd();

    }
    void Boat2WindowLoop()
    {
        Boat2Windows();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        for (int windowNo = 0; windowNo < 4; windowNo++)
        {
            glTranslatef(20, 0, 0);
            Boat2Windows();
        }
        glTranslatef(20, 0, 0);
        Boat2Windows();
        glPopMatrix();
    }
    void Boat2Shed()
    {

        glBegin(GL_QUADS);
        glColor3ub(102, 102, 51);//brown-shed
        glVertex2f(120, 30);
        glVertex2f(240, 30);
        glVertex2f(240, 55);
        glVertex2f(130, 55);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(102, 0, 0);//red-shed-ceiling
        glVertex2f(240, 55);
        glVertex2f(130, 55);
        glVertex2f(128, 60);
        glVertex2f(240, 60);
        glEnd();
        Boat2WindowLoop();
    }
    void Boat2BackStick()
    {
        glBegin(GL_LINES);
        glColor3ub(165, 42, 42);//brown-stick
        glVertex2f(210 + 50, 75);
        glVertex2f(220 + 50, 10);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);//red-quads
        glVertex2f(218 + 50, 20);
        glVertex2f(220 + 50, 10);
        glVertex2f(230 + 50, 10);
        glVertex2f(280, 20);
        glEnd();

    }
    void Boat2BackBox()
    {
        glBegin(GL_POLYGON);
        glColor3ub(245, 176, 66);//orange-box
        glVertex2f(260 + 5, 40);
        glVertex2f(250 + 5, 30);
        glVertex2f(230 + 5, 30);
        glVertex2f(230 + 5, 70);
        glVertex2f(260 + 5, 70);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(245, 0, 0);//red-box-ceiling
        glVertex2f(230, 70);
        glVertex2f(260 + 5 + 5, 70);
        glVertex2f(260 + 5, 75);
        glVertex2f(230 + 5 + 2, 75);
        glEnd();

    }
    void Boat2Body()
    {
        Boat2BackStick();
        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);//red-base
        glVertex2f(120, 10);
        glVertex2f(250, 10);
        glVertex2f(250, 30);
        glVertex2f(120, 30);
        glEnd();
        glBegin(GL_TRIANGLES);//black-nose-front
        glVertex2f(120, 10);
        glVertex2f(120, 30);
        glVertex2f(80, 40);
        glEnd();

        glBegin(GL_TRIANGLES);//black-nose-back
        glVertex2f(200 + 50, 10);
        glVertex2f(200 + 50, 30);
        glVertex2f(240 + 50, 40 + 20);
        glEnd();
        glColor3f(0.0,1.0,0.7);
        //text(130.0,20.0,text1);
        glBegin(GL_POLYGON);//yellow-inside-shape
        glColor3ub(255, 255, 0);
        glVertex2f(250, 40);
        glVertex2f(80, 40);
        glVertex2f(120, 30);
        glVertex2f(250, 30);
        glEnd();

        Boat2Shed();
        Boat2BackBox();

    }
    void Boat2()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(0, 0, 0);
        Boat2Body();
        glPopMatrix();
    }

    void ScaledBoat2()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(450, 0, 0);
        glScalef(1.2, 1.2, 0);
        glTranslatef((-_boatMove / 3) % 750, 0, 0);
        Boat2();
        glPopMatrix();
    }




    // ... (rest of the functions)
};

Port scene;

class GraphicsScene {
public:
    static void display() {
        if (currentScene == SceneType::FIRST) {
            displayFirstScene();
        } else if (currentScene == SceneType::SECOND) {
            displaySecondScene();
        } else if (currentScene == SceneType::THIRD) {
            displayThirdScene();
        } else if (currentScene == SceneType::FOURTH) {
            displayFourthScene();
        }
    }

    static void keyboard(unsigned char key, int x, int y) {
        if (key == 'M' || key == 'm') {
            switchScene();
        }
    }

private:
    enum class SceneType { FIRST, SECOND, THIRD, FOURTH };
    static SceneType currentScene;

    static void displayFirstScene() {
        // Rendering code for the first scene

        glClear(GL_COLOR_BUFFER_BIT);
	         glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    // Clear the color buffer (background)

glColor3f(1.0,1.0,0.0);
renderBitmapString(0.63f, 0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Hello");








//.....sky.....

glBegin(GL_QUADS);

glColor3ub(11,25,60);

glVertex2f(-1.0,0.5);


glColor3ub(77,74,103);

glVertex2f(1.0,0.5);
glColor3ub(13,37,99);

glVertex2f(1.0,1.0);



glVertex2f(-1.0,1.0);

glEnd();
//............moon........
int k;


    GLfloat m=-0.6f; GLfloat n=0.7f; GLfloat radius3 =.13f;

    int triangleAmount3 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi3 = 2.0f * PI;


    glColor3ub(249,250,254);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(m,n); // center of circle

        for(k = 0; k <= triangleAmount3;k++) {

            glVertex2f( m + (radius3 * cos(k *  twicePi3 / triangleAmount3)),

                        n + (radius3 * sin(k * twicePi3 / triangleAmount3)) );

}

glEnd();

glLineWidth(3);
	glColor3ub(249,250,254);

    glBegin(GL_LINES);
    glVertex2f(-0.2, 0.8f);
    glVertex2f(-0.2f, 0.79f);

    glVertex2f(-0.2, 0.7f);
    glVertex2f(-0.2f, 0.69f);

   /* glVertex2f(0.25, 0.50f);
    glVertex2f(0.25f, 0.49f);*/

    glVertex2f(0.2, 0.63f);
    glVertex2f(0.2f, 0.62f);

        glVertex2f(0.0, 0.80f);
    glVertex2f(0.0f, 0.79f);

    glVertex2f(0.1, 0.79f);
    glVertex2f(0.1f, 0.78f);

     /*glVertex2f(0.1, 0.49f);
    glVertex2f(0.1f, 0.48f);*/

     glVertex2f(0.15, 0.75f);
    glVertex2f(0.15f, 0.74f);

     glVertex2f(0.22, 0.86f);
    glVertex2f(0.22f, 0.85f);

     glVertex2f(0.3, 0.96f);
    glVertex2f(0.3f, 0.95f);

     glVertex2f(0.38, 0.64f);
    glVertex2f(0.38f, 0.63f);

    glVertex2f(0.43, 0.72f);
    glVertex2f(0.43f, 0.71f);

    glVertex2f(0.5, 0.61f);
    glVertex2f(0.5f, 0.60f);

     glVertex2f(0.65, 0.98f);
    glVertex2f(0.65f, 0.97f);

   glVertex2f(0.9, 0.59f);
    glVertex2f(0.9f, 0.58f);

     glVertex2f(0.8, 0.88f);
    glVertex2f(0.8f, 0.87f);

    glVertex2f(0.7, 0.65f);
    glVertex2f(0.7f, 0.64f);


    /*glVertex2f(-0.3, 0.46f);
    glVertex2f(-0.3f, 0.45f);*/


glVertex2f(-0.37, 0.91f);
    glVertex2f(-0.37f, 0.90f);

/*glVertex2f(-0.58, 0.45f);
    glVertex2f(-0.58f, 0.44f);*/


glVertex2f(-0.46, 0.87f);
    glVertex2f(-0.46f, 0.86f);


   /* glVertex2f(-0.88, 0.45f);
    glVertex2f(-0.88f, 0.44f);*/


glVertex2f(-0.92, 0.91f);
    glVertex2f(-0.92f, 0.90f);

    glVertex2f(-0.73, 0.92f);
    glVertex2f(-0.73f, 0.91f);


glVertex2f(-0.89, 0.69f);
    glVertex2f(-0.89f, 0.68f);



glEnd();

//....river..
//glColor3ub(54,70,145);

glBegin(GL_QUADS);
glColor3ub(41,199,248);
glVertex2d(-1.0f,0.5f);
glColor3ub(54,70,145);
glVertex2d(-1.0f,0.23f);
glVertex2d(1.0f,0.1f);
glVertex2d(1.0f,0.5f);
glEnd();

//
/*glColor3ub(110,100,88);

glBegin(GL_QUADS);
glVertex2d(-1.0f,0.23f);
glVertex2d(-1.0f,-1.0f);
glVertex2d(1.0f,-1.0f);
glVertex2d(1.0f,0.1f);
glEnd();*/


glBegin(GL_QUADS);
glColor3ub(128,74,62);
glVertex2d(-1.0f,0.23f);
glColor3ub(254,227,138);
glVertex2d(-1.0f,-1.0f);
glColor3ub(241,181,71);
glVertex2d(1.0f,-1.0f);
glColor3ub(128,74,62);

glVertex2d(1.0f,0.1f);
glEnd();







//....stall

glPushMatrix();
glTranslatef(0.05f,0.0f,0.0f);


glPushMatrix();
glTranslatef(-0.1f,-0.4f,0.0f);
glBegin(GL_QUADS);
glColor3ub(129,76,58);
glVertex2f(-0.28,0.7);
glVertex2f(-0.28,0.75);
glVertex2f(-0.6,0.75);
glVertex2f(-0.6,0.7);
glEnd();


glBegin(GL_QUADS);
glColor3ub(65,35,24);

glVertex2f(-0.601,0.7);
  glColor3ub (219,147,49);
glVertex2f(-0.65,0.47);
glVertex2f(-0.25,0.47);
glVertex2f(-0.279,0.7);
glEnd();



glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.25f);
    glVertex2f(-0.62f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.25f);
    glVertex2f(-0.28f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.6f, 0.47f);
glEnd();

glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.4f);
    glVertex2f(-0.3f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(165,42,42);
glVertex2f(-0.26,0.25);
glVertex2f(-0.26,0.21);
glVertex2f(-0.64,0.21);
glVertex2f(-0.64,0.25);
glEnd();

glBegin(GL_QUADS);
glColor3ub(161,109,69);
glVertex2f(-0.28,0.21);
glVertex2f(-0.28,-0.001);
 glColor3ub(200,145,55);
glVertex2f(-0.62,-0.001);
glVertex2f(-0.62,0.21);
glEnd();

glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(0.05f,0.0f,0.0f);
//..fish1...
glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.67f, 0.17f);
    glVertex2f(-0.67f, 0.13f);
glColor3ub(207,55,34);
    glBegin(GL_LINES);
    glVertex2f(-0.66f, 0.12f);
    glVertex2f(-0.68f, 0.12f);
glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.67f,0.12f);
glVertex2d(-0.68f,0.12f);
glVertex2d(-0.68f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.66f,0.12f);
glVertex2d(-0.67f,0.12f);
glVertex2d(-0.66f,0.17f);




glEnd();
glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.66,0.12);
glVertex2f(-0.667,0.03);
glVertex2f(-0.673,0.03);
glVertex2f(-0.68,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.664f, 0.07f);
    glVertex2f(-0.676f, 0.07f);
glEnd();
glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.671f, 0.043f);
    glVertex2f(-0.671f, 0.049f);
glEnd();
glPopMatrix();



//.....fish2

glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.61f, 0.17f);
    glVertex2f(-0.61f, 0.13f);
glEnd();

glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.61f,0.12f);
glVertex2d(-0.62f,0.12f);
glVertex2d(-0.62f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.6f,0.12f);
glVertex2d(-0.61f,0.12f);
glVertex2d(-0.6f,0.173f);

glEnd();


glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.6,0.12);
glVertex2f(-0.607,0.03);
glVertex2f(-0.613,0.03);
glVertex2f(-0.62,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.604f, 0.07f);
    glVertex2f(-0.616f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.611f, 0.043f);
    glVertex2f(-0.611f, 0.049f);
glEnd();
glPopMatrix();






//.fish3


glPushMatrix();
glTranslatef(0.1,-0.1f,0.f);


glLineWidth(2);

glColor3ub(207,55,34);



    glBegin(GL_LINES);

    glVertex2f(-0.64f, 0.17f);

    glVertex2f(-0.64f, 0.13f);

glEnd();





glColor3ub(98,119,146);



glBegin(GL_TRIANGLES);



glVertex2d(-0.65f,0.18f);

glVertex2d(-0.65f,0.12f);

glVertex2d(-0.64f,0.12f);





glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);



glVertex2d(-0.64f,0.12f);

glVertex2d(-0.63f,0.12f);

glVertex2d(-0.63f,0.17f);







glEnd();

glBegin(GL_QUADS);

glColor3ub(181,194,211);

glVertex2f(-0.65,0.12);

glVertex2f(-0.643,0.03);

glVertex2f(-0.637,0.03);

glVertex2f(-0.63,0.12);

glEnd();



glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.635f, 0.07f);
    glVertex2f(-0.645f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.64f, 0.043f);
    glVertex2f(-0.64f, 0.049f);
glEnd();
glPopMatrix();

glPopMatrix();




//....
glPushMatrix();
glTranslatef(0.05f,0.0f,0.0f);
glLineWidth(3);
glColor3ub(129,76,58);

    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.7f, -0.15f);
glEnd();

glLineWidth(3);
glColor3ub(129,76,58);

    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.05f);
    glVertex2f(-0.5f, -0.15f);
glEnd();


glLineWidth(3);
glColor3ub(129,76,58);

    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.062f);
    glVertex2f(-0.5f, -0.062f);
glEnd();



//....fish1..
glPushMatrix();
glTranslatef(0.0f,-0.24f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.67f, 0.17f);
    glVertex2f(-0.67f, 0.12f);
glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.67f,0.12f);
glVertex2d(-0.68f,0.12f);
glVertex2d(-0.68f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.66f,0.12f);
glVertex2d(-0.67f,0.12f);
glVertex2d(-0.66f,0.17f);




glEnd();
glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.66,0.12);
glVertex2f(-0.667,0.03);
glVertex2f(-0.673,0.03);
glVertex2f(-0.68,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.664f, 0.07f);
    glVertex2f(-0.676f, 0.07f);
glEnd();
glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.671f, 0.043f);
    glVertex2f(-0.671f, 0.049f);
glEnd();

glLineWidth(3);
glColor3ub(133,92,84);
glBegin(GL_LINES);
    glVertex2f(-0.661f, 0.12f);
    glVertex2f(-0.681f, 0.12f);
glEnd();
glPopMatrix();





//...fish2

glPushMatrix();
glTranslatef(0.0f,-0.24f,0.0f);

glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.61f, 0.17f);
    glVertex2f(-0.61f, 0.12f);
glEnd();

glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.61f,0.12f);
glVertex2d(-0.62f,0.12f);
glVertex2d(-0.62f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.6f,0.12f);
glVertex2d(-0.61f,0.12f);
glVertex2d(-0.6f,0.173f);

glEnd();



glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.12f);
    glVertex2f(-0.6f, 0.12f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.6,0.12);
glVertex2f(-0.607,0.03);
glVertex2f(-0.613,0.03);
glVertex2f(-0.62,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.604f, 0.07f);
    glVertex2f(-0.616f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.611f, 0.043f);
    glVertex2f(-0.611f, 0.049f);
glEnd();

glLineWidth(3);
glColor3ub(133,92,84);

    glBegin(GL_LINES);
    glVertex2f(-0.6f, 0.12f);
    glVertex2f(-0.62f, 0.12f);
glEnd();

glPopMatrix();


//.....fish3



glPushMatrix();
glTranslatef(0.1f,-0.24f,0.0f);
glLineWidth(2);

glColor3ub(207,55,34);



    glBegin(GL_LINES);

    glVertex2f(-0.64f, 0.17f);

    glVertex2f(-0.64f, 0.12f);

glEnd();





glColor3ub(98,119,146);



glBegin(GL_TRIANGLES);



glVertex2d(-0.65f,0.18f);

glVertex2d(-0.65f,0.12f);

glVertex2d(-0.64f,0.12f);





glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);


glVertex2d(-0.64f,0.12f);

glVertex2d(-0.63f,0.12f);

glVertex2d(-0.63f,0.17f);







glEnd();

glBegin(GL_QUADS);

glColor3ub(181,194,211);

glVertex2f(-0.65,0.12);

glVertex2f(-0.643,0.03);

glVertex2f(-0.637,0.03);

glVertex2f(-0.63,0.12);

glEnd();



glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.635f, 0.07f);
    glVertex2f(-0.645f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.64f, 0.043f);
    glVertex2f(-0.64f, 0.049f);
glEnd();


glLineWidth(3);
glColor3ub(133,92,84);

    glBegin(GL_LINES);
    glVertex2f(-0.65f, 0.12f);
    glVertex2f(-0.63f, 0.12f);
glEnd();

glPopMatrix();




//..man.............


glPushMatrix();
glTranslatef(-0.65f,-0.33f,0.0f);

int H;

	GLfloat j7=0.2f; GLfloat j8=0.3f; GLfloat radius6 =.05f;
	int triangleAmount5 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(j7,j8); // center of circle
		for(H = 0; H <= triangleAmount5;H++) {
			glVertex2f( j7 + (radius6 * cos(H *  twicePi5 / triangleAmount5)),
                        j8 + (radius6 * sin(H * twicePi5 / triangleAmount5)) );
		}
	glEnd();



	int L;

	GLfloat j1=0.2f; GLfloat j2=0.285f; GLfloat radius4 =.04f;
	int triangleAmount16 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(j1,j2); // center of circle
		for(L = 0; L <= triangleAmount16;L++) {
			glVertex2f( j1 + (radius4 * cos(L *  twicePi16 / triangleAmount16)),
                        j2 + (radius4 *sin(L * twicePi16/ triangleAmount16)) );
		}
		glEnd();

int F;

	GLfloat j3=0.18; GLfloat j4=0.289f; GLfloat radius5=.01f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(j3,j4); // center of circle
		for(F= 0; F <= triangleAmount4;F++) {
			glVertex2f( j3 + (radius5 * cos(F *  twicePi4 / triangleAmount4)),
                        j4 + (radius5 *sin(F * twicePi4/ triangleAmount4)) );
		}
		glEnd();

GLfloat j5=0.22; GLfloat j6=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(j5,j6); // center of circle
		for(F= 0; F <= triangleAmount4;F++) {
			glVertex2f( j5 + (radius5 * cos(F *  twicePi4 / triangleAmount4)),
                        j6 + (radius5 *sin(F * twicePi4/ triangleAmount4)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.168,0.245);
glVertex2f(0.168,0.18);
glVertex2f(0.231,0.18);
glVertex2f(0.231,0.245);
glEnd();


glPopMatrix();

glPopMatrix();

glPopMatrix();
glPopMatrix();


//...stall 2

glPushMatrix();
glTranslatef(-0.1f,-0.3f,0.0f);


glColor3ub(161,109,67);

glBegin(GL_TRIANGLES);

glVertex2d(0.18f,0.4f);
glColor3ub(141,77,42);
glVertex2d(0.5f,0.4f);
glColor3ub(99,42,25);
glVertex2d(0.35f,0.7f);

glEnd();
glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.236f, 0.4f);
    glVertex2f(0.236f, 0.2f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.456f, 0.4f);
    glVertex2f(0.456f, 0.2f);
glEnd();






glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.233f, 0.2f);
    glVertex2f(0.461f, 0.2f);
glEnd();


glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.25f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.32f, 0.2f);
    glVertex2f(0.32f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.26f);
    glVertex2f(0.321f, 0.26f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.24,0.2);
glVertex2f(0.24,0.0);
glVertex2f(0.45,0.0);
glVertex2f(0.45,0.2);
glEnd();


glLineWidth(2);
glColor3ub(99,42,25);

    glBegin(GL_LINES);
    glVertex2f(0.26f, 0.2f);
    glVertex2f(0.26f, 0.0f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.30f, 0.0f);
    glVertex2f(0.34f, 0.2f);
    glVertex2f(0.34f, 0.0f);
    glVertex2f(0.38f, 0.2f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.2f);
    glVertex2f(0.42f, 0.0f);

glEnd();

glColor3ub(255,251,214);

glBegin(GL_QUADS);

glVertex2f(0.25,0.15);
glVertex2f(0.25,0.07);
glVertex2f(0.44,0.07);
glVertex2f(0.44,0.15);
glEnd();
glPopMatrix();


//ice-cream


glPushMatrix();
glTranslatef(-0.1f,-0.3f,0.0f);
glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.27f);
glVertex2d(0.28f,0.27f);
glVertex2d(0.27f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.33f);
glVertex2d(0.28f,0.33f);
glVertex2d(0.27f,0.25f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.39f);
glVertex2d(0.28f,0.39f);
glVertex2d(0.27f,0.31f);

glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);
glVertex2d(0.29f,0.27f);
glVertex2d(0.32f,0.27f);
glVertex2d(0.305f,0.2f);

glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);
glVertex2d(0.29f,0.33f);
glVertex2d(0.32f,0.33f);
glVertex2d(0.305f,0.25f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);

glVertex2d(0.29f,0.39f);
glVertex2d(0.32f,0.39f);
glVertex2d(0.305f,0.31f);

glEnd();
glPopMatrix();

//...box

glPushMatrix();
glTranslatef(-0.12f,-0.3f,0.0f);
glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.21);
glVertex2f(0.346,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.375,0.21);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.25f);
    glVertex2f(0.38f, 0.25f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.25);
glVertex2f(0.346,0.29);
glVertex2f(0.38,0.29);
glVertex2f(0.375,0.25);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.29f);
    glVertex2f(0.38f, 0.29f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.29);
glVertex2f(0.346,0.33);
glVertex2f(0.38,0.33);
glVertex2f(0.375,0.29);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.33f);
    glVertex2f(0.38f, 0.33f);
glEnd();


glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.43,0.21);
glVertex2f(0.43,0.27);
glVertex2f(0.45,0.27);
glVertex2f(0.45,0.21);
glEnd();

glLineWidth(2);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.43f, 0.27f);
    glVertex2f(0.45f, 0.27f);
glEnd();


glLineWidth(1);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.435f, 0.272f);
    glVertex2f(0.435f, 0.32f);
glEnd();

glLineWidth(1);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.445f, 0.272f);
    glVertex2f(0.445f, 0.32f);
glEnd();
glPopMatrix();



//....stall 1 man


glPushMatrix();
glTranslatef(0.1f,-0.3f,0.0);
int u;

	GLfloat q7=0.2f; GLfloat q8=0.3f; GLfloat radius14 =.04f;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q7,q8); // center of circle
		for(u = 0; u <= triangleAmount7;u++) {
			glVertex2f( q7 + (radius14 * cos(u *  twicePi7 / triangleAmount7)),
                        q8 + (radius14 * sin(u * twicePi7 / triangleAmount7)) );
		}
	glEnd();



	int d;

	GLfloat q9=0.2f; GLfloat q10=0.285f; GLfloat radius15 =.03f;
	int triangleAmount12= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q9,q10); // center of circle
		for(d = 0; d <= triangleAmount12;d++) {
			glVertex2f( q9 + (radius15 * cos(d *  twicePi12 / triangleAmount12)),
                        q10 + (radius15 *sin(d * twicePi12 / triangleAmount12)) );
		}
		glEnd();

int c;

	GLfloat q11=0.18; GLfloat q12=0.289f; GLfloat radius16=.009f;
	int triangleAmount13 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q11,q12); // center of circle
		for(c= 0; c <= triangleAmount13;c++) {
			glVertex2f( q11 + (radius16 * cos(c*  twicePi13 / triangleAmount13)),
                        q12 + (radius16 *sin(c * twicePi13/ triangleAmount13)) );
		}
		glEnd();

GLfloat q13=0.22; GLfloat q14=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q13,q14); // center of circle
		for(c= 0; c <= triangleAmount13;c++) {
			glVertex2f( q13 + (radius16 * cos(c *  twicePi13 / triangleAmount13)),
                        q14 + (radius16 *sin(c * twicePi13/ triangleAmount13)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


/*glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();*/


glPushMatrix();
glTranslatef(-0.205f,0.007f,0.0);
glBegin(GL_QUADS);
glColor3ub(107,201,203);
glVertex2f(0.434,0.195);
glVertex2f(0.432,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.38,0.195);
glEnd();
glPopMatrix();


glPopMatrix();







//..stall3



//..coconut


glPushMatrix();
glTranslatef(0.0f,-0.2f,0.0f);

glPushMatrix();
glTranslatef(0.3f,-0.25f,0.f);

int i;

	GLfloat m1=0.32f; GLfloat m2=0.34f; GLfloat radius =.028f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
glColor3f(0.255f, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m1, m2); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m1 + (radius * cos(i *  twicePi / triangleAmount)),
                        m2+ (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();




	GLfloat m3=0.43f; GLfloat m4=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m3,m4); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m3 + (radius * cos(i*  twicePi / triangleAmount)),
                        m4 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m5=0.48f; GLfloat m6=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m5,m6); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m5 + (radius * cos(i*  twicePi / triangleAmount)),
                        m6 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m7=0.52f; GLfloat m8=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m7,m8); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m7 + (radius * cos(i*  twicePi / triangleAmount)),
                        m8 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m9=0.50f; GLfloat m10=0.3f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m9 + (radius * cos(i*  twicePi / triangleAmount)),
                        m10 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

GLfloat m11=0.45f; GLfloat m12=0.3f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m11 + (radius * cos(i*  twicePi / triangleAmount)),
                        m12 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();






GLfloat m13=0.475f; GLfloat m14=0.35f; //GLfloat radius =.028f;

glColor3ub(66,144,67);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m13 + (radius * cos(i*  twicePi / triangleAmount)),
                        m14 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();






int l1;

GLfloat x1=0.32f; GLfloat x2 =0.349f; GLfloat radi2 =0.012f;

int triangleAmount1 = 20;
GLfloat twicePi1 = 2.0f * PI;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(238,177,90);

glVertex2f(x1, x2);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x1+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x2 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();


    // Clear the color buffer (background)

GLfloat x3=0.43f; GLfloat x4 =0.259f;



glBegin(GL_TRIANGLE_FAN);


glColor3ub(238,177,90);

glVertex2f(x3, x4);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x3+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x4 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();


    // Clear the color buffer (background)
GLfloat x5=0.48f; GLfloat x6 =0.259f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x5, x6);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x5+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x6 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();



GLfloat x7=0.52f; GLfloat x8 =0.259f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x7, x8);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x7+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x8 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (background)


GLfloat x9=0.50f; GLfloat x10 =0.3f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x9, x10);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x9+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x10 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (b


GLfloat x11=0.45f; GLfloat x12 =0.3f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x11, x12);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x11+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x12 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (b




GLfloat x13=0.475f; GLfloat x14 =0.35f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x13, x14);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x13+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x14 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;

//...stall 3....

//glColor3f(0.255f, 0.0f, 0.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.255f, 0.0f, 0.0f);
glVertex2d(0.18f,0.4f);
glColor3ub(126,90,66);//(201,83,73);
glVertex2d(0.62f,0.4f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);
glVertex2d(0.28f,0.45f);
glColor3ub(105,42,22);
glVertex2d(0.33f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);
glVertex2d(0.38f,0.45f);
glColor3ub(105,42,22);

glVertex2d(0.43f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);

glVertex2d(0.48f,0.45f);
glColor3ub(105,42,22);

glVertex2d(0.53f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();



glColor3ub(213,113,37);
glBegin(GL_TRIANGLES);

glVertex2d(0.23f,0.4f);
glVertex2d(0.24f,0.4f);
glVertex2d(0.24f,0.1f);


glEnd();




glColor3ub(213,113,37);
glBegin(GL_TRIANGLES);

glVertex2d(0.56f,0.4f);
glVertex2d(0.57f,0.4f);
glVertex2d(0.57f,0.1f);


glEnd();





glBegin(GL_QUADS);
glColor3ub(182,97,44);
glVertex2d(0.26f,0.23f);
glVertex2d(0.26f,0.1f);
glColor3ub(105,42,22);
glVertex2d(0.54f,0.1f);
glColor3ub(40,15,14);
glVertex2d(0.54f,0.23f);
glEnd();



glLineWidth(3);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.28f, 0.31f);
    glVertex2f(0.42f, 0.31f);

glEnd();


glLineWidth(2);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.29f, 0.31f);
    glVertex2f(0.29f, 0.23f);

    glVertex2f(0.41f, 0.31f);
    glVertex2f(0.41f, 0.23f);


    glVertex2f(0.35f, 0.31f);
    glVertex2f(0.35f, 0.23f);



glEnd();
//...glass...
glColor3ub(121,197,220);
glBegin(GL_QUADS);
glVertex2d(0.31f,0.23f);
glVertex2d(0.31f,0.28f);
glVertex2d(0.32f,0.28f);
glVertex2d(0.32f,0.23f);
glEnd();

glColor3f(201,232,237);
glBegin(GL_QUADS);
glVertex2d(0.31f,0.27f);
glVertex2d(0.31f,0.28f);
glVertex2d(0.32f,0.28f);
glVertex2d(0.32f,0.27f);
glEnd();


glColor3ub(121,197,220);

glBegin(GL_QUADS);
glVertex2d(0.37f,0.23f);
glVertex2d(0.37f,0.28f);
glVertex2d(0.38f,0.28f);
glVertex2d(0.38f,0.23f);
glEnd();

glColor3f(201,232,237);
glBegin(GL_QUADS);
glVertex2d(0.37f,0.27f);
glVertex2d(0.37f,0.28f);
glVertex2d(0.38f,0.28f);


glVertex2d(0.38f,0.27f);
glEnd();







glPopMatrix();
glPopMatrix();











//....tree
glPushMatrix();
glTranslatef(-1.15f,-0.18f,0.0);
glPushMatrix();
glScalef(6.0f,6.0f,0.0f);






 glBegin(GL_QUADS);

 glColor3f(0.063f, 0.51f, 0.063f);

 glVertex2f(0.075f,0.02f);

 glVertex2f(0.075f,0.04f);

 glVertex2f(0.025f,0.04f);

 glVertex2f(0.025f,0.02f);




 glVertex2f(0.03f,0.04f);

 glVertex2f(0.03f,0.06f);

 glVertex2f(0.07f,0.06f);

 glVertex2f(0.07f,0.04f);





 glVertex2f(0.035f,0.06f);

 glVertex2f(0.035f,0.08f);

 glVertex2f(0.0665f,0.08f);

 glVertex2f(0.0665f,0.06f);

 glEnd();



 glBegin(GL_TRIANGLES);

 glColor3f(0.063f, 0.51f, 0.063f);

 glVertex2f(0.040f,0.08f);

 glVertex2f(0.05075f,0.12f);

 glVertex2f(0.0615f,0.08f);

 glEnd();

glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,0.019f,0.0);
glBegin(GL_QUADS);

 glColor3ub(65,35,24);

 glVertex2f(-0.83f,-0.08f);

 glVertex2f(-0.83f,-0.4f);

 glVertex2f(-0.86f,-0.4f);

 glVertex2f(-0.86f,-0.08f);

glEnd();
glPushMatrix();

//...tree

glPushMatrix();
glTranslatef(-0.6f,-0.3f,0.0);

glPushMatrix();
glScalef(5.0f,5.0f,0.0f);





 glBegin(GL_QUADS);

 glColor3f(0.42f, 0.235f, 0.012f);

 glVertex2f(0.109f,0.0f);

 glVertex2f(0.109f,0.02f);

 glVertex2f(0.112f,0.02f);

 glVertex2f(0.112f,0.0f);

 glEnd();




 glBegin(GL_QUADS);

 glColor3f(0.063f, 0.51f, 0.063f);

 glVertex2f(0.085f,0.02f);

 glVertex2f(0.085f,0.04f);

 glVertex2f(0.135f,0.04f);

 glVertex2f(0.135f,0.02f);




 glVertex2f(0.09f,0.04f);

 glVertex2f(0.09f,0.06f);

 glVertex2f(0.13f,0.06f);

 glVertex2f(0.13f,0.04f);



 glVertex2f(0.095f,0.06f);

 glVertex2f(0.095f,0.08f);

 glVertex2f(0.125f,0.08f);

 glVertex2f(0.125f,0.06f);

 glEnd();




 glBegin(GL_TRIANGLES);

 glColor3f(0.063f, 0.51f, 0.063f);

 glVertex2f(0.10f,0.08f);

 glVertex2f(0.11f,0.12f);

 glVertex2f(0.12f,0.08f);

 glEnd();

glPopMatrix();

glPopMatrix();






//tree.....
glPushMatrix();
glTranslatef(0.25f,0.0f,0.0f);
glPushMatrix();
glScalef(2.1f,2.3f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.063f, 0.51f, 0.063f);

    glVertex2f(0.085f,0.02f);

    glVertex2f(0.085f,0.04f);

    glVertex2f(0.135f,0.04f);

    glVertex2f(0.135f,0.02f);


     ///2

    glVertex2f(0.09f,0.04f);

    glVertex2f(0.09f,0.06f);

    glVertex2f(0.13f,0.06f);

    glVertex2f(0.13f,0.04f);


    ///3

    glVertex2f(0.095f,0.06f);

    glVertex2f(0.095f,0.08f);

    glVertex2f(0.125f,0.08f);

    glVertex2f(0.125f,0.06f);

    glEnd();


    ///4

    glBegin(GL_TRIANGLES);

    glColor3f(0.063f, 0.51f, 0.063f);

    glVertex2f(0.10f,0.08f);

    glVertex2f(0.11f,0.12f);

    glVertex2f(0.12f,0.08f);

    glEnd();

glPopMatrix();
glPopMatrix();



glPushMatrix();
glTranslatef(-0.03f,-0.05f,0.0f);
glBegin(GL_QUADS);

    glColor3f(0.42f, 0.235f, 0.012f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.5f,0.1f);

    glVertex2f(0.51f,0.1f);

    glVertex2f(0.51f,-0.1f);

    glEnd();

    glPopMatrix();



    //tree....


glPushMatrix();
glTranslatef(0.7f,0.0f,0.0f);
    glPushMatrix();
glScalef(2.1f,2.3f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.063f, 0.51f, 0.063f);

    glVertex2f(0.085f,0.02f);

    glVertex2f(0.085f,0.04f);

    glVertex2f(0.135f,0.04f);

    glVertex2f(0.135f,0.02f);


     ///2

    glVertex2f(0.09f,0.04f);

    glVertex2f(0.09f,0.06f);

    glVertex2f(0.13f,0.06f);

    glVertex2f(0.13f,0.04f);


    ///3

    glVertex2f(0.095f,0.06f);

    glVertex2f(0.095f,0.08f);

    glVertex2f(0.125f,0.08f);

    glVertex2f(0.125f,0.06f);

    glEnd();


    ///4

    glBegin(GL_TRIANGLES);

    glColor3f(0.063f, 0.51f, 0.063f);

    glVertex2f(0.10f,0.08f);

    glVertex2f(0.11f,0.12f);

    glVertex2f(0.12f,0.08f);

    glEnd();

glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(0.43f,-0.05f,0.0f);

glBegin(GL_QUADS);

    glColor3f(0.42f, 0.235f, 0.012f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.5f,0.1f);

    glVertex2f(0.51f,0.1f);

    glVertex2f(0.51f,-0.1f);

    glEnd();


    glPopMatrix();
/*
//.bbq...
glPushMatrix();
glTranslatef(0.2f,-0.2f,0.0f);


   glPushMatrix();
glTranslatef(-0.5f,-0.5f,0.0f);
	int j;

	GLfloat x=0.2f; GLfloat y=0.3f; GLfloat radius1 =.13f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f( x + (radius1 * cos(j *  twicePi2 / triangleAmount2)),
                        y + (radius1 * sin(j * twicePi2 / triangleAmount2)) );
		}
	glEnd();

//glPopMatrix();




	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(1,0,40);

    glVertex2f(0.2f, 0.43f);
    glVertex2f(0.2f, 0.17f);


    glVertex2f(0.26f, 0.43f);
    glVertex2f(0.26f, 0.17f);


   glVertex2f(0.3f, 0.4f);
    glVertex2f(0.09f, 0.4f);

glVertex2f(0.3f, 0.2f);
    glVertex2f(0.09f, 0.2f);

    glVertex2f(0.34f, 0.3f);
    glVertex2f(0.06f, 0.3f);



    glVertex2f(0.14f, 0.43f);
    glVertex2f(0.14f, 0.17f);


glEnd();
//glPushMatrix();

glPopMatrix();

glPopMatrix();


*/

//.......man 1
glPushMatrix();
glTranslatef(0.0f,-0.6f,0.0f);
int t;

	GLfloat q19=0.2f; GLfloat q20=0.3f; GLfloat radius20 =.04f;
	int triangleAmount21 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q19,q20); // center of circle
		for(t = 0; t <= triangleAmount21;t++) {
			glVertex2f( q19 + (radius20 * cos(t *  twicePi21 / triangleAmount21)),
                        q20 + (radius20 * sin(t * twicePi21 / triangleAmount21)) );
		}
	glEnd();



	int v;

	GLfloat q21=0.2f; GLfloat q22=0.285f; GLfloat radius21 =.03f;
	int triangleAmount22= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q21,q22); // center of circle
		for(v= 0; v <= triangleAmount22;v++) {
			glVertex2f( q21 + (radius21 * cos(v *  twicePi22 / triangleAmount22)),
                        q22 + (radius21 *sin(v * twicePi22 / triangleAmount22)) );
		}
		glEnd();

int w;

	GLfloat q23=0.18; GLfloat q24=0.289f; GLfloat radius22=.009f;
	int triangleAmount23 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q23,q24); // center of circle
		for(w= 0; w <= triangleAmount23;w++) {
			glVertex2f( q23 + (radius22 * cos(w*  twicePi23 / triangleAmount23)),
                        q24 + (radius22 *sin(w* twicePi23/ triangleAmount23)) );
		}
		glEnd();

GLfloat q25=0.22; GLfloat q26=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q25,q26); // center of circle
		for(w= 0; w <= triangleAmount23;w++) {
			glVertex2f( q25 + (radius22 * cos(w *  twicePi23 / triangleAmount23)),
                        q26 + (radius22 *sin(w * twicePi23/ triangleAmount23)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.178,0.245);
glVertex2f(0.178,0.18);
glVertex2f(0.223,0.18);
glVertex2f(0.223,0.245);
glEnd();


glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.19f,0.18f);
    glVertex2f(0.19f, 0.15f);

    glBegin(GL_LINES);
    glVertex2f(0.21f,0.18f);
    glVertex2f(0.21f, 0.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.185,0.15);
glVertex2f(0.185,0.14);
glVertex2f(0.195,0.14);
glVertex2f(0.195,0.15);



glColor3ub(142,83,39);
glVertex2f(0.205,0.15);
glVertex2f(0.205,0.14);
glVertex2f(0.215,0.14);
glVertex2f(0.215,0.15);
glEnd();

glPopMatrix();

//......










//....man 2




glPushMatrix();
glTranslatef(-0.3f,-0.8f,0.0f);

int b;

	GLfloat q31=0.2f; GLfloat q32=0.3f; GLfloat radius31 =.04f;
	int triangleAmount31 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi31 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q31,q32); // center of circle
		for(b = 0; b <= triangleAmount31;b++) {
			glVertex2f( q31 + (radius31 * cos(b *  twicePi31 / triangleAmount31)),
                        q32 + (radius31 * sin(b * twicePi31 / triangleAmount31)) );
		}
	glEnd();



	int z;

	GLfloat q33=0.2f; GLfloat q34=0.285f; GLfloat radius32 =.03f;
	int triangleAmount32= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi32 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q33,q34); // center of circle
		for(z= 0; z <= triangleAmount32;z++) {
			glVertex2f( q33 + (radius32 * cos(z*  twicePi32 / triangleAmount32)),
                        q34+ (radius32 *sin(z * twicePi32 / triangleAmount32)) );
		}
		glEnd();

int a;

	GLfloat q35=0.18; GLfloat q36=0.289f; GLfloat radius33=.009f;
	int triangleAmount33 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi33 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q35,q36); // center of circle
		for(a= 0; a <= triangleAmount33;a++) {
			glVertex2f( q35 + (radius33 * cos(a*  twicePi33 / triangleAmount33)),
                        q36 + (radius33 *sin(a* twicePi33/ triangleAmount33)) );
		}
		glEnd();

GLfloat q37=0.22; GLfloat q38=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q37,q38); // center of circle
		for(a= 0; a <= triangleAmount33;a++) {
			glVertex2f( q37 + (radius33 * cos(a *  twicePi33 / triangleAmount33)),
                        q38 + (radius33 *sin(a * twicePi33/ triangleAmount33)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.178,0.245);
glVertex2f(0.178,0.18);
glVertex2f(0.223,0.18);
glVertex2f(0.223,0.245);
glEnd();


glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.19f,0.18f);
    glVertex2f(0.19f, 0.15f);

    glBegin(GL_LINES);
    glVertex2f(0.21f,0.18f);
    glVertex2f(0.21f, 0.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.185,0.15);
glVertex2f(0.185,0.14);
glVertex2f(0.195,0.14);
glVertex2f(0.195,0.15);



glColor3ub(142,83,39);
glVertex2f(0.205,0.15);
glVertex2f(0.205,0.14);
glVertex2f(0.215,0.14);
glVertex2f(0.215,0.15);
glEnd();


glPopMatrix();

glPopMatrix();





glPushMatrix();
glTranslatef(-0.3f,-0.7f,0.0f);

glPushMatrix();
glScalef(-0.35f,0.4f,0.0f);
//glPushMatrix();
//glTranslatef(-0.7f,-0.8f,0.0f);

	int j;

	GLfloat x=0.2f; GLfloat y=0.3f; GLfloat radius1 =.13f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f( x + (radius1 * cos(j *  twicePi2 / triangleAmount2)),
                        y + (radius1 * sin(j * twicePi2 / triangleAmount2)) );
		}
	glEnd();

//glPopMatrix();




	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(231,56,0);

    glVertex2f(0.2f, 0.43f);
    glColor3ub(231,140,0);
    glVertex2f(0.2f, 0.17f);

glColor3ub(231,56,0);

    glVertex2f(0.26f, 0.43f);
    glColor3ub(231,140,0);

    glVertex2f(0.26f, 0.17f);

glColor3ub(231,56,0);
   glVertex2f(0.32f, 0.37f);
   glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.37f);
glColor3ub(231,56,0);
     glVertex2f(0.32f, 0.23f);
     glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.23f);
glColor3ub(231,56,0);
    glVertex2f(0.34f, 0.3f);
    glColor3ub(231,140,0);
    glVertex2f(0.06f, 0.3f);


glColor3ub(231,56,0);
    glVertex2f(0.14f, 0.43f);
     glColor3ub(231,140,0);

    glVertex2f(0.14f, 0.17f);


glEnd();
//glPushMatrix();
//.bbq fish
/*
glPopMatrix();

glPushMatrix();
        glScalef(0.6f,0.6f,0.0f);*///.fish

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.2f,0.32f);
glVertex2d(0.2f,0.28f);

glVertex2d(0.173f,0.3f);
glVertex2d(0.173f,0.29f);



glEnd();

glPopMatrix();
glPopMatrix();



glPushMatrix();
glTranslatef(-0.48f,-0.68f,0.0f);
glPushMatrix();
glScalef(0.45f,0.45f,0.0f);

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.2f,0.32f);
glVertex2d(0.2f,0.28f);

glVertex2d(0.173f,0.3f);
glVertex2d(0.173f,0.29f);



glEnd();

glPopMatrix();
glPopMatrix();







//man 3

glPushMatrix();
glTranslatef(-0.4f,-0.6f,0.0f);

int ab;

GLfloat q39=0.2f; GLfloat q40=0.3f; GLfloat radius34 =.04f;



    int triangleAmount34 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi34 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q39,q40); // center of circle



        for(ab = 0; ab <= triangleAmount34;ab++) {



            glVertex2f( q39 + (radius34 * cos(ab *  twicePi34 / triangleAmount34)),



                        q40 + (radius34 * sin(ab * twicePi34 / triangleAmount34)) );



        }



    glEnd();







    int cd;





    GLfloat q41=0.2f; GLfloat q42=0.285f; GLfloat radius35 =.03f;



    int triangleAmount35= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi35 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q41,q42); // center of circle



        for(cd= 0; cd<= triangleAmount35;cd++) {



            glVertex2f( q41 + (radius35 * cos(cd*  twicePi35 / triangleAmount35)),



                        q42+ (radius35 *sin(cd * twicePi35 / triangleAmount35)) );



        }



        glEnd();





int o;





    GLfloat q43=0.18; GLfloat q44=0.289f; GLfloat radius36=.009f;



    int triangleAmount36 = 100; //# of lines used to draw circle









    GLfloat twicePi36 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q43,q44); // center of circle



        for(o= 0; o<= triangleAmount36;o++) {



            glVertex2f( q43 + (radius36 * cos(o*  twicePi36 / triangleAmount36)),



                        q44 + (radius36 *sin(0* twicePi36/ triangleAmount36)) );



        }



        glEnd();





GLfloat q45=0.22; GLfloat q46=0.289f; //GLfloat radius36=.01f;


    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q45,q46); // center of circle



        for(o= 0; o<= triangleAmount36;o++) {



            glVertex2f( q45 + (radius36 * cos(o *  twicePi36 / triangleAmount36)),



                        q46 + (radius36 *sin(o * twicePi36/ triangleAmount36)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//man4

glPushMatrix();
glTranslatef(-0.5f,-1.0f,0.0f);

int ef;

GLfloat q51=0.2f; GLfloat q52=0.3f; GLfloat radius51 =.04f;



    int triangleAmount51 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi51 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q51,q52); // center of circle



        for(ef = 0; ef <= triangleAmount34;ef++) {



            glVertex2f( q51 + (radius51 * cos(ef *  twicePi51 / triangleAmount51)),



                        q52 + (radius51 * sin(ef * twicePi51 / triangleAmount51)) );



        }



    glEnd();







    int gh;





    GLfloat q53=0.2f; GLfloat q54=0.285f; GLfloat radius52 =.03f;



    int triangleAmount52= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi52 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q53,q54); // center of circle



        for(gh= 0; gh<= triangleAmount35;gh++) {



            glVertex2f( q53 + (radius52 * cos(gh*  twicePi52 / triangleAmount52)),



                        q54+ (radius52 *sin(gh* twicePi52 / triangleAmount52)) );



        }



        glEnd();





int ij;





    GLfloat q55=0.18; GLfloat q56=0.289f; GLfloat radius53=.009f;



    int triangleAmount53 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi53 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q55,q56); // center of circle



        for(ij= 0; ij<= triangleAmount53;ij++) {



            glVertex2f( q55 + (radius53 * cos(ij*  twicePi53 / triangleAmount53)),



                        q56 + (radius53 *sin(ij* twicePi53/ triangleAmount53)) );



        }



        glEnd();





GLfloat q57=0.22; GLfloat q58=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q57,q58); // center of circle



        for(ij= 0; ij<= triangleAmount53;ij++) {



            glVertex2f( q57 + (radius53 * cos(ij*  twicePi53 / triangleAmount53)),



                        q58 + (radius53 *sin(ij * twicePi53/ triangleAmount53)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();



//man 5
glPushMatrix();
glTranslatef(-0.7f,-0.6f,0.0f);


int kl;

GLfloat q59=0.2f; GLfloat q60=0.3f; GLfloat radius54 =.04f;



    int triangleAmount54 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi54 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q59,q60); // center of circle



        for(kl = 0; kl <= triangleAmount54;kl++) {



            glVertex2f( q59 + (radius54 * cos(kl *  twicePi54 / triangleAmount54)),



                        q60 + (radius54 * sin(kl * twicePi54 / triangleAmount54)) );



        }



    glEnd();







    int mn;





    GLfloat q61=0.2f; GLfloat q62=0.285f; GLfloat radius55 =.03f;



    int triangleAmount55= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi55 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q61,q62); // center of circle



        for(mn= 0; mn<= triangleAmount35;mn++) {



            glVertex2f( q61 + (radius55 * cos(mn*  twicePi55 / triangleAmount55)),



                        q62+ (radius55 *sin(mn* twicePi55 / triangleAmount55)) );



        }



        glEnd();





int op;





    GLfloat q63=0.18; GLfloat q64=0.289f; GLfloat radius56=.009f;



    int triangleAmount56 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi56 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q63,q64); // center of circle



        for(op= 0; op<= triangleAmount53;op++) {



            glVertex2f( q63 + (radius56 * cos(op*  twicePi56/ triangleAmount56)),



                        q64 + (radius56 *sin(op* twicePi56/ triangleAmount56)) );



        }



        glEnd();





GLfloat q65=0.22; GLfloat q66=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q65,q66); // center of circle



        for(op= 0; op<= triangleAmount56;op++) {



            glVertex2f( q65 + (radius56 * cos(op*  twicePi56 / triangleAmount56)),



                        q66 + (radius56 *sin(op * twicePi56/ triangleAmount56)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//man 6

glPushMatrix();
glTranslatef(0.4f,-0.7f,0.0f);
int qr;

GLfloat q67=0.2f; GLfloat q68=0.3f; GLfloat radius57 =.04f;



    int triangleAmount57 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi57 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q67,q68); // center of circle



        for(qr = 0; qr <= triangleAmount34;qr++) {



            glVertex2f( q67 + (radius57 * cos(qr *  twicePi57 / triangleAmount57)),



                        q68 + (radius57 * sin(qr * twicePi57 / triangleAmount57)) );



        }



    glEnd();







    int st;





    GLfloat q69=0.2f; GLfloat q70=0.285f; GLfloat radius58 =.03f;



    int triangleAmount58= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi58 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q69,q70); // center of circle



        for(st= 0; st<= triangleAmount35;st++) {



            glVertex2f( q69 + (radius58 * cos(st*  twicePi58 / triangleAmount58)),



                        q70+ (radius58 *sin(st* twicePi58 / triangleAmount58)) );



        }



        glEnd();





int uv;





    GLfloat q71=0.18; GLfloat q72=0.289f; GLfloat radius59=.009f;



    int triangleAmount59 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi59 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q71,q72); // center of circle



        for(uv= 0; uv<= triangleAmount59;uv++) {



            glVertex2f( q71 + (radius59 * cos(uv*  twicePi59 / triangleAmount59)),



                        q72 + (radius59 *sin(uv* twicePi59/ triangleAmount59)) );



        }



        glEnd();





GLfloat q73=0.22; GLfloat q74=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q73,q74); // center of circle



        for(uv= 0; uv<= triangleAmount59;uv++) {



            glVertex2f( q73 + (radius59 * cos(uv*  twicePi59 / triangleAmount59)),



                        q74 + (radius59 *sin(uv * twicePi59/ triangleAmount59)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//bbq 2
glPushMatrix();
glTranslatef(0.9f,-0.6f,0.0f);

glPushMatrix();
glScalef(-0.4f,0.4f,0.0f);
int qw;

	GLfloat p1=0.2f; GLfloat p2=0.3f; GLfloat radius77 =.13f;
	int triangleAmount70 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi70 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(p1,p2); // center of circle
		for(qw = 0; qw <= triangleAmount70;qw++) {
			glVertex2f( p1 + (radius77 * cos(qw *  twicePi70 / triangleAmount70)),
                        p2 + (radius77 * sin(qw * twicePi70 / triangleAmount70)) );
		}
	glEnd();


	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();









glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(231,56,0);

    glVertex2f(0.2f, 0.43f);
    glColor3ub(231,140,0);
    glVertex2f(0.2f, 0.17f);

glColor3ub(231,56,0);

    glVertex2f(0.26f, 0.43f);
    glColor3ub(231,140,0);

    glVertex2f(0.26f, 0.17f);

glColor3ub(231,56,0);
   glVertex2f(0.32f, 0.37f);
   glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.37f);
glColor3ub(231,56,0);
     glVertex2f(0.32f, 0.23f);
     glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.23f);
glColor3ub(231,56,0);
    glVertex2f(0.34f, 0.3f);
    glColor3ub(231,140,0);
    glVertex2f(0.06f, 0.3f);


glColor3ub(231,56,0);
    glVertex2f(0.14f, 0.43f);
     glColor3ub(231,140,0);

    glVertex2f(0.14f, 0.17f);


glEnd();

glPushMatrix();
glTranslatef(-0.05f,0.0f,0.0f);
glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();
glPopMatrix();



glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.16f,0.32f);
glVertex2d(0.16f,0.28f);

glVertex2d(0.152f,0.3f);
glVertex2d(0.152f,0.29f);



glEnd();

glPopMatrix();

glPopMatrix();





//man 7........

glPushMatrix();
glTranslatef(0.5f,-0.8f,0.0f);



int su;

GLfloat q81=0.2f; GLfloat q82=0.3f; GLfloat radius80 =.04f;



    int triangleAmount80 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi80 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q81,q82); // center of circle



        for(su = 0; su <= triangleAmount80;su++) {



            glVertex2f( q81 + (radius80 * cos(su *  twicePi80 / triangleAmount80)),



                        q82 + (radius80 * sin(su * twicePi80 / triangleAmount80)) );



        }



    glEnd();







    int ma;





    GLfloat q83=0.2f; GLfloat q84=0.285f; GLfloat radius81 =.03f;



    int triangleAmount81= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi81 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q83,q84); // center of circle



        for(ma= 0; ma<= triangleAmount81;ma++) {



            glVertex2f( q83 + (radius81 * cos(ma*  twicePi81/ triangleAmount81)),



                        q84+ (radius81 *sin(ma* twicePi81 / triangleAmount81)));


        }



        glEnd();





int sw;





    GLfloat q85=0.18; GLfloat q86=0.289f; GLfloat radius83=.009f;



    int triangleAmount83 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi83 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q85,q86); // center of circle



        for(sw= 0; sw<= triangleAmount83;sw++) {



            glVertex2f( q85 + (radius83 * cos(sw*  twicePi83 / triangleAmount83)),



                        q86 + (radius83 *sin(sw* twicePi83/ triangleAmount83)) );



        }



        glEnd();





GLfloat q87=0.22; GLfloat q88=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q87,q88); // center of circle



        for(sw= 0; sw<= triangleAmount83;sw++) {



            glVertex2f( q87 + (radius83 * cos(sw*  twicePi83 / triangleAmount83)),



                        q88 + (radius83 *sin(sw* twicePi83/ triangleAmount83)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();
glPopMatrix();





//.....

glPushMatrix();
glTranslatef(-0.1f,-0.35f,0.0f);

glPushMatrix();
glTranslatef(-1.0f,-0.6f,0.0f);
glPushMatrix();
glScalef(0.9f,0.9f,0.0);
glColor3ub(9,158,134);

glBegin(GL_TRIANGLES);

glVertex2d(0.18f,0.4f);
glColor3ub(195,206,210);
glVertex2d(0.5f,0.4f);
glColor3ub(99,42,25);
glVertex2d(0.35f,0.7f);

glEnd();
glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.236f, 0.4f);
    glVertex2f(0.236f, 0.2f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.456f, 0.4f);
    glVertex2f(0.456f, 0.2f);
glEnd();






glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.233f, 0.2f);
    glVertex2f(0.461f, 0.2f);
glEnd();


glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.25f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.32f, 0.2f);
    glVertex2f(0.32f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.26f);
    glVertex2f(0.321f, 0.26f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(240,197,190);
glVertex2f(0.24,0.2);
glColor3ub(246,144,121);
glVertex2f(0.24,0.0);
glVertex2f(0.45,0.0);
glVertex2f(0.45,0.2);
glEnd();


glLineWidth(2);
glColor3ub(99,42,25);

    glBegin(GL_LINES);
    glVertex2f(0.26f, 0.2f);
    glVertex2f(0.26f, 0.0f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.30f, 0.0f);
    glVertex2f(0.34f, 0.2f);
    glVertex2f(0.34f, 0.0f);
    glVertex2f(0.38f, 0.2f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.2f);
    glVertex2f(0.42f, 0.0f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(243,130,166);
glVertex2d(0.26f,0.27f);
glVertex2d(0.28f,0.27f);
glVertex2d(0.27f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(243,130,166);
glVertex2d(0.26f,0.33f);
glVertex2d(0.28f,0.33f);
glVertex2d(0.27f,0.25f);

glEnd();
glBegin(GL_QUADS);
glColor3ub(239,79,112);
glVertex2f(0.346,0.21);
glVertex2f(0.346,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.375,0.21);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.25f);
    glVertex2f(0.38f, 0.25f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(239,79,112);
glVertex2f(0.346,0.25);
glVertex2f(0.346,0.29);
glVertex2f(0.38,0.29);
glVertex2f(0.375,0.25);
glEnd();
glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.29f);
    glVertex2f(0.38f, 0.29f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(26,168,159);
glVertex2d(0.29f,0.27f);
glVertex2d(0.32f,0.27f);
glVertex2d(0.305f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(26,168,159);
glVertex2d(0.29f,0.33f);
glVertex2d(0.32f,0.33f);
glVertex2d(0.305f,0.25f);

glEnd();

glPopMatrix();
glPopMatrix();

glPopMatrix();




// stall5



glPushMatrix();
glTranslatef(0.72f,-0.5f,0.0f);
glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(-0.1f,-0.4f,0.0f);
glBegin(GL_QUADS);
glColor3ub(129,76,58);
glVertex2f(-0.28,0.7);
glVertex2f(-0.28,0.75);
glVertex2f(-0.6,0.75);
glVertex2f(-0.6,0.7);
glEnd();


glBegin(GL_QUADS);
glColor3ub(65,35,24);

glVertex2f(-0.601,0.7);
  glColor3ub (219,147,49);
glVertex2f(-0.65,0.47);
glVertex2f(-0.25,0.47);
glVertex2f(-0.279,0.7);
glEnd();



glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.25f);
    glVertex2f(-0.62f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.25f);
    glVertex2f(-0.28f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.6f, 0.47f);
glEnd();

glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.4f);
    glVertex2f(-0.3f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(165,42,42);
glVertex2f(-0.26,0.25);
glVertex2f(-0.26,0.21);
glVertex2f(-0.64,0.21);
glVertex2f(-0.64,0.25);
glEnd();

glBegin(GL_QUADS);
glColor3ub(161,109,69);
glVertex2f(-0.28,0.21);
glVertex2f(-0.28,-0.001);
 glColor3ub(200,145,55);
glVertex2f(-0.62,-0.001);
glVertex2f(-0.62,0.21);
glEnd();

glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(0.05f,0.0f,0.0f);
//..fish1...

glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.67f, 0.17f);
    glVertex2f(-0.67f, 0.13f);
glColor3ub(207,55,34);
    glBegin(GL_LINES);
    glVertex2f(-0.66f, 0.12f);
    glVertex2f(-0.68f, 0.12f);
glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.67f,0.12f);
glVertex2d(-0.68f,0.12f);
glVertex2d(-0.68f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.66f,0.12f);
glVertex2d(-0.67f,0.12f);
glVertex2d(-0.66f,0.17f);




glEnd();
glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.66,0.12);
glVertex2f(-0.667,0.03);
glVertex2f(-0.673,0.03);
glVertex2f(-0.68,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.664f, 0.07f);
    glVertex2f(-0.676f, 0.07f);
glEnd();
glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.671f, 0.043f);
    glVertex2f(-0.671f, 0.049f);
glEnd();
glPopMatrix();

glPopMatrix();


//.....fish2

glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.3f,0.0f);


glPushMatrix();
glTranslatef(0.0f,-0.3f,0.0f);
glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.61f, 0.17f);
    glVertex2f(-0.61f, 0.13f);
glEnd();

glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.61f,0.12f);
glVertex2d(-0.62f,0.12f);
glVertex2d(-0.62f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.6f,0.12f);
glVertex2d(-0.61f,0.12f);
glVertex2d(-0.6f,0.173f);

glEnd();


glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.6,0.12);
glVertex2f(-0.607,0.03);
glVertex2f(-0.613,0.03);
glVertex2f(-0.62,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.604f, 0.07f);
    glVertex2f(-0.616f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.611f, 0.043f);
    glVertex2f(-0.611f, 0.049f);
glEnd();
glPopMatrix();


glPopMatrix();

glPopMatrix();



//.fish3

glPushMatrix();

glScalef(-0.9f,-0.9f,0.0f);
glPushMatrix();
glTranslatef(0.1,-0.1f,0.f);


glLineWidth(2);

glColor3ub(207,55,34);



    glBegin(GL_LINES);

    glVertex2f(-0.64f, 0.17f);

    glVertex2f(-0.64f, 0.13f);

glEnd();





glColor3ub(98,119,146);



glBegin(GL_TRIANGLES);



glVertex2d(-0.65f,0.18f);

glVertex2d(-0.65f,0.12f);

glVertex2d(-0.64f,0.12f);





glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);



glVertex2d(-0.64f,0.12f);

glVertex2d(-0.63f,0.12f);

glVertex2d(-0.63f,0.17f);







glEnd();

glBegin(GL_QUADS);

glColor3ub(181,194,211);

glVertex2f(-0.65,0.12);

glVertex2f(-0.643,0.03);

glVertex2f(-0.637,0.03);

glVertex2f(-0.63,0.12);

glEnd();



glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.635f, 0.07f);
    glVertex2f(-0.645f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.64f, 0.043f);
    glVertex2f(-0.64f, 0.049f);
glEnd();
glPopMatrix();


glPopMatrix();

glPopMatrix();

glPopMatrix();
glPopMatrix();

glPopMatrix();

	glFlush();



//glFlush();



 // Render no


    // Render nowM

    }



    static void displaySecondScene() {


        glClear(GL_COLOR_BUFFER_BIT);
	         glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    // Clear the color buffer (background)

glColor3f(1.0,1.0,0.0);
renderBitmapString(0.63f, 0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Hello");







//.....sky.....

glBegin(GL_QUADS);

glColor3ub(3,190,252);

glVertex2f(-1.0,0.5);


glColor3ub(13, 191, 188);

glVertex2f(1.0,0.5);
glColor3ub(13, 191, 188);

glVertex2f(1.0,1.0);



glVertex2f(-1.0,1.0);

glEnd();
//............sun........
int k;


    GLfloat m=-0.6f; GLfloat n=0.7f; GLfloat radius3 =.13f;

    int triangleAmount3 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi3 = 2.0f * PI;


    glColor3ub(252,244,3);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(m,n); // center of circle

        for(k = 0; k <= triangleAmount3;k++) {

            glVertex2f( m + (radius3 * cos(k *  twicePi3 / triangleAmount3)),

                        n + (radius3 * sin(k * twicePi3 / triangleAmount3)) );

}

glEnd();
    //cloud
    glColor3ub(231, 242, 241);
    circle(-.425,.585,.04);

    circle(-.5,.6,.07);
    circle(-.59,.592,.05);
    circle(-.64,.58,.03);










//....river..
//glColor3ub(54,70,145);

glBegin(GL_QUADS);
glColor3ub(41,199,248);
glVertex2d(-1.0f,0.5f);
glColor3ub(54,70,145);
glVertex2d(-1.0f,0.23f);
glVertex2d(1.0f,0.1f);
glVertex2d(1.0f,0.5f);
glEnd();

//
/*glColor3ub(110,100,88);

glBegin(GL_QUADS);
glVertex2d(-1.0f,0.23f);
glVertex2d(-1.0f,-1.0f);
glVertex2d(1.0f,-1.0f);
glVertex2d(1.0f,0.1f);
glEnd();*/


glBegin(GL_QUADS);
glColor3ub(191, 141, 13);
glVertex2d(-1.0f,0.23f);
glColor3ub(254,227,138);
glVertex2d(-1.0f,-1.0f);
glColor3ub(191, 141, 13);
glVertex2d(1.0f,-1.0f);
glColor3ub(128,74,62);

glVertex2d(1.0f,0.1f);
glEnd();


//beach bench




//car

glPushMatrix();

    glTranslatef(-0.5f,-1.2f,0.0f);

    glTranslatef(carPositionX, carPositionY, 0.0f);

glBegin(GL_QUADS);



    glColor3ub(12,77,115);



    glVertex2f(0.6f,0.60f);



    glVertex2f(.58f,0.5f);



    glVertex2f(.75f,0.5f);

glVertex2f(.73f,0.6f);





glVertex2f(0.58f,0.5f);



    glVertex2f(.58f,0.38f);



    glVertex2f(.75f,0.38f);

glVertex2f(.75f,0.5f);







glColor3f(1.0f, 0.0f, 1.0f);

glVertex2f(0.6f,0.5f);



    glVertex2f(.6f,0.42f);



    glVertex2f(.73f,0.42f);

glVertex2f(.73f,0.5f);



glEnd();







glPushMatrix();

glTranslatef(0.0f,-0.1f,0.0f);

glBegin(GL_QUADS);



glColor3f(1.0f, -0.3f, 1.0f);



        glVertex2f(0.6f,0.85f);



    glVertex2f(.58f,0.8f);



    glVertex2f(.75f,0.8f);

glVertex2f(.73f,0.85f);



glEnd();

glPopMatrix();





glLineWidth(5);



glColor3ub(109,166,56);



glBegin(GL_LINES);

glVertex2f(0.618f,0.7f);

glVertex2f(0.618f,0.6f);



glVertex2f(0.72f,0.7f);

glVertex2f(0.72f,0.6f);





glEnd();

glPopMatrix();



glPushMatrix();

glTranslatef(-0.5f,-1.05f,0.0f);

int iq;



    GLfloat p21=0.6f; GLfloat p22=0.23f; GLfloat radius91 =.03f;

    int triangleAmount91 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi91 = 2.0f * PI;



    glColor3f(1.0f, 0.0f, 1.0f);



    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(p21, p22); // center of circle

        for(iq = 0; iq <= triangleAmount91;iq++) {

            glVertex2f( p21 + (radius91 * cos(iq *  twicePi91 / triangleAmount91)),

                        p22 + (radius91 * sin(iq * twicePi91 / triangleAmount91)) );

        }

    glEnd();





int ra;



    GLfloat p24=0.6f; GLfloat p25=0.23f; GLfloat radius92 =.01f;

    int triangleAmount92 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi92 = 2.0f * PI;



    glColor3ub(102,102,102);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(p24, p25); // center of circle

        for(ra = 0; ra <= triangleAmount92;ra++) {

            glVertex2f( p24 + (radius92 * cos(ra *  twicePi92 / triangleAmount92)),

                        p25 + (radius92 * sin(ra * twicePi92 / triangleAmount92)) );

        }

    glEnd();



int A;



    GLfloat p26=0.73f; GLfloat p27=0.23f; GLfloat radius93 =.03f;

    int triangleAmount93 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi93 = 2.0f * PI;



    glColor3f(1.0f, 0.0f, 1.0f);



    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(p26, p27); // center of circle

        for(A = 0; A <= triangleAmount93;A++) {

            glVertex2f( p26 + (radius93 * cos(A *  twicePi93 / triangleAmount93)),

                        p27 + (radius93 * sin(A * twicePi93 / triangleAmount93)) );

        }

    glEnd();





int B;



    GLfloat p28=0.73f; GLfloat p29=0.23f; GLfloat radius94 =.01f;

    int triangleAmount94 = 100; //# of lines used to draw circle



    //GLfloat radius = 0.8f; //radius

    GLfloat twicePi94 = 2.0f * PI;



    glColor3ub(102,102,102);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(p28, p29); // center of circle

        for(B = 0; B <= triangleAmount94;B++) {

            glVertex2f( p28 + (radius94 * cos(B *  twicePi94 / triangleAmount94)),

                        p29 + (radius94 * sin(B * twicePi94 / triangleAmount94)) );

        }

    glEnd();



glPopMatrix();





glPopMatrix();




//...stall 2

glPushMatrix();
glTranslatef(-0.1f,-0.3f,0.0f);


glColor3ub(161,109,67);

glBegin(GL_TRIANGLES);

glVertex2d(0.18f,0.4f);
glColor3ub(141,77,42);
glVertex2d(0.5f,0.4f);
glColor3ub(99,42,25);
glVertex2d(0.35f,0.7f);

glEnd();
glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.236f, 0.4f);
    glVertex2f(0.236f, 0.2f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.456f, 0.4f);
    glVertex2f(0.456f, 0.2f);
glEnd();






glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.233f, 0.2f);
    glVertex2f(0.461f, 0.2f);
glEnd();


glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.25f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.32f, 0.2f);
    glVertex2f(0.32f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.26f);
    glVertex2f(0.321f, 0.26f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.24,0.2);
glVertex2f(0.24,0.0);
glVertex2f(0.45,0.0);
glVertex2f(0.45,0.2);
glEnd();


glLineWidth(2);
glColor3ub(99,42,25);

    glBegin(GL_LINES);
    glVertex2f(0.26f, 0.2f);
    glVertex2f(0.26f, 0.0f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.30f, 0.0f);
    glVertex2f(0.34f, 0.2f);
    glVertex2f(0.34f, 0.0f);
    glVertex2f(0.38f, 0.2f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.2f);
    glVertex2f(0.42f, 0.0f);

glEnd();

glColor3ub(255,251,214);

glBegin(GL_QUADS);

glVertex2f(0.25,0.15);
glVertex2f(0.25,0.07);
glVertex2f(0.44,0.07);
glVertex2f(0.44,0.15);
glEnd();
glPopMatrix();


//ice-cream


glPushMatrix();
glTranslatef(-0.1f,-0.3f,0.0f);
glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.27f);
glVertex2d(0.28f,0.27f);
glVertex2d(0.27f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.33f);
glVertex2d(0.28f,0.33f);
glVertex2d(0.27f,0.25f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(127,89,66);
glVertex2d(0.26f,0.39f);
glVertex2d(0.28f,0.39f);
glVertex2d(0.27f,0.31f);

glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);
glVertex2d(0.29f,0.27f);
glVertex2d(0.32f,0.27f);
glVertex2d(0.305f,0.2f);

glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);
glVertex2d(0.29f,0.33f);
glVertex2d(0.32f,0.33f);
glVertex2d(0.305f,0.25f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(248,220,110);

glVertex2d(0.29f,0.39f);
glVertex2d(0.32f,0.39f);
glVertex2d(0.305f,0.31f);

glEnd();
glPopMatrix();

//...box

glPushMatrix();
glTranslatef(-0.12f,-0.3f,0.0f);
glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.21);
glVertex2f(0.346,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.375,0.21);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.25f);
    glVertex2f(0.38f, 0.25f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.25);
glVertex2f(0.346,0.29);
glVertex2f(0.38,0.29);
glVertex2f(0.375,0.25);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.29f);
    glVertex2f(0.38f, 0.29f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.346,0.29);
glVertex2f(0.346,0.33);
glVertex2f(0.38,0.33);
glVertex2f(0.375,0.29);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.33f);
    glVertex2f(0.38f, 0.33f);
glEnd();


glBegin(GL_QUADS);
glColor3ub(227,227,227);
glVertex2f(0.43,0.21);
glVertex2f(0.43,0.27);
glVertex2f(0.45,0.27);
glVertex2f(0.45,0.21);
glEnd();

glLineWidth(2);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.43f, 0.27f);
    glVertex2f(0.45f, 0.27f);
glEnd();


glLineWidth(1);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.435f, 0.272f);
    glVertex2f(0.435f, 0.32f);
glEnd();

glLineWidth(1);
glColor3ub(85,83,97);

    glBegin(GL_LINES);
    glVertex2f(0.445f, 0.272f);
    glVertex2f(0.445f, 0.32f);
glEnd();
glPopMatrix();



//....stall 1 man


glPushMatrix();
glTranslatef(0.1f,-0.3f,0.0);
int u;

	GLfloat q7=0.2f; GLfloat q8=0.3f; GLfloat radius14 =.04f;
	int triangleAmount7 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q7,q8); // center of circle
		for(u = 0; u <= triangleAmount7;u++) {
			glVertex2f( q7 + (radius14 * cos(u *  twicePi7 / triangleAmount7)),
                        q8 + (radius14 * sin(u * twicePi7 / triangleAmount7)) );
		}
	glEnd();



	int d;

	GLfloat q9=0.2f; GLfloat q10=0.285f; GLfloat radius15 =.03f;
	int triangleAmount12= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q9,q10); // center of circle
		for(d = 0; d <= triangleAmount12;d++) {
			glVertex2f( q9 + (radius15 * cos(d *  twicePi12 / triangleAmount12)),
                        q10 + (radius15 *sin(d * twicePi12 / triangleAmount12)) );
		}
		glEnd();

int c;

	GLfloat q11=0.18; GLfloat q12=0.289f; GLfloat radius16=.009f;
	int triangleAmount13 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q11,q12); // center of circle
		for(c= 0; c <= triangleAmount13;c++) {
			glVertex2f( q11 + (radius16 * cos(c*  twicePi13 / triangleAmount13)),
                        q12 + (radius16 *sin(c * twicePi13/ triangleAmount13)) );
		}
		glEnd();

GLfloat q13=0.22; GLfloat q14=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q13,q14); // center of circle
		for(c= 0; c <= triangleAmount13;c++) {
			glVertex2f( q13 + (radius16 * cos(c *  twicePi13 / triangleAmount13)),
                        q14 + (radius16 *sin(c * twicePi13/ triangleAmount13)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


/*glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();*/


glPushMatrix();
glTranslatef(-0.205f,0.007f,0.0);
glBegin(GL_QUADS);
glColor3ub(107,201,203);
glVertex2f(0.434,0.195);
glVertex2f(0.432,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.38,0.195);
glEnd();
glPopMatrix();


glPopMatrix();







//..stall3



//..coconut


glPushMatrix();
glTranslatef(0.0f,-0.2f,0.0f);

glPushMatrix();
glTranslatef(0.3f,-0.25f,0.f);

int i;

	GLfloat m1=0.32f; GLfloat m2=0.34f; GLfloat radius =.028f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
glColor3f(0.255f, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m1, m2); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m1 + (radius * cos(i *  twicePi / triangleAmount)),
                        m2+ (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();




	GLfloat m3=0.43f; GLfloat m4=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m3,m4); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m3 + (radius * cos(i*  twicePi / triangleAmount)),
                        m4 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m5=0.48f; GLfloat m6=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m5,m6); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m5 + (radius * cos(i*  twicePi / triangleAmount)),
                        m6 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m7=0.52f; GLfloat m8=0.25f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m7,m8); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m7 + (radius * cos(i*  twicePi / triangleAmount)),
                        m8 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();



GLfloat m9=0.50f; GLfloat m10=0.3f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m9 + (radius * cos(i*  twicePi / triangleAmount)),
                        m10 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

GLfloat m11=0.45f; GLfloat m12=0.3f; //GLfloat radius =.028f;

glColor3f(0.0f, 204.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m11 + (radius * cos(i*  twicePi / triangleAmount)),
                        m12 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();






GLfloat m13=0.475f; GLfloat m14=0.35f; //GLfloat radius =.028f;

glColor3ub(66,144,67);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m9,m10); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( m13 + (radius * cos(i*  twicePi / triangleAmount)),
                        m14 + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();






int l1;

GLfloat x1=0.32f; GLfloat x2 =0.349f; GLfloat radi2 =0.012f;

int triangleAmount1 = 20;
GLfloat twicePi1 = 2.0f * PI;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(238,177,90);

glVertex2f(x1, x2);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x1+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x2 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();


    // Clear the color buffer (background)

GLfloat x3=0.43f; GLfloat x4 =0.259f;



glBegin(GL_TRIANGLE_FAN);


glColor3ub(238,177,90);

glVertex2f(x3, x4);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x3+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x4 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();


    // Clear the color buffer (background)
GLfloat x5=0.48f; GLfloat x6 =0.259f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x5, x6);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x5+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x6 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}
glEnd();



GLfloat x7=0.52f; GLfloat x8 =0.259f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x7, x8);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x7+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x8 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (background)


GLfloat x9=0.50f; GLfloat x10 =0.3f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x9, x10);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x9+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x10 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (b


GLfloat x11=0.45f; GLfloat x12 =0.3f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x11, x12);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x11+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x12 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;  // Clear the color buffer (b




GLfloat x13=0.475f; GLfloat x14 =0.35f;


glBegin(GL_TRIANGLE_FAN);


glColor3ub(246,223,169);

glVertex2f(x13, x14);

for(l1 = 0; l1 <= triangleAmount1;l1++) {

glVertex2f(

x13+ (radi2 * cos(l1 *  twicePi1/ triangleAmount1)),

x14 + (radi2 * sin(l1 * twicePi1 / triangleAmount1))
);

}

 glEnd() ;

//...stall 3....

//glColor3f(0.255f, 0.0f, 0.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.255f, 0.0f, 0.0f);
glVertex2d(0.18f,0.4f);
glColor3ub(126,90,66);//(201,83,73);
glVertex2d(0.62f,0.4f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);
glVertex2d(0.28f,0.45f);
glColor3ub(105,42,22);
glVertex2d(0.33f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);
glVertex2d(0.38f,0.45f);
glColor3ub(105,42,22);

glVertex2d(0.43f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(171,90,40);

glVertex2d(0.48f,0.45f);
glColor3ub(105,42,22);

glVertex2d(0.53f,0.45f);
glVertex2d(0.4f,0.7f);


glEnd();



glColor3ub(213,113,37);
glBegin(GL_TRIANGLES);

glVertex2d(0.23f,0.4f);
glVertex2d(0.24f,0.4f);
glVertex2d(0.24f,0.1f);


glEnd();




glColor3ub(213,113,37);
glBegin(GL_TRIANGLES);

glVertex2d(0.56f,0.4f);
glVertex2d(0.57f,0.4f);
glVertex2d(0.57f,0.1f);


glEnd();





glBegin(GL_QUADS);
glColor3ub(182,97,44);
glVertex2d(0.26f,0.23f);
glVertex2d(0.26f,0.1f);
glColor3ub(105,42,22);
glVertex2d(0.54f,0.1f);
glColor3ub(40,15,14);
glVertex2d(0.54f,0.23f);
glEnd();



glLineWidth(3);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.28f, 0.31f);
    glVertex2f(0.42f, 0.31f);

glEnd();


glLineWidth(2);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.29f, 0.31f);
    glVertex2f(0.29f, 0.23f);

    glVertex2f(0.41f, 0.31f);
    glVertex2f(0.41f, 0.23f);


    glVertex2f(0.35f, 0.31f);
    glVertex2f(0.35f, 0.23f);



glEnd();
//...glass...
glColor3ub(121,197,220);
glBegin(GL_QUADS);
glVertex2d(0.31f,0.23f);
glVertex2d(0.31f,0.28f);
glVertex2d(0.32f,0.28f);
glVertex2d(0.32f,0.23f);
glEnd();

glColor3f(201,232,237);
glBegin(GL_QUADS);
glVertex2d(0.31f,0.27f);
glVertex2d(0.31f,0.28f);
glVertex2d(0.32f,0.28f);
glVertex2d(0.32f,0.27f);
glEnd();


glColor3ub(121,197,220);

glBegin(GL_QUADS);
glVertex2d(0.37f,0.23f);
glVertex2d(0.37f,0.28f);
glVertex2d(0.38f,0.28f);
glVertex2d(0.38f,0.23f);
glEnd();

glColor3f(201,232,237);
glBegin(GL_QUADS);
glVertex2d(0.37f,0.27f);
glVertex2d(0.37f,0.28f);
glVertex2d(0.38f,0.28f);


glVertex2d(0.38f,0.27f);
glEnd();






















glPushMatrix();
glTranslatef(0.43f,-0.05f,0.0f);

glBegin(GL_QUADS);

    glColor3f(0.42f, 0.235f, 0.012f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.5f,0.1f);

    glVertex2f(0.51f,0.1f);

    glVertex2f(0.51f,-0.1f);

    glEnd();


    glPopMatrix();
/*
//.bbq...
glPushMatrix();
glTranslatef(0.2f,-0.2f,0.0f);


   glPushMatrix();
glTranslatef(-0.5f,-0.5f,0.0f);
	int j;

	GLfloat x=0.2f; GLfloat y=0.3f; GLfloat radius1 =.13f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f( x + (radius1 * cos(j *  twicePi2 / triangleAmount2)),
                        y + (radius1 * sin(j * twicePi2 / triangleAmount2)) );
		}
	glEnd();

//glPopMatrix();




	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(1,0,40);

    glVertex2f(0.2f, 0.43f);
    glVertex2f(0.2f, 0.17f);


    glVertex2f(0.26f, 0.43f);
    glVertex2f(0.26f, 0.17f);


   glVertex2f(0.3f, 0.4f);
    glVertex2f(0.09f, 0.4f);

glVertex2f(0.3f, 0.2f);
    glVertex2f(0.09f, 0.2f);

    glVertex2f(0.34f, 0.3f);
    glVertex2f(0.06f, 0.3f);



    glVertex2f(0.14f, 0.43f);
    glVertex2f(0.14f, 0.17f);


glEnd();
//glPushMatrix();

glPopMatrix();

glPopMatrix();


*/

//.......man 1
glPushMatrix();
glTranslatef(0.0f,-0.6f,0.0f);
int t;

	GLfloat q19=0.2f; GLfloat q20=0.3f; GLfloat radius20 =.04f;
	int triangleAmount21 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q19,q20); // center of circle
		for(t = 0; t <= triangleAmount21;t++) {
			glVertex2f( q19 + (radius20 * cos(t *  twicePi21 / triangleAmount21)),
                        q20 + (radius20 * sin(t * twicePi21 / triangleAmount21)) );
		}
	glEnd();



	int v;

	GLfloat q21=0.2f; GLfloat q22=0.285f; GLfloat radius21 =.03f;
	int triangleAmount22= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q21,q22); // center of circle
		for(v= 0; v <= triangleAmount22;v++) {
			glVertex2f( q21 + (radius21 * cos(v *  twicePi22 / triangleAmount22)),
                        q22 + (radius21 *sin(v * twicePi22 / triangleAmount22)) );
		}
		glEnd();

int w;

	GLfloat q23=0.18; GLfloat q24=0.289f; GLfloat radius22=.009f;
	int triangleAmount23 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q23,q24); // center of circle
		for(w= 0; w <= triangleAmount23;w++) {
			glVertex2f( q23 + (radius22 * cos(w*  twicePi23 / triangleAmount23)),
                        q24 + (radius22 *sin(w* twicePi23/ triangleAmount23)) );
		}
		glEnd();

GLfloat q25=0.22; GLfloat q26=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q25,q26); // center of circle
		for(w= 0; w <= triangleAmount23;w++) {
			glVertex2f( q25 + (radius22 * cos(w *  twicePi23 / triangleAmount23)),
                        q26 + (radius22 *sin(w * twicePi23/ triangleAmount23)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.178,0.245);
glVertex2f(0.178,0.18);
glVertex2f(0.223,0.18);
glVertex2f(0.223,0.245);
glEnd();


glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.19f,0.18f);
    glVertex2f(0.19f, 0.15f);

    glBegin(GL_LINES);
    glVertex2f(0.21f,0.18f);
    glVertex2f(0.21f, 0.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.185,0.15);
glVertex2f(0.185,0.14);
glVertex2f(0.195,0.14);
glVertex2f(0.195,0.15);



glColor3ub(142,83,39);
glVertex2f(0.205,0.15);
glVertex2f(0.205,0.14);
glVertex2f(0.215,0.14);
glVertex2f(0.215,0.15);
glEnd();

glPopMatrix();

//......










//....man 2




glPushMatrix();
glTranslatef(-0.3f,-0.8f,0.0f);

int b;

	GLfloat q31=0.2f; GLfloat q32=0.3f; GLfloat radius31 =.04f;
	int triangleAmount31 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi31 = 2.0f * PI;

	glColor3ub(55,36,38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q31,q32); // center of circle
		for(b = 0; b <= triangleAmount31;b++) {
			glVertex2f( q31 + (radius31 * cos(b *  twicePi31 / triangleAmount31)),
                        q32 + (radius31 * sin(b * twicePi31 / triangleAmount31)) );
		}
	glEnd();



	int z;

	GLfloat q33=0.2f; GLfloat q34=0.285f; GLfloat radius32 =.03f;
	int triangleAmount32= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi32 = 2.0f * PI;

	glColor3ub(251,180,138);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q33,q34); // center of circle
		for(z= 0; z <= triangleAmount32;z++) {
			glVertex2f( q33 + (radius32 * cos(z*  twicePi32 / triangleAmount32)),
                        q34+ (radius32 *sin(z * twicePi32 / triangleAmount32)) );
		}
		glEnd();

int a;

	GLfloat q35=0.18; GLfloat q36=0.289f; GLfloat radius33=.009f;
	int triangleAmount33 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi33 = 2.0f * PI;

	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q35,q36); // center of circle
		for(a= 0; a <= triangleAmount33;a++) {
			glVertex2f( q35 + (radius33 * cos(a*  twicePi33 / triangleAmount33)),
                        q36 + (radius33 *sin(a* twicePi33/ triangleAmount33)) );
		}
		glEnd();

GLfloat q37=0.22; GLfloat q38=0.289f; //GLfloat radius5=.01f;
	//int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi4 = 2.0f * PI;

	glColor3f(255,255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(q37,q38); // center of circle
		for(a= 0; a <= triangleAmount33;a++) {
			glVertex2f( q37 + (radius33 * cos(a *  twicePi33 / triangleAmount33)),
                        q38 + (radius33 *sin(a * twicePi33/ triangleAmount33)) );
		}
		glEnd();




glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.291f);
    glVertex2f(0.22f, 0.282f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.291f);
    glVertex2f(0.18f, 0.282f);
glEnd();


glLineWidth(6);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.2475f);
    glVertex2f(0.2f, 0.245f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.178,0.245);
glVertex2f(0.178,0.18);
glVertex2f(0.223,0.18);
glVertex2f(0.223,0.245);
glEnd();


glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.19f,0.18f);
    glVertex2f(0.19f, 0.15f);

    glBegin(GL_LINES);
    glVertex2f(0.21f,0.18f);
    glVertex2f(0.21f, 0.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(142,83,39);
glVertex2f(0.185,0.15);
glVertex2f(0.185,0.14);
glVertex2f(0.195,0.14);
glVertex2f(0.195,0.15);



glColor3ub(142,83,39);
glVertex2f(0.205,0.15);
glVertex2f(0.205,0.14);
glVertex2f(0.215,0.14);
glVertex2f(0.215,0.15);
glEnd();


glPopMatrix();

glPopMatrix();





glPushMatrix();
glTranslatef(-0.3f,-0.7f,0.0f);

glPushMatrix();
glScalef(-0.35f,0.4f,0.0f);
//glPushMatrix();
//glTranslatef(-0.7f,-0.8f,0.0f);

	int j;

	GLfloat x=0.2f; GLfloat y=0.3f; GLfloat radius1 =.13f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f( x + (radius1 * cos(j *  twicePi2 / triangleAmount2)),
                        y + (radius1 * sin(j * twicePi2 / triangleAmount2)) );
		}
	glEnd();

//glPopMatrix();




	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(231,56,0);

    glVertex2f(0.2f, 0.43f);
    glColor3ub(231,140,0);
    glVertex2f(0.2f, 0.17f);

glColor3ub(231,56,0);

    glVertex2f(0.26f, 0.43f);
    glColor3ub(231,140,0);

    glVertex2f(0.26f, 0.17f);

glColor3ub(231,56,0);
   glVertex2f(0.32f, 0.37f);
   glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.37f);
glColor3ub(231,56,0);
     glVertex2f(0.32f, 0.23f);
     glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.23f);
glColor3ub(231,56,0);
    glVertex2f(0.34f, 0.3f);
    glColor3ub(231,140,0);
    glVertex2f(0.06f, 0.3f);


glColor3ub(231,56,0);
    glVertex2f(0.14f, 0.43f);
     glColor3ub(231,140,0);

    glVertex2f(0.14f, 0.17f);


glEnd();
//glPushMatrix();
//.bbq fish
/*
glPopMatrix();

glPushMatrix();
        glScalef(0.6f,0.6f,0.0f);*///.fish

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.2f,0.32f);
glVertex2d(0.2f,0.28f);

glVertex2d(0.173f,0.3f);
glVertex2d(0.173f,0.29f);



glEnd();

glPopMatrix();
glPopMatrix();



glPushMatrix();
glTranslatef(-0.48f,-0.68f,0.0f);
glPushMatrix();
glScalef(0.45f,0.45f,0.0f);

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.2f,0.32f);
glVertex2d(0.2f,0.28f);

glVertex2d(0.173f,0.3f);
glVertex2d(0.173f,0.29f);



glEnd();

glPopMatrix();
glPopMatrix();







//man 3

glPushMatrix();
glTranslatef(-0.4f,-0.6f,0.0f);

int ab;

GLfloat q39=0.2f; GLfloat q40=0.3f; GLfloat radius34 =.04f;



    int triangleAmount34 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi34 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q39,q40); // center of circle



        for(ab = 0; ab <= triangleAmount34;ab++) {



            glVertex2f( q39 + (radius34 * cos(ab *  twicePi34 / triangleAmount34)),



                        q40 + (radius34 * sin(ab * twicePi34 / triangleAmount34)) );



        }



    glEnd();







    int cd;





    GLfloat q41=0.2f; GLfloat q42=0.285f; GLfloat radius35 =.03f;



    int triangleAmount35= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi35 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q41,q42); // center of circle



        for(cd= 0; cd<= triangleAmount35;cd++) {



            glVertex2f( q41 + (radius35 * cos(cd*  twicePi35 / triangleAmount35)),



                        q42+ (radius35 *sin(cd * twicePi35 / triangleAmount35)) );



        }



        glEnd();





int o;





    GLfloat q43=0.18; GLfloat q44=0.289f; GLfloat radius36=.009f;



    int triangleAmount36 = 100; //# of lines used to draw circle









    GLfloat twicePi36 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q43,q44); // center of circle



        for(o= 0; o<= triangleAmount36;o++) {



            glVertex2f( q43 + (radius36 * cos(o*  twicePi36 / triangleAmount36)),



                        q44 + (radius36 *sin(0* twicePi36/ triangleAmount36)) );



        }



        glEnd();





GLfloat q45=0.22; GLfloat q46=0.289f; //GLfloat radius36=.01f;


    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q45,q46); // center of circle



        for(o= 0; o<= triangleAmount36;o++) {



            glVertex2f( q45 + (radius36 * cos(o *  twicePi36 / triangleAmount36)),



                        q46 + (radius36 *sin(o * twicePi36/ triangleAmount36)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//man4

glPushMatrix();
glTranslatef(-0.5f,-1.0f,0.0f);

int ef;

GLfloat q51=0.2f; GLfloat q52=0.3f; GLfloat radius51 =.04f;



    int triangleAmount51 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi51 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q51,q52); // center of circle



        for(ef = 0; ef <= triangleAmount34;ef++) {



            glVertex2f( q51 + (radius51 * cos(ef *  twicePi51 / triangleAmount51)),



                        q52 + (radius51 * sin(ef * twicePi51 / triangleAmount51)) );



        }



    glEnd();







    int gh;





    GLfloat q53=0.2f; GLfloat q54=0.285f; GLfloat radius52 =.03f;



    int triangleAmount52= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi52 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q53,q54); // center of circle



        for(gh= 0; gh<= triangleAmount35;gh++) {



            glVertex2f( q53 + (radius52 * cos(gh*  twicePi52 / triangleAmount52)),



                        q54+ (radius52 *sin(gh* twicePi52 / triangleAmount52)) );



        }



        glEnd();





int ij;





    GLfloat q55=0.18; GLfloat q56=0.289f; GLfloat radius53=.009f;



    int triangleAmount53 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi53 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q55,q56); // center of circle



        for(ij= 0; ij<= triangleAmount53;ij++) {



            glVertex2f( q55 + (radius53 * cos(ij*  twicePi53 / triangleAmount53)),



                        q56 + (radius53 *sin(ij* twicePi53/ triangleAmount53)) );



        }



        glEnd();





GLfloat q57=0.22; GLfloat q58=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q57,q58); // center of circle



        for(ij= 0; ij<= triangleAmount53;ij++) {



            glVertex2f( q57 + (radius53 * cos(ij*  twicePi53 / triangleAmount53)),



                        q58 + (radius53 *sin(ij * twicePi53/ triangleAmount53)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();



//man 5
glPushMatrix();
glTranslatef(-0.7f,-0.6f,0.0f);


int kl;

GLfloat q59=0.2f; GLfloat q60=0.3f; GLfloat radius54 =.04f;



    int triangleAmount54 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi54 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q59,q60); // center of circle



        for(kl = 0; kl <= triangleAmount54;kl++) {



            glVertex2f( q59 + (radius54 * cos(kl *  twicePi54 / triangleAmount54)),



                        q60 + (radius54 * sin(kl * twicePi54 / triangleAmount54)) );



        }



    glEnd();







    int mn;





    GLfloat q61=0.2f; GLfloat q62=0.285f; GLfloat radius55 =.03f;



    int triangleAmount55= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi55 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q61,q62); // center of circle



        for(mn= 0; mn<= triangleAmount35;mn++) {



            glVertex2f( q61 + (radius55 * cos(mn*  twicePi55 / triangleAmount55)),



                        q62+ (radius55 *sin(mn* twicePi55 / triangleAmount55)) );



        }



        glEnd();





int op;





    GLfloat q63=0.18; GLfloat q64=0.289f; GLfloat radius56=.009f;



    int triangleAmount56 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi56 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q63,q64); // center of circle



        for(op= 0; op<= triangleAmount53;op++) {



            glVertex2f( q63 + (radius56 * cos(op*  twicePi56/ triangleAmount56)),



                        q64 + (radius56 *sin(op* twicePi56/ triangleAmount56)) );



        }



        glEnd();





GLfloat q65=0.22; GLfloat q66=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q65,q66); // center of circle



        for(op= 0; op<= triangleAmount56;op++) {



            glVertex2f( q65 + (radius56 * cos(op*  twicePi56 / triangleAmount56)),



                        q66 + (radius56 *sin(op * twicePi56/ triangleAmount56)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//man 6

glPushMatrix();
glTranslatef(0.4f,-0.7f,0.0f);
int qr;

GLfloat q67=0.2f; GLfloat q68=0.3f; GLfloat radius57 =.04f;



    int triangleAmount57 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi57 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q67,q68); // center of circle



        for(qr = 0; qr <= triangleAmount34;qr++) {



            glVertex2f( q67 + (radius57 * cos(qr *  twicePi57 / triangleAmount57)),



                        q68 + (radius57 * sin(qr * twicePi57 / triangleAmount57)) );



        }



    glEnd();







    int st;





    GLfloat q69=0.2f; GLfloat q70=0.285f; GLfloat radius58 =.03f;



    int triangleAmount58= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi58 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q69,q70); // center of circle



        for(st= 0; st<= triangleAmount35;st++) {



            glVertex2f( q69 + (radius58 * cos(st*  twicePi58 / triangleAmount58)),



                        q70+ (radius58 *sin(st* twicePi58 / triangleAmount58)) );



        }



        glEnd();





int uv;





    GLfloat q71=0.18; GLfloat q72=0.289f; GLfloat radius59=.009f;



    int triangleAmount59 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi59 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q71,q72); // center of circle



        for(uv= 0; uv<= triangleAmount59;uv++) {



            glVertex2f( q71 + (radius59 * cos(uv*  twicePi59 / triangleAmount59)),



                        q72 + (radius59 *sin(uv* twicePi59/ triangleAmount59)) );



        }



        glEnd();





GLfloat q73=0.22; GLfloat q74=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q73,q74); // center of circle



        for(uv= 0; uv<= triangleAmount59;uv++) {



            glVertex2f( q73 + (radius59 * cos(uv*  twicePi59 / triangleAmount59)),



                        q74 + (radius59 *sin(uv * twicePi59/ triangleAmount59)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();

glPopMatrix();





//bbq 2
glPushMatrix();
glTranslatef(0.9f,-0.6f,0.0f);

glPushMatrix();
glScalef(-0.4f,0.4f,0.0f);
int qw;

	GLfloat p1=0.2f; GLfloat p2=0.3f; GLfloat radius77 =.13f;
	int triangleAmount70 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi70 = 2.0f * PI;

	glColor3ub(90,73,65);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(p1,p2); // center of circle
		for(qw = 0; qw <= triangleAmount70;qw++) {
			glVertex2f( p1 + (radius77 * cos(qw *  twicePi70 / triangleAmount70)),
                        p2 + (radius77 * sin(qw * twicePi70 / triangleAmount70)) );
		}
	glEnd();


	glLineWidth(5);
	glColor3ub(16,13,4);

    glBegin(GL_LINES);
    glVertex2f(0.325f, 0.26f);
    glVertex2f(0.325f, -0.1f);
glEnd();

glLineWidth(5);
    glBegin(GL_LINES);
	glColor3ub(16,13,4);

    glVertex2f(0.078f, 0.26f);
    glVertex2f(0.078f, -0.1f);

     glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.1f);

glEnd();









glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(231,56,0);

    glVertex2f(0.2f, 0.43f);
    glColor3ub(231,140,0);
    glVertex2f(0.2f, 0.17f);

glColor3ub(231,56,0);

    glVertex2f(0.26f, 0.43f);
    glColor3ub(231,140,0);

    glVertex2f(0.26f, 0.17f);

glColor3ub(231,56,0);
   glVertex2f(0.32f, 0.37f);
   glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.37f);
glColor3ub(231,56,0);
     glVertex2f(0.32f, 0.23f);
     glColor3ub(231,140,0);
    glVertex2f(0.09f, 0.23f);
glColor3ub(231,56,0);
    glVertex2f(0.34f, 0.3f);
    glColor3ub(231,140,0);
    glVertex2f(0.06f, 0.3f);


glColor3ub(231,56,0);
    glVertex2f(0.14f, 0.43f);
     glColor3ub(231,140,0);

    glVertex2f(0.14f, 0.17f);


glEnd();

glPushMatrix();
glTranslatef(-0.05f,0.0f,0.0f);
glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.34f);
glVertex2d(0.35f,0.35f);





glVertex2d(0.3f,0.3f);
glVertex2d(0.3f,0.26f);
glVertex2d(0.35f,0.25f);

glVertex2d(0.23f,0.328f);
glVertex2d(0.25f,0.32f);
glVertex2d(0.25f,0.35f);



glEnd();

glColor3ub(181,194,211);
glBegin(GL_QUADS);
glVertex2d(0.3f,0.34f);
glVertex2d(0.15f,0.3f);
glVertex2d(0.15f,0.29f);

glVertex2d(0.3f,0.26f);



glEnd();
glPopMatrix();



glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(98,119,146);
  glVertex2d(0.16f,0.32f);
glVertex2d(0.16f,0.28f);

glVertex2d(0.152f,0.3f);
glVertex2d(0.152f,0.29f);



glEnd();

glPopMatrix();

glPopMatrix();





//man 7........

glPushMatrix();
glTranslatef(0.5f,-0.8f,0.0f);



int su;

GLfloat q81=0.2f; GLfloat q82=0.3f; GLfloat radius80 =.04f;



    int triangleAmount80 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi80 = 2.0f * PI;





    glColor3ub(55,36,38);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q81,q82); // center of circle



        for(su = 0; su <= triangleAmount80;su++) {



            glVertex2f( q81 + (radius80 * cos(su *  twicePi80 / triangleAmount80)),



                        q82 + (radius80 * sin(su * twicePi80 / triangleAmount80)) );



        }



    glEnd();







    int ma;





    GLfloat q83=0.2f; GLfloat q84=0.285f; GLfloat radius81 =.03f;



    int triangleAmount81= 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi81 = 2.0f * PI;





    glColor3ub(251,180,138);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q83,q84); // center of circle



        for(ma= 0; ma<= triangleAmount81;ma++) {



            glVertex2f( q83 + (radius81 * cos(ma*  twicePi81/ triangleAmount81)),



                        q84+ (radius81 *sin(ma* twicePi81 / triangleAmount81)));


        }



        glEnd();





int sw;





    GLfloat q85=0.18; GLfloat q86=0.289f; GLfloat radius83=.009f;



    int triangleAmount83 = 100; //# of lines used to draw circle





    //GLfloat radius = 0.8f; //radius



    GLfloat twicePi83 = 2.0f * PI;





    glColor3ub(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q85,q86); // center of circle



        for(sw= 0; sw<= triangleAmount83;sw++) {



            glVertex2f( q85 + (radius83 * cos(sw*  twicePi83 / triangleAmount83)),



                        q86 + (radius83 *sin(sw* twicePi83/ triangleAmount83)) );



        }



        glEnd();





GLfloat q87=0.22; GLfloat q88=0.289f; //GLfloat radius36=.01f;






    glColor3f(255,255,255);



    glBegin(GL_TRIANGLE_FAN);



        glVertex2f(q87,q88); // center of circle



        for(sw= 0; sw<= triangleAmount83;sw++) {



            glVertex2f( q87 + (radius83 * cos(sw*  twicePi83 / triangleAmount83)),



                        q88 + (radius83 *sin(sw* twicePi83/ triangleAmount83)) );



        }



        glEnd();









glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.22f, 0.291f);



    glVertex2f(0.22f, 0.282f);



glEnd();





glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.18f, 0.291f);



    glVertex2f(0.18f, 0.282f);



glEnd();







glLineWidth(6);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.2f, 0.2475f);



    glVertex2f(0.2f, 0.245f);



glEnd();







glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.178,0.245);



glVertex2f(0.178,0.18);



glVertex2f(0.223,0.18);



glVertex2f(0.223,0.245);



glEnd();







glLineWidth(3);



glColor3ub(42,23,9);





    glBegin(GL_LINES);



    glVertex2f(0.19f,0.18f);



    glVertex2f(0.19f, 0.15f);





    glBegin(GL_LINES);



    glVertex2f(0.21f,0.18f);



    glVertex2f(0.21f, 0.15f);



glEnd();





glBegin(GL_QUADS);



glColor3ub(142,83,39);



glVertex2f(0.185,0.15);



glVertex2f(0.185,0.14);



glVertex2f(0.195,0.14);



glVertex2f(0.195,0.15);







glColor3ub(142,83,39);



glVertex2f(0.205,0.15);



glVertex2f(0.205,0.14);



glVertex2f(0.215,0.14);



glVertex2f(0.215,0.15);



glEnd();
glPopMatrix();





//.....

glPushMatrix();
glTranslatef(-0.1f,-0.35f,0.0f);

glPushMatrix();
glTranslatef(-1.0f,-0.6f,0.0f);
glPushMatrix();
glScalef(0.9f,0.9f,0.0);
glColor3ub(9,158,134);

glBegin(GL_TRIANGLES);

glVertex2d(0.18f,0.4f);
glColor3ub(195,206,210);
glVertex2d(0.5f,0.4f);
glColor3ub(99,42,25);
glVertex2d(0.35f,0.7f);

glEnd();
glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.236f, 0.4f);
    glVertex2f(0.236f, 0.2f);
glEnd();

glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.456f, 0.4f);
    glVertex2f(0.456f, 0.2f);
glEnd();






glLineWidth(3);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.233f, 0.2f);
    glVertex2f(0.461f, 0.2f);
glEnd();


glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.25f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.32f, 0.2f);
    glVertex2f(0.32f, 0.28f);
glEnd();

glLineWidth(2);
glColor3ub(42,23,9);

    glBegin(GL_LINES);
    glVertex2f(0.25f, 0.26f);
    glVertex2f(0.321f, 0.26f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(240,197,190);
glVertex2f(0.24,0.2);
glColor3ub(246,144,121);
glVertex2f(0.24,0.0);
glVertex2f(0.45,0.0);
glVertex2f(0.45,0.2);
glEnd();


glLineWidth(2);
glColor3ub(99,42,25);

    glBegin(GL_LINES);
    glVertex2f(0.26f, 0.2f);
    glVertex2f(0.26f, 0.0f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.30f, 0.0f);
    glVertex2f(0.34f, 0.2f);
    glVertex2f(0.34f, 0.0f);
    glVertex2f(0.38f, 0.2f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.2f);
    glVertex2f(0.42f, 0.0f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(243,130,166);
glVertex2d(0.26f,0.27f);
glVertex2d(0.28f,0.27f);
glVertex2d(0.27f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(243,130,166);
glVertex2d(0.26f,0.33f);
glVertex2d(0.28f,0.33f);
glVertex2d(0.27f,0.25f);

glEnd();
glBegin(GL_QUADS);
glColor3ub(239,79,112);
glVertex2f(0.346,0.21);
glVertex2f(0.346,0.25);
glVertex2f(0.38,0.25);
glVertex2f(0.375,0.21);
glEnd();

glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.25f);
    glVertex2f(0.38f, 0.25f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(239,79,112);
glVertex2f(0.346,0.25);
glVertex2f(0.346,0.29);
glVertex2f(0.38,0.29);
glVertex2f(0.375,0.25);
glEnd();
glLineWidth(2);
glColor3ub(148,227,231);

    glBegin(GL_LINES);
    glVertex2f(0.346f, 0.29f);
    glVertex2f(0.38f, 0.29f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(26,168,159);
glVertex2d(0.29f,0.27f);
glVertex2d(0.32f,0.27f);
glVertex2d(0.305f,0.2f);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(26,168,159);
glVertex2d(0.29f,0.33f);
glVertex2d(0.32f,0.33f);
glVertex2d(0.305f,0.25f);

glEnd();

glPopMatrix();
glPopMatrix();

glPopMatrix();




// stall5



glPushMatrix();
glTranslatef(0.72f,-0.5f,0.0f);
glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(-0.1f,-0.4f,0.0f);
glBegin(GL_QUADS);
glColor3ub(129,76,58);
glVertex2f(-0.28,0.7);
glVertex2f(-0.28,0.75);
glVertex2f(-0.6,0.75);
glVertex2f(-0.6,0.7);
glEnd();


glBegin(GL_QUADS);
glColor3ub(65,35,24);

glVertex2f(-0.601,0.7);
  glColor3ub (219,147,49);
glVertex2f(-0.65,0.47);
glVertex2f(-0.25,0.47);
glVertex2f(-0.279,0.7);
glEnd();



glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.25f);
    glVertex2f(-0.62f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.25f);
    glVertex2f(-0.28f, 0.47f);
glEnd();


glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.6f, 0.47f);
glEnd();

glLineWidth(5);
    glColor3ub(224,148,88);
    glBegin(GL_LINES);
    glVertex2f(-0.28f, 0.4f);
    glVertex2f(-0.3f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(165,42,42);
glVertex2f(-0.26,0.25);
glVertex2f(-0.26,0.21);
glVertex2f(-0.64,0.21);
glVertex2f(-0.64,0.25);
glEnd();

glBegin(GL_QUADS);
glColor3ub(161,109,69);
glVertex2f(-0.28,0.21);
glVertex2f(-0.28,-0.001);
 glColor3ub(200,145,55);
glVertex2f(-0.62,-0.001);
glVertex2f(-0.62,0.21);
glEnd();

glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(0.05f,0.0f,0.0f);
//..fish1...

glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.67f, 0.17f);
    glVertex2f(-0.67f, 0.13f);
glColor3ub(207,55,34);
    glBegin(GL_LINES);
    glVertex2f(-0.66f, 0.12f);
    glVertex2f(-0.68f, 0.12f);
glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.67f,0.12f);
glVertex2d(-0.68f,0.12f);
glVertex2d(-0.68f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.66f,0.12f);
glVertex2d(-0.67f,0.12f);
glVertex2d(-0.66f,0.17f);




glEnd();
glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.66,0.12);
glVertex2f(-0.667,0.03);
glVertex2f(-0.673,0.03);
glVertex2f(-0.68,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.664f, 0.07f);
    glVertex2f(-0.676f, 0.07f);
glEnd();
glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.671f, 0.043f);
    glVertex2f(-0.671f, 0.049f);
glEnd();
glPopMatrix();

glPopMatrix();


//.....fish2

glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.3f,0.0f);


glPushMatrix();
glTranslatef(0.0f,-0.3f,0.0f);
glPushMatrix();

glScalef(0.5f,0.5f,0.0f);
glPushMatrix();
glTranslatef(0.0f,-0.1f,0.0f);
glLineWidth(2);
glColor3ub(207,55,34);

    glBegin(GL_LINES);
    glVertex2f(-0.61f, 0.17f);
    glVertex2f(-0.61f, 0.13f);
glEnd();

glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);

glVertex2d(-0.61f,0.12f);
glVertex2d(-0.62f,0.12f);
glVertex2d(-0.62f,0.18f);


glEnd();

glColor3ub(98,119,146);
glBegin(GL_TRIANGLES);

glVertex2d(-0.6f,0.12f);
glVertex2d(-0.61f,0.12f);
glVertex2d(-0.6f,0.173f);

glEnd();


glBegin(GL_QUADS);
glColor3ub(181,194,211);
glVertex2f(-0.6,0.12);
glVertex2f(-0.607,0.03);
glVertex2f(-0.613,0.03);
glVertex2f(-0.62,0.12);
glEnd();

glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.604f, 0.07f);
    glVertex2f(-0.616f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.611f, 0.043f);
    glVertex2f(-0.611f, 0.049f);
glEnd();
glPopMatrix();


glPopMatrix();

glPopMatrix();



//.fish3

glPushMatrix();

glScalef(-0.9f,-0.9f,0.0f);
glPushMatrix();
glTranslatef(0.1,-0.1f,0.f);


glLineWidth(2);

glColor3ub(207,55,34);



    glBegin(GL_LINES);

    glVertex2f(-0.64f, 0.17f);

    glVertex2f(-0.64f, 0.13f);

glEnd();





glColor3ub(98,119,146);



glBegin(GL_TRIANGLES);



glVertex2d(-0.65f,0.18f);

glVertex2d(-0.65f,0.12f);

glVertex2d(-0.64f,0.12f);





glEnd();



glColor3ub(98,119,146);

glBegin(GL_TRIANGLES);



glVertex2d(-0.64f,0.12f);

glVertex2d(-0.63f,0.12f);

glVertex2d(-0.63f,0.17f);







glEnd();

glBegin(GL_QUADS);

glColor3ub(181,194,211);

glVertex2f(-0.65,0.12);

glVertex2f(-0.643,0.03);

glVertex2f(-0.637,0.03);

glVertex2f(-0.63,0.12);

glEnd();



glLineWidth(2);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.635f, 0.07f);
    glVertex2f(-0.645f, 0.07f);
glEnd();


glLineWidth(3);
glColor3ub(98,119,146);

    glBegin(GL_LINES);
    glVertex2f(-0.64f, 0.043f);
    glVertex2f(-0.64f, 0.049f);
glEnd();
glPopMatrix();


glPopMatrix();

glPopMatrix();

glPopMatrix();
glPopMatrix();

glPopMatrix();

	glFlush();

    }

    static void displayThirdScene() {
        // Rendering code for the third scene
       glClear(GL_COLOR_BUFFER_BIT);


    scene.sky();

    scene.sun();
    scene.movingcloud();


    scene.river();
    scene.Boats();
   ;
     scene.scalledship();
     scene.fullBath();

        scene.fullBadh3layer();
        scene.ScaledBoat2();
    glutSwapBuffers();
     glPushMatrix();
    glTranslatef(_boatMoveLeft, 0, 0);  // Translate the left boat's position
    //scene.Boat2();
    glPopMatrix();

     glClearColor(1.0, 1.0, 1.0, 1.0);


    }

    static void displayFourthScene() {
        // Rendering code for the second scene
        glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
    }

    static void switchScene() {
        if (currentScene == SceneType::FIRST) {
            currentScene = SceneType::SECOND;
        } else if (currentScene == SceneType::SECOND) {
            currentScene = SceneType::THIRD;
        } else if (currentScene == SceneType::THIRD) {
            currentScene = SceneType::FOURTH;
        } else if (currentScene == SceneType::FOURTH) {
            currentScene = SceneType::FIRST;
        }
        glutPostRedisplay();
    }
};

GraphicsScene::SceneType GraphicsScene::currentScene = GraphicsScene::SceneType::FIRST;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Multiple Scenes");
    glutPositionWindow(30, 50);

    glutDisplayFunc(GraphicsScene::display);
    glutKeyboardFunc(GraphicsScene::keyboard);
    //glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
