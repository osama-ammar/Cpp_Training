"""

Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

 

Example 1:

Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1
Example 2:

Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
    
"""
class Solution(object):

    def year_type(self,year):

        if year%100==0:
            #THEN IT'S A CENTURY YEAR EX)1900 ,2000
            if year%400==0  or year%4==0 :
                return "leab"
            else:
                return "normal"


    def daysBetweenDates(self, date1, date2):
        """
        :type date1: str
        :type date2: str
        :rtype: int
        """
        normal_year = [31,28,31,30,31,30,
                       31,31,30,31,30,31]

        leab_year   = [31,29,31,30,31,30,
                        31,31,30,31,30,31]

        #analyze inputs
        year1,month1,day1 = [int(i) for i in date1.split("-")]
        year2,month2,day2 = [int(i) for i in date2.split("-")]

        # get yaer type
        #self.year_type= lambda year : "leab" if year%4==0 else "normal"

        #getting no of days in a year so that we have only year and day index in this yaer
        days1 = sum(normal_year[0:month1-1])+day1 if self.year_type(year1)=="normal" else sum(leab_year[0:month1-1])+day1
        days2 = sum(normal_year[0:month2-1])+day2 if self.year_type(year2)=="normal" else sum(leab_year[0:month2-1])+day2

        ##
        print(days1,days2,sum(normal_year),sum(leab_year) )
        if year1==year2 :
            return abs(days1-days2)

        ##
        if year1>year2 :
            rest_days_year2= 365-days2 if self.year_type(year2)=="normal" else 366-days2 
            result= rest_days_year2 + days1
            for year in range(year2+1,year1):
                result+= 365 if self.year_type(year) =="normal" else 366
                #print( year, 365 if self.year_type(year) =="normal" else 366)

            return result
        ##    
        if year1<year2 :
            rest_days_year1= 365-days1 if self.year_type(year1)=="normal" else 366-days1 
            result= rest_days_year1 + days2
            for year in range(year1+1,year2):
                result+= 365 if self.year_type(year) =="normal" else 366
                #print( year,365 if self.year_type(year) =="normal" else 366)
            return result







