// වර්ණ සංවේදක පින් නිර්වචනය කරන්න
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

// වර්ණ ස්පන්දන පළල මිනුම් සඳහා විචල්‍යයන්
int greenPW = 0;

// කොළ පැහැය සඳහා ක්‍රමාංකන අගයන් (ඔබ මේවා ක්‍රමාංකනය කළ යුතුයි!)
int green_min = 90;   // අවම කොළ ස්පන්දන පළල (ක්‍රමාංකනය කරන්න!)
int green_max = 120; // උපරිම කොළ ස්පන්දන පළල (ක්‍රමාංකනය කරන්න!)

void setup() {
  // S0 - S3 ප්‍රතිදානය ලෙස සකසන්න
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // සංවේදක ප්‍රතිදානය ආදානය ලෙස සකසන්න
  pinMode(sensorOut, INPUT);

  // ස්පන්දන පළල පරිමාණය 20% ලෙස සකසන්න (අවශ්‍ය පරිදි සකස් කරන්න)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Serial Monitor සකසන්න
  Serial.begin(9600);
  Serial.println("කොළ පැහැය හඳුනාගැනීම");
}

void loop() {
  // කොළ ස්පන්දන පළල කියවන්න
  greenPW = getGreenPW();

  Serial.print("G: ");
  Serial.println(greenPW);

  // කොළ පැහැය හඳුනාගැනීමේ තාර්කිකය (ක්‍රමාංකනය කළ පරාසයන් භාවිතා කරමින්)
  if (greenPW >= green_min && greenPW <= green_max) {
    Serial.println("හඳුනාගත් වර්ණය: කොළ");
    // මෙහි ඔබට කොළ හඳුනාගත් විට යමක් කිරීමට ඔබේ කේතය එක් කළ හැකිය
    // උදාහරණයක් ලෙස, LED එකක් ක්‍රියාත්මක කිරීම, මෝටරයක් චලනය කිරීම යනාදිය.
  } else {
    Serial.println("කොළ නොවේ"); // හෝ ඔබ කැමති වෙනත් පණිවිඩයක්
  }

  delay(500); // වේගවත් කියවීම් සඳහා අඩු ප්‍රමාදයක්
}

// කොළ ස්පන්දන පළල කියවීමට ශ්‍රිතය
int getGreenPW() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}