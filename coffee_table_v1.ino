const int enA = 3;
const int in1 = 4;
const int in2 = 5;
const int button = 6;
const int stop_button = 7;

bool table_open = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(stop_button, INPUT_PULLUP);

  
}

void loop() {


  if(digitalRead(button) == LOW && digitalRead(stop_button) == LOW) {
    Serial.println("Button pressed");
    closeTable();
    delay(3000); // add delay to allow shaft to release the button
  } else if(digitalRead(button) == LOW) {
    Serial.println("Button pressed");
    if(table_open) {
      closeTable();
    } else {
      openTable();
    }
  } else {
    if(digitalRead(stop_button) == LOW) {
      analogWrite(enA, 0);
      table_open = true;
      Serial.println("Opened");
    }
  }
}

void closeTable() {
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  table_open = false;
  Serial.println("Closing");
  delay(1000); // add delay to allow time when button is pressed
}

void openTable() {
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  Serial.println("Opening");
}
