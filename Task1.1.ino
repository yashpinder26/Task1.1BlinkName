const int ledPin = 3;       
const int buttonPin = 2;   
const int dotDuration = 250;
const int dashDuration = 750;
const int letterPause = 1000;
const int wordPause = 2000;

String morseCode[] = 
{
  "-.--",  // Y
  ".-",    // A
  "...",   // S
  "....",  // H
  ".--.",  // P
  "..",    // I
  "-.",    // N
  "-..",   // D
  ".",     // E
  ".-."    // R
};

int currentLetter = 0;
bool isBlinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);         
  pinMode(buttonPin, INPUT_PULLUP);  
}
void loop() {
  if (digitalRead(buttonPin) == LOW) {  
    if (!isBlinking) {
      isBlinking = true;
      currentLetter = 0;  
    } else {
      currentLetter = 0;  
    }
  }

  if (isBlinking) {
    if (currentLetter < 10) {
      blinkMorseCode(morseCode[currentLetter]);
      delay(letterPause);
      currentLetter++;
    } else {
      isBlinking = false;  
      delay(wordPause);
    }
  }
}

void blinkMorseCode(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      blinkDot();
    } else if (code[i] == '-') {
      blinkDash();
    }
    delay(dotDuration);
  }
}

void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}
