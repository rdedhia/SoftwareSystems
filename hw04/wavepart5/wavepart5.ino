/*
  
 Contains code from Allen Downey that has been modified
 by Rahil Dedhia for Software Systems Homework 4. This code
 addresses all parts of the assignment. It uses bitwise writes,
 timer interrupts, and external interrupts using attachInterrupt()
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
int buttonPin1 = 2;
int buttonPin2 = 3;

void setup() {
  
  cli();//stop interrupts

  //set timer2 interrupt at 40kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 10khz increments
  OCR2A = 196;// = (16*10^6) / (8*10000)-1
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);  
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  
  sei();//allow interrupts
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);
  
  //Switch the frequency when buttonPin1 goes from LOW to HIGH
  attachInterrupt(0, interrupt, RISING);

  DDRD = B11000000; //set pins 6 to 7 as output
  DDRB = B00111111; //set pins 8 to 13 as output
}

void writeByte(int x) {
  x = ~x; //invert all the bits
  PORTD &= B00111111; //turns off bits 6 and 7
  PORTD |= (x<<6); //set bits 6 and 7 to the least sig digits of x
  PORTB &= B11000000; //turns off bits 8 to 13
  PORTB |= (x>>2); //set bits 0 to 5 to the most sig digits of x
}

// Changes the frequency when called by attachInterrupt
void interrupt() {
  if (OCR2A == 196)
    OCR2A = 392;
  else //(OCR2A == 392)
    OCR2A = 196;
}

int low = 36;
int high = 255;
int stride = 5;
int counter = low;

ISR(TIMER2_COMPA_vect) {  
  int button2 = digitalRead(buttonPin2);
  if (button2) return;
  counter += stride;  
  if (counter > high) {
    counter = low;
  }
  // write to the digital pins  
  writeByte(counter);
}

void loop() {}

