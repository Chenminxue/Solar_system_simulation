#include <GL/glut.h>
#include "stars.hpp"

#define STARS_NUM 10

class SolarSystem {
public:

    SolarSystem();
    ~SolarSystem();

    void onDisplay();
    void onUpdate();
    void onKeyboard(unsigned char key, int x, int y);

private:
    Star* stars[STARS_NUM];

    // Viewing parameters.
    GLdouble viewX, viewY, viewZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;
};