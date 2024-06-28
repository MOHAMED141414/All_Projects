import requests
import csv
from bs4 import BeautifulSoup
import openpyxl
# date 6/27/2024
date=input("Please enter a date following this format MM/DD/YYYY:")
# the url of yallakora
page=requests.get(f"https://www.yallakora.com/match-center/%D9%85%D8%B1%D9%83%D8%B2-%D8%A7%D9%84%D9%85%D8%A8%D8%A7%D8%B1%D9%8A%D8%A7%D8%AA?date={date}")

def main(page):
    source=page.content
    soup=BeautifulSoup(source,"lxml")
    matches_details=[]
    chimpionships=soup.find_all("div",{'class':'matchCard'})

    def match_info(chimpionships):

        chim_title=chimpionships.contents[1].find("h2").text.strip()
        
        all_matches=chimpionships.contents[3].find_all('div',{'class':"item finish liItem"})
        num_of_matches=len(all_matches)
        for i in range (num_of_matches):
            # teams name
            team_A=all_matches[i].find('div',{'class':'teamA'}).text.strip()
            team_B=all_matches[i].find('div',{'class':'teamB'}).text.strip()
            # teams score
            match_result=all_matches[i].find('div',{'class':'MResult'}).find_all('span',{'class':'score'})
            score=f"{match_result[0].text.strip()} - {match_result[1].text.strip()}"
            # time
            match_time=all_matches[i].find('div',{'class':'MResult'}).find('span',{'class':'time'}).text.strip()
            #add match into matches_details
            matches_details.append({"نوع البطوله":chim_title,"الفريق الاول":team_A,"الفريق الثاني":team_B,"ميعاد المباراه":match_time,"النتيجه":score})
    for i in range(len(chimpionships)):
        match_info(chimpionships[i])
     
     
   
    keys=matches_details[0].keys()
    with open("/home/mohamed-esam/Documents/matchdetails.csv","w") as out_file:
        dic= csv.DictWriter(out_file,keys)
        dic.writeheader()
        dic.writerows(matches_details)
        print("file created")



main(page)
