#ifndef EC_2D_SHAPE_H
#define EC_2D_SHAPE_H

// Abstract class for shape
class EC2DShape
{
public:
    // Get bounding box (i.e. smallest rectangle contaiing the shape with sides parellel to axes) of the shape
    // the left-upper corner of the window is (0,0)
    virtual void GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const = 0;
    
    // is the shape intersecting with point (px, py)
    virtual bool IsIntersect(int px, int py) const = 0;
    
    // is the shape intersecting with another shape?
    // Assume: only consider bounding box; if two bounding boxes intersect, they intersect
    virtual bool IsIntersectShape(const EC2DShape &rhs) const;
    
    // is one shape containing another?
    virtual bool IsContaining(const EC2DShape &rhs) const;
};

// Recentangle
class ECRectangle : public EC2DShape
{
public:
    // (xUL,yUL): the upper left corner, (xLR,yLR): the lower right corner
    ECRectangle(int xUL, int yUL, int xLR, int yLR);
    ~ECRectangle();

    void GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const;
    bool IsIntersect(int px, int py) const; 

private:
    int x1, y1, x2, y2;
    
};

// circle
class ECCircle : public EC2DShape
{
public:
    // (x,y): the center of circle, (xLR,yLR): the lower right corner
    ECCircle(int x, int y, int radius);
    ~ECCircle();
    
    void GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const;
    bool IsIntersect(int px, int py) const; 

    // your code continues here
private:
    int cx, cy, rad;
    int BBux, BBuy, BBlx, BBly;
};

#endif
