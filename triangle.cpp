#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template
<
  typename TYPE,
  std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{   
  return SIZE;
}

struct Coordinate {
  double x0;
  double y0;
  double x1;
  double y1;
  double x2;
  double y2;
  double gradient1 () {
    double g1 = (y1 - y0) / (x1 - x0);
    return fabs(g1);
  }
  double gradient2 () {
    double g2 = (y2 - y1) / (x2 - x1);
    return fabs(g2);
  }
  void print() {
    cout << fixed << setprecision(1) << endl;
    cout << "[x0, y0] = [" << x0 << ", " << y0 << "]" << endl;
    cout << "[x1, y1] = [" << x1 << ", " << y1 << "]" << endl;
    cout << "[x2, y2] = [" << x2 << ", " << y2 << "]" << endl;
  }
};

bool is_triangle(Coordinate* pcoordicate) {
  Coordinate coordinate = *pcoordicate;

  // 座標から２点を選び、傾き(絶対値)を取得
  // 傾きが異なるなら、三角形（直線状にない）
  // 傾きが同じなら、直線（直線上にある)
  if (coordinate.gradient1() != coordinate.gradient2()) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  // サンプルデータ
  double clist[][6] =  {
    {1.0, 4.0, 2.0, 5.0, 3.0, 3.0},
    {1.0, 1.0, 3.0, 3.0, 5.0, 5.0},
    {2.0, 3.0, 3.0, 5.0, 6.0, 8.0},
    {2.0, 3.0, 3.0, 5.0, 6.0, 11.0},
    {3.0, 4.7, 2.7, 5.9, 3.4, 3.46666},
    {4.0, 9.8, 7.3, 6.7, 3.7, 7.8},
  };

  for (int i = 0; i < array_length(clist); i++ ) {
    Coordinate coordinate = {
      clist[i][0],
      clist[i][1],
      clist[i][2],
      clist[i][3],
      clist[i][4],
      clist[i][5]
    };
    coordinate.print();
    if (is_triangle(&coordinate) == true) {
      cout << "三角形です" << endl << endl;
    } else {
      cout << "三角形ではないです" << endl << endl;
    }
  };

  return 0;
}