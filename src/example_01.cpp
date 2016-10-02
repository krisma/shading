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

// Optional params
vector<float> ka(3);
vector<float> kd(3);
vector<float> ks(3);
float spu = 1;
float spv = 1;
float sp = 1;
vector<vector<float>> plxyz(5, vector<float>(3));
vector<vector<float>> plrgb(5, vector<float>(3));
vector<vector<float>> dlxyz(5, vector<float>(3));
vector<vector<float>> dlrgb(5, vector<float>(3));
int plCount = 0;
int dlCount = 0;

void triLoad(vector<float>& dest, float r, float g, float b) {
    dest[0] = r;
    dest[1] = g;
    dest[2] = b;
}
void normalizeVec(vector<float>& vec) {
    float l = sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
    vec[0] /= l;
    vec[1] /= l;
    vec[2] /= l;
}
void negateVec(vector<float>& vec) {
    vec[0] = -vec[0];
    vec[1] = -vec[1];
    vec[2] = -vec[2];
}
void addVec(vector<float>& a, vector<float>& b) {
    for (int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
}
void subtractVec(vector<float>& minuend, vector<float>& subtrahend) {
    for (int i = 0; i < minuend.size(); i++) {
        minuend[i] -= subtrahend[i];
    }
}
void scaleVec(vector<float>& multiplier, float multiplicand) {
    for (int i = 0; i < multiplier.size(); i++) {
        multiplier[i] *= multiplicand;
    }
}
vector<float> multiplyVec(vector<float>& multiplier, vector<float>& multiplicand) {
    vector<float> rtn(multiplier.size());
    for (int i = 0; i < multiplier.size(); i++) {
        rtn[i] = multiplier[i] * multiplicand[i];
    }
    return rtn;
}
vector<float> crossProduct(vector<float>& a, vector<float>& b) {
    return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
}
float dotProduct(vector<float>& v1, vector<float>& v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}
void parseArgs(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        switch (str2int(argv[i])) {
            case str2int("-ka"):
                triLoad(ka, strtof(argv[i + 1], nullptr), strtof(argv[i + 2], nullptr), strtof(argv[i + 3], nullptr));
                i += 3;
                break;
            case str2int("-kd"):
                triLoad(kd, strtof(argv[i + 1], nullptr), strtof(argv[i + 2], nullptr), strtof(argv[i + 3], nullptr));
                i += 3;
                break;
            case str2int("-ks"):
                triLoad(ks, strtof(argv[i + 1], nullptr), strtof(argv[i + 2], nullptr), strtof(argv[i + 3], nullptr));
                i += 3;
                break;
            case str2int("-spu"):
                spu = strtof(argv[i + 1], nullptr);
                i += 1;
                break;
            case str2int("-spv"):
                spv = strtof(argv[i + 1], nullptr);
                i += 1;
                break;
            case str2int("-sp"):
                sp = strtof(argv[i + 1], nullptr);
                spu = sp;
                spv = sp;
                break;
            case str2int("-pl"):
                triLoad(plxyz[plCount], strtof(argv[i + 1], nullptr), strtof(argv[i + 2], nullptr), strtof(argv[i + 3], nullptr));
                triLoad(plrgb[plCount], strtof(argv[i + 4], nullptr), strtof(argv[i + 5], nullptr), strtof(argv[i + 6], nullptr));
                plCount++;
                i += 6;
                break;
            case str2int("-dl"):
                triLoad(dlxyz[dlCount], strtof(argv[i + 1], nullptr), strtof(argv[i + 2], nullptr), strtof(argv[i + 3], nullptr));
                triLoad(dlrgb[dlCount], strtof(argv[i + 4], nullptr), strtof(argv[i + 5], nullptr), strtof(argv[i + 6], nullptr));
                dlCount++;
                i += 6;
                break;          
        }
    }
}
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


                vector<float> colorVec {0, 0, 0};
                vector<float> positionVec {x, y, z};
                normalizeVec(positionVec);



                for (int i = 0; i < plCount; i++) {

                    // Deep copy
                    vector<float> plxyzVec(plxyz[i]);
                    subtractVec(plxyzVec, positionVec);
                    normalizeVec(plxyzVec);
                    float dDiff = max(0.0f, dotProduct(plxyzVec, positionVec));

                    // Deep copy
                    vector<float> positionVecCpy(positionVec);
                    scaleVec(positionVecCpy, 2.0 * dotProduct(plxyzVec, positionVec));
                    subtractVec(positionVecCpy, plxyzVec);
                    normalizeVec(positionVecCpy);


                    vector<float> initVec {0, 0, 1};
                    // Deep copy
                    vector<float> plrgbVec(plrgb[i]);
                    vector<float> ambient = multiplyVec(plrgbVec, ka);
                    
                    vector<float> diffuse = multiplyVec(plrgbVec, kd);
                    scaleVec(diffuse, dDiff);

                    if (spu == spv) {
                        float dSpec = pow(max(0.0f, dotProduct(positionVecCpy, initVec)), sp);
                        vector<float> specular = multiplyVec(plrgbVec, ks);
                        scaleVec(specular, dSpec);

                        for (int i = 0; i < colorVec.size(); i++) {
                            colorVec[i] += ambient[i] + diffuse[i] + specular[i];
                            // cout << colorVec[i] << endl;
                        }
                    } else {
                        vector<float> half = {0, 0, 0};
                        addVec(half, plxyzVec);
                        addVec(half, initVec);
                        normalizeVec(half);

                        vector<float> u;
                        vector<float> v {0, 1, 0};
                        
                        vector<float> tempy {0, 1, 0};
                        vector<float> positionVecCpy1(positionVec);
                        scaleVec(positionVecCpy1, dotProduct(positionVec, tempy));
                        subtractVec(v, positionVecCpy1);
                        normalizeVec(v);
                        u = crossProduct(v, positionVec);
                        normalizeVec(u);


                        float fac0 = sqrt((spu + 1) * (spv + 1)) / (8 * PI);
                        float base = dotProduct(positionVec, half);
                        float pwr = spu * (pow(dotProduct(half, u), 2)) + spv * (pow(dotProduct(half, v), 2));
                        pwr /= 1 - pow(dotProduct(half, positionVec), 2);
                        base = pow(base, pwr);
                        base /= dotProduct(half, initVec) * max(dotProduct(positionVec, initVec), dotProduct(positionVec, plxyzVec));
                        base *= fac0;

                        base *= sp + (1 - sp) * pow((1- dotProduct(half, initVec)), 5);

                        vector<float> specular = multiplyVec(plrgbVec, ks);
                        scaleVec(specular, base / 3);
                        
                        for (int i = 0; i < colorVec.size(); i++) {
                            colorVec[i] += ambient[i] + diffuse[i] + specular[i];
                            // cout << colorVec[i] << endl;
                        }

                    }

                }

                for (int i = 0; i < dlCount; i++) {
                    // Deep copy
                    vector<float> dlxyzVec(dlxyz[i]);

                    negateVec(dlxyzVec);
                    normalizeVec(dlxyzVec);
                    float diff = max(0.0f, dotProduct(dlxyzVec, positionVec));

                    // Deep copy
                    vector<float> positionVecCpy(positionVec);
                    scaleVec(positionVecCpy, 2.0 * dotProduct(dlxyzVec, positionVec));
                    subtractVec(positionVecCpy, dlxyzVec);
                    normalizeVec(positionVecCpy);


                    vector<float> initVec {0, 0, 1};
                    // Deep copy
                    vector<float> dlrgbVec(dlrgb[i]);
                    vector<float> ambient = multiplyVec(dlrgbVec, ka);
                    
                    vector<float> diffuse = multiplyVec(dlrgbVec, kd);
                    scaleVec(diffuse, diff);

                    if (spu == spv) {                   
                        vector<float> specular = multiplyVec(dlrgbVec, ks);
                        float dSpec = pow(max(0.0f, dotProduct(positionVecCpy, initVec)), sp);
                        scaleVec(specular, dSpec);

                        for (int i = 0; i < colorVec.size(); i++) {
                            colorVec[i] += ambient[i] + diffuse[i] + specular[i];
                        }
                    } else {
                        vector<float> half = {0, 0, 0};
                        addVec(half, dlxyzVec);
                        addVec(half, initVec);
                        normalizeVec(half);

                        vector<float> u;
                        vector<float> v {0, 1, 0};
                        
                        vector<float> tempy {0, 1, 0};
                        vector<float> positionVecCpy1(positionVec);
                        scaleVec(positionVecCpy1, dotProduct(positionVec, tempy));
                        subtractVec(v, positionVecCpy1);
                        normalizeVec(v);
                        u = crossProduct(v, positionVec);
                        normalizeVec(u);
                        cout << u[0] << endl;cout << u[1] << endl;cout << u[2] << endl;
                        cout << v[0] << endl;cout << v[1] << endl;cout << v[2] << endl;
                        float fac0 = sqrt((spu + 1) * (spv + 1)) / (8 * PI);
                        float base = dotProduct(positionVec, half);
                        float pwr = spu * (pow(dotProduct(half, u), 2)) + spv * (pow(dotProduct(half, v), 2));
                        pwr /= 1 - pow(dotProduct(half, positionVec), 2);
                        base = pow(base, pwr);
                        base /= dotProduct(half, initVec) * max(dotProduct(positionVec, initVec), dotProduct(positionVec, dlxyzVec));
                        base *= fac0;

                        base *= sp + (1 - sp) * pow((1- dotProduct(half, initVec)), 5);

                        vector<float> specular = multiplyVec(dlrgbVec, ks);
                        scaleVec(specular, base / 3);

                        for (int i = 0; i < colorVec.size(); i++) {
                            colorVec[i] += ambient[i] + diffuse[i] + specular[i];
                            // cout << colorVec[i] << endl;
                        }

                    }
                }
                // setPixel(i, j, 1.0, 1.0, 0.0);

                setPixel(i, j, colorVec[0], colorVec[1], colorVec[2]);

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
    
    // Parse args
    parseArgs(argc, argv);




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








