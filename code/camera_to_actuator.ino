#include <Servo.h>
Servo servo0;
struct VideoFrame {
  uint16_t ballCoordinates[2]; // ball center coordinates in pixels
  uint16_t frameSize[2]; // width, height
};
VideoFrame cam0;

void setup()
{
  Serial.begin(57600);
  servo0.attach(9, 1000, 2000);
}

void loop()
{
  //Serial.println(sizeof(greenBall));
  static bool firstFrame = false;
  static uint16_t maxDistance = 0; // max distance to frame center in pixels
  static uint16_t distance = 0; // actual distance to frame center in pixels
  if (!firstFrame) {
    if (Serial.read() == 's') {
      firstFrame = true;
      Serial.readBytes((byte*)cam0.frameSize, 4);
      maxDistance = sqrt(pow(cam0.frameSize[0]/2, 2) + pow(cam0.frameSize[1]/2, 2)); 
    }
  }
  else {
    if (Serial.read() == 'h')
      Serial.readBytes((byte*)cam0.ballCoordinates, 4);
      distance = distance_to_frame_center();
      /* topu merkeze yakın başlatıp PWM sinyalini 1ms yapıyoruz ve 
      böylece fırçasız motor ve ESC'yi aktif hale getiriyoruz*/
      if (distance < 100)
        servo0.write(0);
      else
        servo0.write(map(distance, 0, maxDistance, 0, 90)); // max PWM değeri 1.5ms olsun
      Serial.print(cam0.ballCoordinates[0]); Serial.print(' '); 
      Serial.print(cam0.ballCoordinates[1]); Serial.print(' ');
      Serial.println(distance);
  }
}


uint16_t distance_to_frame_center()
{
  uint32_t d = 0; // distance square, i.e., distance^2
  for (int i = 0; i < 2; i++)
    d = d + pow(int(cam0.ballCoordinates[i])-int(cam0.frameSize[i]/2), 2);
  return sqrt(d);
}
