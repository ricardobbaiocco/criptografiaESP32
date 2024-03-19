#define BUTTON1 18
#define BUTTON2 19
#define LED1 2
#define LED2 4
#define LED_ON_TIME 3000 // Tempo em milissegundos para ligar o LED

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  unsigned long startTime = millis();
  bool button1Pressed = false;

  // Aguardar até que se passem 5 segundos ou o botão 1 seja pressionado
  while (millis() - startTime < 5000) {
    if (digitalRead(BUTTON1) == HIGH) {
      button1Pressed = true;
      break;
    }
  }

  // Verificar se o botão 1 foi pressionado
  if (button1Pressed) {
    digitalWrite(LED1, HIGH); // Ligar LED1
    delay(LED_ON_TIME); // Manter o LED1 ligado por 3 segundos
    digitalWrite(LED1, LOW); // Desligar LED1
  } else {
    digitalWrite(LED2, HIGH); // Ligar LED2
    delay(LED_ON_TIME); // Manter o LED2 ligado por 3 segundos
    digitalWrite(LED2, LOW); // Desligar LED2
  }

  // Esperar um tempo antes de começar de novo
  delay(1000);
}
