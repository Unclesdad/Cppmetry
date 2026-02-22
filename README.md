# Cppmetry

A programming challenge I made for my friend! (And ultimately, ended up taking on myself.)

The challenge itself:

Classes
- these are subjective - if you want to add more methods or more features to make the challenges easier, feel free to do so!

Point
- Constructor(x, y)
- Constructor(Vector)
- Vector displacement(Point)

Vector2D
- Constructor(x, y)
- Constructor(angle, magnitude)
- double magnitude()
- double angle()
- Operator overloads: +, - (vector arithmetic), * (scalar multiplication)
- double dot(Vector2D)
- double cross(Vector2D) - returns scalar magnitude

LineSegment (or just Line, if you want)
- Constructor(Point, Point)
- Constructor(Point, Vector)
- bool intersects(LineSegment)
- Vector toVector() - from point1 to point2

from here on, implementation is up to you! I won’t give initial hints:

Shape (interface)
Circle implements Shape
Polygon implements Shape
Triangle extends Polygon

Challenges - they’re ranked based on how difficult i find them on first glance, but it may not be the same for you! It’s possible you think of a way that I didn’t think of.

1. (Easy) Check if a line segment intersects a Shape’s perimeter
2. (Easy) Check if a Polygon is convex
3. (Easy) Calculate the area of a convex Polygon
4. (Easy) Rotate a Shape around a given Point
5. (Medium) Check if a line segment is fully contained within a Shape’s area
6. (Medium) Check if a Shape is fully contained, partially overlapping, or fully outside another Shape - return result as an enum
7. (Hard) Find the circumcircle of a Shape
8. (Hard) Calculate the area of any Shape
9. (Harder) Find the largest incircle of a Shape - must be fully interior and only tangent to edges.
10. (Extreme) Extend everything to 3D: all prior tasks apply, and area generalizes to volume​​​​​​​​​​​​​​​​