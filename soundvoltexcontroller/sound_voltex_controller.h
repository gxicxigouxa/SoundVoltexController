#ifndef SOUNDVOLTEXCONTROLLER_SOUND_VOLTEX_CONTROLLER_H_
#define SOUNDVOLTEXCONTROLLER_SOUND_VOLTEX_CONTROLLER_H_
#include "gamecontrollerwithled/game_controller_with_led.h"
#include "knob/knob.h"
#ifdef GAMECONTROLLER_GAME_CONTROLLER_H_
namespace soundvoltexcontroller {
//GameController를 상속받아 만든 Sound Voltex 컨트롤러.
class SoundVoltexController
  : public gamecontrollerwithled::GameControllerWithLed {
 public:
  //생성자.
  SoundVoltexController();
  //소멸자.
  virtual ~SoundVoltexController();
  //매개 변수로 전달받은 두 값을 이용해 왼쪽 노브의
  //왼쪽, 오른쪽 회전에 해당하는 Pin을 할당.
  void SetLeftKnobPins(const int left_turn_pin, const int right_turn_pin);
  //매개 변수로 전달받은 두 값을 이용해 오른쪽 노브의
  //왼쪽, 오른쪽 회전에 해당하는 Pin을 할당.
  void SetRightKnobPins(const int left_turn_pin, const int right_turn_pin);
  //매개 변수로 전달받은 네 값을 이용해 각 노브의
  //왼쪽, 오른쪽 회전에 해당하는 Pin을 할당.
  void SetKnobPins(const int left_knob_left_turn_pin,
                   const int left_knob_right_turn_pin,
                   const int right_knob_left_turn_pin,
                   const int right_knob_right_turn_pin);
  //왼쪽 노브에 할당된 Pin들을 전부 해제.
  void ResetLeftKnobPins();
  //오른쪽 노브에 할당된 Pin들을 전부 해제.
  void ResetRightKnobPins();
  //노브에 할당된 Pin들을 전부 해제.
  void ResetKnobPins();
  //왼쪽 노브의 감도 설정.
  void SetLeftKnobSensitivity(const double knob_sensitivity);
  //오른쪽 노브의 감도 설정.
  void SetRightKnobSensitivity(const double knob_sensitivity);
  //각 매개 변수를 이용해 왼쪽 노브와 오른쪽 노브의 감도 설정.
  void SetKnobSensitivity(const double left_knob_sensitivity,
                          const double right_knob_sensitivity);
  //매개 변수를 이용해 각 노브의 감도를 동일하게 설정.
  void SetKnobSensitivity(const double knob_sensitivity);
  //Override.
  virtual void Work();
 protected:
  //Override.
  //현재 버튼 및 노브의 값을 이용해 controller_data_ 초기화.
  virtual void MakeControllerData();
 private:
  //왼쪽 노브.
  Knob *left_knob_ = nullptr;
  //오른쪽 노브.
  Knob *right_knob_ = nullptr;
};

SoundVoltexController::SoundVoltexController()
  : GameControllerWithLed() {
  left_knob_position_ = kMiddleAnalogStickValue;
  right_knob_position_ = kMiddleAnalogStickValue;
}

SoundVoltexController::~SoundVoltexController() {
}

inline void SoundVoltexController::SetLeftKnobPins(const int left_turn_pin,
                                                   const int right_turn_pin) {
  ResetAnalogStickPins();
  ResetLeftKnobPins();
  left_knob_ = new Knob(left_turn_pin, right_turn_pin);
}

inline void SoundVoltexController::SetRightKnobPins(const int left_turn_pin,
                                                    const int right_turn_pin) {
  ResetAnalogStickPins();
  ResetRightKnobPins();
  right_knob_ = new Knob(left_turn_pin, right_turn_pin);
}

inline void SoundVoltexController::SetKnobPins(
  const int left_knob_left_turn_pin,
  const int left_knob_right_turn_pin,
  const int right_knob_left_turn_pin,
  const int right_knob_right_turn_pin) {
  SetLeftKnobPins(left_knob_left_turn_pin, left_knob_right_turn_pin);
  SetRightKnobPins(right_knob_left_turn_pin, right_knob_right_turn_pin);
}

inline void SoundVoltexController::ResetLeftKnobPins() {
  delete left_knob_;
  left_knob_ = nullptr;
}

inline void SoundVoltexController::ResetRightKnobPins() {
  delete right_knob_;
  right_knob_ = nullptr;
}

inline void SoundVoltexController::ResetKnobPins() {
  ResetLeftKnobPins();
  ResetRightKnobPins();
}

inline void SoundVoltexController::SetLeftKnobSensitivity(
  const double knob_sensitivity) {
  left_knob_->set_sensitivity(knob_sensitivity);
}

inline void SoundVoltexController::SetRightKnobSensitivity(
  const double knob_sensitivity) {
  right_knob_->set_sensitivity(knob_sensitivity);
}

inline void SoundVoltexController::SetKnobSensitivity(
  const double left_knob_sensitivity, const double right_knob_sensitivity) {
  SetLeftKnobSensitivity(left_knob_sensitivity);
  SetRightKnobSensitivity(right_knob_sensitivity);
}

inline void SoundVoltexController::SetKnobSensitivity(const double knob_sensitivity) {
  SetLeftKnobSensitivity(knob_sensitivity);
  SetRightKnobSensitivity(knob_sensitivity);
}

inline void SoundVoltexController::Work() {
  GameControllerWithLed::Work();
}

inline void SoundVoltexController::MakeControllerData() {
  GameControllerWithLed::MakeControllerData();
  SetLeftAnalogStickXAxisValue(left_knob_->ReadValue());
  SetLeftAnalogStickYAxisValue(right_knob_->ReadValue());
}
}
#endif
#endif
