#ifndef stars_hpp
#define stars_hpp

#include <GL/glut.h>

class Star {
public:
    // Radius of the star.
    GLfloat m_radius;

    // Revolution speed.

    
    GLfloat m_revolutionSpd;

    // Rotation speed.
    GLfloat m_rotationSpd;

    // Distance from the center of the sun.
    GLfloat m_distance;

    // Star color.
    GLfloat m_rgbaColor[4];

    // Father Star.
    Star* m_parentStar;

protected:
    GLfloat alphaSelf, alpha;

public:
    // Inilization.
    Star(GLfloat radius, GLfloat revolutionSpd, GLfloat rotationSpd, GLfloat distance, Star* parentStar);

    // Draw the regular stars.
    void drawStar();

    // Call drawStar();
    virtual void draw() {
        drawStar();
    }

    // Update the stars, input of the function is the time range between two updates.
    virtual void update(long timespan);
};

class Planet : public Star {
public:
    Planet(GLfloat radius, GLfloat revolutionSpd, 
    GLfloat rotationSpd, GLfloat distance, GLfloat rgbColor[3], Star* parentStar);

    void drawPlanet();

    virtual void draw() {
        drawPlanet();
        drawStar();
    }
};

class OurSun : public Planet {
public:
    OurSun(GLfloat radius, GLfloat revolutionSpd, 
    GLfloat rotationSpd, GLfloat distance, GLfloat rgbColor[3], Star* parentStar);

    // Sun has light.
    void drawLight();

    virtual void draw() {
        drawLight();
        drawPlanet();
        drawStar();
    }
};

#endif