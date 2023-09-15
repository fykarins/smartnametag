#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <ITG3200.h>
#include <Adafruit_MLX90614.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;
TinyGPSPlus gps; 
HardwareSerial ss(1);
ITG3200 gyro;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


float latitude , longitude;
String  lat_str , lng_str;
const int motorDCPin = 12;
const int solenoidValvePin = 14;
const int pushButtonPin = 15;
bool motorDCOn = false;
bool solenoidValveOn = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  ads.begin();// Inisialisasi sensor MPS20N004
  accel.begin();// Inisialisasi sensor accelerometer GY85
  accel.setRange(ADXL345_RANGE_16_G);
  mlx.begin();// Inisialisasi sensor MLX906
  gyro.init();// Inisialisasi sensor gyroscope GY85
  gyro.zeroCalibrate(100, 10);// Inisialisasi sensor gyroscope GY85
  ss.begin(9600,SERIAL_8N1, 16, 17);// Inisialisasi sensor gps
  pinMode(motorDCPin, OUTPUT);// Inisialisasi Pompa angin
  pinMode(solenoidValvePin, OUTPUT); // Inisialisasi katup buangan angin
  pinMode(pushButtonPin, INPUT_PULLUP);// Inisialisasi Push button
  digitalWrite(motorDCPin, LOW);
  digitalWrite(solenoidValvePin, LOW);
}



void loop() {
// read Sensor MPS20N004
     int buttonState = digitalRead(pushButtonPin);
     if (buttonState == HIGH) {
        digitalWrite(motorDCPin, HIGH);
        motorDCOn = true;
        delay (5000);
        digitalWrite(motorDCPin, LOW);
        motorDCOn = false;
        int16_t adc0 = ads.readADC_SingleEnded(0);
        float voltage = adc0 * 0.000125; 
        float Vcc = 3.3; 
        float Pmax = 300.0; 
        float pressure = (voltage / Vcc) * Pmax; 
        Serial.print("Nilai ADC: "); 
        Serial.println(adc0);
        Serial.print("Tegangan (V): "); 
        Serial.println(voltage, 4);
        Serial.print("Tekanan (kPa): "); 
        Serial.println(pressure, 2);
        delay (2000);
        digitalWrite(solenoidValvePin, HIGH);
        solenoidValveOn = true;
        delay (1000);
        digitalWrite(solenoidValvePin, LOW);
        solenoidValveOn = false;
      } 
      else {
        delay(100);
      }
// Read MAX30102 sensor
    Wire.requestFrom(0x57, 6); 
    float irData;
    float redData;
       irData = Wire.read();
        Serial.print("data inframerah :");
        Serial.print(irData);
       redData = Wire.read();

// Read ADXL345 accelerometer
    sensors_event_t event;
    accel.getEvent(&event);
        Serial.print("Accelerometer [X,Y,Z] (m/s^2): ");
        Serial.print(event.acceleration.x); Serial.print(", ");
        Serial.print(event.acceleration.y); Serial.print(", ");
        Serial.println(event.acceleration.z);

// Read ITG3200 gyroscope
    int16_t x, y, z;
    gyro.getXYZ(&x, &y, &z);
        Serial.print("Posisi alat: ");
        Serial.print(x);
        Serial.print(" , ");
        Serial.print(y);
        Serial.print(" , ");
        Serial.println(z);
        delay(100);

    float ax, ay, az;
    gyro.getAngularVelocity(&ax, &ay, &az);
    int kecepatan = (ax + ay + az)/3;
        Serial.print("kecepatan orang = ");
        Serial.print(kecepatan);
        Serial.print("m/s \n");
   
// Read ITG3200 gyroscope
    float objectTempC = mlx.readObjectTempC();
        Serial.print("suhu badan: ");
        Serial.print(objectTempC);
        Serial.print("°C \n");

// Read sensor GPS
    gps.encode(ss.read()); 
    latitude = gps.location.lat();
    lat_str = String(latitude , 6); 
    longitude = gps.location.lng();
    lng_str = String(longitude , 6);    
        Serial.print( "koordinat :");
        Serial.print( latitude);
        Serial.print(" , ");
        Serial.print( longitude);
        delay(1000);
}
