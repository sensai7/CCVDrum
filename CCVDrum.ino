// Pin connections
// Complete pinmap on http://energia.nu/pinmaps/img/LaunchPadMSP430G2452-v1.5.jpg
#define POT_BIT 2
#define POT_FLD 5
#define POT_DRV 6
#define POT_PAN 7
#define POT_GAN 14
#define POT_PART 15
#define LED_P1 13
#define LED_P2 12
#define LED_P3 11
#define LED_P4 10
#define LED_P5 9
#define LED_P6 8
#define PUSH_L1 18
#define PUSH_L1 19

//operation variables
const unsigned int numReadings = 10;
const unsigned int potPort[6] = {POT_PART, POT_BIT, POT_FLD, POT_DRV, POT_PAN, POT_GAN};
const unsigned int ledPort[6] = {LED_P1, LED_P2, LED_P3, LED_P4, LED_P5, LED_P6};
const unsigned int CCValues[5] = {49, 50, 51, 10, 52}; //Complete Midi implementation on https://www.korg.com/us/support/download/product/0/809/
unsigned int readings[6][numReadings];
unsigned int readIndex = 0;
unsigned int total[6] = {0, 0, 0, 0, 0};
unsigned int average[6] = {0, 0, 0, 0, 0};
unsigned int outputValue[6] = {0, 0, 0, 0, 0};
unsigned int previousValue[6] = {0, 0, 0, 0, 0};
unsigned int part = 0;

//timing variables
unsigned long previousMillis = 0;
const unsigned int interval = 10; //(milliseconds for each midi send)

void setup(){
	Serial.begin(31250); 

	//Setup LEDs
	for (int i = 0; i < 6; i++){
		pinMode(ledPort[i], OUTPUT);
		digitalWrite(ledPort[i], LOW);
	}

	//Read pot initial status
	for (int j = 0; j < numReadings; j++) {
		digitalWrite(LED_P6, HIGH);
		for (int i = 0; i < 6; i++){
			readings[i][j] = analogRead(potPort[i]);
			total[i] += readings[i][j];
		}
		delay(1); //this should theoretically work
		digitalWrite(LED_P6, LOW);
	} 
}

void loop(){
	//Averaging and updating pot status
	for (int i = 0; i < 6; i++){
		average[i] = total[i] / numReadings;
		outputValue[i] = average[i] >> 2;
		total[i] -= readings[i][readIndex];
		readings[i][readIndex] = analogRead(potPort[i]);
		total[i] += readings[i][readIndex];
	}
	readIndex = (readIndex + 1) % (numReadings);

	//Buttons

	// to be executed once every 'interval' miliseconds
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis > interval){	 
		previousMillis = currentMillis;
		part = (outputValue[0] + 22) / 43 - 1; // 0-255 to 0-5 in even steps map() doesn't work as it should
		for (int i = 1; i < 6; i++){
			if (outputValue[i] != previousValue[i]){
				digitalWrite(ledPort[i], HIGH);
				Serial.write(0xB0 + part); 
				Serial.write(CCValues[i - 1]);
				Serial.write(outputValue[i]);
				previousValue[i] = outputValue[i];
				digitalWrite(ledPort[i], LOW);
			}
		}
		for (int i = 0; i < 6; i++){
			if (i != part){
				digitalWrite(ledPort[i], LOW);
			}
		}
		digitalWrite(ledPort[part], HIGH);
		
	} 
}
