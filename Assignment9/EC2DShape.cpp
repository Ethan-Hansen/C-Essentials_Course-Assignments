#include "EC2DShape.h"
#include <iostream>

bool EC2DShape :: IsIntersectShape(const EC2DShape &rhs) const
{
    if((*this).IsContaining(rhs) || rhs.IsContaining(*this))
    {
        return true;
    }
    int x1, x2, y1, y2;
    int rx1, ry1, rx2, ry2;
    (*this).GetBoundingBox(x1, y1, x2, y2);
    rhs.GetBoundingBox(rx1, ry2, rx2, ry2);
    int count = 0;
    if(rhs.IsIntersect(x1, y1))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x1, y2))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x2, y1))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x2, y2))
    {
        count = count + 1;
    }
    if((*this).IsIntersect(rx1, ry1))
    {
        count = count + 1;
    }
    if((*this).IsIntersect(rx1, ry2))
    {
        count = count + 1;
    }
    if((*this).IsIntersect(rx2, ry1))
    {
        count = count + 1;
    }
    if((*this).IsIntersect(rx2, ry2))
    {
        count = count + 1;
    }
    if(count > 0)
    {
        return true;
    }
    std::cout << count << std::endl;
    return false;
    
    
}

bool EC2DShape :: IsContaining(const EC2DShape &rhs) const
{
    int x1, x2, y1, y2;
    (*this).GetBoundingBox(x1, y1, x2, y2);
    int count = 0;
    if(x1 == x2 || y1 == y2)
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x1, y1))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x1, y2))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x2, y1))
    {
        count = count + 1;
    }
    if(rhs.IsIntersect(x2, y2))
    {
        count = count + 1;
    }
    if(count == 4)
    {
        return true;
    }
    return false;
    
}


//RECTANGLE METHODS
ECRectangle :: ECRectangle(int xUL, int yUL, int xLR, int yLR)
{
    x1 = xUL;
    y1 = yUL;
    x2 = xLR;
    y2 = yLR;
    
}

ECRectangle :: ~ECRectangle()
{

}

void ECRectangle :: GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const
{
    xUpperLeft = x1;
    yUpperLeft = y1;
    xLowerRight = x2;
    yLowerRight = y2;
}

bool ECRectangle :: IsIntersect(int px, int py) const
{
    if(px >= x1 && px <= x2)
    {
        if(py >= y1 && py <= y2)
        {
            return true;
        }
    }
    return false;
}

//CIRCLE METHODS
ECCircle :: ECCircle(int x, int y, int radius)
{
    cx = x;
    cy = y;
    rad = radius;
}

ECCircle :: ~ECCircle()
{

}

void ECCircle :: GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const
{
    xUpperLeft = cx - rad;
    yUpperLeft = cy + rad;

    xLowerRight = cx + rad;
    yLowerRight = cy + rad;
}

bool ECCircle :: IsIntersect(int px, int py) const
{
    if(px >= (cx - rad) &&  px <= (cx + rad))
    {
        if(py <= (cy + rad) && px >= (cy - rad))
        {
            return true;
        }
    }
    return false;
}