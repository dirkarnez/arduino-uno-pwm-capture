const int outputPin = 9;  // Output pin for PWM
const int resolution = 8; // Resolution of the PWM (8-bit)

const int numSamples = 3600;   // Number of samples for the WAV file
const float sampleRate = 44100; // Sample rate of the WAV file (Hz)


void setup() {
  // Set the output pin as output
  pinMode(outputPin, OUTPUT);
  
  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
      int audioSamples[numSamples];
  // Generate a sine wave with varying duty cycle
  for (int i = 0; i < 360; i++) {
    // Calculate the duty cycle based on the sine function
    int dutyCycle = map(sin(radians(i)), -1, 1, 0, 255);
    
    // Generate the PWM signal
    analogWrite(outputPin, dutyCycle);

    // Send the duty cycle over the serial port
    Serial.println(dutyCycle);

    // Delay between each step to control the frequency
    audioSamples[i] = dutyCycle;

    // Delay between each step to control the frequency
    delayMicroseconds(1000000 / sampleRate);
  }

    delay(5000);
}