#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

//include header file for glfw library so that we can use OpenGL
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef _WIN32
static DWORD lastTime;
#else
static struct timeval lastTime;
#endif

#define PI 3.14159265 // Should be used from mathlib

using namespace std;

//****************************************************
// Global Variables
//****************************************************
GLfloat translation[3] = {0.0f, 0.0f, 0.0f};
bool auto_strech = false;
int Width_global = 400;
int Height_global = 400;

inline float sqr(float x) { return x*x; }


//****************************************************
// Simple init function
//****************************************************
void initializeRendering()
{
    glfwInit();
}


//****************************************************
// A routine to set a pixel by drawing a GL point.  This is not a
// general purpose routine as it assumes a lot of stuff specific to
// this example.
//****************************************************
void setPixel(float x, float y, GLfloat r, GLfloat g, GLfloat b) {
    glColor3f(r, g, b);
    glVertex2f(x+0.5, y+0.5);  // The 0.5 is to target pixel centers
    // Note: Need to check for gap bug on inst machines.
}

//****************************************************
// Keyboard inputs
//****************************************************
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch (key) {
            
        case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        case GLFW_KEY_Q: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        case GLFW_KEY_LEFT :
            if (action) translation[0] -= 0.01f * Width_global; break;
        case GLFW_KEY_RIGHT:
            if (action) translation[0] += 0.01f * Width_global; break;
        case GLFW_KEY_UP   :
            if (action) translation[1] += 0.01f * Height_global; break;
        case GLFW_KEY_DOWN :
            if (action) translation[1] -= 0.01f * Height_global; break;
        case GLFW_KEY_F:
            if (action) auto_strech = !auto_strech; break;
        case GLFW_KEY_SPACE: break;
            
        default: break;
    }
    
}

//****************************************************
// Draw a filled circle.
//****************************************************
void drawCircle(float centerX, float centerY, float radius) {
    // Draw inner circle
    glBegin(GL_POINTS);

    // We could eliminate wasted work by only looping over the pixels
    // inside the sphere's radius.  But the example is more clear this
    // way.  In general drawing an object by loopig over the whole
    // screen is wasteful.

    int minI = max(0,(int)floor(centerX-radius));
    int maxI = min(Width_global-1,(int)ceil(centerX+radius));

    int minJ = max(0,(int)floor(centerY-radius));
    int maxJ = min(Height_global-1,(int)ceil(centerY+radius));

    for (int i = 0; i < Width_global; i++) {
        for (int j = 0; j < Height_global; j++) {

            // Location of the center of pixel relative to center of sphere
            float x = (i+0.5-centerX);
            float y = (j+0.5-centerY);

            float dist = sqrt(sqr(x) + sqr(y));

            if (dist <= radius) {

                // This is the front-facing Z coordinate
                float z = sqrt(radius*radius-dist*dist);

                setPixel(i, j, 1.0, 0.0, 0.0);

                // This is amusing, but it assumes negative color values are treated reasonably.
                // setPixel(i,j, x/radius, y/radius, z/radius );
                
                // Just for fun, an example of making the boundary pixels yellow.
                // if (dist > (radius-1.0)) {
                //     setPixel(i, j, 1.0, 1.0, 0.0);
                // }
            }
        }
    }

    glEnd();
}

//****************************************************
// function that does the actual drawing of stuff
//***************************************************
void display( GLFWwindow* window )
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); //clear background screen to black
    
    glClear(GL_COLOR_BUFFER_BIT);                // clear the color buffer (sets everything to black)
    
    glMatrixMode(GL_MODELVIEW);                  // indicate we are specifying camera transformations
    glLoadIdentity();                            // make sure transformation is "zero'd"
    
    //----------------------- code to draw objects --------------------------
    glPushMatrix();
    glTranslatef (translation[0], translation[1], translation[2]);
    drawCircle(Width_global / 2.0 , Height_global / 2.0 , min(Width_global, Height_global) * 0.8 / 2.0);
    glPopMatrix();
    
    glfwSwapBuffers(window);
    
}

//****************************************************
// function that is called when window is resized
//***************************************************
void size_callback(GLFWwindow* window, int width, int height)
{
    // Get the pixel coordinate of the window
    // it returns the size, in pixels, of the framebuffer of the specified window
    glfwGetFramebufferSize(window, &Width_global, &Height_global);
    
    glViewport(0, 0, Width_global, Height_global);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Width_global, 0, Height_global, 1, -1);
    
    display(window);
}


//****************************************************
// the usual stuff, nothing exciting here
//****************************************************
int main(int argc, char *argv[]) {
    //This initializes glfw
    initializeRendering();
    
    GLFWwindow* window = glfwCreateWindow( Width_global, Height_global, "CS184", NULL, NULL );
    if ( !window )
    {
        cerr << "Error on window creating" << endl;
        glfwTerminate();
        return -1;
    }
    
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    if ( !mode )
    {
        cerr << "Error on getting monitor" << endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent( window );
    
    // Get the pixel coordinate of the window
    // it returns the size, in pixels, of the framebuffer of the specified window
    glfwGetFramebufferSize(window, &Width_global, &Height_global);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Width_global, 0, Height_global, 1, -1);
    
    glfwSetWindowTitle(window, "CS184");
    glfwSetWindowSizeCallback(window, size_callback);
    glfwSetKeyCallback(window, key_callback);
    
    while( !glfwWindowShouldClose( window ) ) // infinite loop to draw object again and again
    {   // because once object is draw then window is terminated
        display( window );
        
        if (auto_strech){
            glfwSetWindowSize(window, mode->width, mode->height);
            glfwSetWindowPos(window, 0, 0);
        }
        
        glfwPollEvents();
        
    }

    return 0;
}








