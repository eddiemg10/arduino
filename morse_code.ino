
int led = 2;
int buzzer = 7;

// Morse code mapping
  const char* morseCodeMap[36] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
  };

void setup()
{  
  Serial.begin(9600); 
  
  pinMode(led, OUTPUT);
 
}

void loop()
{
   if (Serial.available() > 0) { // Check if there is serial data available
    String input = Serial.readString(); // Read the serial input as a string
    input.toUpperCase();
    
     for(int i = 0; i < input.length(); i++){
     	int character = int(input[i])-int('A');  // Get ASCII for character
        
        if(character >= 0){
           String morseCode = morseCodeMap[character];
           for(int j = 0; j < morseCode.length(); j++){
          	   Serial.println(morseCode[j]);
               if(morseCode[j] == '.'){
					digitalWrite(led, HIGH);
                 	tone(buzzer, 750);
                 	delay(100);
               }
               else{
                 	digitalWrite(led, HIGH);
                 	tone(buzzer, 750);
                 	delay(300);
               }
               digitalWrite(led, LOW);
               noTone(buzzer);
               delay(100);
             	
           }
          delay(300);
           
        }
         else{
           digitalWrite(led, LOW);
           delay(700);
         }
       	

     }

  }
}
