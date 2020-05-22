//
//  ECMerchandiseFactory.hpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"
#include <vector>
#include <iostream>

// *********************************************************
// List of vendors
typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;

// *********************************************************
// merchandise factory

class ECMerchandiseFactory
{
    public:
        virtual ~ECMerchandiseFactory() {};
        virtual ECTennisShoe* Create_Shoe(int x) = 0;
        virtual ECTennisBallCan* Create_Can() = 0;
        virtual ECTennisBag* Create_Bag() = 0;
};

class Adidas_Factory : public ECMerchandiseFactory
{
    public:
        ECTennisShoe* Create_Shoe(int x)
        {
            return new Adidas_ECTennisShoe(x);
        }
        ECTennisBallCan* Create_Can()
        {
            return new Adidas_ECTennisBallCan();
        }
        ECTennisBag* Create_Bag()
        {
            return new Adidas_ECTennisBag();
        }
};

class Nike_Factory : public ECMerchandiseFactory
{
    public:
        ECTennisShoe* Create_Shoe(int x)
        {
            return new Nike_ECTennisShoe(x);
        }
        ECTennisBallCan* Create_Can()
        {
            return new Nike_ECTennisBallCan();
        }
        ECTennisBag* Create_Bag()
        {
            return new Nike_ECTennisBag();
        }
};

class Head_Factory : public ECMerchandiseFactory
{
    public:
        ECTennisShoe* Create_Shoe(int x)
        {
            return new Head_ECTennisShoe(x);
        }
        ECTennisBallCan* Create_Can()
        {
            return new Head_ECTennisBallCan();
        }
        ECTennisBag* Create_Bag()
        {
            return new Head_ECTennisBag();
        }
};


// *********************************************************
// Merchandise creation: singleton pattern


class ECMerchandiseTennisShop
{
    static ECMerchandiseTennisShop* _instance;

    ECMerchandiseTennisShop()
    {

    };

    public:
        ~ECMerchandiseTennisShop()
        {
            delete factory;
        }
        static ECMerchandiseTennisShop &Instance()
        {
            if(!_instance)
            {
                _instance = new ECMerchandiseTennisShop();
            }
            return (*_instance);
        }
        ECTennisShoe *OrderTennisShoe(int sz)
        {
            ECTennisShoe* temp = (*factory).Create_Shoe(sz);
            shoes.push_back(temp);
            return temp;
        }
        ECTennisBallCan *OrderTennisBallCan()
        {
            ECTennisBallCan* temp = (*factory).Create_Can();
            cans.push_back(temp);
            return temp;
        }
        ECTennisBag *OrderTennisBag()
        {
            ECTennisBag* temp = (*factory).Create_Bag();
            bags.push_back(temp);
            return temp;
        }
        void ChooseVendor(TENNIS_VENDOR vendor)
        {
            ECMerchandiseFactory* temp = factory;
            delete temp;
            if(vendor == TENNIS_NIKE)
            {
                factory = new Nike_Factory();
            }
            else if(vendor == TENNIS_ADIDAS)
            {
                factory = new Adidas_Factory();
            }
            else
            {
                factory = new Head_Factory();
            }  
        }
        int GetNumShoesSold() const
        {
            return shoes.size();
        }
        int GetNumBallcansSold() const
        {
            return cans.size();
        }
        int GetNumBagsSold() const
        {
            return bags.size();
        }
        int GetTotNumBallsSold() const
        {
            int total = 0;
            for(int i = 0; i < cans.size(); i++)
            {
                total = total + (*cans[i]).Get_Balls();
            }
            return total;
        }
        int GetTotRacquetBagCapaictySold() const
        {
            int total = 0;
            for(int i = 0; i < bags.size(); i++)
            {
                total = total + (*bags[i]).Get_Rackets();
            }
            return total;
        }
        int GetTotRevenue() const
        {
            int total = 0;
            for(int i = 0; i < shoes.size(); i++)
            {
                total = total + (*shoes[i]).Get_Price();
            }
            for(int i = 0; i < cans.size(); i++)
            {
                total = total + (*cans[i]).Get_Price();
            }
            for(int i = 0; i < bags.size(); i++)
            {
                total = total + (*bags[i]).Get_Price();
            }
            return total;
        }
        static void DestroyInstance()
        {
            if(_instance != 0)
            {
                delete _instance;
                _instance = 0;
            }
        }
        
    private:
        //Tracking
        std::vector<ECTennisShoe*> shoes;
        std::vector<ECTennisBallCan*> cans;
        std::vector<ECTennisBag*> bags;

        //Current Factory
        ECMerchandiseFactory* factory = new Adidas_Factory();

};

#endif /* ECMerchandiseFactory_hpp */