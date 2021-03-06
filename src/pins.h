// Declare pins for the display:
#define TFT_CS     14
#define TFT_RST    10  // You can also connect this to the Arduino reset in which case, set this #define pin to -1!
#define TFT_DC     15

// Declare pins for the MUX CD74HC4067:
#define S0 0
#define S1 1
#define S2 2
#define S3 3 
#define SIG1 22   //  A8
#define SIG2 16   //  A8

#define ENCODER_1_S readEncMux(5)
#define ENCODER_1_A readEncMux(3)
#define ENCODER_1_B readEncMux(4)

#define ENCODER_2_S readEncMux(6)
#define ENCODER_2_A readEncMux(7)
#define ENCODER_2_B readEncMux(10)
/*
#define ENCODER_3_S 8
#define ENCODER_3_A 7
#define ENCODER_3_B 6

#define ENCODER_4_S 5
#define ENCODER_4_A 4
#define ENCODER_4_B 3

#define ENCODER_5_S 2
#define ENCODER_5_A 1
#define ENCODER_5_B 0
*/
#define ENCODER_PROCESSING_DELAY 100

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int encoder1Position = 0;
int encoder2Position = 0;
int encoder3Position = 0;
int encoder4Position = 0;
int encoder5Position = 0;

int e1AOut;
int e1SOut;
int e1AOutPrev;
int e1SOutPrev;

int e2AOut;
int e2SOut;
int e2AOutPrev;
int e2SOutPrev;
/*
int e3AOut;
int e3SOut;
int e3AOutPrev;
int e3SOutPrev;

int e4AOut;
int e4SOut;
int e4AOutPrev;
int e4SOutPrev;

int e5AOut;
int e5SOut;
int e5AOutPrev;
int e5SOutPrev;
*/
int encoderProcessingDelayCounter = 0;