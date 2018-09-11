#include <math.h>
#include <limits>
#include <random>
#include "elapsedtime.h"
#include <iostream>
#include <algorithm>

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

double SplitClosestPair(Point *strip, int n, double d, Point *pairs)
{

	double min = d;  // Initialize the minimum distance as d 

	// sort according ti y coordinate
	std::sort(strip, strip + n, [](Point point1, Point point2) { return point1.y < point2.y; });

	// Pick all points one by one and try the next points till the difference 
	// between y coordinates is smaller than d. 
	// This is a proven fact that this loop runs at most 6 times 
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; ++j)
			if (distance(strip[i], strip[j]) < min)
			{
				min = distance(strip[i], strip[j]);
				pairs[0] = strip[i];
				pairs[1] = strip[j];
			}

	return min;
}


//algorithm for closest pair 
double ClosestPair(Point *points, int n, Point *pairs)
{

    // call base closest pair method
	if(n <= 3)
	{
		double d = baseClosestPair(points, n, pairs);
        return d;
	}
		
    // devide the points and find closes pairs	
	int mid = n / 2;
	Point midPoint = points[mid];
	
	Point lClosestPairs[2];
	double dl = ClosestPair(points, mid, lClosestPairs); 
	
	double d = dl;
	
	Point rClosestPairs[2];
	double dr = ClosestPair(points+mid, n-mid, rClosestPairs);
	
	if(dl < dr)
	{
		pairs[0] = lClosestPairs[0];
		pairs[1] = lClosestPairs[1];
	}
	else
	{
		d = dr;
		pairs[0] = rClosestPairs[0];
		pairs[1] = rClosestPairs[1];
	}

	// strip of points which fall between minmum distance
	// time compexity of O(n)
	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (std::abs(points[i].x - midPoint.x) < d)
			strip[j] = points[i], j++;
	}

	//split closest pair
	return std::min(d, SplitClosestPair(strip, j, d, pairs));
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
	std::cout << "Divide and conquer algorithm :" << std::endl;

    begintime(begin_time);
	//sort the point with x coordinates 
	std::sort(pt, pt + N, [](Point point1, Point point2) {return point1.x < point2.x; });// time complexity O(NlogN)
    double d = ClosestPair(pt, N, closestPair);
    elapsedtimeFile(timefile, begin_time);
	
    std::cout << "closest distance :" << d << std::endl;
    std::cout << "closest pair : {";
    for (int i = 0; i < 2; i++)
        std::cout << "{ " << closestPair[i].x << " , " << closestPair[i].y << " }";
    std::cout << " }" << std::endl;
    
    // brute force algorithm
	std::cout << "Brute force algorithm :" << std::endl;

    begintime(begin_time);
    d = baseClosestPair(pt, N, closestPair); // time complexity O(N^2)
    elapsedtimeFile(timefile, begin_time);

    std::cout << "closest distance :" << d << std::endl;
    std::cout << "closest pair : {";
    for (int i = 0; i < 2; i++)
        std::cout << "{ " << closestPair[i].x << " , " << closestPair[i].y << " }";
    std::cout << " }";
    std::getchar();

    return 0;
}