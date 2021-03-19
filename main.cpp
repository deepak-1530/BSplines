#include"bspline.h"

using namespace std;

BSpline::BSpline bspline(0.15);  // bspline object

std::vector<Eigen::Vector3d> controlPoints; 

int splineOrder = 4;


int main()
{
    std::ofstream splineData;

    std::cout<<"BSpline fitting on points in space ..."<<std::endl;

    std::cout<<"Enter the num of control points ";
    std::cin>>bspline.numCtrlPoints;

    splineData.open("dataControlPoints.txt");

    // take the points as input
    for(int i = 0; i<=bspline.numCtrlPoints; i++)
    {
        std::cout<<"Enter the coordinate "<<i<<" ";
        Eigen::Vector3d pt;
        std::cin>>pt(0)>>pt(1)>>pt(2);
        splineData<<pt(0)<<","<<pt(1)<<","<<pt(2)<<std::endl;
        controlPoints.push_back(pt);
    }

    splineData.close();
    
    // set this as the control points
    bspline.setControlPoints(controlPoints);

    // set the order
    bspline.setOrder(splineOrder);

    // now calculate the spline
    bspline.setKnotVector();    // this sets the knot vector

    // set the no. of segments
    bspline.setNumSegments();

    // calculate the bspline points
    bspline.getBSplineTrajectory();

    // print the spline points
    splineData.open("data.txt");

    for(int i = 0; i<bspline.splineSegments.size(); i++)
    {
        std::vector<Eigen::Vector3d> spPts = bspline.splineSegments[i];

        for(int i = 0; i<spPts.size(); i++)
        {
            Eigen::Vector3d point;
            std::cout<<spPts[i].transpose()<<std::endl;
            point = spPts[i];
            splineData<<point(0)<<","<<point(1)<<","<<point(2)<<std::endl;
        }
    }

    // print the knot-vector
    for(int i = 0; i<bspline.knotVector.size(); i++)
    {
        std::cout<<bspline.knotVector[i]<<std::endl;
    }

    splineData.close();

    return 0;
}