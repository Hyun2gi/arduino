short int led_pin = 13;
short int button_pin = 3;
short int button_state; //버튼상태, high나 low저장

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
// pinMode(button_pin, INPUT_PULLUP); ->연결된게 아무것도 없을 때 HIGH상태값을 읽겠다.
//안정적인상태보장을 위해서 윗줄을 사용
//INPUT_PULLUP은 연결된 핀에 신호가 없을 때 항상 HIGH가 되도록 강제함.
//PULLUP저항을 붙인다.
//선이 끊어져도 해당키가 HIGH가 되도록
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button_pin); //3번PIN의 상태를 읽어서 button_state에 넣음
  digitalWrite(led_pin, button_state); //LED에 button_state값을 보낸다.
}
