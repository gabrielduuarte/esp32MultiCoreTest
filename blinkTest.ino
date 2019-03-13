#define LED1 14
#define LED2 32

TaskHandle_t Task1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  xTaskCreatePinnedToCore(codeForTask1, "Task_1", 1000, NULL, 1, &Task1, 0);
  
  
  delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Nucle: ");
  Serial.println(xPortGetCoreID());

  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  delay(1000);

}

void codeForTask1(void *parameter)
{
  for(;;)
  {
    Serial.print("Core: ");
    Serial.println(xPortGetCoreID());

    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    delay(1000);
  }
}
