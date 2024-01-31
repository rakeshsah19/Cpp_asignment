#include <bits/stdc++.h>
// #include <iostream>

struct Point2 {
    float X;
    float Y;
};

struct Line {
    Point2 FirstPoint;
    Point2 SecondPoint;
};

Point2 GetPerpendicularProjection(const Line& lineSample, const Point2& point) {
    const float x1 = lineSample.FirstPoint.X;
    const float y1 = lineSample.FirstPoint.Y;
    const float x2 = lineSample.SecondPoint.X;
    const float y2 = lineSample.SecondPoint.Y;

    const float dx = x2 - x1;
    const float dy = y2 - y1;

    const float dotProduct = ((point.X - x1) * dx + (point.Y - y1) * dy) / (dx * dx + dy * dy);

    return {x1 + dotProduct * dx, y1 + dotProduct * dy};
}

int main() {
    // Example usage
    Line lineSample = {{1.0f, 1.0f}, {4.0f, 4.0f}};
    Point2 pointToProject = {2.0f, 3.0f};

    Point2 projection = GetPerpendicularProjection(lineSample, pointToProject);

    cout << "Perpendicular Projection Point: (" << projection.X << ", " << projection.Y << ")" <<endl;

    return 0;
}
