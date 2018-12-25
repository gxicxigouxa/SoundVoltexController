//SoundVoltexController를 사용하기 위해 include.
#include "soundvoltexcontroller/sound_voltex_controller.h"
soundvoltexcontroller::SoundVoltexController sound_voltex_controller;
void setup() {
  //버튼의 갯수.
  const static int kNumberOfButtons = 7;
  //Start 버튼에 할당될 핀.
  const static int kStartButton = 2;
  //BT-1 ~ BT-4에 할당될 핀.
  const static int kBt1Button = 3;
  const static int kBt2Button = 4;
  const static int kBt3Button = 5;
  const static int kBt4Button = 6;
  //FX-L, FX-R에 할당될 핀.
  const static int kFxLButton = 7;
  const static int kFxRButton = 8;
  //컨트롤러 초기화.
  sound_voltex_controller.Initialize();
  //버튼에 해당하는 핀 할당.
  sound_voltex_controller.SetButtonPins(kNumberOfButtons, kBt1Button, kBt2Button, kBt3Button, kBt4Button, kFxLButton, kFxRButton, kStartButton);
  //왼쪽, 오른쪽 노브의 왼쪽, 오른쪽 회전에 할당될 핀.
  const static int kLeftKnobLeftTurn = 9;
  const static int kLeftKnobRightTurn = 10;
  const static int kRightKnobLeftTurn = 11;
  const static int kRightKnobRightTurn = 12;
  //노브에 해당하는 핀 할당.
  sound_voltex_controller.SetKnobPins(kLeftKnobLeftTurn, kLeftKnobRightTurn, kRightKnobLeftTurn, kRightKnobRightTurn);
  //노브의 감도
  constexpr static double kKnobSensitivity = 2.7;
  //노브의 감도 설정.
  sound_voltex_controller.SetKnobSensitivity(kKnobSensitivity);
  //LED의 갯수.
  const static int kNumberOfLeds = 7;
  //Start 버튼에 할당된 LED 핀.
  const static int kStartButtonLed = 13;
  //BT-1 ~ BT-4에 할당될 LED 핀.
  const static int kBt1Led = A0;
  const static int kBt2Led = A1;
  const static int kBt3Led = A2;
  const static int kBt4Led = A3;
  //FX-L, FX-R에 할당될 LED 핀.
  const static int kFxLLed = A4;
  const static int kFxRLed = A5;
  //LED에 해당하는 핀 할당.
  sound_voltex_controller.SetLedPins(kNumberOfLeds, kBt1Led, kBt2Led, kBt3Led, kBt4Led, kFxLLed, kFxRLed, kStartButtonLed);
  //할당된 LED 핀과 대응하는 버튼 핀 설정.
  sound_voltex_controller.BindLedPinToButtonPin(kBt1Led, kBt1Button);
  sound_voltex_controller.BindLedPinToButtonPin(kBt2Led, kBt2Button);
  sound_voltex_controller.BindLedPinToButtonPin(kBt3Led, kBt3Button);
  sound_voltex_controller.BindLedPinToButtonPin(kBt4Led, kBt4Button);
  sound_voltex_controller.BindLedPinToButtonPin(kFxLLed, kFxLButton);
  sound_voltex_controller.BindLedPinToButtonPin(kFxRLed, kFxRButton);
  sound_voltex_controller.BindLedPinToButtonPin(kStartButtonLed, kStartButton);
}

void loop() {
  //동작 수행. loop()에 의해 계속 반복.
  sound_voltex_controller.Work();
}
