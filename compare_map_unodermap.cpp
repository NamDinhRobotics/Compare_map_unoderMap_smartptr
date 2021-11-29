//
// Created by dinhnambkhn on 21. 11. 29..
//
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <chrono>

int main(){
  //create a map with 1000 elements
  std::map<int, std::string> myMap;
  std::unordered_map<int, std::string> myUnorderedMap;
  //insert 1000 elements randomly
  for(int i = 0; i < 100000; i++){
    myMap.insert(std::pair<int, std::string>(i, "value " + std::to_string(i)));
    myUnorderedMap.insert(std::pair<int, std::string>(i, "value " + std::to_string(i)));
  }
  //find the element with key = 5000
  //begin count time
  auto start = std::chrono::high_resolution_clock::now();

  //find 1000 elements with key = 1000 to 2000
  for(int i = 1000; i < 2000; i++){
    myMap.find(i);
  }

  //end count time
  auto end = std::chrono::high_resolution_clock::now();
  //print 10 first elements
  for(int i = 0; i < 10; i++){
    std::cout << myMap.find(i)->second << std::endl;
  }

  //show time in microseconds
  std::cout << "TIME myMap: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

  //begin count time
  start = std::chrono::high_resolution_clock::now();
  //find 1000 elements with key = 1000 to 2000
  for(int i = 1000; i < 2000; i++){
    myUnorderedMap.find(i);
  }

  //end count time
  end = std::chrono::high_resolution_clock::now();
  //show time in microseconds
  std::cout << "TIME myUnorderedMap: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
  //print 10 first elements
  for(int i = 0; i < 10; i++){
    std::cout << myUnorderedMap.find(i)->second << std::endl;
  }

  return 0;

}
