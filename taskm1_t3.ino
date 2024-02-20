#define pirPin 2
#define buttonPin 3
#define motionLedPin 8
#define buttonLedPin 4

volatile bool isMotionDetected = false;
volatile bool isButtonPressed = false;

void controlLEDs() {
    if (isMotionDetected) {
        digitalWrite(motionLedPin, HIGH);
        Serial.println("Motion detected! Turning on Motion LED.");
        isMotionDetected = false;
    } else {
        digitalWrite(motionLedPin, LOW);
    }

    if (isButtonPressed) {
        digitalWrite(buttonLedPin, HIGH);
        Serial.println("Button pressed! Turning on Button LED.");
        isButtonPressed = false;
    } else {
        digitalWrite(buttonLedPin, LOW);
    }
}

void interruptPIR() {
    isMotionDetected = true;
    controlLEDs();
}

void interruptButton() {
    isButtonPressed = true;
    controlLEDs();
}

void setup() {
    pinMode(pirPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(motionLedPin, OUTPUT);
    pinMode(buttonLedPin, OUTPUT);
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(pirPin), interruptPIR, RISING);
    attachInterrupt(digitalPinToInterrupt(buttonPin), interruptButton, FALLING);
}

void loop() {
    // Empty loop
}
