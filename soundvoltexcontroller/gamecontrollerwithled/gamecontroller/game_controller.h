#ifndef GAMECONTROLLER_GAME_CONTROLLER_H_
#define GAMECONTROLLER_GAME_CONTROLLER_H_
#include "unojoy/UnoJoy.h"
namespace gamecontroller {
//UnoJoy 라이브러리를 이용해 만든 게임 컨트롤러.
class GameController {
 public:
  //버튼의 최대 개수.
  const static int kMaxButton = 13;
  const static int kMinAnalogStickValue = 0;
  const static int kMiddleAnalogStickValue = 127;
  const static int kMaxAnalogStickValue = 255;
  //기본 생성자.
  GameController();
  //소멸자.
  virtual ~GameController();
  //PC와 컨트롤러간 통신이 가능하도록 초기화.
  void Initialize();
  //각 매개 변수로 전달받은 Pin 번호에 대해 순서대로 D패드의
  //상, 하, 좌, 우에 할당.
  void SetDPadPins(const int up_pin, const int down_pin,
                   const int left_pin, const int right_pin);
  //매개 변수로 전달받은 배열을 이용해서 순서대로 D패드에 대해
  //상, 하, 좌, 우에 대한 Pin 할당.
  //전달받은 배열에는 반드시 4개의 값이 존재해야 함.
  void SetDPadPins(const int pins_array[4]);
  //D패드에 할당된 Pin을 전부 해제.
  void ResetDPadPins();
  //매개 변수로 전달받은 Pin을 할당.
  void SetButtonPin(const int pin);
  //각 매개 변수로 전달받은 Pin 번호부터 버튼의 개수만큼을 순서대로 할당.
  void SetButtonPins(const int start_pin, const int number_of_buttons);
  //매개 변수로 전달받은 배열과 버튼의 갯수를 이용해서 순서대로 버튼에 대한 Pin 할당.
  void SetButtonPins(const int pins_array[], const int number_of_buttons);
  //가변 인자로 버튼의 갯수에 대해 Pin 할당.
  void SetButtonPins(const int number_of_buttons, ...);
  //버튼에 할당된 Pin을 전부 해제.
  void ResetButtonPins();
  //매개 변수로 전달받은 두 인자를 이용해서 순서대로
  //왼쪽 아날로그 스틱에 대한 X축, Y축 Pin 할당.
  void SetLeftAnalogStickPins(const int x_axis_pin, const int y_axis_pin);
  //왼쪽 아날로그 스틱에 할당된 Pin을 전부 해제.
  void ResetLeftAnalogStickPins();
  //매개 변수로 전달받은 두 인자를 이용해서 순서대로
  //오른쪽 아날로그 스틱에 대한 X축, Y축 Pin 할당.
  void SetRightAnalogStickPins(const int x_axis_pin, const int y_axis_pin);
  //오른쪽 아날로그 스틱에 할당된 Pin을 전부 해제.
  void ResetRightAnalogStickPins();
  //매개 변수로 전달받은 인자들을 이용해서 순서대로
  //왼쪽 아날로그 스틱에 대한 X축, Y축,
  //오른쪽 아날로그 스틱에 대한 X축, Y축 Pin 할당.
  void SetAnalogStickPins(const int left_x_axis_pin,
                          const int left_y_axis_pin,
                          const int right_x_axis_pin,
                          const int right_y_axis_pin);
  //아날로그 스틱에 할당된 Pin을 모두 해제.
  void ResetAnalogStickPins();
  //매개 변수로 받은 Pin의 배열을 하나로 묶음.
  void CombineButtons(const int pins_array[], const int number_of_buttons);
  //가변 인자로 매개 변수의 갯수만큼 각 Pin을 묶음.
  void CombineButtons(const int number_of_buttons, ...);
  //묶은 버튼을 해제.
  void ResetCombinedButtons();
  //할당한 Pin들을 이용해 실제 게임 컨트롤러의 역할을 수행.
  //최소 버튼에 대한 Pin의 할당이 돼 있어야 하며
  //loop() 함수 등을 이용해 계속해서 수행되야 함.
  virtual void Work();
 protected:
  //최대 핀 갯수.
  const static int kMaxPin = 20;
  //할당되지 않은 버튼.
  const static int kNullButton = -1;
  //number_of_button_의 getter.
  int number_of_button() const;
  //assigned_d_pad_pins_array_의 getter.
  int *assigned_d_pad_pins_array();
  //assigned_button_pins_array_의 getter.
  int *assigned_button_pins_array();
  //assigned_left_analog_stick_pins_array_의 getter.
  int *assigned_left_analog_stick_pins_array();
  //assigned_right_analog_stick_pins_array_의 getter.
  int *assigned_right_analog_stick_pins_array();
  void SetLeftAnalogStickXAxisValue(const int value);
  void SetLeftAnalogStickYAxisValue(const int value);
  void SetRightAnalogStickXAxisValue(const int value);
  void SetRightAnalogStickYAxisValue(const int value);
  void SetButton1Value(const bool is_pressed);
  void SetButton2Value(const bool is_pressed);
  void SetButton3Value(const bool is_pressed);
  void SetButton4Value(const bool is_pressed);
  void SetButton5Value(const bool is_pressed);
  void SetButton6Value(const bool is_pressed);
  void SetButton7Value(const bool is_pressed);
  void SetButton8Value(const bool is_pressed);
  void SetButton9Value(const bool is_pressed);
  void SetButton10Value(const bool is_pressed);
  void SetButton11Value(const bool is_pressed);
  void SetButton12Value(const bool is_pressed);
  void SetButton13Value(const bool is_pressed);
  //현재 버튼 및 아날로그 스틱 값을 이용해 controller_data_ 초기화.
  virtual void MakeControllerData();
 private:
  //핀을 묶어서 처리하기 위한 구조체.
  struct CombinedPinsData {
    int number_of_combined_pins;
    int combined_pins_array[kMaxButton - 1];
  };
  //버튼의 갯수.
  int number_of_buttons_;
  //묶인 버튼의 갯수.
  int number_of_combined_buttons_;
  //입력 데이터를 저장하기 위한 구조체.
  dataForController_t controller_data_;
  //할당된 D패드에 대한 Pin들을 저장하기 위한 배열.
  int assigned_d_pad_pins_array_[4];
  //할당된 버튼에 대한 Pin들을 저장하기 위한 배열.
  int assigned_button_pins_array_[kMaxButton];
  //할당된 왼쪽 아날로그 스틱에 대한 Pin들을 저장하기 위한 배열.
  int assigned_left_analog_stick_pins_array_[2];
  //할당된 오른쪽 아날로그 스틱에 대한 Pin들을 저장하기 위한 배열.
  int assigned_right_analog_stick_pins_array_[2];
  //D패드에 대한 Pin이 할당되었는지 판단하기 위한 변수.
  bool is_assigned_d_pad_pins_;
  //왼쪽 아날로그 스틱에 대한 Pin이 할당되었는지 판단하기 위한 변수.
  bool is_assigned_left_analog_stick_pins_;
  //오른쪽 아날로그 스틱에 대한 Pin이 할당되었는지 판단하기 위한 변수.
  bool is_assigned_right_analog_stick_pins_;
  //묶인 핀들을 저장하기 위한 배열.
  CombinedPinsData combined_pins_data_array_[kMaxButton];
  //핀에 대한 버튼의 할당 번호를 저장하기 위한 배열.
  int button_by_pin_index_[kMaxPin];
  //SetButton1Value ~ SetButton13Value 함수를 가리키기 위한 함수 포인터를 SetButtonsValue형으로 정의.
  typedef void(GameController::*SetButtonsValue)(bool);
  //각 Button에 대한 배열. 
  SetButtonsValue set_buttons_value_[kMaxButton];
  void SetTriangleButtonValue(const bool is_pressed);
  void SetCircleButtonValue(const bool is_pressed);
  void SetSquareButtonValue(const bool is_pressed);
  void SetCrossButtonValue(const bool is_pressed);
  void SetLeft1ButtonValue(const bool is_pressed);
  void SetLeft2ButtonValue(const bool is_pressed);
  void SetLeft3ButtonValue(const bool is_pressed);
  void SetRight1ButtonValue(const bool is_pressed);
  void SetRight2ButtonValue(const bool is_pressed);
  void SetRight3ButtonValue(const bool is_pressed);
  void SetSelectButtonValue(const bool is_pressed);
  void SetStartButtonValue(const bool is_pressed);
  void SetHomeButtonValue(const bool is_pressed);
  void SetDPadLeftButtonValue(const bool is_pressed);
  void SetDPadUpButtonValue(const bool is_pressed);
  void SetDPadRightButtonValue(const bool is_pressed);
  void SetDPadDownButtonValue(const bool is_pressed);
  //각 Button이 해당하는 SetButton 함수를 가리키도록 설정.
  void MakeButtonsValue();
  //controller_data_를 전송.
  void SendControllerData() const;
};

GameController::GameController() {
  number_of_buttons_ = 0;
  number_of_combined_buttons_ = 0;
  is_assigned_d_pad_pins_ = false;
  is_assigned_left_analog_stick_pins_ = false;
  is_assigned_right_analog_stick_pins_ = false;
  ResetDPadPins();
  ResetButtonPins();
  ResetAnalogStickPins();
  MakeButtonsValue();
}

GameController::~GameController() {
}

inline void GameController::Initialize() {
  setupUnoJoy();
}

inline void GameController::SetDPadPins(const int pins_array[4]) {
  for (int i = 0; i < 4; ++i) {
    assigned_d_pad_pins_array_[i] = pins_array[i];
    pinMode(pins_array[i], INPUT_PULLUP);
  }
  is_assigned_d_pad_pins_ = true;
}

inline void GameController::SetDPadPins(const int up_pin, const int down_pin,
                                        const int left_pin,
                                        const int right_pin) {
  int pins_array[4] = { up_pin, down_pin, left_pin, right_pin };
  SetDPadPins(pins_array);
}

inline void GameController::ResetDPadPins() {
  is_assigned_d_pad_pins_ = false;
}

inline void GameController::SetButtonPin(const int pin) {
  if (button_by_pin_index_[pin] == kNullButton) {
    assigned_button_pins_array_[number_of_buttons_] = pin;
    button_by_pin_index_[pin] = number_of_buttons_;
    pinMode(pin, INPUT_PULLUP);
    ++number_of_buttons_;
  }
}

inline void GameController::SetButtonPins(const int start_pin,
                                          const int number_of_buttons) {
  for (int i = 0; i < number_of_buttons; ++i) {
    SetButtonPin(start_pin + i);
  }
}

inline void GameController::SetButtonPins(const int pins_array[],
                                          const int number_of_buttons) {
  for (int i = 0; i < number_of_buttons; ++i) {
    SetButtonPin(pins_array[i]);
  }
}

inline void GameController::SetButtonPins(const int number_of_buttons, ...) {
  va_list variable_list;
  va_start(variable_list, number_of_buttons);
  for (int i = 0; i < number_of_buttons; ++i) {
    SetButtonPin(va_arg(variable_list, int));
  }
  va_end(variable_list);
}

inline void GameController::ResetButtonPins() {
  for (int i = 0; i < kMaxPin; ++i) {
    button_by_pin_index_[i] = kNullButton;
  }
  number_of_buttons_ = 0;
  ResetCombinedButtons();
}

inline void GameController::SetLeftAnalogStickPins(const int x_axis_pin,
                                                   const int y_axis_pin) {
  assigned_left_analog_stick_pins_array_[0] = x_axis_pin;
  assigned_left_analog_stick_pins_array_[1] = y_axis_pin;
  pinMode(x_axis_pin, INPUT_PULLUP);
  pinMode(y_axis_pin, INPUT_PULLUP);
  is_assigned_left_analog_stick_pins_ = true;
}

inline void GameController::ResetLeftAnalogStickPins() {
  is_assigned_left_analog_stick_pins_ = false;
}

inline void GameController::SetRightAnalogStickPins(const int x_axis_pin,
                                                    const int y_axis_pin) {
  assigned_right_analog_stick_pins_array_[0] = x_axis_pin;
  assigned_right_analog_stick_pins_array_[1] = y_axis_pin;
  pinMode(x_axis_pin, INPUT_PULLUP);
  pinMode(y_axis_pin, INPUT_PULLUP);
}

inline void GameController::ResetRightAnalogStickPins() {
  is_assigned_right_analog_stick_pins_ = false;
}

inline void GameController::SetAnalogStickPins(const int left_x_axis_pin,
                                               const int left_y_axis_pin,
                                               const int right_x_axis_pin,
                                               const int right_y_axis_pin) {
  SetLeftAnalogStickPins(left_x_axis_pin, left_y_axis_pin);
  SetRightAnalogStickPins(right_x_axis_pin, right_y_axis_pin);
}

inline void GameController::ResetAnalogStickPins() {
  ResetLeftAnalogStickPins();
  ResetRightAnalogStickPins();
}

inline void GameController::CombineButtons(const int pins_array[], 
                                    const int number_of_buttons) {
  combined_pins_data_array_[number_of_combined_buttons_]
    .number_of_combined_pins = number_of_buttons;
  for (int i = 0; i < number_of_buttons; ++i) {
    combined_pins_data_array_[number_of_combined_buttons_]
      .combined_pins_array[i] = pins_array[i];
  }
  ++number_of_combined_buttons_;
}

inline void GameController::CombineButtons(const int number_of_buttons, ...) {
  va_list variable_list;
  va_start(variable_list, number_of_buttons);
  combined_pins_data_array_[number_of_combined_buttons_]
    .number_of_combined_pins = number_of_buttons;
  for (int i = 0; i < number_of_buttons; ++i) {
    combined_pins_data_array_[number_of_combined_buttons_]
      .combined_pins_array[i] = va_arg(variable_list, int);
  }
  va_end(variable_list);
  ++number_of_combined_buttons_;
}

inline void GameController::ResetCombinedButtons() {
  number_of_combined_buttons_ = 0;
}

inline void GameController::Work() {
  MakeControllerData();
  SendControllerData();
}

inline int GameController::number_of_button() const {
  return number_of_buttons_;
}

inline int *GameController::assigned_d_pad_pins_array() {
  return assigned_d_pad_pins_array_;
}

inline int *GameController::assigned_button_pins_array() {
  return assigned_button_pins_array_;
}

inline int *GameController::assigned_left_analog_stick_pins_array() {
  return assigned_left_analog_stick_pins_array_;
}

inline int *GameController::assigned_right_analog_stick_pins_array() {
  return assigned_right_analog_stick_pins_array_;
}

inline void GameController::SetTriangleButtonValue(const bool is_pressed) {
  controller_data_.triangleOn = is_pressed;
}

inline void GameController::SetCircleButtonValue(const bool is_pressed) {
  controller_data_.circleOn = is_pressed;
}

inline void GameController::SetSquareButtonValue(const bool is_pressed) {
  controller_data_.squareOn = is_pressed;
}

inline void GameController::SetCrossButtonValue(const bool is_pressed) {
  controller_data_.crossOn = is_pressed;
}

inline void GameController::SetLeft1ButtonValue(const bool is_pressed) {
  controller_data_.l1On = is_pressed;
}

inline void GameController::SetLeft2ButtonValue(const bool is_pressed) {
  controller_data_.l2On = is_pressed;
}

inline void GameController::SetLeft3ButtonValue(const bool is_pressed) {
  controller_data_.l3On = is_pressed;
}

inline void GameController::SetRight1ButtonValue(const bool is_pressed) {
  controller_data_.r1On = is_pressed;
}

inline void GameController::SetRight2ButtonValue(const bool is_pressed) {
  controller_data_.r2On = is_pressed;
}

inline void GameController::SetRight3ButtonValue(const bool is_pressed) {
  controller_data_.r3On = is_pressed;
}

inline void GameController::SetSelectButtonValue(const bool is_pressed) {
  controller_data_.selectOn = is_pressed;
}

inline void GameController::SetStartButtonValue(const bool is_pressed) {
  controller_data_.startOn = is_pressed;
}

inline void GameController::SetHomeButtonValue(const bool is_pressed) {
  controller_data_.homeOn = is_pressed;
}

inline void GameController::SetDPadLeftButtonValue(const bool is_pressed) {
  controller_data_.dpadLeftOn = is_pressed;
}

inline void GameController::SetDPadUpButtonValue(const bool is_pressed) {
  controller_data_.dpadUpOn = is_pressed;
}

inline void GameController::SetDPadRightButtonValue(const bool is_pressed) {
  controller_data_.dpadRightOn = is_pressed;
}

inline void GameController::SetDPadDownButtonValue(const bool is_pressed) {
  controller_data_.dpadDownOn = is_pressed;
}

inline void GameController::SetLeftAnalogStickXAxisValue(const int value) {
  controller_data_.leftStickX = value;
}

inline void GameController::SetLeftAnalogStickYAxisValue(const int value) {
  controller_data_.leftStickY = value;
}

inline void GameController::SetRightAnalogStickXAxisValue(const int value) {
  controller_data_.rightStickX = value;
}

inline void GameController::SetRightAnalogStickYAxisValue(const int value) {
  controller_data_.rightStickY = value;
}

inline void GameController::SetButton1Value(const bool is_pressed) {
  SetSquareButtonValue(is_pressed);
}

inline void GameController::SetButton2Value(const bool is_pressed) {
  SetCrossButtonValue(is_pressed);
}

inline void GameController::SetButton3Value(const bool is_pressed) {
  SetCircleButtonValue(is_pressed);
}

inline void GameController::SetButton4Value(const bool is_pressed) {
  SetTriangleButtonValue(is_pressed);
}

inline void GameController::SetButton5Value(const bool is_pressed) {
  SetLeft1ButtonValue(is_pressed);
}

inline void GameController::SetButton6Value(const bool is_pressed) {
  SetRight1ButtonValue(is_pressed);
}

inline void GameController::SetButton7Value(const bool is_pressed) {
  SetLeft2ButtonValue(is_pressed);
}

inline void GameController::SetButton8Value(const bool is_pressed) {
  SetRight2ButtonValue(is_pressed);
}

inline void GameController::SetButton9Value(const bool is_pressed) {
  SetSelectButtonValue(is_pressed);
}

inline void GameController::SetButton10Value(const bool is_pressed) {
  SetStartButtonValue(is_pressed);
}

inline void GameController::SetButton11Value(const bool is_pressed) {
  SetLeft3ButtonValue(is_pressed);
}

inline void GameController::SetButton12Value(const bool is_pressed) {
  SetRight3ButtonValue(is_pressed);
}

inline void GameController::SetButton13Value(const bool is_pressed) {
  SetHomeButtonValue(is_pressed);
}

void GameController::MakeButtonsValue() {
  set_buttons_value_[0] = &GameController::SetButton1Value;
  set_buttons_value_[1] = &GameController::SetButton2Value;
  set_buttons_value_[2] = &GameController::SetButton3Value;
  set_buttons_value_[3] = &GameController::SetButton4Value;
  set_buttons_value_[4] = &GameController::SetButton5Value;
  set_buttons_value_[5] = &GameController::SetButton6Value;
  set_buttons_value_[6] = &GameController::SetButton7Value;
  set_buttons_value_[7] = &GameController::SetButton8Value;
  set_buttons_value_[8] = &GameController::SetButton9Value;
  set_buttons_value_[9] = &GameController::SetButton10Value;
  set_buttons_value_[10] = &GameController::SetButton11Value;
  set_buttons_value_[11] = &GameController::SetButton12Value;
  set_buttons_value_[12] = &GameController::SetButton13Value;
}

void GameController::MakeControllerData() {
  controller_data_ = getBlankDataForController();
  if (is_assigned_d_pad_pins_) {
    SetDPadUpButtonValue(!digitalRead(assigned_d_pad_pins_array_[0]));
    SetDPadDownButtonValue(!digitalRead(assigned_d_pad_pins_array_[1]));
    SetDPadLeftButtonValue(!digitalRead(assigned_d_pad_pins_array_[2]));
    SetDPadRightButtonValue(!digitalRead(assigned_d_pad_pins_array_[3]));
  }
  for (int i = 0; i < number_of_buttons_; ++i) {
    (this->*set_buttons_value_[i])(!digitalRead(assigned_button_pins_array_[i]));
  }
  for (int i = 0; i < number_of_combined_buttons_; ++i) {
    bool is_fail_combining_pins = false;
    for (int j = 0; j < combined_pins_data_array_[i].number_of_combined_pins; ++j) {
      if (digitalRead(combined_pins_data_array_[i].combined_pins_array[j])) {
        is_fail_combining_pins = true;
        break;
      }
    }
    if (!is_fail_combining_pins) {
      for (int j = 0; j < combined_pins_data_array_[i].number_of_combined_pins; ++j) {
        (this->*set_buttons_value_[button_by_pin_index_[combined_pins_data_array_[i]
         .combined_pins_array[j]]])(LOW);
      }
      (this->*set_buttons_value_[number_of_buttons_ + i])(HIGH);
    }
  }
  if (is_assigned_left_analog_stick_pins_) {
    SetLeftAnalogStickXAxisValue(analogRead(
      assigned_left_analog_stick_pins_array_[0]) >> 2);
    SetLeftAnalogStickYAxisValue(analogRead(
      assigned_left_analog_stick_pins_array_[1]) >> 2);
  }
  if (is_assigned_right_analog_stick_pins_) {
    SetRightAnalogStickXAxisValue(analogRead(
      assigned_right_analog_stick_pins_array_[0]) >> 2);
    SetRightAnalogStickYAxisValue(analogRead(
      assigned_right_analog_stick_pins_array_[1]) >> 2);
  }
}
inline void GameController::SendControllerData() const {
  setControllerData(controller_data_);
}
}
#endif
