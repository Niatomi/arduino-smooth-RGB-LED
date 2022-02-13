#define RED 3
#define GREEN 5
#define BLUE 6
byte buffer = 0;

void setup() {
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);

    analogWrite(RED, 0); //0..255
    analogWrite(GREEN, 0); // 0..65
    analogWrite(BLUE, 0); //0..255

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
        analogWrite(RED, formula(i+120));    
        analogWrite(GREEN, map(formula(i+240), 0, 255, 0, 65));    
        analogWrite(BLUE, formula(i)); 
        delay(50);   
    }
    

}
