#include <iostream>
#include "point.h"
using std::cout;
//не могу скомпилировать, если написать using std::cout, std::endl или в две строки

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
    // Constructors
    Circle(const Point& acenter, float aradius) : mCenter(acenter), mRadius(aradius >= 0 ? aradius : 0) {}
    Circle() : mCenter(Point()), mRadius(1.0) {}
    Circle(const Circle& circle) : mCenter(circle.mCenter), mRadius(circle.mRadius) {}

    // Setters and getters
    const Point& getCenter() const { return mCenter; }
    void setCenter(const Point& center) { mCenter = center; }
    float getRadius() const { return mRadius; }
    void setRadius(float radius) { mRadius = (radius >= 0 ? radius : 0); }

    // Methods
    float getArea() const {
        return 3.14159 * mRadius * mRadius; 
    }

    float getDistance(const Point& p) const {
        return std::abs(mRadius - mCenter.distance(p));
    }

    bool isColliding(const Circle& c) const {
        float distanceBetweenCenters = mCenter.distance(c.getCenter());
        float sumOfRadii = mRadius + c.getRadius();
        return distanceBetweenCenters < sumOfRadii;
    }

    void move(const Point& p) {
        mCenter = mCenter + p;
    }

};

int main()
{
	Point p = { 7, -1 };
	Point q = { -4, 2 };
	cout << "Point p = " << p << std::endl;
	cout << "Point q = " << q << std::endl;
	cout << "p + q = " << p + q << std::endl;

	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << std::endl;
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << std::endl;

	cout << "Area of a = " << a.getArea() << std::endl;
	cout << "Distance from point p to circle a = " << a.getDistance(p) << std::endl;



	cout << "Collisions:" << std::endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << std::endl;
	else
		cout << "No, a isn't colliding b" << std::endl;



	cout << "Moving b by {1, 1}:" << std::endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << std::endl;
	else
		cout << "No, a isn't colliding b" << std::endl;
}
