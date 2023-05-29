#include <iostream>
#include <time.h>
#include <cmath>
#include <string>

using namespace std;

int findChar(const char arr[], int len, char seek)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == seek) return i;
    }
    return -1;
}

string generateSerialNumber(){
    const char alphabet[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const int alphabetValues[26]={10,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28,29,30,31,32,34,35,36,37,38};

   

    char letter1=alphabet[rand()%25];
    char letter2=alphabet[rand()%25];
    char letter3=alphabet[rand()%25];
    char letter4='U';

    string numbers="";

    for(int i=0;i<6;i++){
        numbers+=to_string(rand()%9);
    }

    string rawSerialNumber="";

    rawSerialNumber.append(1,letter1);
    rawSerialNumber.append(1,letter2);
    rawSerialNumber.append(1,letter3);
    rawSerialNumber.append(1,letter4);
    rawSerialNumber+=numbers;

    int sum=0;
  
    for(int i=0;i<4;i++){
        int index = findChar(alphabet,26,rawSerialNumber[i]);
        int value=alphabetValues[index];
        sum+=value*pow(2,i);
    }

    for(int i=4;i<10;i++){
        int number=(int)rawSerialNumber[i] - 48;
        sum+=number*pow(2,i);
    }
    
    int sub=floor(sum / 11) * 11;
    int checkSum=sum-sub;

    if(checkSum==10){
        rawSerialNumber+=to_string(0);
    }else{
        rawSerialNumber+=to_string(checkSum);
    }
 
    return rawSerialNumber;
}

int main(){
    srand(time(NULL));
    int total;
    int out=1;
  
    cout<<"type number of containers : ";
    cin>>total;

    for(int i=0;i<total;i++){
        string serialNumber=generateSerialNumber();
        cout<<serialNumber<<endl;
    }
    
    do{
        cout<<"press 0 to exit ";
        cin>>out;
    }while(out!=0);

    return 0;
}