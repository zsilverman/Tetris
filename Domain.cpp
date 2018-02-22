//	Zack Silverman 913618592
//
//  Domain.cpp
//  RandomRectangles
//
//  Implementation of the Domain class
//

#include <stdio.h>
#include <iostream>
#include "Domain.h"
#include "Shape.h"
using namespace std;

//ctor for Domain using initializer list
Domain::Domain(int sx, int sy) : size_x(sx),size_y(sy){}

//adds shape if fits in domain and doesn't overlap with any other Shapes on the board
void Domain::addShape(char type, int x, int y){
    
    Shape *t1;
    t1=Shape::makeShape(type,x,y);
    
    if((Domain::fits(*t1))==true) {
        
        //if list is emtpy, adds shape to sList
        if(sList.size()==0){
            sList.push_back(t1);
        }
        else {
            //checks entire sList for overlap, if not adds to board
            for(int i=0; i < (int)sList.size();i++) {
                if(t1->overlap(*sList[i]) == true)
                    return;
            }
            sList.push_back(t1);
        }
    }
    
    else{
        delete t1; //delete instance of shape if it doesn't meet criteria
        return;
    }
}

//return true if shape fits in domain
bool Domain::fits(const Shape &s) const{

    for(int i=0; i < s.size();i++) {
        if((s.getX(i) >= 0) && (s.getX(i) < size_x) &&(s.getY(i)>=0) && (s.getY(i) < size_y))
            continue;
        else
            return false;
    }
    return true;
}
    
void Domain::draw(void) const{
    
    //prints svg file header
    
    cout << "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>" << endl
    << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl
    << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl
    << "<svg width=\"670\" height=\"670\" viewBox=\"0 0 650 650\"" << endl
    << "xmlns=\"http://www.w3.org/2000/svg\"" << endl
    << "xmlns:xlink=\"http://www.w3.org/1999/xlink\" >" << endl
    << "<g transform=\"matrix(1,0,0,-1,50,650)\">" <<endl
    << "<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\""
    << (size_x * 40) <<"\" height=\"" << (size_y * 40) << "\"/>" << endl;

    //calls draw function for each shape
    for(int i=0; i < (int)sList.size();i++){
        sList[i]->draw();
    }
    
    //prints svg footer
    cout<<"</g>"<<endl
    <<"</svg>" <<endl;
    
}

//return false if board isn't filled
bool Domain::full(void) const{
    
    int sum=0;
    for (int i=0;i < (int)sList.size();i++){
        sum+= (sList[i]->size());
    }
    if(sum >=(size_x*size_y))
       return true;
    else
       return false;
}
