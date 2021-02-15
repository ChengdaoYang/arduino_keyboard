#include <Keyboard.h>    // This is a "built-in" library no need to install


#define BLUE_BUTTON 6
#define BROWN_BUTTON 10
#define RED_BUTTON 9
#define BLACK_BUTTON 14




//---------------------------------------------------------
//                           Setup
//---------------------------------------------------------'
int RXLED = 17;  // The RX LED has a defined Arduino pin
int times = 1;  // Number of times the led flash

const char win_key = KEY_LEFT_GUI;
const char enter_key = KEY_RETURN;
const char tab_key = KEY_TAB;
const char alt_key = KEY_LEFT_ALT;
const char ctrl_key = KEY_LEFT_CTRL;
const char del_key = KEY_DELETE;
const char left_arrow_key = KEY_LEFT_ARROW;
const char right_arrow_key = KEY_RIGHT_ARROW;
const char down_arrow_key = KEY_DOWN_ARROW;
const char up_arrow_key = KEY_UP_ARROW;




void setup() {
    
pinMode(BLUE_BUTTON,INPUT_PULLUP);  // sets pin 3 to input & pulls it high w/ internal resistor
pinMode(BROWN_BUTTON,INPUT_PULLUP);  // sets pin 4 to input & pulls it high w/ internal resistor
pinMode(RED_BUTTON,INPUT_PULLUP);  // sets pin 5 to input & pulls it high w/ internal resistor
pinMode(BLACK_BUTTON,INPUT_PULLUP);  // sets pin 5 to input & pulls it high w/ internal resistor

pinMode(RXLED, OUTPUT);  // Set RX LED as an output

Serial.begin(9600);       // begin serial comms for debugging

}

//---------------------------------------------------------
//                       Function Start
//---------------------------------------------------------

char delay_bw_key = 120, delay_after_key = 80;


void led_flash(int times) {
  // flash led if led_on==true
  int i;
  for (i=1; i<=times; i++) {
    digitalWrite(RXLED, LOW);   // set the RX LED ON
    delay(20);              // wait for a second
    digitalWrite(RXLED, HIGH);    // set the RX LED OFF
    delay(5);              // wait for a second
  }
}


void copy() {
    // ctrl + c
  led_flash();
  Keyboard.press(ctrl_key);
  Keyboard.press('c');    delay(delay_bw_key);  
  Keyboard.releaseAll();
  led_flash();
  delay(delay_after_key);
}


void paste() {
    // ctrl + c
  led_flash();
  Keyboard.press(ctrl_key);
  Keyboard.press('v');    delay(delay_bw_key);  
  Keyboard.releaseAll();
  led_flash();
  delay(delay_after_key);
}


void select_all() {
    // ctrl + a
  led_flash();
  Keyboard.press(ctrl_key);
  Keyboard.press('a');    delay(delay_bw_key);  
  Keyboard.releaseAll();
  led_flash();
  delay(delay_after_key);
}

void ctrl_alt_del() {
  led_flash();
  Keyboard.press(ctrl_key);
  Keyboard.press(alt_key);
  Keyboard.press(del_key);
  delay(200);
  led_flash();
  Keyboard.releaseAll();    delay(100);
}


void open_app(char app_name[21]) {  // allow max 20 char in arry, the 1 extral if for \n(null ternimator
  led_flash();
  Keyboard.write(win_key); delay(200);
  Keyboard.println(app_name);  delay(300);
  led_flash();
  Keyboard.write(enter_key);  delay(1000);
}


void close_app(char app_name[21]) {
  led_flash();
  Keyboard.write(aly_key); delay(200);
  Keyboard.println(app_name);  delay(300);
  led_flash();
  Keyboard.write(enter_key);  delay(1000);
}


void switch_app(int win_num) {
    // ctrl + c, win_num==0, tab_ctrl for quick switch
  if (win_num == 0) {
    led_flash();
    Keyboard.press(alt_key);
    Keyboard.write(tab_key);    delay(delay_bw_key);  
    Keyboard.releaseAll();
    led_flash();
    delay(delay_after_key);
  }
  else if (win_num != 0) {
    led_flash();
    Keyboard.press(win_key);
    Keyboard.write(win_num);    delay(delay_bw_key);  
    Keyboard.releaseAll();
    led_flash();
    delay(delay_after_key);
  }
}
//---------------------------------------------------------
//                       Function End
//---------------------------------------------------------




//---------------------------------------------------------
//                           Loop
//---------------------------------------------------------

void loop() {
  Keyboard.begin();         //begin keyboard 
  
  if (digitalRead(BLUE_BUTTON) == 0){
    led_flash(); 
    Keyboard.write(ctrl_key);    delay(500);
    Keyboard.println(PASSWORD);    delay(330);
    led_flash(); 
  }
  else if (digitalRead(BROWN_BUTTON) == 0){
    led_flash();
    Keyboard.print(EMAIL);    delay(380);
    led_flash(); 
    
  }
  else if (digitalRead(RED_BUTTON) == 0){  //if button 5 is pressed
    led_flash(); 
    open_app("rsa");    led_flash(); 
    delay(2000);    led_flash(); 
    Keyboard.println(PASSCODE);  delay(700);    led_flash(); 
    Keyboard.write(enter_key);  delay(1300);    led_flash(); 
    copy();    delay(900);  // copy rsa key
  }
  else if (digitalRead(BLACK_BUTTON) == 0){  //if button 5 is pressed
    led_flash(); 
    Keyboard.print("Happy Valentine's day, Feibao,\n   Yours Daobao"); 
    led_flash(); 
  }
  
  Keyboard.end();                 //stops keybord
}
