#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

// --- SERVO CONFIGURATION ---
Servo doorServo;
const int SERVO_PIN = 9; // Connected to Digital Pin 9

// --- LCD PIN CONFIGURATION ---
// RS -> Pin 12, Enable -> Pin 10, Data -> Pins 5, 4, 3, 2
LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

// --- KEYPAD CONFIGURATION ---
const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Keypad rows: A0, A1, A2, A3 | Keypad columns: A4, A5, Digital 7, Digital 8
byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {A4, A5, 7, 8};   

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- PASSWORD VARIABLES ---
const String correctPassword = "1234";
String inputPassword = "";

// Function prototype declaration
void resetDisplay();
void checkPassword();

void setup() {
  // Attach Servo & Set initial locked position (0 degrees)
  doorServo.attach(SERVO_PIN);
  doorServo.write(0); 

  // Initialize LCD screen (16 columns, 2 rows)
  lcd.begin(16, 2);
  resetDisplay();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Press '*' to clear current entry
    if (key == '*') {
      inputPassword = "";
      resetDisplay();
    } 
    // Press '#' to manually submit
    else if (key == '#') {
      checkPassword();
    } 
    // Append pressed key if less than 4 digits
    else if (inputPassword.length() < 4) {
      inputPassword += key;
      
      // Update line 2 with asterisks (*) to mask the password
      lcd.setCursor(0, 1);
      String masked = "";
      for (int i = 0; i < inputPassword.length(); i++) {
        masked += "*";
      }
      while (masked.length() < 16) {
        masked += " ";
      }
      lcd.print(masked);

      // Auto-submit when 4 digits are entered
      if (inputPassword.length() == 4) {
        delay(300);
        checkPassword();
      }
    }
  }
}

// Reset screen display to default prompt
void resetDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
  lcd.print("____"); 
}

// Verify entered password & operate door
void checkPassword() {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (inputPassword == correctPassword) {
    lcd.print("Access Granted!");
    lcd.setCursor(0, 1);
    lcd.print("Door Unlocked...");
    
    // Rotate Servo 90 degrees to unlock door
    doorServo.write(90); 
    
    // Hold door open for 10 seconds (10,000 ms)
    delay(10000); 
    
    // Lock door again (rotate back to 0 degrees)
    doorServo.write(0);
  } else {
    lcd.print("Wrong Password");
    delay(2000); 
  }

  // Reset password string and screen for next user
  inputPassword = "";
  resetDisplay();
}