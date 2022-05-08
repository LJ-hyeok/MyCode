struct point{
  int x,y;
  bool operator<(const point& other)const{
    return x<other.x;
  }
};
