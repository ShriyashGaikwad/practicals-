#include <iostream>
#include <cmath>

using namespace std;

// Function to draw the Koch curve
void kochCurve(float x1, float y1, float x2, float y2, int depth) {
    if (depth == 0) {
        // Base case: Draw a straight line segment
        cout << "(" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")\n";
    } else {
        // Calculate the points for the Koch curve
        float dx = x2 - x1;
        float dy = y2 - y1;

        // Divide the segment into 3 equal parts
        float x3 = x1 + dx / 3.0;
        float y3 = y1 + dy / 3.0;

        float x4 = x1 + 2 * dx / 3.0;
        float y4 = y1 + 2 * dy / 3.0;

        // Calculate the peak of the triangle (the "bump" in the Koch curve)
        float angle = atan2(dy, dx) - M_PI / 3;
        float x5 = (x3 + x4) / 2.0 + cos(angle) * (sqrt(3) * (sqrt(dx * dx + dy * dy) / 3.0));
        float y5 = (y3 + y4) / 2.0 + sin(angle) * (sqrt(3) * (sqrt(dx * dx + dy * dy) / 3.0));

        // Recursively draw 4 smaller Koch curves
        kochCurve(x1, y1, x3, y3, depth - 1);
        kochCurve(x3, y3, x5, y5, depth - 1);
        kochCurve(x5, y5, x4, y4, depth - 1);
        kochCurve(x4, y4, x2, y2, depth - 1);
    }
}

int main() {
    // Starting points for the Koch curve (an equilateral triangle)
    float x1 = 0.0, y1 = 0.0;
    float x2 = 1.0, y2 = 0.0;
    int depth = 4;  // Set the depth of recursion

    cout << "Generating Koch curve with depth " << depth << "...\n";

    // Draw the Koch curve by calling the recursive function
    kochCurve(x1, y1, x2, y2, depth);
    kochCurve(x2, y2, 0.5, sqrt(3) / 2, depth);
    kochCurve(0.5, sqrt(3) / 2, x1, y1, depth);

    return 0;
}
