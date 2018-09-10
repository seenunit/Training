#include <math.h>
#include <limits>
#include <random>
#include "elapsedtime.h"
#include <iostream>

struct Point
{
	double x;
	double y;
};


double distance(Point point1, Point point2)
{	
	double dx = point1.x - point2.x;
	double dy = point1.y - point2.y;
	return sqrt((dx * dx) + (dy * dy));
}

double baseClosestPair(const Point *points, int n, Point *pairs)
{
    double min = std::numeric_limits<double>::max();
	for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if (distance(points[i], points[j]) < min)
            {
                pairs[0] = points[i];
                pairs[1] = points[j];
                min = distance(points[i], points[j]);
            }

    return min;
}


//algorithm for closest pair 
double ClosestPair(Point *points, int n, point &pairs)
{

    // call base closest pair method
	if(n <= 3)
	{
		double d = baseClosestPair(points, n, pairs);
        return d;
	}

    // devide the points

	
	
}

int main()
{

    // intialize random device
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 50.0);

    int N = 10000;

    Point *pt = new Point[N]{};

    //Randomized points
    for (int i = 0; i < N; ++i)
    {
        pt[i].x = dist(mt);
        pt[i].y = dist(mt);
        std::cout << "{ " << pt[i].x << " ," << pt[i].y << " } " << std::endl;
    }

    std::ofstream timefile;
    clock_t begin_time = clock();

    Point closestPair[2];

    // divide and conqure algorithm
    begintime(begin_time);
    double d = ClosestPair(pt, N, closestPair);
    elapsedtimeFile(timefile, begin_time);

    std::cout << "closest distance :" << d << std::endl;
    std::cout << "closest pair : {";
    for (int i = 0; i < 2; i++)
        std::cout << "{ " << closestPair[i].x << " , " << closestPair[i].y << " }";
    std::cout << " }";
    
    // brute force algorithm
    begintime(begin_time);
    d = baseClosestPair(pt, N, closestPair);
    elapsedtimeFile(timefile, begin_time);

    std::cout << "closest distance :" << d << std::endl;
    std::cout << "closest pair : {";
    for (int i = 0; i < 2; i++)
        std::cout << "{ " << closestPair[i].x << " , " << closestPair[i].y << " }";
    std::cout << " }";
    std::getchar();

    return 0;
}