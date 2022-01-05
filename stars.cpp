#include "header/stars.hpp"
#include <cmath>

#define PI 3.14159265354

Star::Star(GLfloat radius, GLfloat revolutionSpd, GLfloat rotationSpd, GLfloat distance, Star* parentStar) {
    m_radius = radius;
    m_revolutionSpd = revolutionSpd;
    m_rotationSpd = this->alpha = 0;
    m_distance = distance;

    for (int i = 0; i < 4; i++)
        m_rgbaColor[i] = 1.0f;

    m_parentStar = parentStar;
    if (rotationSpd > 0)
        m_rotationSpd = 360.0f / rotationSpd;
    else
        m_rotationSpd = 0.0f;
}

void Star::drawStar() {

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);

    int n = 1440;

    glPushMatrix();
    {
        if (m_parentStar != 0 && m_parentStar->m_distance > 0) {
            glRotatef(m_parentStar->alpha, 0, 0, 1);
            glTranslatef(m_parentStar->m_distance, 0.0, 0.0);
        }
        glBegin(GL_LINES);
        for(int i=0; i<n; ++i)
            glVertex2f(m_distance * cos(2 * PI * i / n),
                       m_distance * sin(2 * PI * i / n));
        glEnd();
        glRotatef(alpha, 0, 0, 1);
        glTranslatef(m_distance, 0.0, 0.0);

        glRotatef(alphaSelf, 0, 0, 1);

        glColor3f(m_rgbaColor[0], m_rgbaColor[1], m_rgbaColor[2]);
        glutSolidSphere(m_radius, 40, 32);
    }
    glPopMatrix();

}

void Star::drawPlanet() {
    GLfloat mat_ambient[]  = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_diffuse[]  = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat mat_emission[] = {m_rgbaColor[0], m_rgbaColor[1], m_rgbaColor[2], m_rgbaColor[3]};
    GLfloat mat_shininess  = 90.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION,  mat_emission);
    glMaterialf (GL_FRONT, GL_SHININESS, mat_shininess);
}

void Star::drawLight() {
    GLfloat light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void Star::update(long timespan) {
    alpha += timespan * m_revolutionSpd;
    alphaSelf += m_rotationSpd;
}

Planet::Planet(GLfloat radius, GLfloat revolutionSpd, 
    GLfloat rotationSpd, GLfloat distance, GLfloat rgbColor[3], Star* parentStar) : 
    Star(radius, revolutionSpd, rotationSpd, distance, parentStar) {
 
    m_rgbaColor[0] = rgbColor[0];
    m_rgbaColor[1] = rgbColor[1];
    m_rgbaColor[2] = rgbColor[2];
    m_rgbaColor[3] = 1.0f;
    }

OurSun::OurSun(GLfloat radius, GLfloat revolutionSpd, 
    GLfloat rotationSpd, GLfloat distance, GLfloat rgbColor[3], Star* parentStar) : 
    Star(radius, revolutionSpd, rotationSpd, distance ,parentStar) {
        ;
    }