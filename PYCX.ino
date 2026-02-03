
#include <OneButton.h>

volatile int 平移模式;
volatile int 平移模式左超时;
volatile int 平移模式超;
volatile int 平移模式右超时;
volatile int 平移模式右;
OneButton button0(0,true);
OneButton button20(20,true);

void task_2( void * pvParameters ){
for(;;){
  while (平移模式超) {
    delay(1000);
    平移模式左超时++;
    break;
  }
  while (平移模式右) {
    delay(1000);
    平移模式右超时++;
    break;
  }
  if (平移模式左超时 > 60) {
    digitalWrite(18,LOW);
    digitalWrite(19,LOW);
    digitalWrite(21,LOW);
    digitalWrite(12,HIGH);
    平移模式左超时 = 0;

  }
  if (平移模式右超时 > 60) {
    digitalWrite(18,LOW);
    digitalWrite(19,LOW);
    digitalWrite(21,LOW);
    digitalWrite(12,HIGH);
    平移模式右超时 = 0;

  }
  vTaskDelay(1);
}
}

void attachInterrupt_fun_0() {
  平移模式 = false;
  平移模式右 = false;
  平移模式超 = false;
  平移模式 = false;
  平移模式右 = false;
  平移模式超 = false;
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
}

void task_1( void * pvParameters ){
for(;;){
  if (digitalRead(0) == 0) {

  }
  while (平移模式) {
    if (digitalRead(5) == 1) {
      平移模式超 = false;
      平移模式左超时 = 0;
      digitalWrite(19,LOW);
      delay(1500);
      digitalWrite(18,HIGH);
      平移模式右 = true;

    }
    if (digitalRead(0) == 1) {
      平移模式右 = false;
      平移模式右超时 = 0;
      digitalWrite(18,LOW);
      delay(1500);
      digitalWrite(19,HIGH);
      平移模式超 = true;

    }
    break;
  }
  vTaskDelay(1);
}
}

void attachClick0() {
  if (digitalRead(5) == digitalRead(0)) {
    digitalWrite(18,HIGH);

  } else {
    平移模式 = true;

  }
}

void attachClick20() {
  while (平移模式右) {
    平移模式右 = false;
    平移模式右超时 = 0;
    digitalWrite(19,LOW);
    digitalWrite(18,HIGH);
    平移模式超 = true;
    平移模式左超时 = 0;
    break;
  }
  while (平移模式超) {
    平移模式超 = false;
    平移模式左超时 = 0;
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    平移模式右 = true;
    平移模式右超时 = 0;
    break;
  }
}

void setup(){
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(12, OUTPUT);

  xTaskCreatePinnedToCore(task_2, "task_2", 4096, NULL, 2, NULL, 0);

  平移模式 = 0;
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(13, OUTPUT);
  平移模式左超时 = 0;
  平移模式超 = 0;
  平移模式右超时 = 0;
  平移模式右 = 0;
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  digitalWrite(2,LOW);
  digitalWrite(0,LOW);
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  digitalWrite(21,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  平移模式 = true;
  if (digitalRead(5) == digitalRead(0)) {
    digitalWrite(18,HIGH);

  } else {
    平移模式 = true;

  }

  xTaskCreatePinnedToCore(task_1, "task_1", 4096, NULL, 2, NULL, 0);

  button0.attachClick(attachClick0);
  button20.attachClick(attachClick20);
}

void loop(){
  vTaskDelay(1);

  attachInterrupt(0,attachInterrupt_fun_0,RISING);

  vTaskDelay(1);

  button0.tick();
  button20.tick();
  if (0 == true) {

  }
  if (0 == true) {

  }

  平移模式超 = true;
  平移模式左超时 = 0;

}