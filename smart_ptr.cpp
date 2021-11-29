#include <iostream>
#include <vector>
#include <memory>

//create a function to print the vector of templates
template<typename T>
void printVector(const std::vector<T> vec)
{
    for (const auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

//create a class rectangle area
class RectangleArea
{
public:
    //constructor
    RectangleArea(int width, int height) : _width(width), _height(height) {}
    //destructor
    ~RectangleArea() = default;
    //function to calculate the area
    int getArea() const { return _width * _height; }
    //set width
    void setWidth(int width) { this->_width = width; }
    //set height
    void setHeight(int height) { this->_height = height; }

private:
    int _width;
    int _height;
};

int main() {
  //create a rectangle area
  RectangleArea rect(3, 4);
  //print the area
  std::cout << rect.getArea() << std::endl;
  //create a unique pointer to a rectangle area
  std::unique_ptr<RectangleArea> rectPtr( &rect);
  //print the area
  //std::cout << rectPtr->getArea() << std::endl;
  //create a unique pointer to recPtr
  std::unique_ptr<RectangleArea> recPtr = std::move(rectPtr);
  //print the area
  std::cout << recPtr->getArea() << std::endl;

  //count recPtr
  std::cout << "recPtr: " << recPtr->getArea() << std::endl;

  //create a share d pointer to a rectangle area
  std::shared_ptr<RectangleArea> rectSharedPtr( &rect);
  //print the area
  std::cout << rectSharedPtr->getArea() << std::endl;
    //create a shared pointer to recSharedPtr
  std::shared_ptr<RectangleArea> recSharedPtr = std::move(rectSharedPtr);
  //print the area
  std::cout << recSharedPtr->getArea() << std::endl;

  recSharedPtr->setWidth(5);
  recSharedPtr->setHeight(6);
  std::cout << recSharedPtr->getArea() << std::endl;

  //create new weak pointer to shared pointer
  std::weak_ptr<RectangleArea> rectWeakPtr(rectSharedPtr);
  //print the area
  std::cout << "weak ptr "<<rectWeakPtr.use_count()<< std::endl;

  //create a share ptr to new rectangle area
  std::shared_ptr<RectangleArea> rectSharedPtr2(new RectangleArea(7, 8));
  //create a shared pointer to recSharedPtr
  const std::shared_ptr<RectangleArea>& recSharedPtr3 = rectSharedPtr2;

  return 0;
}
