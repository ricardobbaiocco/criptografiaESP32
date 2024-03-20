#define BUTTON1 18
#define BUTTON2 19
#define BUTTON3 21
#define BUTTON4 22
#define LED1 2
#define LED2 4
#define LED_ON_TIME 1000 // Tempo do LED ligado
#define BUZZER_PIN 23 // Pino do Buzzer

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600); // Inicializar comunicação serial
}

void loop() {
  unsigned long startTime = millis();
  bool button1Pressed = false;
  bool button2Pressed = false;
  bool button3Pressed = false;
  bool button4Pressed = false;

  // Aguardar até que se passem 5 segundos ou os botões sejam pressionados
  while (millis() - startTime < 5000) {
    if (digitalRead(BUTTON1) == HIGH) {
      button1Pressed = true;
    }
    if (digitalRead(BUTTON2) == HIGH) {
      button2Pressed = true;
    }
    if (digitalRead(BUTTON3) == HIGH) {
      button3Pressed = true;
    }
    if (digitalRead(BUTTON4) == HIGH) {
      button4Pressed = true;
    }
  }

  // Valor binário conforme a ação dos botões, se não pressionar é 0 e se pressionar 1
  String binaryValue = "";
  binaryValue += button1Pressed ? "1" : "0";
  binaryValue += button2Pressed ? "1" : "0";
  binaryValue += button3Pressed ? "1" : "0";
  binaryValue += button4Pressed ? "1" : "0";

  Serial.println("Valor binário: " + binaryValue);

  // Verificar se ambos os botões foram pressionados
  if (button1Pressed && button2Pressed && button3Pressed && button4Pressed) {
    digitalWrite(LED1, HIGH); // Ligar LED1
    digitalWrite(BUZZER_PIN, HIGH); // Ligar Buzzer
    delay(LED_ON_TIME); // Manter o LED1 e o Buzzer ligados por 1 segundo
    digitalWrite(LED1, LOW); // Desligar LED1
    digitalWrite(BUZZER_PIN, LOW); // Desligar Buzzer
  } else {
    digitalWrite(LED2, HIGH); // Ligar LED2
    digitalWrite(BUZZER_PIN, HIGH); // Ligar Buzzer
    delay(LED_ON_TIME); // Manter o LED2 e o Buzzer ligados por 1 segundo
    digitalWrite(LED2, LOW); // Desligar LED2
    digitalWrite(BUZZER_PIN, LOW); // Desligar Buzzer
  }

  // Aguardar um tempo antes de começar de novo
  delay(1000);
}