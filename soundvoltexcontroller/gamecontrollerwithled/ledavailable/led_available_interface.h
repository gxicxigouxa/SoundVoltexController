//2016.07.26
//LED 작동을 위한 Interface.
#ifndef LEDAVAILABLE_LED_AVAILABLE_INTERFACE_H_
#define LEDAVAILABLE_LED_AVAILABLE_INTERFACE_H_
namespace ledavailable {
class LedAvailableInterface {
 public:
  const static int kNullLed = -1;
  //매개 변수로 전달받은 Pin 한 개를 LED Pin으로 할당.
  virtual void SetLedPin(const int pin) = 0;
  //각 매개 변수로 전달받은 Pin 번호부터 LED의 개수만큼 순서대로
  //LED Pin으로 할당.
  virtual void SetLedPins(const int start_pin, const int number_of_leds) = 0;
  //매개 변수로 전달받은 배열을 이용해서 순서대로 LED Pin으로 할당.
  virtual void SetLedPins(const int pins_array[], const int number_of_leds) = 0;
  //LED로 할당된 Pin을 전부 해제.
  virtual void ResetLedPins() = 0;
  //Led로 할당된 Pin의 개수.
  virtual int GetNumberOfLeds() const = 0;
  //할당된 Pin들을 이용해 LED가 동작하는 역할을 수행.
  virtual void WorkLed() = 0;
};
}
#endif