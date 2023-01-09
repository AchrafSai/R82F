#include <mbed.h>
InterruptIn RC(p21);
int i, j, k = 0;
int a, b, c = 0;
int x[20], ch1[20], ch[8];
// specifing arrays and variables to store values
void read_me(), read_rc();
Timer t1;

void read_me()
{
    // this code reads value from RC reciever from PPM pin
    // this code gives channel values from 0-1000 values
    a = t1.read_us(); // store time value a when pin value falling
    c = a - b; // calculating time inbetween two peaks
    b = a; //
    x[i] = c; // storing 15 value in array
    i = i + 1;
    if (i == 18) {
        for (int j = 0; j <= 18; j++) {
            ch1[j] = x[j];
        }
        i = 0;
    }
} // copy store all values from temporary array another array after 15 reading

int main()
{

    // put your setup code here, to run once:
    t1.start();
    RC.rise(&read_me);

    while (1) {
        // put your main code here, to run repeatedly:
        read_rc();
        // printf(" a :%i , b: %d c: %d, \r\n",a,b,c);
        printf("ch1: %i,ch2: %i,ch3: %i,ch4: %i,ch5: %i,ch6: %i,ch7: %i,ch8: %i\r\n", ch[0], ch[1], ch[2], ch[3], ch[4],
            ch[5], ch[6], ch[7]);
        // printf("%i %s \r\n",c,ch1);
    }
}

void read_rc()
{
    i = 0;
    j = 0;
    k = 0;
    for (k = 0; k <= 18; k++) {
        if (ch1[k] > 8000) {
            j = k + 1;
            break;
        }
    } // detecting separation space 10000us in that another array
    for (i = 0; i <= 7; i++) {
        ch[i] = (ch1[i + j]);
    }
} // assign 6 channel values after separation space
