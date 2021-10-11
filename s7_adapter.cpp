struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
  {
      // todo
      squareSide = square.side;
  }
  // todo
  int width() const {return squareSide;}
  int height() const {return squareSide;}
private:
 int squareSide;
};
