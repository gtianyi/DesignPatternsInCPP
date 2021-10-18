#include <string>
using namespace std;

struct Renderer
{
    virtual string str() const = 0;
};

struct RasterRenderer:Renderer
{
    string str() const override{
     return " as pixels";   
    }
};

struct VectorRenderer:Renderer
{
    string str() const override{
     return " as lines";   
    }
};

struct Shape
{
    string name;
    Renderer& renderer;
    
    Shape(Renderer& renderer): renderer(renderer){}
    
    string str() const{
        return "Drawing " + name + renderer.str();
    }
};

struct Triangle : Shape
{
    Triangle(Renderer& renderer): Shape(renderer)
    {
        name = "Circle";
    }
};

struct Square : Shape
{
    Square(Renderer& renderer): Shape(renderer)
    {
        name = "Square";
    }
};

// struct VectorSquare : Square
// {
//     string str() const
//     {
//         return "Drawing " + name + " as lines";
//     }
// }

// struct RasterSquare : Square
// {
//     string str() const
//     {
//         return "Drawing " + name + " as pixels";
//     }
// }
