#include <iostream>
#include <string>
using namespace std;



class Date {
    private:
        int year ;
        int month ;
        int day ;
    public:
        void setYear(int y){
            year = y;
        }
        
        void setMonth(int m){
            month = m;
        }

        void setDay(int d){
            day = d;
        }

        void setDate(int y, int m, int d){
            year=y;month=m;day=d;
        }

};





class Time {

    private:
        int hour ;
        int minute ;
        int second ;
    public:

        Time(){
            hour = 0;
            minute = 0;
            second = 0;            
        }
        Time (int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        }  

        int getHour(){
            return hour ;
        }
        
        int getMinute(){
            return minute ;
        }

        int getSecond(){
            return second ;
        }



        void setHour(int h){
            hour = h;
        }
        
        void setMinute(int m){
            minute = m;
        }

        void setSecond(int s){
            second = s;
        }

        void setDate(int h, int m, int s){
            hour=h;minute=m;second=s;
        }


        Time nextSecond(){
            Time obj(hour,minute,second);
            //ther will be a difference between second++ and obj.second++  ?? 
            // second++ will affect only the object it self ex(t1.nextSecond()) ?
            // obj.second++ will affect only the copy object  ex(t2=t1.nextSecond()) ?
            second++;
            //obj.second++;
            
            if (second>=60){
                second=0;
                minute++;;
            }

            if (minute>=60){
                minute=0;
                hour++;
            }

            if (hour>=24){
                second=0;
            }

            return obj;
        }


        Time previousSecond(){
            Time obj(hour,minute,second);
            second-=1;


            if (second<0){
                second=59;
                minute--;;
            }

            if (minute<0){
                minute=59;
                hour--;
            }
            
            if (hour<0){
                hour=23;
            }

            return obj;
        }

};