#ifndef KNOB_SOUND_VOLTEX_CONTROLLER_KNOB_KNOB_H_
#define KNOB_SOUND_VOLTEX_CONTROLLER_KNOB_KNOB_H_
#include "encoder/Encoder.h"
namespace soundvoltexcontroller {
class Knob : public Encoder {
 public:
  //인식 감도의 기본값.
  constexpr static double kDefaultSensitivity = 1.0;
  //기본 최솟값 및 최댓값. GAMECONTROLLER_GAME_CONTROLLER_H_의 정의유무에 따라 값 결정.
#ifdef GAMECONTROLLER_GAME_CONTROLLER_H_
  const static int kDefaultMaxValue = gamecontroller::GameController::kMaxAnalogStickValue;
#else
  const static int kDefaultMaxValue = 255;
#endif
  //매개 변수로 회전 방향에 대한 Pin을 전달받는 생성자.
  Knob(const int left_turn_pin, const int right_turn_pin);
  //소멸자.
  virtual ~Knob();
  //sensitivity_의 setter.
  void set_sensitivity(const double sensitivity);
  void set_max_value(const int max_value);
  //값을 읽어들임.
  int ReadValue();
 private:
  //회전 시 인식 감도. 항상 0보다 커야 하며 값이 클수록 회전에 민감하게 반응.
  double sensitivity_;
  int max_value_;
};

Knob::Knob(const int left_turn_pin, const int right_turn_pin)
  : Encoder(left_turn_pin, right_turn_pin) {
  sensitivity_ = kDefaultSensitivity;
  max_value_ = kDefaultMaxValue;
}

Knob::~Knob() {
}

inline void Knob::set_sensitivity(const double sensitivity) {
  sensitivity_ = sensitivity;
}

inline void Knob::set_max_value(const int max_value) {
  max_value_ = max_value;
}

inline int Knob::ReadValue() {
  return static_cast<int>(static_cast<double>(Encoder::read()) * sensitivity_) % max_value_;
}
}
#endif