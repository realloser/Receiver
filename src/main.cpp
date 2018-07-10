#include <PinChangeInterruptHandler.h>
#include <RFReceiver.h>

// Listen on digital pin 2
RFReceiver receiver(2);

void setup() {
  Serial.begin(9600);
  receiver.begin();
  // Led Indication of received data
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  char msg[MAX_PACKAGE_SIZE];
  byte senderId = 0;
  byte packageId = 0;
  byte len = receiver.recvPackage((byte *)msg, &senderId, &packageId);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("");
  Serial.print("Package: ");
  Serial.println(packageId);
  Serial.print("Sender: ");
  Serial.println(senderId);
  Serial.print("Message: ");
  Serial.println(msg);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

}
