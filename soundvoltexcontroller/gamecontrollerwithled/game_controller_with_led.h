#ifndef GAMECONTROLLERWITHLED_GAME_CONTROLLER_WITH_LED_H_
#define GAMECONTROLLERWITHLED_GAME_CONTROLLER_WITH_LED_H_
#include "gamecontroller/game_controller.h"
#include "ledavailable/led_available_interface.h"
namespace gamecontrollerwithled {
class GameControllerWithLed
  : public gamecontroller::GameController,
  ledavailable::LedAvailableInterface {
 public:
  GameControllerWithLed();
  virtual ~GameControllerWithLed();
  //Override.
  void SetLedPin(const int pin);
  //Override.
  void SetLedPins(const int start_pin, const int number_of_leds);
  //Override.
  void SetLedPins(const int pins_array[], const int number_of_leds);
  //가변 인자로 LED의 갯수를 먼저 받아 그 만큼을 LED Pin으로 할당.
  void SetLedPins(const int number_of_leds, ...);
  //Override.
  void ResetLedPins();
  //number_of_leds_의 getter.
  int number_of_leds() const;
  //TODO. LED pin과 할당된 버튼 pin을 묶음.
  void BindLedPinToButtonPin(const int led_pin, const int button_pin);
  //Override.
  //기존 GameController::Work()에 LED 동작 추가.
  virtual void Work();
 protected:
  //Override.
  virtual void MakeControllerData();
 private:
  //Override.
  void WorkLed();
  //Override.
  int GetNumberOfLeds() const;
  //LED의 최대 갯수.
  const static int kMaxLed = kMaxButton;
  //LED의 개수.
  int number_of_leds_;
  //할당된 LED에 대한 Pin들을 저장하기 위한 배열.
  int assigned_led_pins_array_[kMaxLed];
  //Led Pin에 대해 Mapping된 Button 핀을 저장하기 위한 배열.
  int mapped_button_pin_by_led_pin_[kMaxPin];
};

GameControllerWithLed::GameControllerWithLed()
  : GameController() {
  number_of_leds_ = 0;
  ResetLedPins();
}

GameControllerWithLed::~GameControllerWithLed() {
}

inline void GameControllerWithLed::SetLedPin(const int pin) {
  if (mapped_button_pin_by_led_pin_[pin] == ledavailable::LedAvailableInterface::kNullLed) {
    assigned_led_pins_array_[number_of_leds_] = pin;
    mapped_button_pin_by_led_pin_[pin] =
      assigned_button_pins_array()[number_of_leds_];
    pinMode(pin, OUTPUT);
    ++number_of_leds_;
  }
}

inline void GameControllerWithLed::SetLedPins(
  const int start_pin, const int number_of_leds) {
  for (int i = 0; i < number_of_leds; ++i) {
    SetLedPin(start_pin);
  }
}

inline void GameControllerWithLed::SetLedPins(const int pins_array[],
                                              const int number_of_leds) {
  for (int i = 0; i < number_of_leds; ++i) {
    SetLedPin(pins_array[i]);
  }
}

inline void GameControllerWithLed::SetLedPins(const int number_of_leds, ...) {
  va_list variable_list;
  va_start(variable_list, number_of_leds);
  for (int i = 0; i < number_of_leds; ++i) {
    SetLedPin(va_arg(variable_list, int));
  }
  va_end(variable_list);
}

inline void GameControllerWithLed::ResetLedPins() {
  for (int i = 0; i < kMaxPin; ++i) {
    mapped_button_pin_by_led_pin_[i] = ledavailable::LedAvailableInterface::kNullLed;
  }
  number_of_leds_ = 0;
}

inline int GameControllerWithLed::number_of_leds() const {
  return GetNumberOfLeds();
}

inline void GameControllerWithLed::BindLedPinToButtonPin(const int led_pin,
                                                         const int button_pin) {
  if (mapped_button_pin_by_led_pin_[led_pin] != ledavailable::LedAvailableInterface::kNullLed) {
    mapped_button_pin_by_led_pin_[led_pin] = button_pin;
  }
}

inline void GameControllerWithLed::WorkLed() {
  int number_of_leds = number_of_leds_;
  if (number_of_button() < number_of_leds_) {
    number_of_leds = number_of_button();
  }
  for (int i = 0; i < number_of_leds; ++i) {
    if (!digitalRead(mapped_button_pin_by_led_pin_[assigned_led_pins_array_[i]])) {
      digitalWrite(assigned_led_pins_array_[i], HIGH);
    } else {
      digitalWrite(assigned_led_pins_array_[i], LOW);
    }
  }
}

inline void GameControllerWithLed::Work() {
  GameController::Work();
  WorkLed();
}

inline void GameControllerWithLed::MakeControllerData() {
  GameController::MakeControllerData();
}

inline int GameControllerWithLed::GetNumberOfLeds() const {
  return number_of_leds_;
}
}
#endif