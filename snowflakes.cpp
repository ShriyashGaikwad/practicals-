#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <graphics.h>  // For graphics library

using namespace std;

// Structure to represent a point in 2D space
struct Point {
    int x, y;
};

// Function to draw a line on the screen
void drawLine(Point p1, Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to compute the middle point of a line segment
Point middlePoint(Point p1, Point p2) {
    Point middle;
    middle.x = (p1.x + p2.x) / 2;
    middle.y = (p1.y + p2.y) / 2;
    return middle;
}

// Function to compute the point which is a fraction 'f' along the perpendicular bisector of the line
Point perpendicularPoint(Point p1, Point p2, float f) {
    // Find the middle point of the line segment
    Point mid = middlePoint(p1, p2);

    // Find the angle of the line segment with respect to horizontal
    float angle = atan2(p2.y - p1.y, p2.x - p1.x) + M_PI / 3; // 60 degrees

    // Compute the new point based on the angle
    Point newPoint;
    newPoint.x = mid.x + f * (p2.x - p1.x) / 2 - f * (p2.y - p1.y) / 2;
    newPoint.y = mid.y + f * (p2.y - p1.y) / 2 + f * (p2.x - p1.x) / 2;

    return newPoint;
}

// Function to generate the Koch curve on a line segment
void kochCurve(Point p1, Point p2, int depth) {
    if (depth == 0) {
        drawLine(p1, p2);
        return;
    }

    // Calculate the three new points to form the "spike"
    Point m1 = middlePoint(p1, p2); // Midpoint between p1 and p2
    Point m2 = perpendicularPoint(p1, p2, 1.0 / 3.0);
    Point m3 = perpendicularPoint(p1, p2, 2.0 / 3.0);

    // Recursively draw the smaller Koch curves
    kochCurve(p1, m2, depth - 1);
    kochCurve(m2, m1, depth - 1);
    kochCurve(m1, m3, depth - 1);
    kochCurve(m3, p2, depth - 1);
}

// Function to generate a Koch snowflake
void kochSnowflake(Point p1, Point p2, Point p3, int depth) {
    kochCurve(p1, p2, depth);
    kochCurve(p2, p3, depth);
    kochCurve(p3, p1, depth);
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Define the vertices of an equilateral triangle
    Point p1 = {200, 100};
    Point p2 = {400, 100};
    Point p3 = {300, 300};

    int depth = 4; // Set depth of recursion (higher value = more detail)

    // Generate the Koch snowflake
    kochSnowflake(p1, p2, p3, depth);

    // Wait for the user to close the window
    getch();
    closegraph();

    return 0;
}
