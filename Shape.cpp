//	Zack Silverman 913618592
//
//  Shape.cpp
//  ShapeEditor
//
//  Implementation of the Shape class
//

#include <stdio.h>
#include <iostream>
#include "Shape.h"
#include <cstring>
#include<stdexcept>
using namespace std;

//prints the indices of the Shape with the format (x,y)
void Shape::print(void) const{
    for (int i=0; i < this->size();i++) {
        if(i==0)
            cout << this->name()<< " at";
        cout << " (" << *(x+i) << "," << *(y+i) << ")";
        if(i==this->size())
            cout<< endl;
    }
    cout<< '\n';
}

//moves the shape by (dx,dy)
void Shape::move (int dx, int dy){
    for (int i=0; i < this->size(); i++) {
        *(x+i) = x[i] + dx;
        *(y+i) = y[i] + dy;
    }
}

//returns true if two shapes overlap
//moves through the array and checks if coordinates of Shape t overlap with current shape instance
bool Shape::overlap(const Shape &t) const{
    
    for (int i=0; i < t.size();i++) {
        for(int j=0; j < this->size();j++) {
            if (t.x[i] == this->x[j] && t.y[i] == this->y[j])
                return true;
        }
    }
    return false;
}

//constructor creates new object of Shape type ch
Shape* Shape:: makeShape(char ch,int posx,int posy){
    
    if (ch == 'O') {
        Shape *shape = new O(posx,posy);
        return shape;
    }
    else if (ch == 'I'){
        Shape *shape = new I(posx,posy);
        return shape;
    }
    else if (ch == 'L'){
        Shape *shape = new L(posx,posy);
        return shape;
    }
    else if (ch == 'S'){
        Shape *shape = new S(posx,posy);
        return shape;
    }
    else if (ch == 'X'){
        Shape *shape = new X(posx,posy);
        return shape;
    }
    else if (ch == 'U'){
        Shape *shape = new U(posx,posy);
        return shape;
    }
    else
        throw invalid_argument("invalid type"); //checks for invalid shape character
}

//virtual deconstuctor frees arrays x & y
Shape::~Shape(void){
    delete x;
    delete y;
}

//returns x coordinate of cell i of the shape
int Shape::getX(int i) const{
    int temp;
    temp = this->x[i];
    return temp;
}

//returns y coordinate of cell i of the shape
int Shape::getY(int i) const{
    return this->y[i];
}

//prints each shape, called through Domain.cpp
void Shape::draw(void) const{

    const unsigned WIDTH = 40;
    const unsigned HEIGHT = 40;

    char DrawColor[] = "";
    strcpy(DrawColor,this->color()); //calls color function of each shape
    
    for(int i=0;i<this->size();i++)
    cout<< "<rect fill=\""<<DrawColor<<"\""<<" stroke=\"black\""<<" x=\""<<this->getX(i)*40<<"\" y=\""
        <<this->getY(i)*40<<"\" width=\""<<WIDTH<<"\" height=\""<<HEIGHT<<"\"/>"<<endl;
}

//ctor for the O shape
O::O (int posx, int posy){
    x = new int [1];
    y = new int [1];
    *x = posx;
    *y = posy;
}
char O:: name(void) const{
    return 'O';
}
int O:: size(void) const{
    return 1;
}
//returns color of O shape
const char* O::color(void) const{
    return "cyan";
}

//ctor for the I shape
I::I (int posx, int posy){
    x = new int [2];
    y = new int [2];
    *x = posx;
    *y = posy;
    *(x+1) = posx;
    *(y+1) = posy+1;
}
char I:: name(void) const{
    return 'I';
}
int I:: size(void) const{
    return 2;
}
const char* I::color(void) const{
    return "yellow";
}

//ctor for the L shape
L::L (int posx, int posy){
    x = new int [3];
    y = new int [3];
    *x = posx;
    *y = posy;
    *(x+1) = posx+1;
    *(y+1) = posy;
    *(x+2) = posx;
    *(y+2) = posy+1;
}
char L:: name(void) const{
    return 'L';
}
int L:: size(void) const{
    return 3;
}
const char* L::color(void) const{
    return "purple";
}

//ctor for the S shape
S::S (int posx, int posy){
    x = new int [4];
    y = new int [4];
    *x = posx;
    *y = posy;
    *(x+1) = posx+1;
    *(y+1) = posy;
    *(x+2) = posx+1;
    *(y+2) = posy+1;
    *(x+3) = posx+2;
    *(y+3) = posy+1;
}
char S:: name(void) const{
    return 'S';
}
int S:: size(void) const{
    return 4;
}
const char* S::color(void) const{
    return "blue";
}

//ctor for the X shape
X::X (int posx, int posy){
    x = new int [5];
    y = new int [5];
    *x = posx;
    *y = posy;
    *(x+1) = posx-1;
    *(y+1) = posy+1;
    *(x+2) = posx;
    *(y+2) = posy+1;
    *(x+3) = posx+1;
    *(y+3) = posy+1;
    *(x+4) = posx;
    *(y+4) = posy+2;
}
char X:: name(void) const{
    return 'X';
}
int X:: size(void) const{
    return 5;
}
const char* X::color(void) const{
    return "orange";
}

//ctor for the U shape
U::U (int posx, int posy){
    x = new int [7];
    y = new int [7];
    *x = posx;
    *y = posy;
    *(x+1) = posx+1;
    *(y+1) = posy;
    *(x+2) = posx+2;
    *(y+2) = posy;
    *(x+3) = posx;
    *(y+3) = posy+1;
    *(x+4) = posx+2;
    *(y+4) = posy+1;
    *(x+5) = posx;
    *(y+5) = posy+2;
    *(x+6) = posx+2;
    *(y+6) = posy+2;
    
}
char U:: name(void) const{
    return 'U';
}
int U:: size(void) const{
    return 7;
}
const char* U::color(void) const{
    return "red";
}


