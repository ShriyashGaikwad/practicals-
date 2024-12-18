#include <GL/glut.h>

// Sun position and color
float sunY = -0.8f; // Starting position of the sun (below horizon)
float red = 1.0f, green = 0.5f, blue = 0.0f; // Initial sun color (orange)

// Function to draw the sun
void drawSun() {
    glColor3f(red, green, blue); // Set sun color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, sunY); // Center of the sun
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f; // Convert degrees to radians
        glVertex2f(0.1f * cos(angle), sunY + 0.1f * sin(angle)); // Sun radius = 0.1
    }
    glEnd();
}

// Function to draw the ground
void drawGround() {
    glColor3f(0.0f, 0.5f, 0.0f); // Green ground
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();
}

// Function to draw the sky
void drawSky() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue for the top
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.5f, 0.7f, 1.0f); // Light blue for the bottom
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();    // Draw the sky
    drawGround(); // Draw the ground
    drawSun();    // Draw the sun

    glutSwapBuffers();
}

// Idle function to animate the sun
void update(int value) {
    sunY += 0.005f; // Move the sun upward
    if (sunY > 1.0f) sunY = -1.0f; // Reset position for continuous animation

    // Change sun color based on its position
    if (sunY < 0.0f) {
        red = 1.0f;
        green = 0.5f + 0.5f * (sunY + 0.8f); // Transition to orange
        blue = 0.0f;
    } else {
        red = 1.0f;
        green = 1.0f - 0.5f * sunY; // Transition to yellow
        blue = 0.2f * sunY; // Transition to light blue
    }

    glutPostRedisplay();                  // Redraw the scene
    glutTimerFunc(25, update, 0);         // Schedule the next update
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // Set 2D orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sunrise and Sunset");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Start the animation
    glutMainLoop();
    return 0;
}
