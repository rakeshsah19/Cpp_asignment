#include <bits/stdc++.h>
struct Point2 {
    float X;
    float Y;
};

struct Line {
    Point2 FirstPoint;
    Point2 SecondPoint;
};

Point2 GetIntersection(Line FirstLine, Line SecondLine) {
    Point2 intersection;

    float x1 = FirstLine.FirstPoint.X;
    float y1 = FirstLine.FirstPoint.Y;
    float x2 = FirstLine.SecondPoint.X;
    float y2 = FirstLine.SecondPoint.Y;

    float x3 = SecondLine.FirstPoint.X;
    float y3 = SecondLine.FirstPoint.Y;
    float x4 = SecondLine.SecondPoint.X;
    float y4 = SecondLine.SecondPoint.Y;

    float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    // Check if lines are parallel
    if (denominator == 0) {
        std::cout << "Lines are parallel. No intersection point." <<endl;
        intersection.X = intersection.Y = std::numeric_limits<float>::quiet_NaN();
        return intersection;
    }

    intersection.X = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
    intersection.Y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;

    return intersection;
}

int main() {
    // Example usage
    Line line1 = {{1.0f, 1.0f}, {4.0f, 4.0f}};
    Line line2 = {{1.0f, 4.0f}, {4.0f, 1.0f}};

    Point2 intersection = GetIntersection(line1, line2);

   std::cout << "Intersection Point: (" << intersection.X << ", " << intersection.Y << ")" <<endl;

    return 0;
}
