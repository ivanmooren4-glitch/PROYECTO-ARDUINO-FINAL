#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200);

  if (!rtc.begin()) {
    Serial.println("No encontrado");
    Serial.flush();
    while (1) delay(10);
  }

  Serial.println("Configurando la fecha y hora Actual");
  Serial.print("Fecha: ");
  Serial.println(_DATE_);     // Fecha
  Serial.print("Hora: ");
  Serial.println(_TIME_);     // Hora
  Serial.println();

  // Ajustar RTC con fecha y hora de compilación
  rtc.adjust(DateTime(_DATE, __TIME_));
}

void loop() {
  DateTime tiempo = rtc.now();

  //Serial.println("Completo \t" + tiempo.timestamp(DateTime::TIMESTAMP_FULL)); se muestra la fecha y hora todo junto
  Serial.println("Hora Actual \t" + tiempo.timestamp(DateTime::TIMESTAMP_TIME));// mostramos primero la hora actual
  Serial.println("Fecha Actual \t" + tiempo.timestamp(DateTime::TIMESTAMP_DATE));//mostramos despues la fecha
  Serial.println();

  delay(10000);
}