#include <Keyboard.h>

int upArrowState = HIGH;
int previousUp = HIGH;
const int upArrowInput = 2;

int downArrowState = HIGH;
int previousDown = HIGH;
const int downArrowInput = 4;

int leftArrowState = HIGH;
int previousRight = HIGH;
const int leftArrowInput = 7;

int rightArrowState = HIGH;
int previousLeft = HIGH;
const int rightArrowInput = 8;

void setup() {
  Serial.begin(9600);
  pinMode(upArrowInput, INPUT_PULLUP);
  pinMode(downArrowInput, INPUT_PULLUP);
  pinMode(leftArrowInput, INPUT_PULLUP);
  pinMode(rightArrowInput, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  previousUp = upArrowState;
  upArrowState = digitalRead(upArrowInput);

  previousDown = downArrowState;
  downArrowState = digitalRead(downArrowInput);

  previousRight = rightArrowState;
  rightArrowState = digitalRead(leftArrowInput);

  previousLeft = leftArrowState;
  leftArrowState = digitalRead(rightArrowInput);

  // We had a switch from HIGH -> LOW aka the arrow was released
  if (upArrowState == HIGH  && previousUp == LOW) {
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("UP Release");
  } else if (upArrowState == LOW && previousUp == HIGH) {
    // We had a switch from LOW -> HIGH aka the arrow was pressed
    Serial.println("UP");
    Keyboard.press(KEY_UP_ARROW);
  }

  if (downArrowState == HIGH  && previousDown == LOW) {
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("DOWN Release");
  } else if (downArrowState == LOW && previousDown == HIGH) {
    Serial.println("DOWN");
    Keyboard.press(KEY_DOWN_ARROW);
  }

  if (rightArrowState == HIGH  && previousRight == LOW) {
    Keyboard.release(KEY_RIGHT_ARROW);
    Serial.println("RIGHT Release");
  } else if (rightArrowState == LOW && previousRight == HIGH) {
    Serial.println("RIGHT");
    Keyboard.press(KEY_RIGHT_ARROW);
  }

  if (leftArrowState == HIGH  && previousLeft == LOW) {
    Keyboard.release(KEY_LEFT_ARROW);
    Serial.println("LEFT Release");
  } else if (leftArrowState == LOW && previousLeft == HIGH) {
    Serial.println("LEFT");
    Keyboard.press(KEY_LEFT_ARROW);
  }

  if (leftArrowState == LOW || rightArrowState == LOW || upArrowState == LOW || downArrowState == LOW) {
    // Light up out L led on the arduino
    digitalWrite(13, HIGH);
  } else if (leftArrowState == HIGH && rightArrowState == HIGH && upArrowState == HIGH && downArrowState == HIGH) {
    digitalWrite(13, LOW);
  }
}
