//
// Created by utkugokce on 13.12.2023.
//
#include <iostream>
#include <string>

/* Adaptee (source) interface */
class FruitBasket {
public:
  virtual void addFruit(const std::string& fruit) = 0;
  virtual ~FruitBasket() {}
};

/* Target interface */
class FruitService {
public:
  void addFruitToService(const std::string& fruitName, int quantity) {
    std::cout << quantity << " " << fruitName << " added to the service.\n";
  }
};

/* The Adapter */ /// Let's adapt the FruitBasket interface to the FruitService interface
class FruitServiceAdapter : public FruitBasket {
private:
  FruitService* fruitService;

public:
  FruitServiceAdapter(FruitService* service) : fruitService(service) {}

  void addFruit(const std::string& fruit) override {
    // Perform necessary conversions inside the adapter to add fruit
    fruitService->addFruitToService(fruit, 1);
  }
};