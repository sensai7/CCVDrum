// Pin connections
// Complete pinmap on http://energia.nu/pinmaps/img/LaunchPadMSP430G2452-v1.5.jpg
#define POT_BIT 2
#define LED_BIT 8
#define POT_FLD 5
#define LED_FLD 10
#define POT_DRV 6
#define LED_DRV 11
#define POT_PAN 7
#define LED_PAN 12
#define POT_GAN 15
#define LED_GAN 9
#define LED_ON 13

//operation variables
const unsigned int numReadings = 10;
const unsigned int analogPort[5] = {POT_BIT, POT_FLD, POT_DRV, POT_PAN, POT_GAN};
const unsigned int ledPort[6] = {LED_BIT, LED_FLD, LED_DRV, LED_PAN, LED_GAN, LED_ON};
const unsigned int CCValues[6] = {40, 41, 42, 43, 44}; //Complete Midi implementation on //NOWHERE YET TODO FOR KORG
unsigned int readings[5][numReadings];
unsigned int readIndex = 0;
unsigned int total[5] = {0, 0, 0, 0, 0};
unsigned int average[5] = {0, 0, 0, 0, 0};
unsigned int outputValue[5] = {0, 0, 0, 0, 0};
unsigned int previousValue[5] = {0, 0, 0, 0, 0};

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
		for (int i = 0; i < 5; ++i){
			readings[i][j] = analogRead(analogPort[i]);
			total[i] += readings[i][j];
		}
		digitalWrite(LED_ON, LOW);
		delay(50); //TODO lower as much as possible
		digitalWrite(LED_ON, HIGH);
	} 
}

void loop(){
	//Averaging and updating pot status
	for (int i = 0; i < 5; ++i){
		average[i] = total[i]/ numReadings;
		outputValue[i] = average[i] >> 2;
		total[i] -= readings[i][readIndex];
		readings[i][readIndex] = analogRead(analogPort[i]);
		total[i] += readings[i][readIndex];
	}
	(readIndex == numReadings - 1) ? readIndex = 0 : readIndex++;

	// to be executed once every 1/interval seconds
	unsigned long currentMillis = millis();
	if(currentMillis - previousMillis > interval){	 
		previousMillis = currentMillis;
		for (int i = 0; i < 5; ++i){
			if (outputValue[i] != previousValue[i]){
				digitalWrite(ledPort[i], HIGH);
				Serial.write(0xB0); 
				Serial.write(CCValues[i]);
				Serial.write(outputValue[i]);
				previousValue[i] = outputValue[i];
				digitalWrite(ledPort[i], LOW);
			}
		}
	} 
}
