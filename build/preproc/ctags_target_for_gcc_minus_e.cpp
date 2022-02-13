# 1 "c:\\GIT\\led\\led.ino"



byte buffer = 0;

void setup() {
    pinMode(6, 0x1);
    pinMode(5, 0x1);
    pinMode(3, 0x1);

    analogWrite(3, 0); //0..255
    analogWrite(5, 0); // 0..65
    analogWrite(6, 0); //0..255

    Serial.begin(9600);
}

int formula(int degree) {

    if (degree >= 360) {
        degree -= 360;
    }

    if (degree <= 120) {
        return 0;
    } else if (degree > 120 && degree <= 180) {
        return map(degree, 120, 180, 0, 255);
    } else if (degree > 180 && degree <= 300) {
        return 255;
    } else {
        return map(degree, 300, 360, 255, 0);
    }
}

void loop() {

    for (int i = 0; i < 360; i++)
    {
        analogWrite(3, formula(i+120));
        analogWrite(5, map(formula(i+240), 0, 255, 0, 65));
        analogWrite(6, formula(i));
        delay(50);
    }


}
