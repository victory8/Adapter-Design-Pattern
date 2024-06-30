//
// Created by utkugokce on 13.12.2023.
//

#include <iostream>
#include <string>

// Target Interface
class Car {
public:
  virtual double getSpeed() const = 0;
  virtual ~Car() = default;
};

// Adaptee - Existing Class that returns speed in kilometers per hour (km/h)
class EuropeanCar : public Car {
private:
  double speedKmph;

public:
  EuropeanCar(double speed) : speedKmph(speed) {}

  double getSpeed() const override {
    return speedKmph;
  }
};

// Adapter: Converts speed from miles per hour (mph) to kilometers per hour (km/h)
class AmericanCarAdapter : public Car {
private:
  double speedMph;
  static constexpr double MPH_TO_KMPH = 1.60934; // 1 mile = 1.60934 kilometers

public:
  AmericanCarAdapter(double speed) : speedMph(speed) {}

  double getSpeed() const override {
    return speedMph * MPH_TO_KMPH; // Convert miles per hour to kilometers per hour
  }
};

// Client-usable class
class Speedometer {
private:
  Car *car;

public:
  Speedometer(Car *vehicle) : car(vehicle) {}

  double getCurrentSpeed() const {
    return car->getSpeed();
  }

  ~Speedometer() {
    delete car;
  }
};
