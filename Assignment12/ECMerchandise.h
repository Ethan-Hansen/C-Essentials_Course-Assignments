//
//  ECMerchandise.h
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandise_hpp
#define ECMerchandise_hpp

#include <string>

// your code goes here

class ECTennisShoe
{
    public: 
        virtual ~ECTennisShoe() {};
        virtual int Get_Brand() = 0;
        virtual int Get_Price() = 0;
        virtual int Get_Size() = 0;
};

class Adidas_ECTennisShoe : public ECTennisShoe
{
    public:
        Adidas_ECTennisShoe(int x) : size(x) {}
        ~Adidas_ECTennisShoe() {}; 
        int Get_Brand() {return 1;};
        int Get_Price() {return 20;};
        int Get_Size() {return size;};
    private:
        int size;
};

class Nike_ECTennisShoe : public ECTennisShoe
{
    public:
        Nike_ECTennisShoe(int x) : size(x) {} 
        ~Nike_ECTennisShoe() {};
        int Get_Brand() {return 2;};
        int Get_Price() {return 15;};
        int Get_Size() {return size;};
    private:
        int size;
};

class Head_ECTennisShoe : public ECTennisShoe
{
    public:
        Head_ECTennisShoe(int x) : size(x) {}
        ~Head_ECTennisShoe() {};
        int Get_Brand() {return 3;};
        int Get_Price() {return 10;};
        int Get_Size() {return size;};
    private:
        int size;
};

class ECTennisBallCan
{
    public:
        virtual ~ECTennisBallCan() {};
        virtual int Get_Brand() = 0;
        virtual int Get_Price() = 0;
        virtual int Get_Balls() = 0;
};

class Adidas_ECTennisBallCan : public ECTennisBallCan
{
    public: 
        ~Adidas_ECTennisBallCan() {};
        int Get_Brand() {return 1;};
        int Get_Price() {return 5;};
        int Get_Balls() {return 3;};
};

class Nike_ECTennisBallCan : public ECTennisBallCan
{
    public:
        ~Nike_ECTennisBallCan() {}; 
        int Get_Brand() {return 2;};
        int Get_Price() {return 6;};
        int Get_Balls() {return 4;};
};

class Head_ECTennisBallCan : public ECTennisBallCan
{
    public: 
        ~Head_ECTennisBallCan() {};
        int Get_Brand() {return 3;};
        int Get_Price() {return 4;};
        int Get_Balls() {return 3;};
};

class ECTennisBag
{
    public:
        virtual ~ECTennisBag() {};
        virtual int Get_Brand() = 0;
        virtual int Get_Price() = 0;
        virtual int Get_Rackets() = 0;
};

class Adidas_ECTennisBag : public ECTennisBag
{
    public:
        ~Adidas_ECTennisBag() {};
        int Get_Brand() {return 1;};
        int Get_Price() {return 18;};
        int Get_Rackets() {return 6;};
};

class Nike_ECTennisBag : public ECTennisBag
{
    public:
        ~Nike_ECTennisBag() {};
        int Get_Brand() {return 2;};
        int Get_Price() {return 12;};
        int Get_Rackets() {return 4;};
};

class Head_ECTennisBag : public ECTennisBag
{
    public:
        ~Head_ECTennisBag() {};
        int Get_Brand() {return 3;};
        int Get_Price() {return 10;};
        int Get_Rackets() {return 3;};
};
#endif /* ECMerchandise_hpp */
