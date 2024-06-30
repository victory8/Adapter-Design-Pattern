#include "AdapterDesignPattern1.cpp"
#include "AdapterDesignPattern2.cpp"
#include "AdapterDesignPattern3.cpp"


int main()
{
  /// Adapter Kettle Example
  Socket* socket = new Socket;
  Adapter* adapter = new Adapter;
  ElectricKettle* kettle = new ElectricKettle;

  adapter->plugIn(socket);
  kettle->plugIn(adapter);

  kettle->boil();

  delete socket;
  delete adapter;
  delete kettle;

  std::cout << "***********************\n";

  /*/// Adapter Speed Example
  EuropeanCar euroCar(120.0); // Kilometre/saat cinsinden hız
  Speedometer speedometerForEuroCar(&euroCar);
  std::cout << "European Car Speed: " << speedometerForEuroCar.getCurrentSpeed() << " km/h" << std::endl;

  AmericanCarAdapter americanCar(75.0); // Mil/saat cinsinden hız, Adapter kullanarak dönüşüm yapılacak
  Speedometer speedometerForUSCar(&americanCar);
  std::cout << "American Car Speed: " << speedometerForUSCar.getCurrentSpeed() << " km/h" << std::endl;*/

  std::cout << "***********************\n";
  
  /// Adapter Fruit Basket Example
  // Create FruitService object
  /*FruitService fruitService;

  // Add meyve with FruitBasket interface via Adapter
  FruitBasket* fruitAdapter = new FruitServiceAdapter(&fruitService);
  fruitAdapter->addFruit("Apple");

  delete fruitAdapter;*/

  std::cout << "***********************\n";

  return 0;
}
